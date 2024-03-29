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
for(int linha=2;linha<MAX_LINHAS;linha++){
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
gotoxy(12, 6);printf(" _ _ ____ _ ");
gotoxy(12, 7);printf(" | | ___ __ _ ___ __| | __ _ / ___| ___ _ __| |_ ___ ");
gotoxy(12, 8);printf(" _ | |/ _ \\ / _` |/ _ \\ / _` |/ _` | \\___ \\ / _ \\| '__| __/ _ \\");
gotoxy(12, 9);printf("| |_| | (_) | (_| | (_) | | (_| | (_| | ___) | (_) | | | || __/");
gotoxy(12,10);printf(" \\___/ \\___/ \\__, |\\___/ \\__,_|\\__,_| |____/ \\___/|_| \\__\\___|");
gotoxy(12,11);printf(" |___/ ");
//repetição para animar o texto da Direita para esquerda
for (int coluna=50; coluna>=12; coluna--){
gotoxy(12,13);
printf(" ");
gotoxy(coluna,13);
printf("VAMOS TESTAR SUA SORTE!");
Sleep(20); //essa função requer o #include <windows.h>
}
//repetição para criar o efeito de carregar
gotoxy(12,15);printf("CARREGANDO ");textbackground(BLACK);printf(" ");
gotoxy(23,15);textbackground(RED);
for(int contador=1;contador<=5;contador++){
Sleep(1000);
printf(" ");
}
