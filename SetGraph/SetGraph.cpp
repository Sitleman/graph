#include "SetGraph.h"

SetGraph::SetGraph(int vertices_count){
    vertices.resize(vertices_count);
}

SetGraph::SetGraph(const IGraph &graph){
    vertices.resize(graph.VerticesCount());
    for (int i = 0; i < vertices.size(); i++){
        vector<int> children = graph.GetNextVertices(i);
        vertices[i].insert(children.begin(), children.end());
    }
}

SetGraph::~SetGraph(){

};

void SetGraph::AddEdge(int from, int to) {
    vertices[from].insert(to);
}

int SetGraph::VerticesCount() const{
    return vertices.size();
}

vector<int> SetGraph::GetNextVertices(int vertex) const{
    vector<int> result(vertices[vertex].begin(), vertices[vertex].end());
    return result;
}

vector<int> SetGraph::GetPrevVertices(int vertex) const{
    vector<int> result;
    for (int parent = 0; parent < vertices.size(); parent++){
        if (vertices[parent].count(vertex)){
            result.push_back(parent);
        }
    }
    return result;
}

