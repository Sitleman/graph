#pragma once

#include <iostream>
#include <vector>
#include <set>
#include "IGraph.h"

class SetGraph : public IGraph {
public:

    SetGraph(int vertices_count);

    SetGraph(const IGraph &graph);

    ~SetGraph();

    void AddEdge(int from, int to) override;

    int VerticesCount() const override;

    vector<int> GetNextVertices(int vertex) const override;

    vector<int> GetPrevVertices(int vertex) const override;

private:
    vector<set<int>> vertices;

};


