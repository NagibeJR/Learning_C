#include <stdio.h>
#include <stdlib.h>

int main(){
long num;
scanf("%ld",&num);
if((num %2 == 0) &&(num > 0)){
    printf("POSITIVO PAR\n");
}
else if ((num %2 == 1) &&(num > 0)){
    printf("POSITIVO IMPAR\n");
}
else if ((num %2 == 0) &&(num < 0)){
    printf("NEGATIVO PAR\n");
}
else if ((num %2 == -1) &&(num < 0)){
    printf("NEGATIVO IMPAR\n");
}
else {
    printf("NULO\n");
}
return 0;}
