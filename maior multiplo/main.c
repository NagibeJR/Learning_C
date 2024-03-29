#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int main(){
int m, n, mult;
int cont = 1;
scanf("%d%d",&m,&n);
if (m > n){
    printf("sem multiplos menores que %d",n);
}
if(m <= n){
if (mult <= n){
 while (cont <= (n/m)){
mult = m * cont;
cont++;
 }
}
printf("%d",mult);
}
}
