#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "nomes.h"


TNomes* insere_inicio (TNomes* li, char *nome) {
    TNomes* novo = (TNomes*) malloc(sizeof(TNomes));
    novo->nome = nome;
    novo->prox = li;
    li = novo;
    return novo;
}

void libera_nomes(TNomes *nomes)
{
	TNomes *temp = NULL;
	while(nomes) {
		temp = nomes->prox;
		free(nomes->nome);
		free(nomes);
		nomes = temp;
	}
}

int conta_nomes(TNomes *nomes)
{
	int qtd = 0;
	while(nomes) {
		qtd += 1;
		nomes = nomes->prox;
	}
	return qtd;
}

void imprime_nomes(TNomes *nomes)
{
	while(nomes) {
		printf("%s\n", nomes->nome);
		nomes = nomes->prox;
	}
}
