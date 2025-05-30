#include "MatrixGraph.h"
#include <cassert>

MatrixGraph::MatrixGraph(int vertices_count)
    : adjacency_matrix_(vertices_count, 
                        std::vector<bool>(vertices_count, false)) {}

MatrixGraph::MatrixGraph(const IGraph& graph) {
    const int size = graph.VerticesCount();
    adjacency_matrix_.resize(size, std::vector<bool>(size, false));
    
    for (int from = 0; from < size; ++from) {
        for (int to : graph.GetNextVertices(from)) {
            adjacency_matrix_[from][to] = true;
        }
    }
}

void MatrixGraph::AddEdge(int from, int to) {
    assert(from >= 0 && from < adjacency_matrix_.size());
    assert(to >= 0 && to < adjacency_matrix_.size());
    
    adjacency_matrix_[from][to] = true;
}

int MatrixGraph::VerticesCount() const {
    return adjacency_matrix_.size();
}

std::vector<int> MatrixGraph::GetNextVertices(int vertex) const {
    assert(vertex >= 0 && vertex < adjacency_matrix_.size());
    
    std::vector<int> next_vertices;
    for (int to = 0; to < adjacency_matrix_.size(); ++to) {
        if (adjacency_matrix_[vertex][to]) {
            next_vertices.push_back(to);
        }
    }
    return next_vertices;
}

std::vector<int> MatrixGraph::GetPrevVertices(int vertex) const {
    assert(vertex >= 0 && vertex < adjacency_matrix_.size());
    
    std::vector<int> prev_vertices;
    for (int from = 0; from < adjacency_matrix_.size(); ++from) {
        if (adjacency_matrix_[from][vertex]) {
            prev_vertices.push_back(from);
        }
    }
    return prev_vertices;
}

void MatrixGraph::PrintNextVertices() const {
    std::cout << "Matritsa smezhnosti (vyhodnye rebra):" << std::endl;
    for (int i = 0; i < adjacency_matrix_.size(); ++i) {
        std::cout << i << ": ";
        for (int j = 0; j < adjacency_matrix_[i].size(); ++j) {
            if (adjacency_matrix_[i][j]) {
                std::cout << j << " ";
            }
        }
        std::cout << std::endl;
    }
}

void MatrixGraph::PrintPrevVertices() const {
    std::cout << "Matritsa smezhnosti (vhodnye rebra):" << std::endl;
    for (int j = 0; j < adjacency_matrix_.size(); ++j) {
        std::cout << j << ": ";
        for (int i = 0; i < adjacency_matrix_.size(); ++i) {
            if (adjacency_matrix_[i][j]) {
                std::cout << i << " ";
            }
        }
        std::cout << std::endl;
    }
}
