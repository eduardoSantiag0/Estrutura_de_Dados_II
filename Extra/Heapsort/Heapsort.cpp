#include "Heapsort.hpp"
#include <iostream>


//// Inserção
//// Remoção
//todo Heapify -> Transforma uma lista em um heap
//todo Build Heap -> Gerar um Heap utilizando Heapify
//// Imprimir
//?? Ordenar heap após inserção e remoção 

Heapsort::Heapsort() 
{
}

void Heapsort::heap_sort()
{
    build_heap(); // Constrói o heap
    int ultimoIndex = paraSerOrdenado.size() - 1;

// Once the heap is created, take the root and wap it will the last element of the heap
    while (ultimoIndex > 0) {
// Call max heapify of index 0 i.e, the new root of the heap
        std::swap(paraSerOrdenado[0], paraSerOrdenado[ultimoIndex]); // Troca a raiz com o último elemento
        shift_down(0, ultimoIndex); // Ajusta o heap excluindo o último elemento
// Reduce the size of the heap
        --ultimoIndex;
    }

}

// First, call build max heap to set the heap initially
void Heapsort::build_heap()
{
    int ultimoIndexPai = (paraSerOrdenado.size() / 2) - 1; // Índice do último nó pai. 
    for (int i = ultimoIndexPai; i >= 0; --i) {
        shift_down(i, paraSerOrdenado.size()); 
    }
}



void Heapsort::shift_down(int indexPai, int tamanhoHeap) 
{
    int maiorIndex = indexPai;
    int esquerdo = 2 * indexPai + 1; // Índice do filho esquerdo
    int direito = 2 * indexPai + 2; // Índice do filho direito

    // Verifica se o filho esquerdo é maior que o pai
    if (esquerdo < tamanhoHeap && paraSerOrdenado[esquerdo] > paraSerOrdenado[maiorIndex]) {
        maiorIndex = esquerdo;
    }

    // Verifica se o filho direito é maior que o maior até agora
    if (direito < tamanhoHeap && paraSerOrdenado[direito] > paraSerOrdenado[maiorIndex]) {
        maiorIndex = direito;
    }

    // Se o maior não for o nó atual, troca e ajusta o heap
    if (maiorIndex != indexPai) {
        std::swap(paraSerOrdenado[indexPai], paraSerOrdenado[maiorIndex]);
        shift_down(maiorIndex, tamanhoHeap); // Ajusta a subárvore
    }
}

void Heapsort::insere(int novo)
{
    paraSerOrdenado.emplace_back(novo);
}

int Heapsort::remove()
{
    int rem = paraSerOrdenado.front();
    paraSerOrdenado.pop_back();
    return rem;
}

void Heapsort::imprime() const
{
    for (const auto& i : paraSerOrdenado) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}