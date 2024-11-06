#ifndef GRAFO_LISTA_ADJ
#define GRAFO_LISTA_ADJ

#include <iostream>

struct Node  
{
    int vertice;
    Node* prox;
    int peso;
};

class GrafoLista
{
private:
    int numVertices; 
    int numArestas;
    Node** Lista;

public:
    GrafoLista(int inputVertices);
    ~GrafoLista();

    void imprimirGrafo();
    bool inserirAresta(int v1, int v2, int inputPeso);
    bool removerAresta(int v1, int v2);
    bool verificarSeArestaExiste(int v1, int v2);
    bool verificarVizinhosVertice(int v);
    int verificarGrauVertice(int v);

    int getNumerosVertices();

};

#endif