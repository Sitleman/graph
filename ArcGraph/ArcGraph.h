#pragma once

#include <iostream>
#include <vector>
#include "IGraph.h"

class ArcGraph : public IGraph {
public:

    ArcGraph(int vertices_count);

    ArcGraph(const IGraph &graph);

    ~ArcGraph();

    void AddEdge(int from, int to) override;

    int VerticesCount() const override;

    vector<int> GetNextVertices(int vertex) const override;

    vector<int> GetPrevVertices(int vertex) const override;

private:
    int size;
    vector<pair<int, int>> edges;
};


