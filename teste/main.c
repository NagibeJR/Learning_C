//
// Created by Vanessa Braganholo on 16/09/2018.
// Updated by Raphael Oliveira on 24/08/2021.

#include <stdio.h> // lidar com arquivos (ex.: FILE)
#include <stdlib.h> // lidar com constantes (ex.: NULL)
#include <string.h> // lidar com fun��es de string (ex.: strcpy())

typedef struct Funcionario {
    int cod;
    char nome[50];
    char cpf[15];
    char data_nascimento[11];
    double salario;
} TFunc;

// Imprime funcionario
void imprime(TFunc *func);

// Cria funcionario. Lembrar de usar free(funcionario)
TFunc *funcionario(int cod, char *nome, char *cpf, char *data_nascimento, double salario);

// Salva funcionario no arquivo out, na posicao atual do cursor
void salva(TFunc *func, FILE *out);

// Le um funcionario do arquivo in na posicao atual do cursor
// Retorna um ponteiro para funcionario lido do arquivo
TFunc *le(FILE *in);

// Retorna tamanho do funcionario em bytes
int tamanho();


// Imprime funcionario
void imprime(TFunc *func) {
    printf("**********************************************");
    printf("\nFuncionario de c�digo ");
    printf("%d", func->cod);
    printf("\nNome: ");
    printf("%s", func->nome);
    printf("\nCPF: ");
    printf("%s", func->cpf);
    printf("\nData de Nascimento: ");
    printf("%s", func->data_nascimento);
    printf("\nSal�rio: ");
    printf("%4.2f", func->salario);
    printf("\n**********************************************");
}

// Cria funcionario. Lembrar de usar free(func)
TFunc *funcionario(int cod, char *nome, char *cpf, char *data_nascimento, double salario) {
    TFunc *func = (TFunc *) malloc(sizeof(TFunc));
    //inicializa espa�o de mem�ria com ZEROS para os valores inteiros
    if (func) memset(func, 0, sizeof(TFunc));
    //copia valores para os campos de func
    func->cod = cod;
    strcpy(func->nome, nome);
    strcpy(func->cpf, cpf);
    strcpy(func->data_nascimento, data_nascimento);
    func->salario = salario;
    return func;
}

// Salva funcionario no arquivo out, na posicao atual do cursor
void salva(TFunc *func, FILE *out) {
    fwrite(&func->cod, sizeof(int), 1, out);
    //func->nome ao inv�s de &func->nome, pois string j� � ponteiro
    fwrite(func->nome, sizeof(char), sizeof(func->nome), out);
    fwrite(func->cpf, sizeof(char), sizeof(func->cpf), out);
    fwrite(func->data_nascimento, sizeof(char), sizeof(func->data_nascimento), out);
    fwrite(&func->salario, sizeof(double), 1, out);
}

// Le um funcionario do arquivo in na posicao atual do cursor
// Retorna um ponteiro para funcionario lido do arquivo
TFunc *le(FILE *in) {
    TFunc *func = (TFunc *) malloc(sizeof(TFunc));
    if (0 >= fread(&func->cod, sizeof(int), 1, in)) {
        free(func);
        return NULL;
    }
    fread(func->nome, sizeof(char), sizeof(func->nome), in);
    fread(func->cpf, sizeof(char), sizeof(func->cpf), in);
    fread(func->data_nascimento, sizeof(char), sizeof(func->data_nascimento), in);
    fread(&func->salario, sizeof(double), 1, in);
    return func;
}

// Retorna tamanho do funcionario em bytes
int tamanho() {
    return sizeof(int)  //cod
           + sizeof(char) * 50 //nome
           + sizeof(char) * 15 //cpf
           + sizeof(char) * 11 //data_nascimento
           + sizeof(double); //salario
}

