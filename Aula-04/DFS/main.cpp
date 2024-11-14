#include <iostream>
#include "DFS.hpp"

int main ()
{
    DFS graph(5);

    graph.adicionarAresta(0, 2, 30);
    graph.adicionarAresta(1, 0, 10);
    graph.adicionarAresta(1, 2, 20);
    graph.adicionarAresta(2, 4, 40);
    graph.adicionarAresta(4, 3, 40);
    // graph.adicionarAresta(1, 3, 40);

    graph.imprimir();
    graph.depthFirstSearch();




    return 0;
    
}