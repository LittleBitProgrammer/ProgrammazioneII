/*Scrivere una function C per calcolare dalla definizione l’ULP(x) dove x è il parametro reale float di
input.*/
#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <math.h>

int main()
{
    union num_float
    {
        float x_float;
        int x_int;
    }num;
    float ulp_x;

    printf("Inserisci il numero di cui vuoi calcolare l'ULP, ULP(x):\n|x= ");
    scanf("%f", &num.x_float);
    calcolo_ulp(num.x_int, &ulp_x);

    printf("\nL'ULP(%.4f) e' uguale a= %e", num.x_float, ulp_x);
    printf("\nNumero successivo a x = %f",num.x_float+ulp_x);

}

void calcolo_ulp(int num, float *ulp)
{
    int mask=0x7f800000, esponente;
    esponente=num&mask;
    esponente>>=23;
    esponente-=127;

    *ulp=FLT_EPSILON*pow(2, esponente);
}
