#include "Grafo.hpp"

int main (void)
{
    Grafo g = Grafo(2);

    g.inserirAresta(0, 0);
    g.inserirAresta(1, 1);
    g.imprimirGrafo();

    g.removerAresta(0,0);
    g.imprimirGrafo();

    return 0;
}