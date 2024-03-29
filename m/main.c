#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int n,s,m,menor;
    scanf("%d%d",&n,&s);
    menor = s;
    for(int i = 1;i<=n;i++){
        scanf("%d",&m);
        s = s+ m;
        if(s<menor){
            menor = s;
        }
    }
    printf("%d",menor);
    return 0;
}
