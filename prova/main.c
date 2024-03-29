#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
  int i,Matriz[20];

  for(i=0;i<20;i++)
    scanf("%d",&Matriz[i]);
  float Maior=Matriz[0],Menor=Matriz[0],Media;

  for(i=1;i<20;i++)
    if (Matriz[i]>Maior)
    Maior = Matriz[i];

  for(i=1;i<20;i++)
    if(Matriz[i]<Menor)
    Menor= Matriz[i];

    Media = (Maior + Menor) / 2;
    printf("Media: %.2f\n",Media);
    for(i=0;i<20;i++)
        if(Matriz[i]>Media)
        printf("%d\n",Matriz[i]);

    return 0;
}
