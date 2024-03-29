#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <limits.h>
#include <stdlib.h>
#include <string.h>

#include "encadeamento_exterior.h"
#include "lista_compartimentos.h"
#include "cliente.h"

int tamanho_do_arquivo(FILE *arquivo)
{
    fseek(arquivo, 0L, SEEK_END);
    return (ftell(arquivo) / tamanho_compartimento());
}

void cria_hash(char *nome_arquivo_hash, int tam)
{
    ListaCompartimentos *listaComp = (ListaCompartimentos *)malloc(sizeof(ListaCompartimentos));
    listaComp->qtd = tam;
    listaComp->lista = (CompartimentoHash **)malloc(sizeof(CompartimentoHash *) * (tam));
    int i;
    for (i = 0; i < tam; i++)
    {
        listaComp->lista[i] = compartimento_hash(-1);
    }
    salva_compartimentos(nome_arquivo_hash, listaComp);
}

int busca(int cod_cli, char *nome_arquivo_hash, char *nome_arquivo_dados)
{
    Cliente *cliente;

    FILE *entradaHash = fopen(nome_arquivo_hash, "rb");
    FILE *entradaDados = fopen(nome_arquivo_dados, "rb");
    ListaCompartimentos *listaComp_hash = (ListaCompartimentos *)malloc(sizeof(ListaCompartimentos));
    ListaCompartimentos *listaComp_dados;
    listaComp_hash->qtd = tamanho_do_arquivo(entradaHash);
    fseek(entradaHash, tamanho_compartimento() * (cod_cli % listaComp_hash->qtd), SEEK_SET);
    int aux = le_compartimento(entradaHash)->prox;
    fclose(entradaHash);

    fseek(entradaDados, aux * tamanho_cliente(), SEEK_SET);
    cliente = le_cliente(entradaDados);

    if (cod_cli == cliente->cod_cliente && cliente->status == 1)
    {
        fclose(entradaDados);
        return aux;
    }
    else if (cod_cli == cliente->cod_cliente && cliente->status == 0)
    {
        fclose(entradaDados);
        return -1;
    }
    do
    {
        aux = cliente->prox;
        fseek(entradaDados, aux * tamanho_cliente(), SEEK_SET);
        cliente = le_cliente(entradaDados);
        if (cod_cli == cliente->cod_cliente && cliente->status == 1)
        {
            fclose(entradaDados);
            return aux;
        }
        else if (cliente->cod_cliente == cod_cli && cliente->prox != -1 && cliente->status == 0)
        {
            continue;
        }
        else if (cod_cli == cliente->cod_cliente && cliente->status == 0)
        {
            fclose(entradaDados);
            return -1;
        }
        else if (cliente->prox == -1 && cliente->cod_cliente != cod_cli)
        {
            fclose(entradaDados);
            return -1;
        }
    } while (cliente->prox != -1);
    fclose(entradaDados);

    return INT_MAX;
}

