#ifndef FILA_PRIORIDADE_H
#define FILA_PRIORIDADE_H

#include <queue>
#include <iostream>

class FilaPrioridade 
{
private:
    int* fila; // Array para armazenar os elementos da fila.
    int tamanho;
    int numElementos;

public: 

    FilaPrioridade(int numeroElementos);
    ~FilaPrioridade();

    bool insercaoPrioridade(int num);

    int exclusaoMenorPrioridade();
    int exclusaoElementoArbitrario(int num);

    bool diminuirPrioridade(int num, int novaPrioridade);

    int retornoMenorPrioridade() const;

    bool filaEstaVazia() const;

    void imprimir() const;

};

#endif