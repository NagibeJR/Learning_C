#include <stdio.h>
#include <stdlib.h>

int main(){
int n1, n2, n3;
scanf("%d%d%d",&n1, &n2, &n3);
if(n1==n2&&n2==n3) {
printf("1");
}else if(n1!=n2&&n2!=n3){
printf ("2");
}else if((n1==n2)^(n2==n3)^(n1==n3)){
printf("3");
}
return 0;}
