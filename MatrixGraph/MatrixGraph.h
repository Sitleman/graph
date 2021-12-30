#pragma once

#include <iostream>
#include <vector>
#include "IGraph.h"

class MatrixGraph : public IGraph {
public:
    MatrixGraph(int vertices_count);

    MatrixGraph(const IGraph &graph);

    ~MatrixGraph();

    void AddEdge(int from, int to) override;

    int VerticesCount() const override;

    vector<int> GetNextVertices(int vertex) const override;

    vector<int> GetPrevVertices(int vertex) const override;

private:
    vector<vector<int>> vertices;
};


