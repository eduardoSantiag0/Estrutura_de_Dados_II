#include "Heapsort.hpp"

int main (void)
{

    Heapsort pq = Heapsort();
    pq.insere(10);
    pq.insere(20);
    pq.insere(5);
    pq.insere(30);
    pq.insere(16);

    pq.imprime();

    pq.heap_sort();
    pq.imprime();

}