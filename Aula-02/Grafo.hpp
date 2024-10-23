#ifndef GRAFO_HPP
#define GRAFO_HPP


class Grafo 
{
private:
    int numVertices;
    int numArestas;
    bool** matriz;
public: 

    void iniciarGrafo();
    void imprimirGrafo();
    void liberarMemoria();
    void inserirAresta();
    void removerAresta();
    bool verificarSeArestaExiste();
    int numeroArestas();
    int numeroVertices();
    bool verificarVizinhosVertice();
    int verificarGrauVertice();


};

#endif