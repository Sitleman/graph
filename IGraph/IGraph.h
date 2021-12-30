#pragma once

#include <vector>
using namespace std;

struct IGraph {

    IGraph(){

    }
    // Добавление ребра от from к to.
    virtual void AddEdge(int from, int to) = 0;

    virtual int VerticesCount() const  = 0;

    virtual std::vector<int> GetNextVertices(int vertex) const = 0;
    virtual std::vector<int> GetPrevVertices(int vertex) const = 0;

    virtual ~IGraph() {
        //cout << "~IGraph" << "\n";
    }
};
