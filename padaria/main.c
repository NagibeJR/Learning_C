#include <stdio.h>
#include <stdlib.h>

 int main(void) {
 int broa, pao;
 float vbroa, vpao, total, poupanca;
 scanf("%d%d",&broa,&pao);
 vbroa = (broa*1.50);
 vpao = (pao*0.20);
 total = vbroa + vpao;
 poupanca = (0.1*total);
 printf("O valor a ser guardado na poupança será R$ %.2f\n", poupanca);
 return 0;
 }
