#include "DFS.hpp"


DFS::DFS(int vertices) 
{
    numVertices = vertices;
    numArestas = 0;

    ListaAdj = new Node*[numVertices];
    for (int i = 0; i < numVertices; i++) {
        ListaAdj[i] = nullptr;
    }
}


DFS::~DFS()
{

    for (int i = 0; i < numVertices; i++) {
        Node* atual = ListaAdj[i];
        while (atual)
        {
            Node* temp = atual;
            atual = atual->prox;
            delete temp;
        }
        
        delete ListaAdj[i];
    }

    numVertices = 0;
    numArestas = 0; 
    delete[] ListaAdj;

}

int DFS::getNumArestas() 
{
    return numArestas;
}

int DFS::getNumVertices()
{
    return numVertices;
}

void DFS::imprimir()
{
    for (int i = 0; i < numArestas; i++) {
        Node* walk = ListaAdj[i];
        while (walk)
        {
            printf("Vertice: %i --> Valor: %.2f \n", walk->vertice, walk->peso);
            walk = walk->prox;
        }
        printf("\n");
    }


}

bool DFS::adicionarAresta(int origem, int destino, float peso)
{

    Node* walk = ListaAdj[origem];
    Node* ant = nullptr;
    while (walk)
    {
        ant = walk;
        walk = walk->prox;
    }

    Node* novo = new Node(destino, peso, walk);
    
    //* Caso NÃO seja o primeiro
    if (ant) ant->prox = novo;
    //* Caso seja o primeiro
    else ListaAdj[origem] = novo;
    numArestas++;

    return true;

}


bool DFS::removerVertice(int origem, int destino)
{
    Node* walk = ListaAdj[origem];
    Node* ant = nullptr;

    while (walk && walk->vertice != destino)
    {
        ant = walk;
        walk = walk->prox;
    }

    // Encontrado
    if (walk && walk->vertice == destino) {

        // Caso não seja o primeiro
        if (ant) ant->prox = walk->prox;
        // Caso seja o primeiro 
        else ListaAdj[origem] = walk->prox;

        delete walk;
        numArestas--;
        return true;
    }

    return false;

}

void DFS::DFSAux(int atual)
{
    Node* node = ListaAdj[atual];
    node->visitado = true;

    // std::cout << "Visitando Vertice: " << atual << std::endl;
    std::cout << "Visitando Vertice: " << node->vertice << std::endl;

    Node* prox = node;

    while (prox) {
        if (ListaAdj[prox->vertice] && !ListaAdj[prox->vertice]->visitado) {
            DFSAux(prox->vertice);
        }
        // std::cout << "Valores de Prox: " << prox->vertice << std::endl;
        prox = prox->prox;
    }
}

void DFS::depthFirstSearch()
{
    for (int i = 0; i < numVertices; i++) {
        Node* atual = ListaAdj[i];
        while (atual) {
            atual->visitado = false; 
            atual = atual->prox;
        }
    }

    for (int i = 0; i < numVertices; i++) {
        // if (!ListaAdj[i]->visitado) 
        if (ListaAdj[i] && !ListaAdj[i]->visitado) 
            DFSAux(i);
    }

    std::cout << "Fim da Busca em Profundidade :)" << std::endl;
}