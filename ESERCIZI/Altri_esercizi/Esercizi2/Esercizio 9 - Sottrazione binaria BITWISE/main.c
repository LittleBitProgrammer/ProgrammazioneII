/*Scrivere una function C per eseguire la sottrazione aritmetica* binaria (*: cioè primo operando
maggiore del secondo) di due numeri naturali p e q (p, q, p−q∈) mediante gli operatori bitwise*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    short n1, n2, sott=0;

    printf("Inserisci il primo nuemero: "); scanf("%hd", &n1);
    printf("Inserisci il secondo nuemero: "); scanf("%hd", &n2);

    sott_bitwise(n1, n2, &sott);
    printf("\nLa sottrazione in bit, con i bitwise e': %hd\n", sott);

}
void sott_bitwise(short x1, short x2, short *sott)
{
    short ris, prestito;

    do
    {
        ris=x1^x2;
        x1=~x1;
        prestito=x1&x2;

        x1=ris;
        x2=prestito;
    }while(prestito!=0);

    *sott=ris;
}
