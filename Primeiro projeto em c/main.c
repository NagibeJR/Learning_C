#include <stdio.h>
#include <stdlib.h>
#include <conio2.h>
#include <windows.h>
#include <string.h>

int limite_colunas, limite_linhas, cor_letra, linha, coluna, escolha_da_categoria, escolha=0;
float somaTotal = 0;
float valorRecebido = 0;
float troco = 0;
float taxa = 5;

char nome[100];
char bairro[100];
char rua[100];

int numeroCasa;
//variaveis
float h1 = 5, h2 = 6.5 , h3 = 8.5 , h4 = 10, h5 = 15, h6 = 20, h7 = 25, h8 = 25, h9 = 30;
float a1 = 6, a2 = 12, a3 = 18, a4 = 6, a5 = 12, a6= 18, a7 = 6, a8 = 12, a9 = 18;
float b1 = 4.5, b2= 4.5, b3= 4.5, b4= 4, b5= 4, b6= 4, b7 = 2, b8 = 2.5, b9 = 3;
float s1 = 10, s2 = 10, s3 = 10, s4 = 10 ,s5 = 10, s6 = 10, s7 = 2, s8 = 2, s9 = 2;


void borda()
{

    limite_colunas = 119, limite_linhas = 29, cor_letra = YELLOW;
    textcolor(cor_letra);
    for (linha = 1; linha <= limite_linhas; linha++)
    {
        for (coluna = 1; coluna <= limite_colunas; coluna++)
            printf(" ");
        printf("\n");
    }
    gotoxy(1, 1);

    printf("%c", 201);
    for (coluna = 2; coluna < limite_colunas; coluna++)
        printf("%c", 205);
    printf("%c\n", 187);
    for (linha = 2; linha < limite_linhas; linha++)
    {
        gotoxy(1, linha);
        printf("%c", 186);
        gotoxy(limite_colunas, linha);
        printf("%c", 186);
    }
    printf("\n%c", 200);
    for (coluna = 2; coluna < limite_colunas; coluna++)
        printf("%c", 205);
    printf("%c", 188);
}

void bemVindo()
{
    borda();
    textcolor(RED);
    gotoxy(15, 3);
    printf("  _____ ______     _           ____  ______ __  __     __      _______ _   _ _____   ____  ");
    gotoxy(15, 4);
    printf(" / ____|  ____|   | |  /\\     |  _ \\|  ____|  \\/  |    \\ \\    / /_   _| \\ | |  __ \\ / __ \\  ");
    gotoxy(15, 5);
    printf("| (___ | |__      | | /  \\    | |_) | |__  | \\  / |_____\\ \\  / /  | | |  \\| | |  | | |  | |");
    gotoxy(15, 6);
    printf(" \\___ \\|  __| _   | |/ /\\ \\   |  _ <|  __| | |\\/| |______\\ \\/ /   | | | . ` | |  | | |  | |");
    gotoxy(15, 7);
    printf(" ____) | |___| |__| / ____ \\  | |_) | |____| |  | |       \\  /   _| |_| |\\  | |__| | |__| |");
    gotoxy(15, 8);
    printf("|_____/|______\\____/_/    \\_\\ |____/|______|_|  |_|        \\/   |_____|_| \\_|_____/ \\____/ ");
}

void ITA()
{

    borda();
    textcolor(BROWN);
    gotoxy(23, 10);
    printf(" _____ _______       ____  _    _ _____   _____ _    _ ______ _____   _____ ");
    gotoxy(23, 11);
    printf("|_   _|__   __|/\\   |  _ \\| |  | |  __ \\ / ____| |  | |  ____|  __ \\ / ____|");
    gotoxy(23, 12);
    printf("  | |    | |  /  \\  | |_) | |  | | |__) | |  __| |  | | |__  | |__) | (___  ");
    gotoxy(23, 13);
    printf("  | |    | | / /\\ \\ |  _ <| |  | |  _  /| | |_ | |  | |  __| |  _  / \\___ \\ ");
    gotoxy(23, 14);
    printf(" _| |_   | |/ ____ \\| |_) | |__| | | \\ \\| |__| | |__| | |____| | \\ \\ ____) |");
    gotoxy(23, 15);
    printf("|_____|  |_/_/    \\_\\____/ \\____/|_|  \\_\\\\_____|\\____/|______|_|  \\_\\_____/");

}

