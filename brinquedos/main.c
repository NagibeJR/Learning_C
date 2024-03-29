#include <stdio.h>
#include <stdlib.h>

int main(){
int h, i, a, b, c, nbrinquedos;
scanf("%d%d",&h, &i);
a=0;
b=0;
c=0;
if((h>=140)&&(i>=14)){
a=1;}
if((h>=150)&&(i>=12)){
b=1;}
if((h>=170)||(i>=16)){
c=1;}
nbrinquedos=a+b+c ;
printf("%d\n",nbrinquedos);
return 0;}
