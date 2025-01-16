/*********************************************************************/
/**   ACH2024 - Algoritmos e Estruturas de Dados II                 **/
/**   EACH-USP - Primeiro Semestre de 2024                          **/
/**   Turma 04 - Prof. Luciano Digiampietri                         **/
/**                                                                 **/
/**   Primeiro Exercicio-Programa                                   **/
/**                                                                 **/
/**                                                                 **/
/*********************************************************************/

#include <iostream>
#include <vector>
#include <cstdlib>
#include <cmath>

// #define true 1
// #define false 0
// typedef int boolean;

/* Estrutura para representar nosso grafo usando matriz binária de adjacências */
struct Grafo {
    int numVertices;
    int numArestas;
    std::vector<std::vector<bool>> matriz;
};

/* Função auxiliar para o sistema de correção automática (não mexer) */
void printf123() {
    // Função usada pelo sistema de correção automática (não mexer)
}

/* Função que inicializa o grafo */
bool inicializaGrafo(Grafo& g, int vertices) {
    if (vertices < 1) return false;
    g.numVertices = vertices;
    g.numArestas = 0;
    g.matriz.resize(vertices, std::vector<bool>(vertices, false));
    return true;
}

/* Função que libera a memória da matriz de adjacência */
bool liberaGrafo(Grafo& g) {
    g.matriz.clear();
    g.numVertices = 0;
    g.numArestas = 0;
    return true;
}

/* Função que retorna o número de vértices */
int numeroDeVertices(const Grafo& g) {
    return g.numVertices;
}

/* Função que retorna o número de arestas */
int numeroDeArestas(const Grafo& g) {
    return g.numArestas;
}

/* Função que retorna o grau do vértice */
int retornaGrauDoVertice(const Grafo& g, int v) {
    if (v < 0 || v >= g.numVertices) return -1;
    int grau = 0;
    for (bool adj : g.matriz[v]) {
        if (adj) grau++;
    }
    return grau;
}

/* Função que verifica se o vértice possui vizinhos */
bool possuiVizinhos(const Grafo& g, int v) {
    if (v < 0 || v >= g.numVertices) return false;
    for (bool adj : g.matriz[v]) {
        if (adj) return true;
    }
    return false;
}

/* Função que insere uma nova aresta */
bool insereAresta(Grafo& g, int v1, int v2) {
    if (v1 < 0 || v2 < 0 || v1 >= g.numVertices || v2 >= g.numVertices || v1 == v2) return false;
    if (!g.matriz[v1][v2]) {
        g.matriz[v1][v2] = true;
        g.matriz[v2][v1] = true;
        g.numArestas++;
    }
    return true;
}

/* Função que remove uma aresta */
bool removeAresta(Grafo& g, int v1, int v2) {
    if (v1 < 0 || v2 < 0 || v1 >= g.numVertices || v2 >= g.numVertices || !g.matriz[v1][v2]) return false;
    g.matriz[v1][v2] = false;
    g.matriz[v2][v1] = false;
    g.numArestas--;
    return true;
}

/* Função que verifica se a aresta existe */
bool arestaExiste(const Grafo& g, int v1, int v2) {
    return (v1 >= 0 && v2 >= 0 && v1 < g.numVertices && v2 < g.numVertices && g.matriz[v1][v2]);
}

/* Função que cria um grafo aleatório */
Grafo criaGrafoAleatorio(int numVertices, int numArestas) {
    std::cout << "################# Criando grafo com " << numVertices << " vértice(s) e com " << numArestas << " aresta(s). #################\n";
    if (numVertices < 1 || numArestas >= numVertices * (numVertices - 1) / 2) {
        std::cout << "Parâmetros inválidos, o grafo não será gerado.\n";
        return Grafo();
    }
    Grafo g;
    inicializaGrafo(g, numVertices);
    int a = 0;
    while (a < numArestas) {
        int x = rand() % numVertices;
        int y = rand() % numVertices;
        if (x != y && !g.matriz[x][y]) {
            g.matriz[x][y] = true;
            g.matriz[y][x] = true;
            a++;
        }
    }
    g.numArestas = numArestas;
    return g;
}