void informe()
{
    textcolor(YELLOW);
    gotoxy(15, 20);
    printf("Por favor, informe o seu nome:  ");
    textcolor(WHITE);
    gets(nome);

    Sleep(500);

    textcolor(YELLOW);
    gotoxy(15, 22);
    printf("(%c) Por favor, informe o seu endereco", 25);

    Sleep(500);

    textcolor(YELLOW);
    gotoxy(15, 23);
    printf("Bairro : ");
    textcolor(WHITE);
    gets(bairro);

    Sleep(500);

    textcolor(YELLOW);
    gotoxy(15, 24);
    printf("Rua : ");
    textcolor(WHITE);
    gets(rua);

    Sleep(500);

    textcolor(YELLOW);
    gotoxy(15, 25);
    printf("numero : ");
    textcolor(WHITE);
    scanf("%d",&numeroCasa);

}

void cardapioInicial()
{
    borda();
    textcolor(RED);
    gotoxy(30, 5);
    printf("  _____          _____  _____          _____ _____ ____  ");
    gotoxy(30, 6);
    printf(" / ____|   /\\   |  __ \\|  __ \\   /\\   |  __ \\_   _/ __ \\ ");
    gotoxy(30, 7);
    printf("| |       /  \\  | |__) | |  | | /  \\  | |__) || || |  | |");
    gotoxy(30, 8);
    printf("| |      / /\\ \\ |  _  /| |  | |/ /\\ \\ |  ___/ | || |  | |");
    gotoxy(30, 9);
    printf("| |____ / ____ \\| | \\ \\| |__| / ____ \\| |    _| || |__| |");
    gotoxy(30, 10);
    printf(" \\_____/_/    \\_\\_|  \\_\\_____/_/    \\_\\_|   |_____\\____/");
}



void cardapioLateral()
{

    textcolor(RED);
    gotoxy(3, 3);
    printf("  _____          _____  _____          _____ _____ ____  ");
    gotoxy(3, 4);
    printf(" / ____|   /\\   |  __ \\|  __ \\   /\\   |  __ \\_   _/ __ \\ ");
    gotoxy(3, 5);
    printf("| |       /  \\  | |__) | |  | | /  \\  | |__) || || |  | |");
    gotoxy(3, 6);
    printf("| |      / /\\ \\ |  _  /| |  | |/ /\\ \\ |  ___/ | || |  | |");
    gotoxy(3, 7);
    printf("| |____ / ____ \\| | \\ \\| |__| / ____ \\| |    _| || |__| |");
    gotoxy(3, 8);
    printf(" \\_____/_/    \\_\\_|  \\_\\_____/_/    \\_\\_|   |_____\\____/");
}

void burgLateral()
{
    textcolor(BROWN);
    gotoxy(60,2);
    printf("      _..----.._  ");
    gotoxy(60,3);
    printf("    .'     o    '.  ");
    gotoxy(60,4);
    printf("   /   o       o  \\  ");
    gotoxy(60,5);
    printf("  |o        o     o|  ");
    gotoxy(60,6);
    printf("  /'-.._o     __.-'\\ ");
    gotoxy(60,7);
    printf("  \\      `````     /  ");
    gotoxy(60,8);
    printf("  |``--........--'`|  ");
    gotoxy(60,9);
    printf("   \\              /");
    gotoxy(60,10);
    printf("   `'----------'`");
}

void acompLateral()
{
    textcolor(BROWN);
    gotoxy(60,2);
    printf("     |\\ /| /|_/|");
    gotoxy(60,3);
    printf("   |\\||-|\\||-/|/|");
    gotoxy(60,4);
    printf("    \\\\|\\|//||///");
    gotoxy(60,5);
    printf("    |\\/\\||//||||");
    gotoxy(60,6);
    printf("    |||\\\\|/\\\\ ||");
    gotoxy(60,7);
    printf("    | './\\_/.' |");
    gotoxy(60,8);
    printf("    |          |");
    gotoxy(60,9);
    printf("    |          |");
    gotoxy(60,10);
    printf("     '.______.'");
}

