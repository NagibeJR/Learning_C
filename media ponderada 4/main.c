#include <stdio.h>
#include <stdlib.h>

 int main(void) {
 float n1, n2, n3,n4;
 float media;
 scanf("%f%f%f%f",&n1,&n2,&n3,&n4);
 media = (n1*2+n2*2+n3*3+n4*3)/10;
 printf("A média ponderada será: %.2f\n", media);
 return 0;
 }

