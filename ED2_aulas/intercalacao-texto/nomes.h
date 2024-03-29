#ifndef NOMES_H
#define NOMES_H

typedef struct Nomes {
	char *nome;
	struct Nomes *prox;
} TNomes;

// Imprime lista de nomes
void imprime_nomes(TNomes *nomes);

TNomes* insere_inicio (TNomes* li, char *nome);

// Desaloca lista encadeada de nomes
void libera_nomes(TNomes *nomes);

// Retorna quantidade de nomes
int conta_nomes(TNomes *nomes);

#endif