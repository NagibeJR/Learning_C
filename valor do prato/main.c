#include <stdio.h>
#include <stdlib.h>

 int main(void) {
 float peso, valor;
 scanf("%f",&peso);
 valor = (peso*20.00);
 printf("O valor do prato será: R$ %.2f\n", valor);
 return 0;
 }
