/*Scrivere una function C che, fissato il numero n di bit, calcoli la rappresentazione di un intero:
• per complemento a 2;
• eccesso B (B-biased).*/
#include <stdio.h>
#include <stdlib.h>
char bit[5]={0};
int main()
{
    char val;
    do
    {
        printf("Inserisci un numero che va da 0 a 15: ");
        scanf("%hd", &val);
    }while(val<-15 || val>15);

    rappr_compl2(val);
    printf("\nCOMPL2= ");visualizza();
    rappr_biased(val);
    printf("\nBIASED= ");visualizza();
}
void visualizza()
{
    for(short i=4; i>=0; i--)
    {
        printf("%hd", bit[i]);
    }
}

void rappr_compl2(short valore)
{
    if(valore<0)
    {
        valore*=-1;
        valore=~valore;
        valore+=1;
    }

    for(short i=0; i<5; i++)
    {
        bit[i]=valore&1;
        valore>>=1;
    }
}

void rappr_biased(short valore)
{
    char base=pow(2,4)-1;

    valore+=base;
    for(short i=0; i<5; i++)
    {
        bit[i]=valore&1;
        valore>>=1;
    }
}
