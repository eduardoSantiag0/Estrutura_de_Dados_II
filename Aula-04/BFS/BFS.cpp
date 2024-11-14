#include "BFS.hpp"
#include <stdio.h>
#include <vector>
#include <queue>

BFS::BFS(int v)
{

    this->numVertices = v;
    this->numArestas = 0;

    ListaAdj = new Elemento*[numVertices];
    for (int i = 0 ; i < numVertices; i++) {
        ListaAdj[i] = nullptr;
    }

    // visitados = new bool[numVertices] {false};

}


BFS::~BFS()
{
    for (int i = 0; i < numVertices; i++) {
        Elemento* atual = ListaAdj[i];
        while (atual)
        {
            Elemento* temp = atual;
            atual = atual->prox;
            delete temp;
        }
        
        delete ListaAdj[i];
    }
    
    delete [] ListaAdj;
    // delete[] visitados;


    this->numVertices = 0;
    this->numArestas = 0;
}


int BFS::getNumArestas() 
{
    return numArestas;
}

int BFS::getNumVertices()
{
    return numVertices;
}

bool BFS::adicionarAresta(int origem, int destino)
{
    if (origem >= numVertices ||origem < 0 || destino >= numVertices ||destino < 0) return false;

    Elemento* walk = ListaAdj[origem];
    Elemento* ant = nullptr;

    while (walk)
    {
        ant = walk;
        walk = walk->prox;
    }

    Elemento* novo = new Elemento(destino, walk);

    if (ant) ant->prox = novo;
    else ListaAdj[origem] = novo;

    numArestas++;

    return true;
}

bool BFS::removerAresta(int origem, int destino)
{
    if (origem >= numVertices ||origem < 0 || destino >= numVertices ||destino < 0) return false;

    Elemento* walk = ListaAdj[origem];
    Elemento* ant = nullptr;

    while (walk)
    {
        if (walk->vertice == destino) {
            Elemento* temp = walk;

            if (ant) ant->prox = walk->prox;
            else ListaAdj[origem] = walk->prox;

            delete temp;
            numArestas--;
            return true;
        }
        ant = walk;
        walk = walk->prox;
    }

    return false;
    
}

void BFS::imprimir()
{
    for (int i = 0; i < numVertices; i++) {
        printf("[%2i]",i);
        Elemento* atual = ListaAdj[i];
        while (atual)
        {
            printf(" Vertice: %i ", atual->vertice);
            atual = atual->prox;
        }
        printf("\n");
    }
}



void BFS::inicializaFila()
{
    fila.inicio = nullptr;
    fila.fim = nullptr;
}

bool BFS::filaVazia()
{
    if (!fila.inicio) return true;
    return false;
}

void BFS::insereFila(int valor)
{
    NoFila* novo = new NoFila;
    novo->prox = nullptr;
    novo->valor = valor;
    if (fila.inicio == nullptr) {
        fila.inicio = novo;
        fila.fim = novo;
    } else {
        fila.fim->prox = novo;
        fila.fim = novo;
    }
}

NoFila*BFS::excluirFila()
{
    NoFila* excluido = fila.inicio;
    fila.inicio = fila.inicio->prox;

    if (!fila.inicio) fila.fim = nullptr;

    return excluido;
}


void BFS::breadthFirstSearch(int raiz)
{

    visitados = new bool[numVertices];  
    for (int i = 0; i < numVertices; i++)  
        visitados[i] = false;

    inicializaFila();
    insereFila(raiz);
    visitados[raiz] = true;

    while (!filaVazia())
    {
        NoFila* excluido = excluirFila();
        int atual = excluido->valor;
        delete excluido;

        Elemento* end = ListaAdj[atual];
        printf("Visitando vertice: %d\n", atual);

        while (end)
        {
            int x = end->vertice;
            if (!visitados[x]) {
                insereFila(x);
                visitados[x] = true;
            }
            end = end->prox;
        }
        
    }

}