#ifndef GRAPH_ARCGRAPH_H_
#define GRAPH_ARCGRAPH_H_

#include "IGraph.h"
#include <vector>

class ArcGraph : public IGraph {
public:
    explicit ArcGraph(int vertices_count);
    explicit ArcGraph(const IGraph& graph);
    
    void AddEdge(int from, int to) override;
    int VerticesCount() const override;
    std::vector<int> GetNextVertices(int vertex) const override;
    std::vector<int> GetPrevVertices(int vertex) const override;

    void PrintNextVertices() const;
    void PrintPrevVertices() const;

private:
    std::vector<std::pair<int, int>> edges_;  
    int vertices_count_; 
};

#endif  // GRAPH_ARCGRAPH_H_
