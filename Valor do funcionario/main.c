#include <stdio.h>
#include <stdlib.h>

int main()
{
int numero, horas;
float ganho, salario;
scanf("%d",&numero);
scanf("%d",&horas);
scanf("%f",&ganho);
salario = (horas * ganho);
printf("NUMBER = %d\n",numero);
printf("SALARY = R$.%2f", salario);
return 0;
}
