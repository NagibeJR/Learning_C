#include <stdio.h>
int main() {
int n1,n2,n3,menor;
scanf("%d%d%d",&n1,&n2,&n3);
menor = n1;
if(n2 < menor){
menor = n2;
}
if(n3 < menor){
menor = n3;
}
printf("%d",menor);
return 0;
}
