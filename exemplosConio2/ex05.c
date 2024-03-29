#include <stdio.h>
#include <conio2.h>
#include <windows.h>
#include <time.h>

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
    printf("%c",201);
    for(int coluna=2;coluna<MAX_COLUNAS;coluna++)
        printf("%c",205);
    printf("%c\n",187);

    for(int linha=2;linha<=MAX_LINHAS;linha++){
        gotoxy(1,linha);printf("%c",186);
        gotoxy(MAX_COLUNAS,linha);printf("%c",186);
    }

    printf("\n%c",200);
    for(int coluna=2;coluna<MAX_COLUNAS;coluna++)
        printf("%c",205);
    printf("%c",188);

    //...
    gotoxy(12, 6);printf("     _                         _         ____             _       ");
    gotoxy(12, 7);printf("    | | ___   __ _  ___     __| | __ _  / ___|  ___  _ __| |_ ___ ");
    gotoxy(12, 8);printf(" _  | |/ _ \\ / _` |/ _ \\   / _` |/ _` | \\___ \\ / _ \\| '__| __/ _ \\");
    gotoxy(12, 9);printf("| |_| | (_) | (_| | (_) | | (_| | (_| |  ___) | (_) | |  | ||  __/");
    gotoxy(12,10);printf(" \\___/ \\___/ \\__, |\\___/   \\__,_|\\__,_| |____/ \\___/|_|   \\__\\___|");
    gotoxy(12,11);printf("             |___/                                                ");

    for (int coluna=50; coluna>=12; coluna--){
        gotoxy(12,13);
        printf("                                                             ");
        gotoxy(coluna,13);textbackground(WHITE);textcolor(BLUE);
        printf("TENTE ACERTAR O NUMERO!");
        Sleep(20);
        textbackground(BLUE);textcolor(WHITE);
    }

    gotoxy(12,15);printf("CARREGANDO ");textbackground(BLACK);printf("     ");
    gotoxy(23,15);textbackground(RED);
    for(int contador=1;contador<=5;contador++){
       Sleep(1000);
       printf(" ");
    }
    Sleep(1000);
    gotoxy(12,15);textbackground(BLUE);printf("                ");

    char alternativa;
    do{

        textbackground(BLUE);
        textcolor(WHITE);
        gotoxy(12,15);
        for(int linha=15;linha<=26;linha++){
            for(int coluna=12; coluna<=50;coluna++)
                printf(" ");
            gotoxy(12,linha);
        }
        gotoxy(12,15);printf("ESCOLHA UMA ALTERNATIVA:\n");
        gotoxy(12,16);printf("(1) Para Jogar");
        gotoxy(12,17);printf("(2) Para SAIR");
        alternativa=getch();
        if(alternativa=='1'){
            int numero,tentativas=0,acertos=0;
            char opcao;
            do{
                textbackground(WHITE);
                textcolor(BLACK);
                gotoxy(12,15);
                for(int linha=15;linha<=25;linha++){
                    for(int coluna=12; coluna<=50;coluna++)
                        printf(" ");
                    gotoxy(12,linha);
                }
                gotoxy(12,15);
                printf("%c",201);
                for(int coluna=13;coluna<50;coluna++)
                    printf("%c",205);
                printf("%c",187);

                for(int linha=16;linha<25;linha++){
                    gotoxy(12,linha);printf("%c",186);
                    gotoxy(50,linha);printf("%c",186);
                }

                gotoxy(12,25);
                printf("%c",200);
                for(int coluna=13;coluna<50;coluna++)
                    printf("%c",205);
                printf("%c",188);

                tentativas++;
                gotoxy(13,16);printf("TENTATIVAS: %d",tentativas);
                gotoxy(13,17);printf("ACERTOS: %d",acertos);
                gotoxy(13,19);printf("Escolha um numero de 1 a 10:");
                do{
                    gotoxy(41,19);
                    printf("     ");
                    gotoxy(41,19);
                    scanf("%d",&numero);
                }while((numero<0)||(numero>10));
                srand(time(NULL));
                int sorteio = rand() % 10 +1;
                gotoxy(13,21);printf("               ");
                gotoxy(13,21);printf("Sorteado: %d",sorteio);
                if(sorteio==numero){
                    acertos++;
                    gotoxy(13,22);textbackground(GREEN);textcolor(WHITE);printf("PARABENS!");
                    textbackground(WHITE);textcolor(BLACK);
                }
                gotoxy(13,16);printf("TENTATIVAS: %d",tentativas);
                gotoxy(13,17);printf("ACERTOS: %d",acertos);
                gotoxy(13,23);printf("Deseja continuar tentando?(S/N)");
                opcao=getch();
            }while((opcao=='S')||(opcao=='s'));
        }
    }while(alternativa!='2');

    textbackground(YELLOW);
    textcolor(BLACK);
    gotoxy(1,1);
     for(int linha=1;linha<=MAX_LINHAS;linha++){
        for(int coluna=1; coluna<=MAX_COLUNAS;coluna++)
            printf(" ");
        printf("\n");
    }
    clrscr();
    gotoxy(20, 8);printf(" _    _ ______ _____       __  _____   _____ _____ ");
    gotoxy(20, 9);printf("| |  | |  ____/ ____|     / / |  __ \\ / ____|_   _|");
    gotoxy(20,10);printf("| |  | | |__ | (___      / /  | |  | | (___   | |  ");
    gotoxy(20,11);printf("| |  | |  __| \\___ \\    / /   | |  | |\\___ \\  | |  ");
    gotoxy(20,12);printf("| |__| | |    ____) |  / /    | |__| |____) |_| |_ ");
    gotoxy(20,13);printf(" \\____/|_|   |_____/  /_/     |_____/|_____/|_____|");
    getch();
    return 0;
}
