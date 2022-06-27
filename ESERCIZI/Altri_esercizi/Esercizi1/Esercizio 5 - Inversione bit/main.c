/*Scrivere una function C per invertire l’ordine dei bit di una variabile intera A mediante operatori
bitwise.*/
#include <stdio.h>
#include <stdlib.h>
char inverti(char a);
void show_bit(char c, short bit[]);
short bit[8]={0};
int main()
{
    unsigned char c, x;
    printf("Inserisci la variabile di cui vuoi invertire l'ordine dei bit:\n|-----> ");
    fflush(stdin); scanf("%c", &c); fflush(stdin);
    show_bit(c, bit);

    printf("\nLa variabile invertita e': %c\n", x=inverti(c));
    for(short i=0; i<8; i++)
    {
        bit[i]=0;
    }
    show_bit(x, bit);
}

void show_bit(char c, short bit[])
{
    for(short i=0; i<8; i++)
    {
        bit[i]=c&1;
        c>>=1;
    }

    for(short i=7; i>=0; i--)
    {
        printf("%hd ", bit[i]);
    }
}

char inverti(char a)
{
    short i;
    unsigned char b, c=0;
    for(i=0; i<=7; i++)
    {
        b=a;
        b<<=i;
        b>>=7;
        b<<=i;

        c=b|c;
    }

    return c;
}
