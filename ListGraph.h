#ifndef GRAPH_LISTGRAPH_H_
#define GRAPH_LISTGRAPH_H_

#include "IGraph.h"
#include <vector>

class ListGraph : public IGraph {
public:
    explicit ListGraph(int vertices_count);
    explicit ListGraph(const IGraph& graph);
    
    void AddEdge(int from, int to) override;
    int VerticesCount() const override;
    std::vector<int> GetNextVertices(int vertex) const override;
    std::vector<int> GetPrevVertices(int vertex) const override;

    void PrintNextVertices() const;
    void PrintPrevVertices() const;

private:
    std::vector<std::vector<int>> adjacency_lists_;
};

#endif  // GRAPH_LISTGRAPH_H_
