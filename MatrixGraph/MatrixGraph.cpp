#include "MatrixGraph.h"

MatrixGraph::MatrixGraph(int vertices_count){
    vertices.resize(vertices_count, vector<int> (vertices_count, 0));
}

MatrixGraph::MatrixGraph(const IGraph &graph){
    vertices.resize(graph.VerticesCount(), vector<int> (graph.VerticesCount(), 0));
    for (int parent = 0; parent < vertices.size(); parent++){
        vector<int> children = graph.GetNextVertices(parent);
        for (auto child : children){
            vertices[parent][child] = 1;
        }
    }
}

MatrixGraph::~MatrixGraph(){

};

void MatrixGraph::AddEdge(int from, int to) {
    vertices[from][to] = 1;
}

int MatrixGraph::VerticesCount() const{
    return vertices.size();
}

vector<int> MatrixGraph::GetNextVertices(int vertex) const{
    vector<int> result;
    for (int child = 0; child < vertices.size(); child++){
        if (vertices[vertex][child] == 1) {
            result.push_back(child);
        }
    }
    return result;
}

vector<int> MatrixGraph::GetPrevVertices(int vertex) const{
    vector<int> result;
    for (int parent = 0; parent < vertices.size(); parent++){
        if (vertices[parent][vertex] == 1){
            result.push_back(parent);
        }
    }
    return result;
}

