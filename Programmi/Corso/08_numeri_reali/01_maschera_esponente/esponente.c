#include <stdio.h>
#define bias 127

typedef union
{
    float x;
    long n;
} real;

short estrai_esponente(long);

int main()
{
    real f;
    short exponent;

    printf("Inserire numero reale: ");
    scanf("%f", &f.x);

    exponent = estrai_esponente(f.n);

    printf("Esponente = %hd", exponent);
}

short estrai_esponente(long floating_number)
{
    /* Estrae l'esponente */
    long int exponent, mask;

    mask = 0x7f800000;
    exponent = floating_number & mask;
    exponent >>= 23;
    exponent -= bias;

    return (short)(exponent);
}