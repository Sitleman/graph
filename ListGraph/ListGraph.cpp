#include "ListGraph.h"


ListGraph::ListGraph(int vertices_count){
    vertices.resize(vertices_count);
}

ListGraph::ListGraph(const IGraph &graph){
    vertices.resize(graph.VerticesCount());
    for (int i = 0; i < vertices.size(); i++){
        vertices[i] = graph.GetNextVertices(i);
    }
}

ListGraph::~ListGraph(){

};

void ListGraph::AddEdge(int from, int to) {
    vertices[from].push_back(to);
}

int ListGraph::VerticesCount() const{
    return vertices.size();
}

vector<int> ListGraph::GetNextVertices(int vertex) const{
    vector<int> result(vertices[vertex].begin(), vertices[vertex].end());
    return result;
}

vector<int> ListGraph::GetPrevVertices(int vertex) const{
    vector<int> result;
    for (int parent= 0; parent < vertices.size(); parent++){
        for (auto child : vertices[parent]){
            if (child == vertex){
                result.push_back(parent);
                break;
            }
        }
    }
    return result;
}

