#include <stdio.h>
#include <stdlib.h>

int main()
{
    unsigned char a, b;

    fflush(stdin);
    scanf("%d", &a);

    fflush(stdin);
    scanf("%d", &b);

    printf("\nA = %d\nB = %d", a, b);

    return 0;
}