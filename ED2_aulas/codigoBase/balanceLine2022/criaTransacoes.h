/*
 * criaTransacoes.h
 *
 *  Modified on: Sep 12, 2021
 *      Author: raphael oliveira
 */

/* Grava dados formatados num arquivo TRANSAÇÕES */

#include <stdio.h> /* define FILE */
#include <stdlib.h>

void criaTransacoes()
{
    FILE *fTransacoes; /* ponteiro para arquivo */

    fTransacoes = fopen("Transacoes.dat", "wb");

    if (fTransacoes == NULL)
    {
        printf("\n Erro ao abrir o arquivo TRANSACOES");
        exit(1);
    }

    TTransacao *t1 = Transacao(11, 'E', "", "");
    TTransacao *t2 = Transacao(17, 'M', "Nome", "Maria");
    TTransacao *t3 = Transacao(18, 'I', "Andrea", "02/04/1990");
    TTransacao *t4 = Transacao(25, 'I', "Jonas", "03/07/2002");
    TTransacao *t5 = Transacao(56, 'I', "Andre", "12/11/2011");
    TTransacao *t6 = Transacao(58, 'I', "Luis", "06/11/2002");
    TTransacao *t7 = Transacao(59, 'I', "soca", "06/11/2002");
    TTransacao *t8 = Transacao(60, 'I', "fofo", "06/11/2002");
    TTransacao *t9 = Transacao(80, 'I', "muzan", "06/11/2002");

    salvaTransacao(t1, fTransacoes);
    salvaTransacao(t2, fTransacoes);
    salvaTransacao(t3, fTransacoes);
    salvaTransacao(t4, fTransacoes);
    salvaTransacao(t5, fTransacoes);
    salvaTransacao(t6, fTransacoes);
    salvaTransacao(t7, fTransacoes);
    salvaTransacao(t8, fTransacoes);
    salvaTransacao(t9, fTransacoes);

    fclose(fTransacoes);
}
