#include "Grafo.hpp"
//// a) Inicializar um Grafo; 
//// (b) Imprimir um Grafo; 
//// (c) Liberar a Memória de um Grafo; 
//// (d) Inserir uma Aresta; 
//// (e) Remover uma Aresta; 
//// (f) Verificar se uma Aresta Existe; 
//// (g) Retornar o Número de Vértices; 
//// (h) Retornar o Número de Arestas; 
//// (i) Verifica se um Vértice Possui Vizinhos; 
//// (j) Retornar o Grau de um Vértice.


Grafo::Grafo(int vertices)
{
    if (vertices < 1) return;
    this->numVertices = vertices;
    this->numArestas = 0;

    matriz = new bool*[vertices];
    for ( int i = 0; i < vertices; i++) {
        matriz[i] = new bool[vertices]; //? 
        for ( int j = 0; j < vertices ; j++) {
            matriz[i][j] = false;
        }
    }

}

Grafo::~Grafo()
{
    for (int i = 0; i < numVertices ; i++) {
        delete[] matriz[i]; // Libera cada fileira
    }
    delete[] matriz; // Libera o array de ponteiros
}

void Grafo::imprimirGrafo()
{
    for (int i = 0; i < numVertices ; i++) {
        for (int j = 0; j < numVertices ; j++) {
            std::cout << matriz[i][j] << " ";
        }
        std::cout << std::endl;
    }

}

bool Grafo::inserirAresta(int v1, int v2)
{
    if (v1 < 0 || v2 < 0 || v1 >= numVertices  || v2 >= numVertices ) return false;
    if (matriz[v1][v2] == false) {
        matriz[v1][v2] = true;
        matriz[v2][v1] = true;
        numArestas++;
    }

    return true;
}

bool Grafo::removerAresta(int v1, int v2)
{
    if (v1 < 0 || v2 < 0 || v1 >= numArestas || v2 >= numArestas) return false;

    if (matriz[v1][v2] == true) {
        matriz[v1][v2] = false;
        matriz[v2][v1] = false;
        numArestas--;
    }

    return true;

}

bool Grafo::verificarSeArestaExiste(int v1, int v2)
{
    return matriz[v1][v2];
}

bool Grafo::verificarVizinhosVertice(int v)
{
    if (v < 0 || v >= numVertices) return false;
    for (int walk = 0; walk < numVertices; walk++) 
        if (matriz[v][walk]) return true;

    return false;
}

int Grafo::verificarGrauVertice (int v)
{
    if (v < 0 || v >= numVertices) return false;
    int grau = 0;
    for (int i = 0; i < numVertices; i++) 
        if (matriz[v][i]) grau++;
    

    return grau;

}


int Grafo::verNumeroArestas()
{
    return numArestas;
}

int Grafo::verNumeroVertices()
{
    return numVertices;
}