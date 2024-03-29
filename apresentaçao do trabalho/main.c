#include <stdio.h>
#include <stdlib.h>

int main(){
int n1, n2, n3, n4, n5, a, b, c;
scanf("%d%d%d%d%d",&n1, &n2, &n3, &n4, &n5);
a=0;
b=0;
c=0;
if((n1==1)||(n2==1)){
a=1;
}
if((n3==1)&&(n4==1)){
b=1;
}
if(n5==1){
c=1;
}
if ((a==1)&&(b==1)&&(c==1)){
printf("AVALIADO\n");
}
else {
printf("0\n");
}
return 0;}
