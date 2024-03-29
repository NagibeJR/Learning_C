#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio2.h>

typedef struct Veiculo
{
    char Modelo[15];
    char Marca[15];
    int Valor;
    char Placa[7];
} Veiculos;

Veiculos vetorVeiculos[5];

void qSort(Veiculos *vetorVeiculos, int Inicio, int TAM);

int main()
{
    int Inicio = 0, TAM = 0, i = 1;
    printf("Digite a quantidade de veiculos:");
    scanf("%d",&TAM);
    clrscr();
    do
    {
        printf("Digite a marca, modelo, placa e valor do carro %d: \n",i);
        scanf("%s%*c",&vetorVeiculos[i].Marca);
        scanf("%s%*c",&vetorVeiculos[i].Modelo);
        scanf("%s%*c",&vetorVeiculos[i].Placa);
        scanf("%d%*c",&vetorVeiculos[i].Valor);
        i++;
        clrscr();
    }
    while(i <= TAM);
    qSort(vetorVeiculos,Inicio,TAM);
    clrscr();
    for(int i = 1 ; i <= TAM; i++)
    {
        printf("Carro %d\n",i);
        printf("%s\n",vetorVeiculos[i].Marca);
        printf("%s\n",vetorVeiculos[i].Modelo);
        printf("%s\n",vetorVeiculos[i].Placa);
        printf("%d\n",vetorVeiculos[i].Valor);
        printf("\n");
    }
    return 0;
}

void qSort(Veiculos*vetorVeiculos, int Inicio, int TAM)
{
    int i,j,x,aux;
    char auxChar[30];
    i = Inicio;
    j = TAM;
    x = vetorVeiculos[i].Valor;
    do
    {
        while(vetorVeiculos[i].Valor < x && i < TAM)i++;
        while(vetorVeiculos[j].Valor > x && j > Inicio)j--;
        if(i <= j)
        {
            aux = vetorVeiculos[i].Valor;
            vetorVeiculos[i].Valor = vetorVeiculos[j].Valor;
            vetorVeiculos[j].Valor = aux;
            strcpy(auxChar,vetorVeiculos[i].Modelo);
            strcpy(vetorVeiculos[i].Modelo,vetorVeiculos[j].Modelo);
            strcpy(vetorVeiculos[j].Modelo,auxChar);
            strcpy(auxChar,vetorVeiculos[i].Marca);
            strcpy(vetorVeiculos[i].Marca,vetorVeiculos[j].Marca);
            strcpy(vetorVeiculos[j].Marca,auxChar);
            strcpy(auxChar,vetorVeiculos[i].Placa);
            strcpy(vetorVeiculos[i].Placa,vetorVeiculos[j].Placa);
            strcpy(vetorVeiculos[j].Placa,auxChar);
            i++;
            j--;
        }
    }
    while(i <= j);
    if(Inicio < j)
        qSort(vetorVeiculos,Inicio,j);
    if(i < TAM)
        qSort(vetorVeiculos, i, TAM);
}
