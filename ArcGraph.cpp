#include "ArcGraph.h"
#include <cassert>

ArcGraph::ArcGraph(int vertices_count) 
    : vertices_count_(vertices_count) {}

ArcGraph::ArcGraph(const IGraph& graph) 
    : vertices_count_(graph.VerticesCount()) {
    for (int from = 0; from < graph.VerticesCount(); ++from) {
        for (int to : graph.GetNextVertices(from)) {
            edges_.emplace_back(from, to);
        }
    }
}

void ArcGraph::AddEdge(int from, int to) {
    assert(from >= 0 && from < vertices_count_);
    assert(to >= 0 && to < vertices_count_);
    
    edges_.emplace_back(from, to);
}

int ArcGraph::VerticesCount() const {
    return vertices_count_;
}

std::vector<int> ArcGraph::GetNextVertices(int vertex) const {
    assert(vertex >= 0 && vertex < vertices_count_);
    
    std::vector<int> next_vertices;
    for (const auto& [from, to] : edges_) {
        if (from == vertex) {
            next_vertices.push_back(to);
        }
    }
    return next_vertices;
}

std::vector<int> ArcGraph::GetPrevVertices(int vertex) const {
    assert(vertex >= 0 && vertex < vertices_count_);
    
    std::vector<int> prev_vertices;
    for (const auto& [from, to] : edges_) {
        if (to == vertex) {
            prev_vertices.push_back(from);
        }
    }
    return prev_vertices;
}

void ArcGraph::PrintNextVertices() const {
    std::cout << "Spisok reber (vyhodnye svyazi):" << std::endl;
    for (int i = 0; i < vertices_count_; ++i) {
        std::cout << i << ": ";
        for (const auto& [from, to] : edges_) {
            if (from == i) {
                std::cout << to << " ";
            }
        }
        std::cout << std::endl;
    }
}

void ArcGraph::PrintPrevVertices() const {
    std::cout << "Spisok reber (vhodnye svyazi):" << std::endl;
    for (int i = 0; i < vertices_count_; ++i) {
        std::cout << i << ": ";
        for (const auto& [from, to] : edges_) {
            if (to == i) {
                std::cout << from << " ";
            }
        }
        std::cout << std::endl;
    }
}
