#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main(){
int n1,n2,contador;
scanf("%d%d",&n1,&n2);
contador=n1;
while (contador<=n2){
if(contador%2==1){
printf("%d\n",contador);
}
contador+=1;
}
return 0;
}

