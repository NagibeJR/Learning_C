#include <stdio.h>
#include <conio2.h>

int main(){
    int MAX_COLUNAS=90;//verificar o total de colunas na sua tela
    int MAX_LINHAS=25;//verificar o total de linhas na sua tela
    int COR_FUNDO=BLUE;
    int COR_LETRA=WHITE;

    textbackground(COR_FUNDO);
    textcolor(COR_LETRA);
    for(int linha=1;linha<=MAX_LINHAS;linha++){
        for(int coluna=1; coluna<=MAX_COLUNAS;coluna++)
            printf(" ");
        printf("\n");
    }
    gotoxy(1,1);
    printf("%c",201);//caractere ╔
    for(int coluna=2;coluna<MAX_COLUNAS;coluna++)
        printf("%c",205);// caractere ═
    printf("%c\n",187);//caractere ╗

    for(int linha=2;linha<=MAX_LINHAS;linha++){
        gotoxy(1,linha);printf("%c",186);//caractere ║
        gotoxy(MAX_COLUNAS,linha);printf("%c",186);//caractere ║
    }

    printf("\n%c",200);//caractere ╚
    for(int coluna=2;coluna<MAX_COLUNAS;coluna++)
        printf("%c",205);//caractere ═
    printf("%c",188);//caractere ╝
    getch();
    return 0;
}
