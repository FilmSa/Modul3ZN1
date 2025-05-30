#ifndef GRAPH_MATRIXGRAPH_H_
#define GRAPH_MATRIXGRAPH_H_

#include "IGraph.h"
#include <vector>

// Граф, хранящийся как матрица смежности
class MatrixGraph : public IGraph {
public:
    explicit MatrixGraph(int vertices_count);
    explicit MatrixGraph(const IGraph& graph);
    
    void AddEdge(int from, int to) override;
    int VerticesCount() const override;
    std::vector<int> GetNextVertices(int vertex) const override;
    std::vector<int> GetPrevVertices(int vertex) const override;

    void PrintNextVertices() const;
    void PrintPrevVertices() const;

private:
    std::vector<std::vector<bool>> adjacency_matrix_;
};

#endif  // GRAPH_MATRIXGRAPH_H_
