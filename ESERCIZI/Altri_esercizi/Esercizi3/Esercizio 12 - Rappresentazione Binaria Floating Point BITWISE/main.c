/*Scrivere una function C per visualizzare la rappresentazione binaria (s,e,m) di un numero float.
Verificare che il valore del numero ottenuto coincida con il dato iniziale.*/
#include <stdio.h>
#include <stdlib.h>
union floating_point
{
    float n_float;
    int n_int;
}real_numb;

char bit[32];

int main()
{
        printf("Inserisci il numero reale da cui vuoi estrarre i bit: ");
        scanf("%f", &real_numb.n_float);

        estrai(real_numb.n_int);
        printf("Rappresentazione in bit:\n");
        for(short i=31; i>=0; i--)
        {
            (i==31 || i==23) ? printf("%hd ", bit[i]) : printf("%hd", bit[i]);
        }
}

void estrai(int n)
{
    for(short i=0; i<32; i++)
    {
        bit[i]=n&1;
        n>>=1;
    }
}
