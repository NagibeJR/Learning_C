
#include <stdio.h>
#include <stdlib.h>

typedef struct node{
int dado;
struct node *pai;
struct node *filhoEsq;
struct node *filhoDir;
}tipoNode;

tipoNode *achou;

/*Fun��o para criar um n�*/
tipoNode* criaNo(int n, tipoNode *noPai){
tipoNode *novo;
novo = (tipoNode*) malloc(sizeof(tipoNode));
novo->dado = n;
novo->filhoDir = NULL;
novo->filhoEsq = NULL;
novo->pai = noPai;
return novo;
}


void exibeInOrdem(tipoNode *atual){
if(atual != NULL){
    exibeInOrdem(atual->filhoEsq);
    printf("  %8d",atual->dado);
    exibeInOrdem(atual->filhoDir);
}
}

void buscaNo(tipoNode *atual, int n){
 if(atual != NULL){
    if(atual->dado == n){
        achou = atual;
        return;
    }
    buscaNo(atual->filhoEsq, n);
    buscaNo(atual->filhoDir, n);
 }
}

void exibePreOrdem(tipoNode *atual){
if(atual != NULL){
    printf("  %8d",atual->dado);
    exibePreOrdem(atual->filhoEsq);
    exibePreOrdem(atual->filhoDir);
}
}

void exibePosOrdem(tipoNode *atual){
if(atual != NULL){
    exibePosOrdem(atual->filhoEsq);
    exibePosOrdem(atual->filhoDir);
    printf("  %8d",atual->dado);
}
}

void excluirArv(tipoNode *raiz){
    if(raiz!=NULL){
        excluirArv(raiz->filhoEsq);
        excluirArv(raiz->filhoDir);
        free(raiz);
    }
}

char getPosNo(tipoNode *no){
  if(no->pai->filhoEsq == no)
    return 'e';
  else
    return 'd';
}

/*O retorno dessa fun��o deve ser o endere�o do filho que ocupou a posi��o do n� removido
para no caso da remo��o da raiz a vari�vel local ao programa principal poder ser atualizada*/
tipoNode* removeNo(tipoNode* no){
if(no != NULL){
    if(no->filhoEsq != NULL){ /*Tem filho esquerdo*/
        if(no->filhoDir != NULL){ /*Tem filho direito*/
            printf("\nErro! O nao pode ser removido por ter 2 filhos!");
            return NULL;
        }
    else{ /*Situacao em que s� tem filho esquerdo*/
            if(no->pai == NULL){ /*Se o n� � a raiz*/
                tipoNode *antigo = no;
                no = no->filhoEsq;
                no->pai = NULL;
                free(antigo);
                return no;
                }
                char posicao = getPosNo(no); /*Qual a posicao do n� em rel��o ao pr�prio pai*/
                if(posicao == 'e')
                    no->pai->filhoEsq = no->filhoEsq;
                else
                    no->pai->filhoDir = no->filhoEsq;
                no->filhoEsq->pai = no->pai;
                tipoNode *aux = no->filhoEsq;
                free(no);
                return aux;
        }
    }
    else{ /*S� tem filho da direita ou filho nenhum*/
            if(no->pai == NULL){
                tipoNode *antigo = no;
                no = no->filhoDir;
                if(no != NULL)
                     no->pai = NULL;
                free(antigo);
                return no;
            }
        else{
            char posicao = getPosNo(no);
            if(posicao == 'e')
                no->pai->filhoEsq = no->filhoDir;
            else
                no->pai->filhoDir = no->filhoDir;
            if(no->filhoDir != NULL)
                no->filhoDir->pai = no->pai;
            tipoNode *aux = no->filhoDir;
            free(no);
            return aux;
        }
    }
}
return NULL;
}


void main(){
tipoNode *raiz = NULL, *resposta;
int op, valor, valorPai;
char filhoEouD;

do{
    printf("\n Escolha sua opcao");
    printf("\n 1 - Insere um no na arvore");
    printf("\n 2 - Exibe a arvore em ordem simetrica");
    printf("\n 3 - Exibe a arvore em pre ordem");
    printf("\n 4 - Exibe a arvore em pos ordem");
    printf("\n 5 - Mostra se um no existe na arvore");
    printf("\n 6 - Remove no (folha ou com um filho apenas)");
    printf("\n 0 - Encerra o programa");
    printf("\nDigite sua opcao:");
    scanf("%d",&op);
    switch(op){
    case 1:printf("\nDigite o dado que deseja incluir: ");
    scanf("%d",&valor);
    if(raiz == NULL) /*Esta sendo criado o primeiro valor da arvore*/
        raiz = criaNo(valor, NULL);
    else{
        printf("\nDigite o pai do no:");
        scanf("%d",&valorPai);
        achou = NULL;
        buscaNo(raiz,valorPai);
        if(achou == NULL)
                printf("\nPai nao encontrado. Insercao nao feita");
        else{
            printf("\nDigite se o no sera filho da esquerda <e> ou da direita <d> : ");
            fflush(stdin);
            scanf("%c",&filhoEouD);
            if(filhoEouD == 'e'){
                if(achou->filhoEsq != NULL)
                       printf("\nNo nao inserido. Pai ja possui filho da esquerda");
                else{
                    achou->filhoEsq = criaNo(valor, achou);
                    printf("\nNo criado com sucesso!");
                }
            }
            else{
                if(achou->filhoDir != NULL)
                    printf("\nNo nao inserido. Pai ja possui filho da direita.");
                else{
                    achou->filhoDir = criaNo(valor, achou);
                    printf("\nNo criado com sucesso!");
                }
            }
        }
    }
        break;
    case 2: printf("\nExibindo a arvore in-ordem:\n");
    exibeInOrdem(raiz);
    break;
    case 3: printf("\n\n\nExibindo a arvore pre-ordem\n:");
    exibePreOrdem(raiz);
    break;
    case 4: printf("\n\n\nExibindo a arvore pos-ordem\n");
    exibePosOrdem(raiz);
    break;
    case 5: printf("\nDigite que dado deseja procurar na arvore: ");
    scanf("%d",&valor);
    achou = NULL;
    buscaNo(raiz,valor);
    if(achou)
        printf("\nNo encontrado com sucesso");
    else
        printf("\nNo nao encontrado na arvore");
    break;
    case 6: printf("\nDigite o dado que deseja remover: ");
    scanf("%d",&valor);
    achou = NULL;
    buscaNo(raiz, valor);
    if(achou == NULL)
        printf("\n No nao encontrado.");
    else{
        if(achou == raiz){
           raiz = removeNo(achou);
           printf("\nNo removido com sucesso!");
        }else
           if(removeNo(achou) != NULL)
              printf("\nNo removido com sucesso!");
        }
    break;
    case 0: printf("\nEncerrando programa...");
    excluirArv(raiz);
    raiz = NULL;
    break;
    default: printf("\nOpcao invalida! Escolha uma nova opcao: ");
    }
}while(op != 0);
}

