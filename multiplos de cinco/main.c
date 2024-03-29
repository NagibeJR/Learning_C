#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int main(){
int m, n, result;
int cont = 1;
scanf("%d%d",&m,&n);
while (result<n){
result = (m / cont);
cont++;
if(result%5 == 0){
printf("%d|",result);
 }
if(n%5 == 0){
printf("%d",result);
}
}
}
