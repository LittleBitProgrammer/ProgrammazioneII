/*Scrivere una function C per visualizzare la rappresentazione binaria (s,e,m) di un numero float.
Verificare che il valore del numero ottenuto coincida con il dato iniziale.*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define max_bit 32

union valore
{
    float x_f;
    int x_i;
}val;

void estrazione(unsigned char bit[], int x_i);
void s_e_m(unsigned int x_i);
void verifica(int s, int exp, int man, int *n);

unsigned char bit[max_bit];

int main()
{

    printf("VISUALIZZAZIONE DI UN NUMERO IN SEGNO, ESPONENTE E MANTISSA\n");
    printf("\nInserisci il numero da analizzare= ");
    scanf("%f", &val.x_f);

    estrazione(bit, val.x_i);
    s_e_m(val.x_i);

    printf("\nVERIFICA\nNumero= %f", val.x_f);
}
void estrazione(unsigned char bit[], int x_i)
{
    char i;
    i = max_bit - 1;
    while (i >= 0)
    {
        bit[i] = x_i & 1;
        x_i = x_i >> 1;
        i--;
    }
    printf("\nS   EXP\t   MANTISSA\n");
    printf("%hu ", bit[0]);///Segno
    for (i = 1; i <= 8; i++) printf("%hu", bit[i]);///Esponente
    printf(" ");
    for (i = 9; i < max_bit; i++) printf("%hu", bit[i]);///Mantissa
    printf("\n");
}
void s_e_m(unsigned int x_i)
{
    int esponente, mask, mantissa,segno;
    float valore;
    segno=bit[max_bit-1];
    /*Calcolo il valore dell'esponente*/
    mask = 0x7f800000;
    esponente = x_i & mask;
    esponente = esponente >> 23;
    esponente = esponente - 127;
    printf("Il valore dell'esponente e' = %d\n", esponente);
    /*Calcolo il valore della mantissa*/
    mantissa = x_i << 9;
    mantissa = x_i >> 9;
    printf("Il valore della mantissa e' = %d\n", mantissa);
    /*Calcolo il valore inserito*/

    verifica(segno, esponente, mantissa, &val.x_i);
}
void verifica(int s, int exp, int man, int *n)
{
    *n|=s<<31;
    *n|=exp<<23;
    *n|=man;
}