void bebidaLateral()
{
textcolor(BROWN);
gotoxy(60,2);
printf("                        \ ");
gotoxy(60,3);
printf("   .\\\"""""""""-.");
gotoxy(60,4);
printf("   \\`\\-------'`/");
gotoxy(60,5);
printf("    \\ \\__ o . /");
gotoxy(60,6);
printf("     \\/  \  o /");
gotoxy(60,7);
printf("      \\__/. /");
gotoxy(60,8);
printf("       \\_ _/");
gotoxy(60,9);
printf("         Y");
gotoxy(60,10);
printf("         |");
gotoxy(60,11);
printf("         |");
gotoxy(60,12);
printf("     .-' '-.");
gotoxy(60,13);
printf("    `---------`");
}

void sobLateral()
{
     textcolor(BROWN);
    gotoxy(60,2);
    printf("        .-''`''-.");
    gotoxy(60,3);
    printf("       /        \\");
    gotoxy(60,4);
    printf("       |        |");
    gotoxy(60,5);
    printf("       /'---'--`\\");
    gotoxy(60,6);
    printf("      |          |");
    gotoxy(60,7);
    printf("      \\.--.---.-./");
    gotoxy(60,8);
    printf("      (_.--._.-._)");
    gotoxy(60,9);
    printf("        \\=-=-=-/");
    gotoxy(60,10);
    printf("         \\=-=-/   ");
    gotoxy(60,11);
    printf("          \\=-/  ");
    gotoxy(60,12);
    printf("           \\/");

}



void categorias()
{
    textcolor(YELLOW);
    gotoxy(15, 16);
    printf("HAMBURGUERS (1)");
    Sleep(500);
    gotoxy(15, 18);
    printf("ACOMPANHAMENTOS (2)");
    Sleep(500);
    gotoxy(15, 20);
    printf("BEBIDAS (3)");
    Sleep(500);
    gotoxy(15, 22);
    printf("SOBREMESAS (4)");
    Sleep(500);
    gotoxy(15, 24);
    textcolor(LIGHTGREEN);
    printf("EFETUAR COMPRA (5)");
    Sleep(500);
    gotoxy(15, 26);
    textcolor(LIGHTRED);
    printf("CANCELAR COMPRA (0)");
    Sleep(500);
    textcolor(WHITE);
    gotoxy(15, 14);
    printf("%s, SELECIONE UMAS DAS OPCOES ABAIXO: ", nome);
    scanf("%d", &escolha_da_categoria);
}



void itensBurg()
{

    textcolor(YELLOW);
    gotoxy(2, 12);
    printf("(1) ITRADICIONAL R$ 5,00");
    textcolor(LIGHTGRAY);
    gotoxy(2, 13);
    printf("pao, carne, mussarela, tomate, alface, cebola.");

    Sleep(250);

    textcolor(YELLOW);
    gotoxy(2, 15);
    printf("(2) ITA CHEDDAR  R$ 6,50");
    textcolor(LIGHTGRAY);
    gotoxy(2, 16);
    printf("pao, carne, cheddar, cebola caramelizada.");

    Sleep(250);

    textcolor(YELLOW);
    gotoxy(2, 18);
    printf("(3) ITA BACON R$ 8,50");
    textcolor(LIGHTGRAY);
    gotoxy(2, 19);
    printf("pao, carne, bacon, mussarela, tomate, alface, cebola.");


    Sleep(250);

    textcolor(YELLOW);
    gotoxy(2, 21);
    printf("(4) ITA CHICKEN  R$ 10,00");
    textcolor(LIGHTGRAY);
    gotoxy(2, 22);
    printf("pao, frango, mussarela, alface, tomate, cebola.");

    Sleep(250);

    textcolor(YELLOW);
    gotoxy(2, 24);
    printf("(5) ITA HOUSE R$ 15,00");
    textcolor(LIGHTGRAY);
    gotoxy(2, 25);
    printf("pao, picanha, alface, tomate, cebola, mussarela, barbecue.");

    Sleep(250);

    textcolor(YELLOW);
    gotoxy(59, 12);
    printf("(6) ITA VEGETARIANO R$ 20,00");
    textcolor(LIGHTGRAY);
    gotoxy(59, 13);
    printf("pao, carne de soja, tomate, alface, cebola, champignon.");

    Sleep(250);

    textcolor(YELLOW);
    gotoxy(59, 15);
    printf("(7) ITA KONG R$ 25,00");
    textcolor(LIGHTGRAY);
    gotoxy(59, 16);
    printf("pao, carne 3x, bacon, cheddar 3x, tomate, banana frita.");

    Sleep(250);

    textcolor(YELLOW);
    gotoxy(59, 18);
    printf("(8) ITA GODZILLA R$ 25,00 ");
    textcolor(LIGHTGRAY);
    gotoxy(59, 19);
    printf("pao, carne 3x, ovo frito, bacon, cheddar 3x, tomate, cebola.");

    Sleep(250);

    textcolor(YELLOW);
    gotoxy(59, 21);
    printf("(9) ITA PICANHA R$ 30,00");
    textcolor(LIGHTGRAY);
    gotoxy(59, 22);
    printf("pao, picanha, alface, tomate, cebola, mucarela, barbecue.");

    textcolor(LIGHTRED);
    gotoxy(2, 27);
    printf("VOLTAR PARA CARDAPIO (0)");
    textcolor(WHITE);
    gotoxy(2, 28);
    printf("DIGITE UMA DAS OPCOES ACIMA : ");

}

