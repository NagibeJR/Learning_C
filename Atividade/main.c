#include<stdio.h>
#include<stdlib.h>

struct Reg {
  int dado;
  struct Reg *prox;
};

/* Protótipo da função que calcula o número de nós em uma lista circular. */
int NumeroDeNos(struct Reg *c);

int main(int argc, char **argv) {
  int N; /* quantidade de pessoas */
  int M; /* numero de "saltos" */
  int i; /* indice generico */

  struct Reg *tmp;
  struct Reg *x;
  struct Reg *t = (struct Reg *) malloc(sizeof(struct Reg));
  if(t == 0) {  /*o sistema está sem memória */
     printf("Erro: falta de memória\n");
     exit(1);
   }
  x = t;

  if(argc <=2) {
    printf("\nEste programa resolve o problema de Josephus.\n");
    printf("Número insuficiente de argumentos.\n");
    printf("Uso: <nomeDoPrograma> <N> <M>.\n");
    printf("\t<nomeDoPrograma>: nome do executável;\n");
    printf("\t             <N>: quantidade de pessoas;\n");
    printf("\t             <M>: número de \"saltos\".\n");
    exit(2);
  }

  N = atoi(argv[1]);
  M = atoi(argv[2]);

  printf("\nN = %d\n", N);
  printf("M = %d\n", M);
  printf("Resolvendo o problema de Josephus para %d ", N);
  printf("pessoas, saltando de %d em %d.\n", M, M);

  /* A variável t aponta para o primeiro nó (registro) da lista circular. */
  t->dado = 1;
  t->prox = t;

  /* Alocação do restante da lista circular. */
  for(i = 2; i <= N; i++) {
    x = x->prox = (struct Reg *) malloc(sizeof(struct Reg));
    if(x == 0) {
      printf("Erro: falta de memória\n");
      exit(1);
    }
    x->dado = i;
    x->prox = t;
  }

  printf("Número de pessoas na lista circular (parâmetro 't'): %d\n",
    NumeroDeNos(t));
  /* Também podemos passar o apontador x para a função NumeroDeNos. */
  printf("Número de pessoas na lista circular (parâmetro 'x'): %d\n",
    NumeroDeNos(x));

  /* Escolha do próximo suicida até sobrar apenas o eleito. */
  while(x != x->prox) {
    for(i = 1; i < M; i++)
      x = x->prox;
    tmp = x->prox;
    x->prox = tmp->prox;
    free(tmp);
  }

  printf("Número do eleito: %d\n", x->dado);

  free(t);

  return 0;
}

/*
 * Esta função devolve o número de nós existente na lista circular que contém o
 * nó apontado por p como um de seus nós.
 */
int NumeroDeNos(struct Reg *p) {
  int c = 1;
  struct Reg *x;

  if(p == 0)
    return 0;
  x = p->prox;
  while(x != p) {
    c++;
    x = x->prox;
  }
  return c;
}
