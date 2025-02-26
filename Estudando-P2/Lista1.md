### **1. Grafos e Busca em Profundidade**

1.1. Defina os quatro tipos de arestas que podem ser identificadas durante a busca em profundidade em grafos direcionados e forneça exemplos de cada uma.

    1. **Árvore**: Arestas dentro do árvore de busca em profundidade
    2. **Retorno**: Conectam um vértice com um já visitado (gera cíclos)
    3. **Avanço**: Não fazem parte da da árvore de busca porém conectam um vértice a um descente já descoberto. Apenas em grafos direcionados
    4. **Cruzamento**: Ligam uma subárvore a outro vértice em uma outra subávore.   


1.2. É possível realizar uma ordenação topológica em um grafo direcionado que possua arestas de retorno? Justifique sua resposta.

    Não, pois arestas de retorno indicam um cíclo.

1.3. Qual(is) tipo(s) de aresta(s) sempre estarão presentes em um grafo direcionado cíclico? Explique.

    Aresta de Retorno

### **2. Hashing**

2.1. Compare as vantagens e desvantagens do uso de hashing considerando Endereçamento Fechado e Endereçamento Aberto.

    Em termos de espaço, fechado permite que a tabela mantenha o mesmo tamanho, enquanto o aberto mantém todos os elementos dentro da tabela, mas pode necessitarde redimensionamento. 

    Sobre desempenho, fechado é mais eficientet para remoção (apenas atualizando os ponteiros). Já o aberto é mais eficiente para pequenas tabelas, mas sua remoção exige marcações como lápides. 

2.2. Suponha que você está utilizando uma estrutura de hashing e todas as inserções colidam em uma mesma posição. Qual o custo computacional da n-ésima inserção nos seguintes casos?
a) Endereçamento Fechado
b) Endereçamento Aberto com Sondagem Linear
c) Endereçamento Aberto com Sondagem Quadrática

    a) 0(N)
    b) 0(N)
    c) 0(N)

### **3. Árvores B**

3.1. Implemente a função `divideNoFilho` para dividir um nó cheio em Árvores B. Utilize a estrutura fornecida na prova.

3.2. Construa a Árvore B de grau mínimo 3 (T=3) após a inserção das chaves de 1 a 10, em ordem crescente. Desenhe a árvore resultante.

3.3. Com base na árvore da questão anterior, remova as chaves de 4 a 7, uma por vez, e desenhe a árvore após cada remoção.

### **4. Conjuntos Disjuntos e Algoritmo de Kruskal**

4 Explique como a estrutura de conjuntos disjuntos baseada em florestas é utilizada no algoritmo de Kruskal para encontrar a árvore geradora mínima de um grafo.

    Resposta: Após a ordenação dos pesos dos vértices, union é usado para juntar as diferentes subárvores, enquanto o find é usado para encontrar o próximo menor aresta


### **5. Hashing Dinâmico**

5.1. Considere o seguinte conjunto de registros e seus valores em binário e decimal:

| Valor Binário | Valor Decimal | Registro |
| --- | --- | --- |
| 0001 | 1 | A |
| 0010 | 2 | B |
| 1001 | 9 | C |
| 0101 | 5 | D |
| 0110 | 6 | E |
| 1101 | 13 | F |
| 1111 | 15 | G |
| 1010 | 12 | H |

a) Desenhe como ficará o Hashing Dinâmico Extensível após a inserção destes oito registros. Considere que ele é inicializado vazio com tamanho 2 (i=1).

b) Desenhe como ficará o Hashing Dinâmico Linear após a inserção destes oito registros, considerando um tamanho inicial de 2.

---

**Instruções**:

- Resolva os exercícios justificando suas respostas.
- Utilize algoritmos e pseudo-códigos sempre que necessário.
- Caso precise, utilize programas para testar implementações.
- Bons estudos!