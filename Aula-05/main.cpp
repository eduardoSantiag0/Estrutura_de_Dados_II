#include "FilaPrioridade.hpp"
#include <iostream>


int main (void)
{
    FilaPrioridade fila (5);

    std::cout << "Inserindo elementos: 10, 20, 15, 5, 30" << std::endl;
    fila.insercaoPrioridade(10);
    fila.insercaoPrioridade(20);
    fila.insercaoPrioridade(15);
    fila.insercaoPrioridade(5);
    fila.insercaoPrioridade(30);

    fila.imprimir();

    std::cout << "Menor elemento na fila: " << fila.retornoMenorPrioridade() << std::endl;

    std::cout << "Removendo o menor elemento: " << fila.exclusaoMenorPrioridade() << std::endl;

    std::cout << "Menor elemento na fila: " << fila.retornoMenorPrioridade() << std::endl;
    fila.imprimir();

    std::cout << "Removendo elemento 15: ";
    int removido = fila.exclusaoElementoArbitrario(15);
    if (removido != -1) {
        std::cout << "Elemento removido: " << removido << std::endl;
    } else {
        std::cout << "Elemento não encontrado!" << std::endl;
    }

    fila.imprimir();

    std::cout << "Diminuindo prioridade do elemento 20 para 8: ";
    if (fila.diminuirPrioridade(20, 8)) {
        std::cout << "Prioridade diminuída com sucesso." << std::endl;
    } else {
        std::cout << "Falha ao diminuir prioridade (elemento não encontrado)." << std::endl;
    }

    fila.imprimir();
}