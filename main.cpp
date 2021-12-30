#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <stack>

#include "IGraph.h"
#include "ListGraph.h"
#include "MatrixGraph.h"
#include "SetGraph.h"
#include "ArcGraph.h"
using namespace std;

void dfs(const IGraph& graph, void (*callback)(int v)){
    vector<bool> visited(graph.VerticesCount(), false);
    stack<int> q;

    for (int vertex = 0; vertex < graph.VerticesCount(); vertex++){
        if (!visited[vertex]){
            visited[vertex] = true;
            callback(vertex);
            q.push(vertex);
            while (!q.empty()){
                int parent = q.top();
                bool has_unvisited_child = false;
                vector<int> children = graph.GetNextVertices(parent);

                for (auto& child: children){
                    if (!visited[child]){
                        visited[child] = true;
                        callback(child);
                        q.push(child);
                        has_unvisited_child = true;
                        break;
                    }
                }
                if (!has_unvisited_child) q.pop();
            }
        }
    }
}

void bfs(const IGraph& graph, void (*callback)(int v)){
    vector<bool> visited(graph.VerticesCount(), false);
    queue<int> q;



    for (int vertex = 0; vertex < graph.VerticesCount(); vertex++){
        if (!visited[vertex]){
            visited[vertex] = true;
            q.push(vertex);
            while(!q.empty()){
                int v = q.front();
                q.pop();
                callback(v);
                vector<int> children = graph.GetNextVertices(v);
                for (auto& child : children){
                    if (!visited[child]){
                        visited[child] = true;
                        q.push(child);
                    }
                }
            }
        }
    }
}

void test(const IGraph& graph){
    cout << "-------DFS--------\n";
    dfs(graph, [](int v){
        cout << v << " ";
    });

    cout << "\n-------BFS--------\n";
    bfs(graph, [](int v){
        cout << v << " ";
    });

    cout << "\n\n\n";
}

int main(){
    IGraph* graph = new ListGraph(9);
    graph->AddEdge(1, 2);
    graph->AddEdge(1, 3);
    graph->AddEdge(1, 4);
    graph->AddEdge(2, 5);
    graph->AddEdge(2, 6);
    graph->AddEdge(3, 7);
    graph->AddEdge(4, 8);
    graph->AddEdge(8, 0);
    graph->AddEdge(0, 4);
    graph->AddEdge(0, 1);

    IGraph* matrixGraph = new MatrixGraph(*graph);
    IGraph* setGraph = new SetGraph(*matrixGraph);
    IGraph* arcGraph = new ArcGraph(*setGraph);
    IGraph* listGraph = new ListGraph(*arcGraph);

    test(*matrixGraph);
    test(*setGraph);
    test(*arcGraph);
    test(*listGraph);

    delete graph;
    delete listGraph;
    delete matrixGraph;
    delete setGraph;
    delete arcGraph;
    return 0;
}