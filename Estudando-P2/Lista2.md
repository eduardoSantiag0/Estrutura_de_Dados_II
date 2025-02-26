7, 8, 9, 10, 11, 12, 13

### **Grafos e Busca em Profundidade (DFS)**

### **1. Tipos de arestas em busca em profundidade**

**Questão 1:** Considere o seguinte grafo direcionado e a execução da busca em profundidade a partir do vértice 1:

    1 → 2 → 3
    ↓     ↘︎ ↓
    4 → 5 → 6

Seja o tempo de descoberta e finalização de cada vértice na DFS conforme abaixo:

- (1: d=1, f=12)
- (2: d=2, f=5)
- (3: d=6, f=9)
- (4: d=3, f=4)
- (5: d=7, f=8)
- (6: d=10, f=11)

Classifique cada aresta do grafo como **aresta de árvore, retorno, avanço ou cruzamento**.

    Resposta: Todos são de árvore, menos a aresta {2,6} é de avanço


### **2. Detecção de ciclos e impacto na ordenação topológica**

**Questão 2:** Seja um grafo direcionado **G = (V, E)**. Explique por que a presença de uma aresta de **retorno** impossibilita a realização de uma ordenação topológica.

    Resposta: Porque é criado um ciclo, impossibilitando a ordenação topológica.

**Questão 3:** Dado o seguinte grafo, identifique se ele possui ciclos e determine se é possível realizar uma ordenação topológica:

    A → B → C
    ↓    ↓
    D → E → F

(a) Execute a DFS e classifique as arestas.

    Resposta: A, B, C, E, F, D

(b) Caso haja um ciclo, identifique-o e justifique por que impede a ordenação topológica.

    Resposta: Não existe um ciclo

### **Hashing e Tratamento de Colisões**

### **3. Comparação entre Endereçamento Fechado e Aberto**

**Questão 4:** Explique as principais diferenças entre o **endereçamento fechado** (tabelas com listas encadeadas) e o **endereçamento aberto** (sondagem linear, quadrática e duplo hashing).

    Respostas: O endereçamento fechado, usa listas encadeadas quando o mesmo hash é dado para entradas diferentes. A colisão, nesse caso, é tratada por meio de uma lista ligada. Isso impacta diretamente na peformance da busca de um item, deixando de ser O(1) para 0(N) onde N é o tamanho da lista em um dado endereço. 
    
    Já o endereçamento aberto trata as colisões fazendo outro hashing (sondagem linear, quadrática e duplo hashing). A tabela busca a próxima posição disponível para armazenar o elemento.
    
    Em termos de espaço, fechado permite que a tabela mantenha o mesmo tamanho, enquanto o aberto mantém todos os elementos dentro da tabela, mas pode necessitarde redimensionamento. 

    Sobre desempenho, fechado é mais eficientet para remoção (apenas atualizando os ponteiros). Já o aberto é mais eficiente para pequenas tabelas, mas sua remoção exige marcações como lápides. 



**Questão 5:** Para uma tabela hash de tamanho **m = 7**, com função de hash **h(k) = k mod 7**, insira as chaves **10, 21, 17, 38, 34, 45** utilizando:

(a) Endereçamento fechado (listas encadeadas).
    Resposta: 0 = {21}, 2 = { 10, 17, 38, 45}, 6 = {34}

(b) Endereçamento aberto com sondagem linear.
    Resposta: 0={21}, 2={10}, 3={17}, 4={38}, 5={45}, 6={34}

### **4. Complexidade das inserções em hashing**

**Questão 6:** Considere uma tabela hash de tamanho **m = 11** e a inserção dos seguintes valores usando **sondagem linear** e **sondagem quadrática**:

**Chaves:** 10, 22, 31, 4, 15, 28, 17

**Função hash:** h(k) = k mod 11

Qual a **complexidade** da n-ésima inserção nos dois casos?

    Resposta: O(N) nos dois casos, porém a sondagem quadrática dispersa melhor.

### **Árvores B**

### **5. Operações em Árvores B**

**Questão 7:** Implemente uma função para a inserção de uma chave em uma **Árvore B de ordem T=2**. Explique como ocorre a divisão de nós quando um nó atinge a capacidade máxima.

**Questão 8:** Insira as chaves **10, 20, 30, 40, 50, 60, 70, 80, 90, 100** em uma **Árvore B de ordem 3** e desenhe o resultado após cada inserção.

### **6. Remoção em Árvores B**

**Questão 9:** Considere a **Árvore B de ordem 3** obtida na questão anterior. Remova as chaves **40, 50 e 60** e desenhe a árvore resultante.

---

### **Conjuntos Disjuntos e Algoritmo de Kruskal**

### **7. Implementação com florestas**

**Questão 10:** A seguinte estrutura de dados é usada para representar conjuntos disjuntos:

typedef struct {
int pai[MAX];
} Conjunto;

(a) Implemente uma função para realizar a operação **find**  sem compressão de caminho.

(b) Modifique a função para incluir compressão de caminho e explique como isso melhora o desempenho.

### **8. Otimizações com compressão de caminho**

**Questão 11:** Durante a execução do algoritmo de Kruskal, utilizamos a estrutura de **conjuntos disjuntos** com **união por rank e compressão de caminho**. Explique como essas otimizações afetam a complexidade do algoritmo.

---

### **Hashing Dinâmico**

### **9. Hashing Dinâmico Extensível e Linear**

**Questão 12:** Insira as chaves **1, 2, 9, 5, 6, 13, 15, 12** em uma **tabela de Hashing Dinâmico Extensível** (iniciada com i=1 e blocos de tamanho 2).

(a) Mostre as etapas do crescimento da tabela.

(b) Qual o impacto do fator de carga no desempenho dessa estrutura?

**Questão 13:** Repita a inserção da questão anterior utilizando **Hashing Dinâmico Linear** e compare as diferenças entre as abordagens.