void insere_5_funcionarios(FILE *out) {
    printf("Inserindo 5 funcion�rios no arquivo...");

    TFunc *f1 = funcionario(1, "Liz", "000.000.000-00", "01/01/1980", 3000);
    salva(f1, out);
    free(f1);
    TFunc *f2 = funcionario(2, "Raphael", "111.111.111-11", "01/01/1990", 500);
    salva(f2, out);
    free(f2);
    TFunc *f3 = funcionario(3, "F�tima", "222.222.222-22", "02/02/1980", 1000);
    salva(f3, out);
    free(f3);
    TFunc *f4 = funcionario(4, "Marcelo", "333.333.333-33", "03/03/1990", 1500);
    salva(f4, out);
    free(f4);
    TFunc *f5 = funcionario(5, "Silvia", "444.444.444-44", "04/04/1980", 900);
    salva(f5, out);
    free(f5);
}

void le_funcionarios(FILE *in) {
    printf("\n\nLendo funcion�rios do arquivo...\n\n");
    rewind(in);
    TFunc *f;
    while ((f = le(in)) != NULL) {
        imprime(f);
        free(f);
    }
}

void le_segundo_funcionario(FILE *in) {
    printf("\n\nLendo segundo funcion�rio do arquivo...\n\n");
    //tamanho() indica quantos bytes vamos pular, o que aqui � igual ao tamanho de um registro
    //(vamos pular o primeiro e nos posicionar no in�cio do segundo)
    //** ATEN��O: n�o usar sizeof(Funcionario), pois ele pode retornar valor maior que o tamanho ocupado em disco,
    //            devido a alinhamento autom�tico (ver https://en.wikipedia.org/wiki/Data_structure_alignment))
    //SEEK_SET indica o in�cio do arquivo
    //ao final, o cursor estar� posicionado em 0 + tamanho() +1
    fseek(in, tamanho(), SEEK_SET);
    TFunc *f = le(in);
    if (f != NULL) {
        imprime(f);
        free(f);
    }
}

void adiciona_funcionario(FILE *in) {
    printf("\n\nAdicionando funcion�rio no final do arquivo...\n\n");
    //pula 5 registros para posicionar no in�cio do final do arquivo
    fseek(in, tamanho() * 5, SEEK_SET);
    TFunc *f = funcionario(6, "Bruna", "666.666.666-66", "06/06/1980", 2500);
    salva(f, in);
    free(f);

    //l� funcion�rio que acabou de ser gravado
    //posiciona novamente o cursor no in�cio desse registro
    fseek(in, tamanho() * 5, SEEK_SET);
    TFunc *f6 = le(in);
    if (f6 != NULL) {
        imprime(f6);
        free(f6);
    }
}

void sobrescreve_quarto_funcionario(FILE *in) {
    printf("\n\nSobrescrevendo quarto funcion�rio do arquivo...\n\n");
    //pula primeiros 3 registros para posicionar no in�cio do quarto registro
    fseek(in, tamanho() * 3, SEEK_SET);
    TFunc *f4 = funcionario(7, "Catarina", "777.777.777-77", "07/07/1990", 5000);
    salva(f4, in);
    free(f4);

    //l� funcion�rio que acabou de ser gravado
    //posiciona novamente o cursor no in�cio desse registro
    fseek(in, tamanho() * 3, SEEK_SET);
    TFunc *f = le(in);
    if (f != NULL) {
        imprime(f);
        free(f);
    }
}

int main() {
    //declara ponteiro para arquivo
    FILE *out;
    //abre arquivo
    if ((out = fopen("funcionario.dat", "wb+")) == NULL) {
        printf("Erro ao abrir arquivo\n");
        exit(1);
    }
    else {
        //insere funcion�rios
        insere_5_funcionarios(out);
        //volta ao in�cio do arquivo e l� os funcion�rios inseridos
        le_funcionarios(out);
        //volta ao in�cio do arquivo e l� o segundo funcion�rio
        le_segundo_funcionario(out);
        //grava mais um funcion�rio no final do arquivo
        adiciona_funcionario(out);
        //sobrescreve quarto funcion�rio
        sobrescreve_quarto_funcionario(out);
        //lendo o arquivo todo novamente
        le_funcionarios(out);

        //fecha arquivo
        fclose(out);
    }
}
