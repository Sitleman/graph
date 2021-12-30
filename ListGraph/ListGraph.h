#pragma once

#include <iostream>
#include <vector>
#include "IGraph.h"

class ListGraph : public IGraph {
public:

    ListGraph(int vertices_count);

    ListGraph(const IGraph &graph);

    ~ListGraph();

    void AddEdge(int from, int to) override;

    int VerticesCount() const override;

    vector<int> GetNextVertices(int vertex) const override;

    vector<int> GetPrevVertices(int vertex) const override;

private:
    vector<vector<int>> vertices;

};


