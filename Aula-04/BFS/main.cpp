#include <iostream>
#include "BFS.hpp"

int main ()
{
    BFS graph(5);

    graph.adicionarAresta(0, 2);
    // graph.adicionarAresta(0, 1);
    // graph.adicionarAresta(1, 0);
    graph.adicionarAresta(1, 2);
    graph.adicionarAresta(2, 4);
    graph.adicionarAresta(1, 3);
    graph.adicionarAresta(3, 2);
    graph.adicionarAresta(4, 1);

    graph.imprimir();
    graph.breadthFirstSearch(0);
    printf("\n");

    graph.breadthFirstSearch(4);

    return 0;
    
}