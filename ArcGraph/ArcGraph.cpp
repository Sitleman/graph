#include "ArcGraph.h"

ArcGraph::ArcGraph(int vertices_count){
    size = vertices_count;
}

ArcGraph::ArcGraph(const IGraph &graph){
    size = graph.VerticesCount();
    for (int parent = 0; parent < size; parent++){
        vector<int> children = graph.GetNextVertices(parent);
        for (auto child : children){
            edges.push_back({parent, child});
        }
    }
}

ArcGraph::~ArcGraph(){

};

void ArcGraph::AddEdge(int from, int to) {
    edges.push_back({from, to});
}

int ArcGraph::VerticesCount() const{
    return size;
}

vector<int> ArcGraph::GetNextVertices(int vertex) const{
    vector<int> result;
    for (auto& edge : edges){
        if (edge.first == vertex){
            result.push_back(edge.second);
        }
    }
    return result;
}

vector<int> ArcGraph::GetPrevVertices(int vertex) const{
    vector<int> result;
    for (auto& edge : edges){
        if (edge.second == vertex){
            result.push_back(edge.first);
        }
    }
    return result;
}

