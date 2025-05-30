#ifndef GRAPH_SETGRAPH_H_
#define GRAPH_SETGRAPH_H_

#include "IGraph.h"
#include <vector>
#include <unordered_set>

// Граф, хранящийся как массив хэш-таблиц
class SetGraph : public IGraph {
public:
    explicit SetGraph(int vertices_count);
    explicit SetGraph(const IGraph& graph);
    
    void AddEdge(int from, int to) override;
    int VerticesCount() const override;
    std::vector<int> GetNextVertices(int vertex) const override;
    std::vector<int> GetPrevVertices(int vertex) const override;

    void PrintNextVertices() const;
    void PrintPrevVertices() const;

private:
    std::vector<std::unordered_set<int>> adjacency_sets_;
};

#endif  // GRAPH_SETGRAPH_H_
