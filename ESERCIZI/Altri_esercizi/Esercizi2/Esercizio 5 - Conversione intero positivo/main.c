/*Scrivere due function C di conversione di un intero positivo (int) da base 10 a base 2 mediante
l’algoritmo delle divisioni successive realizzato rispettivamente:
• Usando gli operatori di quoziente e resto della divisione intera;
• Usando gli operatori bitwise.*/
#include <stdio.h>
#include <stdlib.h>
short bit[32]={0};
int main()
{
    int myval;

    printf("Inserisci il valore che voi convertire: ");
    scanf("%d", &myval);
    printf("\nCon quoziente e resto:   ");
    conv_10to2_divisione(myval, bit);
    for(short i=31; i>=0; i--)
    {
        (i%4==0) ? printf("%hd ", bit[i]) : printf("%hd", bit[i]);
        bit[i]=0;
    }
    printf("\nCon opertatori bitwise:  ");
    conv_10to2_bitwise(myval, bit);
    for(short i=31; i>=0; i--)
    {
        (i%4==0) ? printf("%hd ", bit[i]) : printf("%hd", bit[i]);
    }

}

void conv_10to2_divisione(int x, short bit[])
{
    short i=0;

    do
    {
        bit[i++]=x%2;
        x/=2;
    }while(x>0);
}

void conv_10to2_bitwise(int x, short bit[])
{
    short i=0;

    do
    {
        bit[i++]=x%2;
        x>>=1;
    }while(x>0);
}

