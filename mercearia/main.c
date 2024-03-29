#include <stdio.h>
#include <stdlib.h>

int main(){
int produto, quantidade;
float valor, valorfinal;
scanf("%d%d",&produto, &quantidade);
if(produto==1){
    valor=quantidade*5.30;}
 if(produto==2){
     valor=quantidade*6.00;}
  if(produto==3){
      valor=quantidade*3.20;}
   if(produto==4){
       valor=quantidade*2.50;}
    if((quantidade>=15)||(valor>=40)){
        valorfinal=0.85*valor;
printf("R$ %.2f\n",valorfinal);}
else printf("R$ %.2f\n",valor);
return 0;}
