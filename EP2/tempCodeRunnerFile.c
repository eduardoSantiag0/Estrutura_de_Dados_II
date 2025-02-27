
  Grafo g2;
  inicializaGrafo(&g2, 2);
  insereAresta(&g2, 0, 1, 3);
  insereAresta(&g2, 1, 1, 5);
  printf("\n##### Terceiro problema: duas cidades (nao ha solucao).\n");
  exibeGrafo(&g2);
  if (caixeiroViajante(&g2)){
    printf("Custo encontrado: %.2f\n", melhorValor); 
    exibeCiclo(melhorCiclo, g2.numVertices);
  }else printf("Nenhuma solucao foi encontrada.\n");

  printf("\n##### Quarto problema: duas cidades (ha solucao).\n");
  insereAresta(&g2, 1, 0, 7);
  exibeGrafo(&g2);
  if (caixeiroViajante(&g2)){
    printf("Custo encontrado: %.2f\n", melhorValor); 
    exibeCiclo(melhorCiclo, g2.numVertices);
  }else printf("Nenhuma solucao foi encontrada.\n");