void itensAcomp()
{

    textcolor(YELLOW);
    gotoxy(3, 12);
    printf("ITABATATINHA");
    textcolor(LIGHTGRAY);
    gotoxy(3, 13);
    printf("(1) P R$ 6,00");
    gotoxy(3, 14);
    printf("(2) M R$ 12,00");
    gotoxy(3, 15);
    printf("(3) G R$ 18,00");

    Sleep(250);

    textcolor(YELLOW);
    gotoxy(3, 17);
    printf("ITANUGGETS");
    textcolor(LIGHTGRAY);
    gotoxy(3, 18);
    printf("(4) P R$ 6,00");
    gotoxy(3, 19);
    printf("(5) M R$ 12,00");
    gotoxy(3, 20);
    printf("(6) G R$ 18,00");

    Sleep(250);

    textcolor(YELLOW);
    gotoxy(3, 22);
    printf("ITACEBOLITAS");
    textcolor(LIGHTGRAY);
    gotoxy(3, 23);
    printf("(7) P R$ 6,00");
    gotoxy(3, 24);
    printf("(8) M R$ 12,00");
    gotoxy(3, 25);
    printf("(9) G R$ 18,00");

    Sleep(250);

    textcolor(LIGHTRED);
    gotoxy(2, 27);
    printf("VOLTAR PARA CARDAPIO (0)");
    textcolor(WHITE);
    gotoxy(2, 28);
    printf("DIGITE UMA DAS OPCOES ACIMA : ");

}

void itensBeb()
{

    textcolor(YELLOW);
    gotoxy(3, 12);
    printf("ITAREFRI");
    textcolor(LIGHTGRAY);
    gotoxy(3, 13);
    printf("(1) ita-cola        R$ 4,50");
    gotoxy(3, 14);
    printf("(2) itaguarana      R$ 4,50");
    gotoxy(3, 15);
    printf("(3) italaranjinha   R$ 4,50");

    Sleep(250);

    textcolor(YELLOW);
    gotoxy(3, 17);
    printf("ITASUCAO");
    textcolor(LIGHTGRAY);
    gotoxy(3, 18);
    printf("(4) ita-limao    R$ 4,00");
    gotoxy(3, 19);
    printf("(5) ita-acerola  R$ 4,00");
    gotoxy(3, 20);
    printf("(6) ita-maracuja R$ 4,00");

    Sleep(250);

    textcolor(YELLOW);
    gotoxy(3, 22);
    printf("ITAGUA");
    textcolor(LIGHTGRAY);
    gotoxy(3, 23);
    printf("(7) sem gas R$ 2,00");
    gotoxy(3, 24);
    printf("(8) com gas R$ 2,50");
    gotoxy(3, 25);
    printf("(9) tonica  R$ 3,00");

    Sleep(250);

    textcolor(LIGHTRED);
    gotoxy(2, 27);
    printf("VOLTAR PARA CARDAPIO (0)");
    textcolor(WHITE);
    gotoxy(2, 28);
    printf("DIGITE UMA DAS OPCOES ACIMA : ");

}

