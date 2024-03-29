#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include "intercalacao.h"
#include "nomes.h"
#include "cliente.h"
#include <limits.h>
#include <dirent.h>
#include <string.h>

typedef struct vetor {
    TCliente *cli;
    FILE *f;
} TVet;

int has_txt_extension(char const *name) {
    size_t len = strlen(name);
    return len > 4 && strcmp(name + len - 4, ".txt") == 0;
}

int name_starts_with_p(char const *name) {
    size_t len = strlen(name);
    return len > 1 && strncmp(name, "p", 1) == 0;
}

TNomes *le_nomes_particoes(){
    TNomes* nomes_particoes = NULL;
    DIR *dr;
    struct dirent *en;
    dr = opendir(".");
    if (dr) {
        while ((en = readdir(dr)) != NULL) {
            if ((has_txt_extension(en->d_name)) && (name_starts_with_p(en->d_name))) {
                nomes_particoes = insere_inicio(nomes_particoes, en->d_name);
            }
        }
        closedir(dr);
    }
    return nomes_particoes;
}

void imprime_arquivo(char *name) {
    FILE *arq; //declara ponteiro para arquivo
    // abre arquivo para leitura
    arq = fopen(name, "r");
    if (arq != NULL) {// checa se não deu erro na abertura do arquivo
        char linha[150];
        fgets (linha, 150, arq);
        while (!feof(arq)) {//testa se chegou ao final do arquivo
            printf("%s", linha);
            fgets (linha, 150, arq);
        }
        fclose(arq); //fecha arquivo
    } else printf("Erro ao abrir arquivo\n");
}


void intercalacao_basico(char *nome_arquivo_saida, int num_p, TNomes *nome_particoes) {

    int fim = 0; //variavel que controla fim do procedimento
    FILE *out; //declara ponteiro para arquivo

    //abre arquivo de saida para escrita
    if ((out = fopen(nome_arquivo_saida, "w")) == NULL) {
        printf("Erro ao abrir arquivo de sa?da\n");
    } else {
        //cria vetor de particoes
        TVet v[num_p];

        //abre arquivos das particoes, colocando variavel de arquivo no campo f do vetor
        //e primeiro cliente do arquivo no campo cli do vetor
        for (int i = 0; i < num_p; i++) {
            v[i].f = fopen(nome_particoes->nome, "r");
            if (v[i].f != NULL) {
                TCliente *c = le_cliente(v[i].f);
                if (c == NULL) {
                    //arquivo estava vazio
                    //coloca HIGH VALUE nessa posi??o do vetor
                    v[i].cli = cliente(INT_MAX, "");
                } else {
                    //conseguiu ler cliente, coloca na posicao atual do vetor
                    v[i].cli = c;
                }
            } else {
                fim = 1;
            }
            nome_particoes = nome_particoes->prox;
        }

        while (!(fim)) { //conseguiu abrir todos os arquivos
            int menor = INT_MAX;
            int pos_menor;
            //encontra o cliente com menor chave no vetor
            for (int i = 0; i < num_p; i++) {
                if (v[i].cli->cod_cliente < menor) {
                    menor = v[i].cli->cod_cliente;
                    pos_menor = i;
                }
            }
            if (menor == INT_MAX) {
                fim = 1; //terminou processamento
            } else {
                //salva cliente no arquivo de saida
                salva_cliente(v[pos_menor].cli, out);
                //atualiza posicao pos_menor do vetor com proximo cliente do arquivo
                TCliente *c = le_cliente(v[pos_menor].f);
                if (c == NULL) {
                    //arquivo estava vazio
                    //coloca HIGH VALUE nessa posicao do vetor
                    v[pos_menor].cli = cliente(INT_MAX, "");
                } else {
                    v[pos_menor].cli = c;
                }
            }
        }

        //fecha arquivos das particoes de entrada
        for (int i = 0; i < num_p; i++) {
            fclose(v[i].f);
        }
        //fecha arquivo de saida
        fclose(out);
    }
}

int main() {
    TNomes *nomes_particoes = NULL;
    nomes_particoes = le_nomes_particoes();
    intercalacao_basico("saida.txt", conta_nomes(nomes_particoes), nomes_particoes);
    imprime_arquivo("saida.txt");
}