#include "ListGraph.h"
#include <iostream>
ListGraph::ListGraph(int vertices_count) 
    : adjacency_lists_(vertices_count) {}

ListGraph::ListGraph(const IGraph& graph) {
    adjacency_lists_.resize(graph.VerticesCount());
    for (int i = 0; i < graph.VerticesCount(); ++i) {
        adjacency_lists_[i] = graph.GetNextVertices(i);
    }
}

void ListGraph::AddEdge(int from, int to) {
    assert(from >= 0 && from < adjacency_lists_.size());
    assert(to >= 0 && to < adjacency_lists_.size());
    
    adjacency_lists_[from].push_back(to);
}

int ListGraph::VerticesCount() const {
    return adjacency_lists_.size();
}

std::vector<int> ListGraph::GetNextVertices(int vertex) const {
    assert(vertex >= 0 && vertex < adjacency_lists_.size());
    return adjacency_lists_[vertex];
}

std::vector<int> ListGraph::GetPrevVertices(int vertex) const {
    assert(vertex >= 0 && vertex < adjacency_lists_.size());
    
    std::vector<int> prev_vertices;
    for (int from = 0; from < adjacency_lists_.size(); ++from) {
        for (int to : adjacency_lists_[from]) {
            if (to == vertex) {
                prev_vertices.push_back(from);
                break; 
            }
        }
    }
    return prev_vertices;
}

void ListGraph::PrintNextVertices() const {
    std::cout << "Spisok smezhnosti (vershiny, v kotorye vedut rebra):" << std::endl;
    for (int i = 0; i < adjacency_lists_.size(); ++i) {
        std::cout << i << ": ";
        for (int v : adjacency_lists_[i]) {
            std::cout << v << " ";
        }
        std::cout << std::endl;
    }
}

void ListGraph::PrintPrevVertices() const {
    std::cout << "Obratnye svyazi (vershiny, iz kotoryh vedut rebra):" << std::endl;
    for (int i = 0; i < adjacency_lists_.size(); ++i) {
        std::cout << i << ": ";
        for (int v : GetPrevVertices(i)) {
            std::cout << v << " ";
        }
        std::cout << std::endl;
    }
}
