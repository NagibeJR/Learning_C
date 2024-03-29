#include <stdio.h>
#include <stdlib.h>

int main(void)
{
int dias, km;
double valorkm,valordia,valor,valorfinal;
scanf("%d%d", &dias, &km);
valorkm = (km*0.01);
valordia = (dias*30);
valor = (valordia + valorkm);
valorfinal = valor - (0.1*valor);
printf("%.2lf", valorfinal);
return 0;
}
