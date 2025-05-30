#include <iostream>
#include <vector>
#include "ListGraph.h"
#include "MatrixGraph.h"
#include "SetGraph.h"
#include "ArcGraph.h"

int main() {
    std::cout << "\nARC GRAPH\n";
    ArcGraph arcGraph(5);
    arcGraph.AddEdge(0, 3);
    arcGraph.AddEdge(3, 0);
    arcGraph.AddEdge(0, 4);
    arcGraph.AddEdge(4, 2);
    arcGraph.AddEdge(1, 2);
    arcGraph.PrintNextVertices();
    arcGraph.PrintPrevVertices();

    std::cout << "\nLIST GRAPH\n";
    ListGraph listGraph(arcGraph);
    listGraph.PrintNextVertices();
    listGraph.PrintPrevVertices();

    std::cout << "\nMATRIX GRAPH\n";
    MatrixGraph matrixGraph(listGraph);
    matrixGraph.PrintNextVertices();
    matrixGraph.PrintPrevVertices();

    std::cout << "\nSET GRAPH\n";
    SetGraph setGraph(matrixGraph);
    setGraph.PrintNextVertices();
    setGraph.PrintPrevVertices();

    std::cout << "\nADDING EDGE 2->4\n";
    setGraph.AddEdge(2, 4);
    setGraph.PrintNextVertices();
    setGraph.PrintPrevVertices();

    return 0;
}
