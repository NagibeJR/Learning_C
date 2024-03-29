#include <stdio.h>
#include <stdlib.h>

int main(void)
{
float agua, preco;
float gasto,valoragua,valoresgoto,valorfinal;
scanf("%f%f", &agua, &preco);
gasto = (agua*1000);
valoragua = (gasto*preco);
valoresgoto = (0.8*valoragua);
valorfinal = (valoragua + valoresgoto);
printf("%.2f\n",valoragua);
printf("%.2f\n",valoresgoto);
printf("%.2f", valorfinal);
return 0;
}