void itensSob()
{

    textcolor(YELLOW);
    gotoxy(3, 12);
    printf("ITASORVETE");
    textcolor(LIGHTGRAY);
    gotoxy(3, 13);
    printf("(1) chocolate R$ 10,00");
    gotoxy(3, 14);
    printf("(2) baunilha  R$ 10,00");
    gotoxy(3, 15);
    printf("(3) morango   R$ 10,00");

    Sleep(250);

    textcolor(YELLOW);
    gotoxy(3, 17);
    printf("ITASHAKE");
    textcolor(LIGHTGRAY);
    gotoxy(3, 18);
    printf("(4) chocolate R$ 10,00");
    gotoxy(3, 19);
    printf("(5) baunilha  R$ 10,00");
    gotoxy(3, 20);
    printf("(6) morango   R$ 10,00");

    Sleep(250);

    textcolor(YELLOW);
    gotoxy(3, 22);
    printf("ITACASQUINHA");
    textcolor(LIGHTGRAY);
    gotoxy(3, 23);
    printf("(7) chocolate R$ 2,00");
    gotoxy(3, 24);
    printf("(8) baunilha  R$ 2,00");
    gotoxy(3, 25);
    printf("(9) misto     R$ 2,00");

    Sleep(250);

    textcolor(LIGHTRED);
    gotoxy(2, 27);
    printf("VOLTAR PARA CARDAPIO (0)");
    textcolor(WHITE);
    gotoxy(2, 28);
    printf("DIGITE UMA DAS OPCOES ACIMA : ");

}



void volteSmp()
{

    textcolor(RED);
    gotoxy(20, 3);
    printf("__      ______  _   _______ ______      _____ ______ __  __ _____  _____  ______ ");
    gotoxy(20, 4);
    printf("\\ \\    / / __ \\| | |__   __|  ____|    / ____|  ____|  \\/  |  __ \\|  __ \\|  ____|");
    gotoxy(20, 5);
    printf(" \\ \\  / / |  | | |    | |  | |__      | (___ | |__  | \\  / | |__) | |__) | |__   ");
    gotoxy(20, 6);
    printf("  \\ \\/ /| |  | | |    | |  |  __|      \\___ \\|  __| | |\\/| |  ___/|  _  /|  __|  ");
    gotoxy(20, 7);
    printf("   \\  / | |__| | |____| |  | |____     ____) | |____| |  | | |    | | \\ \\| |____ ");
    gotoxy(20, 8);
    printf("    \\/   \\____/|______|_|  |______|   |_____/|______|_|  |_|_|    |_|  \\_\\______|");

}



void pagamento()
{

    textcolor(RED);
    gotoxy(30, 5);
    printf(" _____        _____          __  __ ______ _   _ _______ ____  ");
    gotoxy(30, 6);
    printf("|  __ \\ /\\   / ____|   /\\   |  \\/  |  ____| \\ | |__   __/ __ \\ ");
    gotoxy(30, 7);
    printf("| |__) /  \\ | |  __   /  \\  | \\  / | |__  |  \\| |  | | | |  | |");
    gotoxy(30, 8);
    printf("|  ___/ /\\ \\| | |_ | / /\\ \\ | |\\/| |  __| | . ` |  | | | |  | |");
    gotoxy(30, 9);
    printf("| |  / ____ \\ |__| |/ ____ \\| |  | | |____| |\\  |  | | | |__| |");
    gotoxy(30, 10);
    printf("|_| /_/    \\_\\_____/_/    \\_\\_|  |_|______|_| \\_|  |_|  \\____/ ");

}

void modosPagamento()
{

    textcolor(LIGHTGREEN);
    gotoxy(15, 17);
    printf("Valor a ser pago pelo pedido, R$ %.2f", somaTotal);
    gotoxy(15, 19);
    printf("Valor a ser pago pela entrega, R$ %.2f", taxa);
    textcolor(YELLOW);
    gotoxy(15, 21);
    printf("(1) DINHEIRO");
    gotoxy(15, 22);
    printf("(%c) CARTAO",25);
    gotoxy(15, 23);
    textcolor(LIGHTGRAY);
    printf("(2) credito");
    gotoxy(15, 24);
    printf("(3) debito");

    Sleep(250);

    textcolor(WHITE);
    gotoxy(15, 15);
    printf("%s, como deseja efetuar o pagamento? ",nome);

}



