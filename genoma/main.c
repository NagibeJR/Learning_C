#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define MAX_N 50001

int genoma[MAX_N];
int finalPos[MAX_N];

troca(int *x, int *y)
{
int z = *x;
*x = *y;
*y = z;
}

reverso(int i, int j)
{
int distancia = j - i + 1;
int metadeDistancia = distancia / 2;
int d;

for (d = 0; d < metadeDistancia; ++d) {
int offset = distancia - 2*d - 1;

finalPos[genoma[i + d]] += offset;
finalPos[genoma[j - d]] -= offset;
    }

for (d = 0; d < metadeDistancia; ++d)
troca(&genoma[i + d], &genoma[j - d]);
}

int main()
{
int testCase = 0;

while (1) {
int N, R, Q;
int i, j, n, x;

scanf("%d", &N);
if (!N)
break;

for (n = 0; n <= N; ++n)
finalPos[n] = genoma[n] = n;

scanf("%d", &R);

for (n = 0; n < R; ++n) {
scanf("%d%d", &i, &j);
reverso(i, j);
}
printf("Genome %d\n", ++testCase);
scanf("%d", &Q);
for (n = 0; n < Q; ++n) {
scanf("%d", &x);
printf("%d\n", finalPos[x]);
}
}
return 0;
}
