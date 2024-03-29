#include <stdio.h>
#include <stdlib.h>

typedef struct Funcionario
{
    int cod;
    char nome[50];
    char cpf[15];
    char data_nascimento[11];
    double salario;
} TFunc;

// Salva no arquivo out, na posição atual do cursor
void salva(TFunc *func, FILE *out)
{
    fwrite(&func->cod, sizeof(int), 1, out);
    // func->nome ao invés de &func->nome,
    // pois string já é ponteiro
    fwrite(func->nome, sizeof(char), sizeof(func->nome), out);
    fwrite(func->cpf, sizeof(char), sizeof(func->cpf), out);
    fwrite(func->data_nascimento, sizeof(char), sizeof(func->data_nascimento), out);
    fwrite(&func->salario, sizeof(double), 1, out);
}

// Le do arquivo in na posição atual do cursor
// Retorna um ponteiro para funcionário lido do arquivo
TFunc *le(FILE *in)
{
    TFunc *func = (TFunc *)malloc(sizeof(TFunc));
    if (0 >= fread(&func->cod, sizeof(int), 1, in))
    {
        free(func);
        return NULL;
    }
    fread(func->nome, sizeof(char), sizeof(func->nome), in);
    fread(func->cpf, sizeof(char), sizeof(func->cpf), in);
    fread(func->data_nascimento, sizeof(char), sizeof(func->data_nascimento), in);
    fread(&func->salario, sizeof(double), 1, in);
    return func;
}

/*
 * tamanho do registro, retornado pela função
 * tamanho_registro() é dado em bytes
 */
int total_registros(FILE *arq)
{
    fseek(arq, 0, SEEK_END);
    int tam = trunc(ftell(arq) / tamanho_registro());
    return tam;
}

