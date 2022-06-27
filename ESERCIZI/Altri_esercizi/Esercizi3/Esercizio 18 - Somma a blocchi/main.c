/*] Scrivere una function C per calcolare la somma di molti addendi ak dello stesso ordine di grandezza
mediante algoritmo di somma a blocchi (Pairwise summation algorithm) implementato in versione iterativa o
ricorsiva (a scelta). Applicare l’algoritmo al seguente particolare problema test di cui è nota la soluzione (100):*/

#include <stdio.h>
#include <stdlib.h>
float pairwise_sum(float a[], char size);

int main()
{
    float lista[10];
    char len=10;

    lista[0]=0.1;

    for(char i=1; i<10; i++)
        lista[i]=lista[i-1];

    printf("Il risultato della somma e' %f\n", pairwise_sum(lista, len));

}

float pairwise_sum(float a[], char size)
{
    char mediano;
    mediano=(size-1)/2;

    if(size==1)
        return a[0];
    else
        return pairwise_sum(a, mediano+1)+pairwise_sum(a+mediano+1, size-mediano-1);
}
