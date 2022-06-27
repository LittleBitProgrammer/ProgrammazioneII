/* Scrivere una function C che estragga da una variabile di tipo intero A i suoi bit di posto pari mediante
operatori bitwise.*/
#include <stdio.h>
#include <stdlib.h>
short bit[8]={0};

int main()
{
    short a;
    printf("Inserisci la variabile di cui vuoi estrarre i bit alle posizioni pari: ");
    scanf("%hd", &a);

    estrai(a);
    for(short i=7; i>=0; i--)
    {
        printf("%hd", bit[i]);
    }
}

void estrai(short a)
{
    short i;
    for(i=0; i<8; i++)
    {
        a>>=1;
        bit[i]=a&1;
        a>>=1;
    }
}
