/*[liv.1] Scrivere una function C che, dopo aver estratto i bit da una variabile intera X (tipo char, short o
int) visualizzi i bit e poi calcoli il valore corrispondente dalla formula:
Val_X = b(n−1)2^n−1+ … + b(2)2^2 + b(1)2^1+ b(0)2^0
dove b è l’array dei bit di X: bj, per j=0, 1,…, n−1 dal meno significativo al più significativo, (dove n=8 per il
tipo char, n=16 per il tipo short o n=32 per il tipo int). Confrontare il risultato con il valore immesso per
la variabile intera X dichiarata una volta signed ed un’altra unsigned.*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef union
{
    char c[4];
    short s[2];
    int i;
} dato;

void bit_show(short len, char val[], int bit[]);
int somma(int bit[], short len);

int main()
{
    unsigned short scelta;
    int bit[32]={0};
    dato dato;

    printf("Quale dato vuoi inserire?\n[1] CHAR;\n[2] SHORT;\n[3] INT;\n\n|-----> ");
    scanf("%hd", &scelta);
    fflush(stdin);
    system("cls");
    switch(scelta)
    {
    case 1:
        printf("Inserisci il tuo dato: "); scanf("%c", &dato.c);
        bit_show(sizeof(char), dato.c, bit);
        printf("\nLa somma e': %d\n", somma(bit, sizeof(char)));
        break;

    case 2:
        printf("Inserisci il tuo dato: "); scanf("%hd", &dato.s);
        bit_show(sizeof(short), dato.c, bit);
        printf("\nLa somma e': %d\n", somma(bit, sizeof(short)));
        break;

    case 3:
        printf("Inserisci il tuo dato: "); scanf("%d", &dato.i);
        bit_show(sizeof(int), dato.c, bit);
        printf("\nLa somma e': %d\n", somma(bit, sizeof(int)));
        break;

    default:
        printf("Scelta non valida.\n");
    }
}

void bit_show(short len, char val[], int bit[])
{
    short byte, i, j;

    for(i=0; i<len; i++)
    {
        byte=val[i];
        for(j=0; j<8; j++)
        {
            bit[j+8*i]=byte&1;
            byte=byte>>1;
        }
    }
    i=0;
    printf("\n");
    for(i=31; i>=0; i--)
    {
        printf("%d", bit[i]);
        if(i%4==0) printf("  ");
    }
}

int somma(int bit[], short len)
{
    int sum=0;

    for(short i=len*8-1; i>=0; i--)
    {
        sum+=bit[i]*pow(2, i);
    }
    return sum;
}
