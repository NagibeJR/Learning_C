#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int total=0;
void resolucao(int solucao[], int tam){
    for (int i = 0; i < tam; i++)
    {
        printf("%c",solucao[i]);
    }
    printf("\n");
    total+=1;
    
}
void backtrack(char *senha,int solucao[],int tam, int atual){
    if (tam == atual){
        resolucao(solucao,tam);
        return;
    }
    int n=0;
    int candidatos[32];
    memset(candidatos,0, sizeof(candidatos));
    Npossiveis(senha[atual],candidatos,&n);
    for (int i = 0; i < n; i++)
    {
        solucao[atual]=candidatos[i];
        backtrack(senha,solucao,tam,atual+1);
    }
}
void Npossiveis (char letra,int candidatos[],int *n){
    switch(letra){
        case 'L' :
            for (int j = 0; j < 26; j++){
                candidatos[j]=j+65;
            }
            *n=26;
            break;
        case 'l' :
            for (int j = 0; j < 26; j++){
                candidatos[j]=j+97;
            }
            *n=26;
            break;
        case 'N' :
            for (int j = 0; j < 10;j++){
                candidatos[j]=j+48;  
            }
            *n=10;
            break;
        case 'S' :
            for (int j = 0; j < 32; j++){
                if (j<15)
                    candidatos[j]=j+33;
                else if (j>=15 && j<22)
                    candidatos[j]=j+43;
                else if (j>=22 && j<28)
                    candidatos[j]=j+69;
                else 
                    candidatos[j]=j+95;
            }
            *n=32;
            break;
    }

}
void gerar_senha(char *senha,int tam){
    int solucao[tam];
    memset(solucao, 0, sizeof(solucao));
    backtrack(senha,solucao,tam,0);
}
int main(){
    char senha[5];
    printf("|Digite como sera a senha gerada|\n");
    printf("|L= Letra maiuscula             | \n");
    printf("|l= Letra minuscula             | \n");
    printf("|N= Numeros                     |\n");
    printf("|S= Simbolos                    |\n");
    printf("|MAX: 5 caracteres             | \n");
    gets(senha);
    int tam = strlen(senha);
    gerar_senha(senha,tam);
    printf("%d",total);
    return 0;
}
