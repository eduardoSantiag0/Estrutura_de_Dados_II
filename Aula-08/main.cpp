/*********************************************************/
/* Este programa faz o gerenciamento basico de arquivos  */
/* com registros de tamanho fixo.                        */
/* Neste caso, os registros tem o tamanho da estrutura   */
/* PROF (professor) e dados binarios sao usados (para    */
/* armazenar os numeros)                                 */
/*********************************************************/


#include <iostream>
#include <iomanip>      // std::setw

#include <fstream>
#include <cstring>
#include <cstdlib>

#define T_nome 30
#define T_email 25

//* Seu programa deve permitir 
//todo inserir
//todo excluir
//todo consultar/buscar docentes
//* com base no número USP.

struct PROF {
    int nusp;
    char nome[T_nome];
    int anoDeIngresso;
    char email[T_email];
    bool lapide;
};

PROF novoProfessor(int nusp, const char* nome, int ano, const char* email, bool lapide) {
    PROF novo;
    novo.nusp = nusp;
    novo.anoDeIngresso = ano;
    
    std::strncpy(novo.nome, nome, T_nome - 1);
    novo.nome[T_nome - 1] = '\0'; // Garante o terminador nulo

    std::strncpy(novo.email, email, T_email - 1);
    novo.email[T_email - 1] = '\0'; // Garante o terminador nulo

    novo.lapide = lapide;

    return novo;
}

void imprimirProfessor(const PROF& prof) {
    std::cout << std::right << std::setw(10) << prof.nusp
              << " " << std::setw(T_nome) << prof.nome
              << " " << std::setw(4) << prof.anoDeIngresso
              << " " << std::setw(T_email) << prof.email << std::endl;
}

void salvarEmArquivo(const char* nomeDoArquivo, const PROF& prof) {
    std::ofstream arquivo(nomeDoArquivo, std::ios::binary);
    if (!arquivo) {
        std::cerr << "Nao foi possivel abrir o arquivo de saida: '" << nomeDoArquivo << "'\n";
        std::exit(1);
    }
    arquivo.write(reinterpret_cast<const char*>(&prof), sizeof(PROF));
    arquivo.close();
}

void adicionarEmArquivo(const char* nomeDoArquivo, const PROF& prof) {
    std::ofstream arquivo(nomeDoArquivo, std::ios::binary | std::ios::app);
    if (!arquivo) {
        std::cerr << "Nao foi possivel abrir o arquivo de saida: '" << nomeDoArquivo << "'\n";
        std::exit(1);
    }
    arquivo.write(reinterpret_cast<const char*>(&prof), sizeof(PROF));
    arquivo.close();
}

void lerArquivo(const char* nomeDoArquivo) {
    std::ifstream arquivo(nomeDoArquivo, std::ios::binary);
    if (!arquivo) {
        std::cerr << "Nao foi possivel abrir o arquivo de entrada: '" << nomeDoArquivo << "'\n";
        std::exit(1);
    }

    std::cout << "\nExibindo conteudo do arquivo: '" << nomeDoArquivo << "'\n";

    PROF buffer;
    while (arquivo.read(reinterpret_cast<char*>(&buffer), sizeof(PROF))) {
        if (buffer.lapide != 1)
            imprimirProfessor(buffer);
    }
    
    arquivo.close();
}

int main() {
    PROF digi = novoProfessor(3140792, "Luciano Antonio Digiampietri", 2008, "digiampietri@usp.br", 0);
    // imprimirProfessor(digi);
    salvarEmArquivo("TamanhoFixo.bin", digi);
    // lerArquivo("TamanhoFixo.bin");

    std::cout << "\nCriando novos professores.\n";

    PROF norton = novoProfessor(12345678, "Norton Trevisan Roman", 2010, "norton@usp.br", 1);
    // imprimirProfessor(norton);
    adicionarEmArquivo("TamanhoFixo.bin", norton);

    PROF daniel = novoProfessor(7654321, "Daniel de Angelis Cordeiro", 2015, "daniel.cordeiro@usp.br", 0);
    // imprimirProfessor(daniel);
    adicionarEmArquivo("TamanhoFixo.bin", daniel);

    lerArquivo("TamanhoFixo.bin");

    return 0;
}

