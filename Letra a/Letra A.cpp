#include <stdio.h>
#include <stdlib.h>
#include <conio2.h>
#include <string.h>
#define TAM 20
#include <iostream>

using namespace std;

typedef struct Pacientes
{
    char nome[TAM];
    char plano_de_saude[TAM];
    int idade;
    int cpf;
} paciente;

typedef struct gerencLista
{
    paciente *inicio, *fim;
    int quant;
} tipoLista;

void inicializa(tipoLista *listaEnc)
{
    listaEnc->inicio = NULL;
    listaEnc->fim = NULL;
    listaEnc->quant = 0;
}


