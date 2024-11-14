#ifndef BFS_HPP
#define BFS_HPP


struct Elemento
{
  int vertice;
  Elemento* prox;

  Elemento(int v, Elemento* n) 
  { 
    vertice = v;
    prox = n;
  }

};

struct NoFila
{
  int valor;
  NoFila* prox;
};

struct Fila
{
  int vertice;
  NoFila* inicio;
  NoFila* fim;
};


class BFS
{
private:
    int numVertices;
    int numArestas;

    Elemento** ListaAdj;
    bool* visitados;

    void BFSAux(int vertice);

    Fila fila;

public:
    BFS(int vertices);
    ~BFS(); 

    int getNumVertices();
    int getNumArestas();

    void imprimir();
    bool adicionarAresta (int origem, int destino);
    bool removerAresta (int origem, int destino);


    void inicializaFila();
    bool filaVazia();
    void insereFila(int valor);
    NoFila* excluirFila();
    void breadthFirstSearch (int raiz);
    
};

#endif