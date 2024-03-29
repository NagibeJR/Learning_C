#include <stdio.h>
#include <stdlib.h>

int main() {
    float num1, num2, num3, media;
    scanf ("%f%f%f",&num1,&num2,&num3);
    media = (num1 + num2 + num3)/3;
    printf ("%.2f\n", media);
	return 0;
}