void notaFiscal()
{

    textcolor(RED);
    gotoxy(25, 3);
    printf(" _   _  ____ _______         ______ _____  _____  _____          _      ");
    gotoxy(25, 4);
    printf("| \\ | |/ __ \\__   __|/\\     |  ____|_   _|/ ____|/ ____|   /\\   | |     ");
    gotoxy(25, 5);
    printf("|  \\| | |  | | | |  /  \\    | |__    | | | (___ | |       /  \\  | |     ");
    gotoxy(25, 6);
    printf("| . ` | |  | | | | / /\\ \\   |  __|   | |  \\___ \\| |      / /\\ \\ | |     ");
    gotoxy(25, 7);
    printf("| |\\  | |__| | | |/ ____ \\  | |     _| |_ ____) | |____ / ____ \\| |____ ");
    gotoxy(25, 8);
    printf("|_| \\_|\\____/  |_/_/    \\_\\ |_|    |_____|_____/ \\_____/_/    \\_\\______|");

}

void notaFiscalDesc()
{

    textcolor(BROWN);

    Sleep(250);

    gotoxy(15,19);
    printf("SUBTOTAL : R$ %.2f",somaTotal);


    somaTotal = ( somaTotal + taxa);

    troco = (valorRecebido - somaTotal);

    Sleep(250);

    gotoxy(15,21);
    printf("TAXA DE ENTREGA : R$ %.2f ",taxa);

    Sleep(250);

    gotoxy(15,23);

    printf("VALOR FINAL : R$ %.2f",somaTotal);

    Sleep(250);

    gotoxy(15,25);
    printf("PAGAMENTO : R$ %.2f", valorRecebido);

    Sleep(250);

    gotoxy(15,27);
    printf("TROCO : R$ %.2f", troco);

    Sleep(250);

    gotoxy(40,27);
    printf("ENDERECO PARA ENTREGA : %s, %s, %d. ",rua ,bairro, numeroCasa);

}

