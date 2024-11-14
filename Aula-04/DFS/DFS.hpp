#ifndef DFS_HPP
#define DFS_HPP

#include <iostream>

struct Node // Vertice no grafo. Cada vertice tem uma lista de vertices no qual ele está conectado
{
  int vertice;
  float peso;
  Node* prox; //* PONT
  bool visitado;
  
  Node(int v, float p, Node* n) 
  { 
    vertice = v;
    peso = p;
    prox = n;
    visitado = false;
  }

};

struct ArestaLista // Armazena os vértices de origem e destino de uma certa aresta.
{
    int origem;
    int destino;
    float peso;
    ArestaLista* prox; //* PONT2
};

class DFS
{
private:
    int numVertices;
    int numArestas;
    Node** ListaAdj; // Lista Adj -> Cada elemento (Node) aponta para lista de Elemento

    void DFSAux(int vertice);

public:
    DFS(int vertices); // Inicia Grafo
    ~DFS(); // Libera Grafo

    int getNumVertices();
    int getNumArestas();

    void imprimir();
    bool adicionarAresta (int origem, int destino, float peso);
    bool removerVertice (int origem, int destino);

    void depthFirstSearch ();

};

#endif