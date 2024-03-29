#include <stdio.h>
#include <stdlib.h>

int main(){
float n1, n2, n3, media;
scanf("%f%f%f",&n1, &n2, &n3);
media=(n1+n2+n3)/3;
if(media>=7){
    printf("aprovado\n");}
 else if(media<3){
     printf("reprovado\n");}
  else if((3<=media)&&(media<7)){
      printf("prova final\n");}
return 0;}