void doWhile()
{

    do
    {
        clrscr();

        cardapioInicial();

        categorias(); // RESULTA NA ESCOLHA DA CATEGORIA

        if (escolha_da_categoria == 1) // hamburguers
        {

            clrscr();

            borda();

            cardapioLateral();

            burgLateral();

            itensBurg();

            scanf("%d",&escolha);

            while ( escolha != 0){

            if (escolha == 1){
                somaTotal += h1;

            }else if (escolha == 2){
                somaTotal += h2;

            }else if (escolha == 3){
                somaTotal += h3;

            }else if (escolha == 4){
                somaTotal += h4;

            }else if (escolha == 5){
                somaTotal += h5;

            }else if (escolha == 6){
                somaTotal += h6;

            }else if (escolha == 7){
                somaTotal += h7;

            }else if (escolha == 8){
                somaTotal += h8;

            }else if (escolha == 9){
                somaTotal += h9;

            }else if ((escolha < 0 ) || (escolha > 9)){
                gotoxy(88,26);
                textcolor(LIGHTRED);
                printf("Essa escolha nao existe !!!");

                getch();
            }

            clrscr();

            borda();

            cardapioLateral();

            burgLateral();

            itensBurg();

            scanf("%d",&escolha);
        }
    }

        else if (escolha_da_categoria == 2) // acompanhamentos
        {

            clrscr();

            borda();

            cardapioLateral();

            acompLateral();

            itensAcomp();

            scanf("%d",&escolha);

            while ( escolha != 0){

            if (escolha == 1){
                somaTotal += a1;

            }else if (escolha == 2){
                somaTotal += a2;

            }else if (escolha == 3){
                somaTotal += a3;

            }else if (escolha == 4){
                somaTotal += a4;

            }else if (escolha == 5){
                somaTotal += a5;

            }else if (escolha == 6){
                somaTotal += a6;

            }else if (escolha == 7){
                somaTotal += a7;

            }else if (escolha == 8){
                somaTotal += a8;

            }else if (escolha == 9){
                somaTotal += a9;

            }else if ((escolha < 0 ) || (escolha > 9)){
                gotoxy(88,26);
                textcolor(LIGHTRED);
                printf("Essa escolha nao existe !!!");

                getch();

            }

            clrscr();

            borda();

            cardapioLateral();

            acompLateral();

            itensAcomp();

            scanf("%d",&escolha);

        }

      }

        else if (escolha_da_categoria == 3) // bebidas
        {

            clrscr();

            borda();

            cardapioLateral();

            bebidaLateral();

            itensBeb();

            scanf("%d",&escolha);

            while ( escolha != 0){

            if (escolha == 1){
                somaTotal += b1;

            }else if (escolha == 2){
                somaTotal += b2;

            }else if (escolha == 3){
                somaTotal += b3;

            }else if (escolha == 4){
                somaTotal += b4;

            }else if (escolha == 5){
                somaTotal += b5;

            }else if (escolha == 6){
                somaTotal += b6;

            }else if (escolha == 7){
                somaTotal += b7;

            }else if (escolha == 8){
                somaTotal += b8;

            }else if (escolha == 9){
                somaTotal += b9;

            }else if ((escolha < 0 ) || (escolha > 9)){
                gotoxy(88,26);
                textcolor(LIGHTRED);
                printf("Essa escolha nao existe !!!");

                getch();

            }

            clrscr();

            borda();

            cardapioLateral();

            bebidaLateral();

            itensBeb();

            scanf("%d",&escolha);

            }
        }

        else if (escolha_da_categoria == 4) // sobremesas
        {

            clrscr();

            borda();

            cardapioLateral();

            sobLateral();

            itensSob();

            scanf("%d",&escolha);

            while ( escolha != 0){

            if (escolha == 1){
                somaTotal += s1;

            }else if (escolha == 2){
                somaTotal += s2;

            }else if (escolha == 3){
                somaTotal += s3;

            }else if (escolha == 4){
                somaTotal += s4;

            }else if (escolha == 5){
                somaTotal += s5;

            }else if (escolha == 6){
                somaTotal += s6;

            }else if (escolha == 7){
                somaTotal += s7;

            }else if (escolha == 8){
                somaTotal += s8;

            }else if (escolha == 9){
                somaTotal += s9;

            }else if ((escolha < 0 ) || (escolha > 9)){
                gotoxy(88,26);
                textcolor(LIGHTRED);
                printf("Essa escolha nao existe !!!");

                getch();
            }

            clrscr();

            borda();

            cardapioLateral();

            sobLateral();

            itensSob();

            scanf("%d",&escolha);

            }

        }

        else if ((escolha_da_categoria == 5) && (somaTotal !=0))
         {

            clrscr();

            borda();

            pagamento();

            modosPagamento();

            scanf("%d", &escolha);

            if(escolha == 1){

                clrscr();

                borda();

                pagamento();

                textcolor(WHITE);
                gotoxy(15,17);
                printf("Insira o valor do pagamento:  ");
                textcolor(GREEN);
                scanf("%f",&valorRecebido);

                  if(valorRecebido >= somaTotal + taxa){

                        clrscr();

                        borda();

                        notaFiscal();

                        ITA();

                        notaFiscalDesc();

                         Sleep(10000);

                        clrscr();

                        borda();

                        volteSmp();

                        ITA();

                        Sleep(5000);
                        break;

                    }

                   else if(valorRecebido < somaTotal + taxa ){

                          clrscr();

                          borda();

                          ITA();

                          textcolor(LIGHTRED);
                          gotoxy(27,20);
                          printf("%s, sua compra nao foi efetuada, fundos insuficientes !!!",nome);

                           Sleep(5000);

                           clrscr();

                           borda();

                           volteSmp();

                            ITA();

                            Sleep(5000);

                            break;



                    }
            }

           if((escolha == 2) || (escolha == 3)){

           valorRecebido = somaTotal + 5;

           clrscr();

           borda();

           notaFiscal();

            ITA();

           notaFiscalDesc();

            Sleep(10000);

            clrscr();

            borda();

            volteSmp();

            ITA();

            Sleep(5000);
            break;

           }

           else if (somaTotal == 0){

             clrscr();

             borda();

             volteSmp();

             ITA();

             textcolor(WHITE);
             gotoxy(27,20);
             printf("%s, a sua compra nao foi aprovada pois nenhum item do cardapio foi selecionado.",nome);

             Sleep(5000);
             break;
           }
        }
        else if (escolha_da_categoria == 0){

             clrscr();

             borda();

             volteSmp();

             ITA();

             textcolor(WHITE);
             gotoxy(27,20);
             printf("%s, sua compra de R$ %.2f foi cancelada com sucesso !!!",nome, somaTotal);

             Sleep(5000);
             break;

        }

    }while (escolha_da_categoria != 0 || escolha_da_categoria!= 5);

}

int main()
{
    bemVindo();

    Sleep(1000);

     ITA();

    Sleep(1000);

    informe();

    doWhile();

    Sleep(10000);

    gotoxy(3,29);
    return 0;
}
