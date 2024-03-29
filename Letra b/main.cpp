#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 20;
#include <iostream>

using namespace std;


int procurarDado(tipoLista *listaEnc, int dado)
{
    tipoNo *atual;
    atual = listaEnc->inicio;
    while(atual != NULL)
    {
        if(atual->cpf == dado)
            return atual;
        atual = atual->proxNo;
    }
    return 0;
}

void BuscarPlano(tipoLista* listaEnc,int cpf )
{

    tipoNo* indice;
    char auxiliar[TAM];
    indice = procurarDado(listaEnc,cpf);
    cin >> aux);
    strcpy(indice->plano_de_saude,auxiliar);

    return 1;

}

int main()
{
    tipoLista listaEnc;
    int cpf;
    printf("CPF para buscar plano de saude: ");
    cout << cpf;
    BuscarPlano(&listaEnc,cpf);

    return 0;
}

