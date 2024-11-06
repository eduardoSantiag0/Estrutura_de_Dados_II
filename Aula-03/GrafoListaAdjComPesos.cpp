#include "GrafoListaAdjComPesos.hpp"

GrafoLista::GrafoLista(int inputVertices)
{
    if (inputVertices < 0) return;

    numVertices = inputVertices;
    numArestas = 0;

    Lista = new Node*[numVertices];
    for (int i = 0; i < numVertices ; i++) {
        Lista[i] = nullptr;
    }

}

GrafoLista::~GrafoLista()
{
    for (int i = 0; i < numVertices; i++) {
        Node* atual = Lista[i];
        while (atual)
        {
            Node* temp = atual;
            atual = atual->prox;
            delete temp;
        }
        
        delete Lista[i];
    }

    numVertices = 0;
    numArestas = 0;
    delete[] Lista;
}

void GrafoLista::imprimirGrafo()
{
    std::cout << "IMPRIMINDO GRAFO" << std::endl;

    Node* walk;
    for (int i = 0 ; i < this->numVertices ; i++) {
        walk = Lista[i];
        while (walk)
        {
            printf (" --> %d com peso: %d", walk->vertice, walk->peso);
            walk = walk->prox;
        }
        printf("\n");
    }
}

bool GrafoLista::inserirAresta (int v1, int v2, int inputPeso)
{
    //* Verificação
    if (v1 < 0 || v2 < 0 || inputPeso < 0 || v1 >= this->numVertices || v2 >= this->numVertices ) return false;

    Node* novo = nullptr; 
    Node* ant = nullptr;

    Node* walk = Lista[v1];

    //* Procurando no vetor
    while (walk && walk->vertice < v2)
    {
        ant = walk;
        walk = walk->prox;
    }

    //* Caso já exista
    if (walk && walk->vertice == v2) {
        walk->peso = inputPeso;
        return true;
    }

    //* Atualizando o novo elemento
    novo = new Node;

    novo->vertice = v2;
    novo->peso = inputPeso;
    novo->prox = walk;

    //* Caso NÃO seja o primeiro
    if (ant) ant->prox = novo;
    //* Caso seja o primeiro
    else Lista[v1] = novo;

    this->numArestas++;
    return true;
}

bool GrafoLista::removerAresta (int v1, int v2)
{
    if (v1 < 0 || v2 < 0 || v1 >= this->numVertices || v2 >= this->numVertices ) return false;

    Node* walk = Lista[v1];
    Node* ant = nullptr;
    while (walk && walk->vertice != v2)
    {
        ant = walk;
        walk = walk->prox;
    }

    if (walk && walk->vertice == v2) {
        if (ant) ant->prox = walk->prox;
        else Lista[v1] = walk->prox;

        delete walk;
        numArestas--;
        
        return true;
    }

    return false;
    

}


bool GrafoLista::verificarSeArestaExiste(int v1, int v2)
{
    if (v1 < 0 || v2 < 0 || v1 >= this->numVertices || v2 >= this->numVertices ) return false;

    Node* atual = Lista[v1];
    while (atual)
    {
        if (atual->vertice == v2) 
            return true;
        atual = atual->prox;
    }
    
    return false;
}

bool GrafoLista::verificarVizinhosVertice(int v)
{
    if (v < 0 || v >= this->numVertices || 
    !(Lista[v])) return false;

    return true;
}

int GrafoLista::verificarGrauVertice(int v)
{

    int contador = 0;

    Node* atual = nullptr;

    // Olhar todos 
    for (int i = 0; i < numVertices; i++) {
        atual = Lista[i];
        while (atual)
        {
            if (atual->vertice == v) contador++;
            if (i == v) contador++;
            atual = atual->prox;
        }
    }

    return contador;

}


int GrafoLista::getNumerosVertices()
{
    return numVertices;
}
