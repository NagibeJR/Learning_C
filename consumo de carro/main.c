#include <stdio.h>
#include <stdlib.h>

 int main(void) {
 float preco, valor,litros;
 scanf("%f%f",&preco,&valor);
 litros = (preco/valor);
 printf("Você conseguiu colocar %.2f litros!\n", litros);
 return 0;
 }
