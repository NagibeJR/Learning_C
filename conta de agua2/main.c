#include <stdio.h>
#include <stdlib.h>

int main(){
int gasto, vfinal;
scanf("%d",&gasto);
if(gasto<=10){
    vfinal=7;}
 if(gasto>=11&&gasto<=30){
     vfinal=(((gasto-10)*1)+7);}
  if(gasto>=31&&gasto<=100){
      vfinal=(((gasto-30)*2)+7+20);}
   if(gasto>=101){
       vfinal=(((gasto-100)*5)+7+20+140);}
printf("%d\n",vfinal);
return 0;}
