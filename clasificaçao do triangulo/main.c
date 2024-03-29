#include <stdio.h>
#include <stdlib.h>

int main(){
int a, b, c;
scanf("%d%d%d",&a, &b, &c);
if((a==b)&&(a!=c)) {
printf("isosceles\n");
}
else if((a!=b)&&(a==c)) {
printf("isosceles\n");
}
else if((c==b)&&(a!=c)) {
printf("isosceles\n");
}
else if((a==b)&&(b==c)){
printf("equilatero\n");
}
else if((a!=b)&&(b!=c)){
printf("escaleno\n");
}

return 0;}
