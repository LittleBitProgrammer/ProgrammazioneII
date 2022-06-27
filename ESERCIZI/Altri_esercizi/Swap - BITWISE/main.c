/*Scambio del contenuto di due variabili senza usare una variabile d'appoggio*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    unsigned short int a,b;

    printf("Inserisci il primo numero: ");
    scanf("%hd", &a);
    printf("Inserisci il secondo numero: ");
    scanf("%hd", &b);

    printf("\nA=%hd - B=%hd", a, b);
    swap(&a, &b);
    printf("\nA=%hd - B=%hd", a, b);
}

void swap(unsigned short int *x, unsigned short int *y)
{
    *x=(*x)^(*y);
    *y=(*x)^(*y);
    *x=(*x)^(*y);
}
