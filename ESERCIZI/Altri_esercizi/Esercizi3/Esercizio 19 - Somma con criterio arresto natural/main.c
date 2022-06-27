/*Scrivere una function C per calcolare iterativamente la somma

k (che va da)1 ad N x^k/k! (circa) e^x

con il criterio di arrestonaturale. */

#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <math.h>
double sum_criterio(char n);

int main()
{
    char n_esp;

    printf("Inserisci l'esponente x di e^x: ");
    scanf("%hd", &n_esp);

    printf("Il risutalto e': %lf\n", sum_criterio(n_esp));
}

double sum_criterio(char n)
{
    char k=1;
    double somma=1, a, k_fattoriale=1;

    do
    {
        a=pow((double)n,(double)k)/k_fattoriale;
        somma+=a;
        k++;
        k_fattoriale*=k;
    }while(a>=somma*(FLT_EPSILON/2) && k<=n);

    printf("\nk= %hd\n", k);
    return somma;
}
