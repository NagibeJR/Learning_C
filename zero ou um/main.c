#include <stdio.h>
#include <stdlib.h>

int main(){
int a, b, c;
scanf("%d%d%d",&a, &b, &c);
if((a!=b)&&(a!=c)&&(b==c)){
printf("A\n");}
else if((b!=a)&&(b!=c)&&(a==c)){
printf("B\n");}
else if((c!=a)&&(c!=b)&&(b==a)){
printf("C\n");}
else {
printf("*\n");}
return 0;}
