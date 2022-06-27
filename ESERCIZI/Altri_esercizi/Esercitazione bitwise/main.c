#include <stdio.h>
#include <stdlib.h>

int main()
{

}

/*Scrivere una function C per invertire l’ordine dei bit di una variabile intera A mediante operatori
bitwise.*/
void inverti(unsigned char *a)
{
    unsigned char b, c;

    for(char i=0; i<8; i++)
    {
        b=*a;
        b<<=i;
        b>>=8-1;
        b<<=i;
        c=b|c;
    }

    return c;

}

