#include <iostream>
#include "GrafoListaAdjComPesos.hpp"

int main ()
{
    GrafoLista graph(5);

    graph.inserirAresta(0, 1, 10);
    graph.inserirAresta(0, 2, 15);
    graph.inserirAresta(1, 3, 20);
    graph.inserirAresta(2, 3, 25);
    graph.inserirAresta(3, 4, 30);

    graph.imprimirGrafo();

    std::cout << "\nChecando Grau dos Vertices :" << std::endl;
    for (int i = 0; i < graph.getNumerosVertices(); ++i) {
        std::cout << "Grau do vertice " << i << ": " << graph.verificarGrauVertice(i) << std::endl;
    }

    
    std::cout << "\nChecando se Aresta Existe:" << std::endl;
    std::cout << "Aresta 0 -> 1: " << (graph.verificarSeArestaExiste(0, 1) ? "Existe" : "Nao Existe") << std::endl;
    std::cout << "Aresta 3 -> 2: " << (graph.verificarSeArestaExiste(3, 2) ? "Existe" : "Nao Existe") << std::endl;
    
    std::cout << "\nRemovendo Aresta 0 -> 1" << std::endl;
    graph.removerAresta(2, 3);
    graph.imprimirGrafo();


    return 0;
    
}