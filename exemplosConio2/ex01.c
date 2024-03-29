#include <stdio.h>
#include <conio2.h>//para modo gráfico
#include <locale.h>//para aceitar acentos

int main(){
    setlocale(LC_ALL,"portuguese");//aceitar acentos
    textbackground(BLUE);
    clrscr();  //Ao limpar, toda a tela fica cinza
    gotoxy(48,5); //coluna 50 e linha 5
    textcolor(WHITE); textbackground(RED);
    printf("DSI"); gotoxy(30,7); //coluna 30 e linha 7
    textcolor(RED); textbackground(LIGHTGRAY);
    printf("Bacharelado em Sistemas de Informação");
    system("pause>NULL");//pausa até que uma tecla seja digitada
    return 0;
}