/* Função que exibe o grafo */
void exibeGrafo(const Grafo& g) {
    std::cout << "\nImprimindo grafo (vértices: " << g.numVertices << "; arestas: " << g.numArestas << ").\n   ";
    for (int x = 0; x < g.numVertices; x++) std::cout << " " << x;
    std::cout << "\n";
    for (int x = 0; x < g.numVertices; x++) {
        std::cout << x;
        for (int y = 0; y < g.numVertices; y++) {
            std::cout << " " << g.matriz[x][y];
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}

/* Funcao que exibe os valores de um arranjo de numeros reais */
void exibeArranjoReais(float* arranjo, int n){
  int x;
  for (x=0; x<n; x++) printf("  v%i\t", x);
  printf("\n");
  for (x=0; x<n; x++){
    printf("%3.2f\t",arranjo[x]);
  }
  printf("\n\n");
}


/* Funcao que exibe os valores de um arranjo de numeros inteiros */
void exibeArranjoInteiros(int* arranjo, int n){
  int x;
  for (x=0; x<n; x++) printf(" v%i\t", x);
  printf("\n");
  for (x=0; x<n; x++){
    printf("%3i\t",arranjo[x]);
  }
  printf("\n\n");
}


//todo FUNÇÕES QUE DEVEM SER COMPLETADAS PARA RESOLVER O EP 

// ENTRADA: Recebe dois vertices
// SAIDA: Retorna os vertices que ambos tem como vizinho
void auxRetornaVizinhosEmComum (const Grafo& g, int v, int y, std::vector<int>& vizinhos) {

    int posicaoVizinho = 0;

    for (int i = 0; i < g.numVertices; i++) {

        if (g.matriz[v][i] == 1 && g.matriz[y][i] == 1) {
            vizinhos.push_back(i);
        }

    }
}

// Calcular o número de vizinhos com cada Nó do grafo
// Ele tem os mesmo número de vizinhos que ele mesmo (vizinhos[v])
void vizinhosEmComum(const Grafo& g, int v, int* vizinhos) {
    
    // Passar por todos os vertices
    for (int i = 0; i < g.numVertices; i++) {
        
        int contador = 0;

        // Passa pelos Adj dos Vizinhos
        for (int x = 0; x < g.numVertices; x++) {
            if (g.matriz[v][x] == 1 && g.matriz[i][x] == 1)
                contador++;
        }

        vizinhos[i] = contador;

    }
}

void coeficienteDeJaccard(const Grafo& g, int v, float* coeficientes) {

    // O numerador é o número de coisas que os dois conjuntos têm em comum.
    // O denominador é o número total de coisas que aparecem em pelo menos um dos conjuntos 
    // (a união dos dois conjuntos).

    // Passar por todos os vertices
    for (int i = 0; i < g.numVertices; i++) {
        
        if (i == v) {
            coeficientes[i] = 1.0; 
            continue;
        }
        
        float emComum = 0;
        float total = 0;

        // Passa pelos Adj dos Vizinhos
        for (int x = 0; x < g.numVertices; x++) {
            if (g.matriz[v][x] || g.matriz[i][x]) {
                total++;
                if (g.matriz[v][x] && g.matriz[i][x]) {
                    emComum++;
                }
            }
        }
        coeficientes[i] =  emComum / total;
    }
}

// Semelhança entre dois vértices em um grafo, baseada nos vizinhos que eles têm em comum. 
void AdamicAdar(const Grafo& g, int v, float* coeficientes) {

    // Vizinhos de V
    // Vizinhos de Y
    // Quantos esses vizinhos tem em comum
    // Dá mais peso para vizinhos menos conectados 

    //* Iterar pelos vértices 
    for (int y = 0 ; y < g.numVertices; y++) {

        float somaPesos = 0.0;

        //* Verifique os vizinhos que v e y compartilham. (Z -> vizinhos de V e Y)
        for (int z = 0; z < g.numVertices; z++) {
            
            //* Verifica os vizinhos que v e y compartilham 
            if (g.matriz[v][z] == 1 && g.matriz[y][z] == 1) {
                //* Número de vizinhos de Z (Atalho)
                int grauDez = 0;
                for (int k = 0; k < g.numVertices; k++) {
                    if (g.matriz[z][k] == 1) {
                        grauDez++;
                    }
                }

                if (grauDez > 1) {
                    somaPesos += 1.0 / std::log(grauDez);
                }
            }
        }

        coeficientes[y] = somaPesos;

    }

}

void alocacaoDeRecursos(const Grafo& g, int v, float* coeficientes) {

    //* Itera sobre todos os vértices do grafo
    for (int y = 0; y < g.numVertices; y++) {

        float somaPesos = 0.0;

        //* Verifica os vizinhos que v e y compartilham
        for (int z = 0; z < g.numVertices; z++) {
            //* Verifica se z é vizinho tanto de v quanto de y
            if (g.matriz[v][z] == 1 && g.matriz[y][z] == 1) {
                //* Calcula o número de vizinhos de z
                int grauDeZ = 0;
                for (int k = 0; k < g.numVertices; k++) {
                    if (g.matriz[z][k] == 1) {
                        grauDeZ++;
                    }
                }

                //* Adiciona a contribuição de z ao somatório
                if (grauDeZ > 0) { 
                    somaPesos += 1.0 / grauDeZ;
                }
            }
        }

        // Armazena o coeficiente calculado para o par (v, y)
        coeficientes[y] = somaPesos;
    }
}


/** Similaridade Cosseno: SA v,y
 * |Γ(V) ∩ Γ(y)| -> Número de Intersecção entre os vizinhos de V e de y
 * |Γ(V)| -> Número de vizinhos de V
 * Conjunto da intersecção entre V e Y 
 * dividido pela raiz do número de (Vizinhos de V * Vizihnos de Y)
*/
void similaridadeCosseno(const Grafo& g, int v, float* coeficientes) {

    int numeroVizinhosDeV = retornaGrauDoVertice(g, v);

    for (int y = 0; y < g.numVertices; y++) {

        float out = 0.0;
        
        std::vector<int> vetorTemp;
        auxRetornaVizinhosEmComum(g, v, y, vetorTemp);

        int numeroVizinhosDeY = retornaGrauDoVertice(g, y);

        float denominador = sqrt(numeroVizinhosDeV * numeroVizinhosDeV);

        if (denominador == 0) 
            denominador = -1.0;

        out = vetorTemp.size() / denominador;

        coeficientes[y] = out;
        
    }
}


void coeficienteDeDice(const Grafo& g, int v, float* coeficientes) {
    /* Complete o código desta função */
}

void HPI(Grafo& g, int v, float* coeficientes) {
/* Complete o codigo desta funcao */

}


/* Hub Depressed Index */
void HDI(Grafo& g, int v, float* coeficientes){

/* Complete o codigo desta funcao */

}


/* Funcao main para testar as funcoes implementadas neste EP.
   Esta parte do codigo nao sera usada na correcao do EP 
   e nao contempla todos os testes possiveis.
   Fique a vontade para realizar testes adicionais.
*/
int main() {

  int n = 5;
  int* vComum = (int*)malloc(sizeof(int)*n);
  float* coeficientes = (float*)malloc(sizeof(float)*n);
  
  Grafo g1;

  printf("PRIMEIRO EXEMPLO\n");

  inicializaGrafo(g1, n);
  insereAresta(g1,0,1);
  insereAresta(g1,0,2);
  insereAresta(g1,1,4);
  insereAresta(g1,1,3);
  insereAresta(g1,2,3);

  exibeGrafo(g1);

  std::vector<int> auxVizinho; 
  auxRetornaVizinhosEmComum(g1, 0, 4, auxVizinho);

//   for (int item : auxVizinho) {
//     std::cout << item << " - "; 
//   }
//   std::cout << std::endl;

  printf("Vizinhos em Comum de v0:\n");
  vizinhosEmComum(g1, 0, vComum);
  exibeArranjoInteiros(vComum, n);

  printf("Coeficientes de Jaccard de v0:\n");
  coeficienteDeJaccard(g1, 0, coeficientes);
  exibeArranjoReais(coeficientes, n);

  printf("Medida de Adamic-Adar de v0:\n");
  AdamicAdar(g1, 0, coeficientes);
  exibeArranjoReais(coeficientes, n);

  printf("Medida de Alocacao de Recursos de v0:\n");
  alocacaoDeRecursos(g1, 0, coeficientes);
  exibeArranjoReais(coeficientes, n);

  printf("Similaridade Cosseno de v0:\n");
  similaridadeCosseno(g1, 0, coeficientes);
  exibeArranjoReais(coeficientes, n);

//   coeficienteDeDice(g1, 0, coeficientes);
//   printf("Coeficiente de Dice de v0:\n");
//   exibeArranjoReais(coeficientes, n);

//   HPI(g1, 0, coeficientes);
//   printf("Indice HPI de v0:\n");
//   exibeArranjoReais(coeficientes, n);

//   HDI(g1, 0, coeficientes);
//   printf("Indice HDI de v0:\n");
//   exibeArranjoReais(coeficientes, n);

  printf("\n\nSEGUNDO EXEMPLO\n");

  // Excluindo duas arestas do grafo
  removeAresta(g1,0,2);
  removeAresta(g1,2,3);


  exibeGrafo(g1);

  printf("Vizinhos em Comum de v0:\n");
  vizinhosEmComum(g1, 0, vComum);
  exibeArranjoInteiros(vComum, n);

  printf("Coeficientes de Jaccard de v0:\n");
  coeficienteDeJaccard(g1, 0, coeficientes);
  exibeArranjoReais(coeficientes, n);

  printf("Medida de Adamic-Adar de v0:\n");
  AdamicAdar(g1, 0, coeficientes);
  exibeArranjoReais(coeficientes, n);

  printf("Medida de Alocacao de Recursos de v0:\n");
  alocacaoDeRecursos(g1, 0, coeficientes);
  exibeArranjoReais(coeficientes, n);

  printf("Similaridade Cosseno de v0:\n");
  similaridadeCosseno(g1, 0, coeficientes);
  exibeArranjoReais(coeficientes, n);

//   coeficienteDeDice(g1, 0, coeficientes);
//   printf("Coeficiente de Dice de v0:\n");
//   exibeArranjoReais(coeficientes, n);

//   HPI(g1, 0, coeficientes);
//   printf("Indice HPI de v0:\n");
//   exibeArranjoReais(coeficientes, n);

//   HDI(g1, 0, coeficientes);
//   printf("Indice HDI de v0:\n");
//   exibeArranjoReais(coeficientes, n);


  /* Grafo gerado aleatoriamente - pode ficar diferente
     de acordo com o compilador usado.                 */
  printf("\nTERCEIRO EXEMPLO\n");
  n = 6;
  int arestas = 8;
  
  free(vComum);
  free(coeficientes);
  vComum = (int*)malloc(sizeof(int)*n);
  coeficientes = (float*)malloc(sizeof(float)*n);
  
  Grafo g2 = criaGrafoAleatorio(n,arestas);
  exibeGrafo(g2);
  
  printf("Vizinhos em Comum de v0:\n");
  vizinhosEmComum(g2, 0, vComum);
  exibeArranjoInteiros(vComum, n);

  printf("Vizinhos em Comum de v1:\n");
  vizinhosEmComum(g2, 1, vComum);
  exibeArranjoInteiros(vComum, n);

  printf("Vizinhos em Comum de v5:\n");
  vizinhosEmComum(g2, 5, vComum);
  exibeArranjoInteiros(vComum, n);


  printf("Coeficientes de Jaccard de v0:\n");
  coeficienteDeJaccard(g2, 0, coeficientes);
  exibeArranjoReais(coeficientes, n);

  printf("Coeficientes de Jaccard de v1:\n");
  coeficienteDeJaccard(g2, 1, coeficientes);
  exibeArranjoReais(coeficientes, n);

  printf("Coeficientes de Jaccard de v5:\n");
  coeficienteDeJaccard(g2, 5, coeficientes);
  exibeArranjoReais(coeficientes, n);


  printf("Medida de Adamic-Adar de v0:\n");
  AdamicAdar(g2, 0, coeficientes);
  exibeArranjoReais(coeficientes, n);

  printf("Medida de Adamic-Adar de v1:\n");
  AdamicAdar(g2, 1, coeficientes);
  exibeArranjoReais(coeficientes, n);

  printf("Medida de Adamic-Adar de v5:\n");
  AdamicAdar(g2, 5, coeficientes);
  exibeArranjoReais(coeficientes, n);


  printf("Medida de Alocacao de Recursos de v0:\n");
  alocacaoDeRecursos(g2, 0, coeficientes);
  exibeArranjoReais(coeficientes, n);

  printf("Medida de Alocacao de Recursos de v1:\n");
  alocacaoDeRecursos(g2, 1, coeficientes);
  exibeArranjoReais(coeficientes, n);

  printf("Medida de Alocacao de Recursos de v5:\n");
  alocacaoDeRecursos(g2, 5, coeficientes);
  exibeArranjoReais(coeficientes, n);


  printf("Similaridade Cosseno de v0:\n");
  similaridadeCosseno(g2, 0, coeficientes);
  exibeArranjoReais(coeficientes, n);

  printf("Similaridade Cosseno de v1:\n");
  similaridadeCosseno(g2, 1, coeficientes);
  exibeArranjoReais(coeficientes, n);

  printf("Similaridade Cosseno de v5:\n");
  similaridadeCosseno(g2, 5, coeficientes);
  exibeArranjoReais(coeficientes, n);


//   coeficienteDeDice(g2, 0, coeficientes);
//   printf("Coeficiente de Dice de v0:\n");
//   exibeArranjoReais(coeficientes, n);

//   printf("Coeficiente de Dice de v1:\n");
//   coeficienteDeDice(g2, 1, coeficientes);
//   exibeArranjoReais(coeficientes, n);

//   printf("Coeficiente de Dice de v5:\n");
//   coeficienteDeDice(g2, 5, coeficientes);
//   exibeArranjoReais(coeficientes, n);


//   HPI(g2, 0, coeficientes);
//   printf("Indice HPI de v0:\n");
//   exibeArranjoReais(coeficientes, n);

//   printf("Indice HPI de v1:\n");
//   HPI(g2, 1, coeficientes);
//   exibeArranjoReais(coeficientes, n);

//   printf("Indice HPI de v5:\n");
//   HPI(g2, 5, coeficientes);
//   exibeArranjoReais(coeficientes, n);
  
  
//   HDI(g2, 0, coeficientes);
//   printf("Indice HDI de v0:\n");
//   exibeArranjoReais(coeficientes, n);

//   printf("Indice HDI de v1:\n");
//   HDI(g2, 1, coeficientes);
//   exibeArranjoReais(coeficientes, n);

//   printf("Indice HDI de v5:\n");
//   HDI(g2, 5, coeficientes);
//   exibeArranjoReais(coeficientes, n);

  return 0;  
}
