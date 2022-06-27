/*Generando in modo random i bit* di un numero reale x (double x) [* vedere: uso di rand() in
Materiale di supporto], determinare i bit della corrispondente rappresentazione float flx (float flx;
flx=(float) x). Se il numero x è rappresentabile nel tipo float, calcolarne l’errore assoluto EA e
l’errore relativo ER di rappresentazione (considerando come esatto double x e come approssimante float
flx(x) ) dalle formule:

EA = | x – flx |, ER = (| x – flx |)/(|x|)
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char bit[64]={0};

union n_double
{
    double x_double;
    long long int x_int;
}n_double;

union n_float
{
    double x_float;
    int x_int;
}n_float;

int main()
{
    double e_assoluto, e_relativo;
    rnd_bit_gen();
    n_float.x_float=(float)n_double.x_double; // FL(X) (FLOAT) LO ASSOCIO AL MIO NUMERO REALE (DOUBLE)
    printf(">Numero reale= %lf\n", n_double.x_double);
    printf(">Numero float associato fl(x)= %f\n", n_float.x_float);

    e_assoluto=n_double.x_double-(double)n_float.x_float;
    if(e_assoluto<0)
        e_assoluto*=-1;

    printf("\nErrore assoluto= %e\n", e_assoluto);

    e_relativo=(n_double.x_double-(double)n_float.x_float)/(n_double.x_double);
    if(e_relativo<0)
        e_relativo*=-1;

    printf("\nErrore relativo= %e\n", e_relativo);

}

void bitshow(long long int x)
{
    char i=0;
    do
    {
        bit[i]=x&1;
        x>>=1;
        i++;
    }while(i<64);

    for(i=63; i>=0; i--)
        (i==63 || i==52) ? printf("%hd ", bit[i]) : printf("%hd", bit[i]);

    printf("\n\n");
}

void rnd_bit_gen()
{
    char i=0;
    long long int random_int;

    srand((unsigned) time(NULL));

    while(i<64)
    {
        random_int=rand();
        random_int<<=i;
        n_double.x_int^=random_int;
        i+=15;

        bitshow(n_double.x_int);
    }

}
