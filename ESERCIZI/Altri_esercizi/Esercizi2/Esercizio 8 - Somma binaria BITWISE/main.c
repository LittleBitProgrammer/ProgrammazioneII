/*Scrivere una function C per eseguire l’addizione aritmetica binaria di due numeri naturali p e q (p,q∈)
mediante gli operatori bitwise.*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    short n1, n2, somma=0;

    printf("Inserisci il primo nuemero: "); scanf("%hd", &n1);
    printf("Inserisci il secondo nuemero: "); scanf("%hd", &n2);

    sum_bitwise(n1, n2, &somma);
    printf("\nLa somma in bit, con i bitwise e': %hd\n", somma);
}

void sum_bitwise(short x1, short x2, short *sum)
{
    short som, rip;

    do
    {
        som=x1^x2;
        rip=x1&x2;
        rip<<=1;
        x1=sum;
        x2=rip;
    }while(x2!=0);

    *sum=som;
}
