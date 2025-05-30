#include "SetGraph.h"
#include <cassert>

SetGraph::SetGraph(int vertices_count) 
    : adjacency_sets_(vertices_count) {}

SetGraph::SetGraph(const IGraph& graph) {
    adjacency_sets_.resize(graph.VerticesCount());
    for (int from = 0; from < graph.VerticesCount(); ++from) {
        for (int to : graph.GetNextVertices(from)) {
            adjacency_sets_[from].insert(to);
        }
    }
}

void SetGraph::AddEdge(int from, int to) {
    assert(from >= 0 && from < adjacency_sets_.size());
    assert(to >= 0 && to < adjacency_sets_.size());
    
    adjacency_sets_[from].insert(to);
}

int SetGraph::VerticesCount() const {
    return adjacency_sets_.size();
}

std::vector<int> SetGraph::GetNextVertices(int vertex) const {
    assert(vertex >= 0 && vertex < adjacency_sets_.size());
    return std::vector<int>(adjacency_sets_[vertex].begin(), 
                           adjacency_sets_[vertex].end());
}

std::vector<int> SetGraph::GetPrevVertices(int vertex) const {
    assert(vertex >= 0 && vertex < adjacency_sets_.size());
    
    std::vector<int> prev_vertices;
    for (int from = 0; from < adjacency_sets_.size(); ++from) {
        if (adjacency_sets_[from].count(vertex) > 0) {
            prev_vertices.push_back(from);
        }
    }
    return prev_vertices;
}

void SetGraph::PrintNextVertices() const {
    std::cout << "Graf na osnove mnozhestv (vyhodnye rebra):" << std::endl;
    for (int i = 0; i < adjacency_sets_.size(); ++i) {
        std::cout << i << ": ";
        for (int v : adjacency_sets_[i]) {
            std::cout << v << " ";
        }
        std::cout << std::endl;
    }
}

void SetGraph::PrintPrevVertices() const {
    std::cout << "Graf na osnove mnozhestv (vhodnye rebra):" << std::endl;
    for (int i = 0; i < adjacency_sets_.size(); ++i) {
        std::cout << i << ": ";
        for (int v : GetPrevVertices(i)) {
            std::cout << v << " ";
        }
        std::cout << std::endl;
    }
}
