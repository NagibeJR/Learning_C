#include <stdio.h>
#include <conio2.h>

int main(){
    int col, lin;
    char c;
    printf("Pressione uma tecla...");
    getch();//pausa até que uma tecla seja pressionada
    clrscr();
    printf ("Posicionar cursor? (s/n): ");
    c = getch();
    while (c == 's' || c == 'S') {
        clrscr();
        gotoxy(1, 1); printf("Digite a coluna: ");
        gotoxy(1, 2); printf("Digite a linha : ");
        gotoxy(18,1); scanf("%d", &col);
        gotoxy(18,2); scanf("%d", &lin);
        gotoxy(col, lin);
        getch();
        clrscr();
        gotoxy(1,1);
        printf("Posicionar cursor? (s/n): ");
        c = getch();
    }
    return 0;
}
