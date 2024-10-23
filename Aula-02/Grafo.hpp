#ifndef GRAFO_HPP
#define GRAFO_HPP
#include <iostream>

class Grafo 
{
private:
    int numVertices;
    int numArestas;
    bool** matriz;

public: 
    Grafo(int v);
    ~Grafo();

    void imprimirGrafo();
    bool inserirAresta(int v1, int v2);
    bool removerAresta(int v1, int v2);
    bool verificarSeArestaExiste(int v1, int v2);
    int verNumeroArestas();
    int verNumeroVertices();
    bool verificarVizinhosVertice(int v);
    int verificarGrauVertice(int v);

};

#endif