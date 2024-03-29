#include <stdio.h>
#include <stdlib.h>
/*exercicio: Dados dois arquivos texto contendo numeros ordenados,
gerar um novo arquivo equivalente a junção dos dois porem sem repetir os numeros*/

void merge(char *nomeArq1, char *nomeArq2, char *nomeMerge)
{
    char  ch;
    if(nomeArq1 == NULL || nomeArq2 == NULL || nomeMerge == NULL){
        printf("\nErro: o arquivo não pode ser aberto");
        exit(1);
    }
    while (1)
    {
        ch = fgetc(nomeArq1);
        if(ch == EOF)
        break;
        fputc(ch,nomeMerge);
    }
    fclose(nomeArq1);
    while (1)
    {
        ch = fgetc (nomeArq2);
        if (ch == EOF)
        break;
        fputc(ch,nomeMerge);
    }
    fclose(nomeArq2);
    fclose(nomeMerge);
    return 0;
}

int main()
{
    FILE *nomeArq1, *nomeArq2, *nomeMerge;
    nomeArq1 = fopen("arquivo1.txt","r");
    nomeArq2 = fopen("arquivo2.txt","r");
    nomeMerge = fopen("arquivoMerge.txt","w");
    void merge();
}
