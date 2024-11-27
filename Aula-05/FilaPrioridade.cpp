#include "FilaPrioridade.hpp"

// Fila com valores decrescentes

FilaPrioridade::FilaPrioridade(int num) : tamanho(num), numElementos(0)
{
    fila = new int[tamanho];
}

FilaPrioridade::~FilaPrioridade()
{
    delete[] fila;
    numElementos = 0;
}

bool FilaPrioridade::insercaoPrioridade(int num)
{
    if (numElementos >= tamanho) 
        return false; 
    
    if (numElementos == 0) {
        fila[0] = num;
        numElementos++;
        return true;
    }

    int index;
    for (index = numElementos - 1; index >= 0 && fila[index] < num; index--) {
            // std::cout << "GIGANTE Index: " << index << std::endl;
            fila[index+1] = fila[index]; // Copia o da direita para o da esquerda

    }
    // std::cout << "FINAL Index: " << index << " -> com Valor: "<< num << std::endl;
    std::cout << std::endl;

    // fila[index] = num;
    fila[index+1] = num;
    numElementos++;
    return true;

}

int FilaPrioridade::exclusaoElementoArbitrario(int num)
{

    int index = -1;

    for (int i = 0; i < numElementos; i++) {
        if (num == fila[i]) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        return -1;
    }

    int out = fila[index];

    for (int i = index; i < numElementos; i++) {
        fila[i] = fila[i+1];
    }


    numElementos--;
    return out;

}

int FilaPrioridade::exclusaoMenorPrioridade() 
{
    int out = fila[numElementos - 1];
    numElementos--;
    return out;
}

bool FilaPrioridade::diminuirPrioridade(int num, int novaPrioridade) 
{
    int index = -1;

    for (int i = 0; i < numElementos; i++) {
        if (num == fila[i]) {
            index = i;
            break;
        }
    }

    if (index == -1) 
        return false;


    exclusaoElementoArbitrario(num);
    insercaoPrioridade(novaPrioridade);
    return true;

}

int FilaPrioridade::retornoMenorPrioridade() const
{
    return fila[numElementos - 1];
}

bool FilaPrioridade::filaEstaVazia() const
{
    return numElementos == 0;
}

void FilaPrioridade::imprimir() const
{
    std::cout << "Imprimindo: \n";
    for (int i = 0; i < numElementos; i++) {
        std::cout << "Index: " << i << " - Valor: " << fila[i] << std::endl;
    }

    std::cout << std::endl;

}