#ifndef HEAPSORT
#define HEAPSORT

#include <vector>


//! Min-Heap: Chave de cada nó seja maior ou igual à chave do seu pai

// #define Node* PONT

// typedef struct aux
// {
//     PONT esq, dir;
//     int chave;
//     aux(int chave) : chave(chave), esq(nullptr), dir(nullptr) {};

// } Node;


class Heapsort 
{
private:
    std::vector<int> paraSerOrdenado;
    void shift_down(int indexPai, int tamanhoHeap);
    void build_heap();
    
public:

    Heapsort();
    void heap_sort();

    void insere(int novo);
    int remove();
    void imprime() const;
};

#endif