int insere(int cod_cli, char *nome_cli, char *nome_arquivo_hash, char *nome_arquivo_dados, int num_registros)
{
    FILE *arquivoHash = fopen(nome_arquivo_hash, "rb+");
    if (arquivoHash == NULL)
    {
        printf("\n Erro ao tentar acessar o arquivo");
        return 0;
    }

    FILE *arquivoDados = fopen(nome_arquivo_dados, "rb+");
    if (arquivoDados == NULL)
    {
        printf("\n Erro ao tentar acessar o arquivo");
        return 0;
    }

    fseek(arquivoHash, (cod_cli % 7) * tamanho_compartimento(), 0);
    CompartimentoHash *compH = le_compartimento(arquivoHash);

    if (compH->prox != -1)
    {
        rewind(arquivoDados);
        fseek(arquivoDados, compH->prox * tamanho_cliente(), 0);
        Cliente *cli = le_cliente(arquivoDados);

        if (cli->cod_cliente == cod_cli)
        {
            fclose(arquivoHash);
            fclose(arquivoDados);
            return -1;
        }

        int auxP;

        while (cli->prox != -1 && cli->status != LIBERADO)
        {
            rewind(arquivoDados);
            fseek(arquivoDados, cli->prox * tamanho_cliente(), 0);
            auxP = cli->prox;
            cli = le_cliente(arquivoDados);
        }
        if (cli->status != LIBERADO)
        {

            compH->prox = num_registros;
            cli->prox = compH->prox;

            rewind(arquivoDados);
            fseek(arquivoDados, auxP * tamanho_cliente(), 0);
            salva_cliente(cli, arquivoDados);

            Cliente *novoCli = (Cliente *)malloc(sizeof(Cliente));
            novoCli->cod_cliente = cod_cli;
            strcpy(novoCli->nome, nome_cli);
            novoCli->prox = -1;
            novoCli->status = OCUPADO;

            salva_cliente(novoCli, arquivoDados);
        }
        else
        {

            compH->prox = auxP;

            Cliente *novoCli = (Cliente *)malloc(sizeof(Cliente));
            novoCli->cod_cliente = cod_cli;
            strcpy(novoCli->nome, nome_cli);
            novoCli->prox = cli->prox;
            novoCli->status = OCUPADO;

            rewind(arquivoDados);
            fseek(arquivoDados, compH->prox * tamanho_cliente(), 0);
            salva_cliente(novoCli, arquivoDados);
        }
    }
    else
    {
        Cliente *cli = (Cliente *)malloc(sizeof(Cliente));
        cli->cod_cliente = cod_cli;
        strcpy(cli->nome, nome_cli);
        cli->prox = -1;
        cli->status = OCUPADO;

        compH->prox = num_registros;

        rewind(arquivoDados);
        fseek(arquivoDados, compH->prox * tamanho_cliente(), 0);
        salva_cliente(cli, arquivoDados);

        rewind(arquivoHash);
        fseek(arquivoHash, (cod_cli % 7) * tamanho_compartimento(), 0);
        salva_compartimento(compH, arquivoHash);
    }

    fclose(arquivoHash);
    fclose(arquivoDados);
    return compH->prox;
}

int exclui(int cod_cli, char *nome_arquivo_hash, char *nome_arquivo_dados)
{
    FILE *arquivoHash = fopen(nome_arquivo_hash, "rb+");
    if (arquivoHash == NULL)
    {
        printf("\n Erro ao tentar acessar o arquivo");
        return 0;
    }

    FILE *arquivoDados = fopen(nome_arquivo_dados, "rb+");
    if (arquivoDados == NULL)
    {
        printf("\n Erro ao tentar acessar o arquivo");
        return 0;
    }

    fseek(arquivoHash, (cod_cli % 7) * tamanho_compartimento(), 0);
    CompartimentoHash *compH = le_compartimento(arquivoHash);
    int excluirP;
    if (compH->prox != -1)
    {
        rewind(arquivoDados);
        fseek(arquivoDados, compH->prox * tamanho_cliente(), 0);
        Cliente *cli = le_cliente(arquivoDados);

        int auxP;
        if (cli->cod_cliente == cod_cli)
        {
            excluirP = compH->prox;
            cli->status = LIBERADO;
            rewind(arquivoDados);
            fseek(arquivoDados, compH->prox * tamanho_cliente(), 0);
            salva_cliente(cli, arquivoDados);

            fclose(arquivoHash);
            fclose(arquivoDados);
            return excluirP;
        }

        while (cli->prox != -1)
        {
            rewind(arquivoDados);
            fseek(arquivoDados, cli->prox * tamanho_cliente(), 0);
            auxP = cli->prox;
            cli = le_cliente(arquivoDados);
            if (cli->cod_cliente == cod_cli)
                break;
        }
        if (cli->status != LIBERADO && cli->cod_cliente == cod_cli)
        {
            excluirP = auxP;
            cli->status = LIBERADO;
            rewind(arquivoDados);
            fseek(arquivoDados, excluirP * tamanho_cliente(), 0);
            salva_cliente(cli, arquivoDados);
        }
        else
        {
            fclose(arquivoHash);
            fclose(arquivoDados);
            return -1;
        }
    }
    else
    {
        fclose(arquivoHash);
        fclose(arquivoDados);
        return -1;
    }

    fclose(arquivoHash);
    fclose(arquivoDados);
    return excluirP;
}
