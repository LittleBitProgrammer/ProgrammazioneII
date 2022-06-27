/*Conoscendo la rappresentazione degli interi in C, riscrivere la function C per l’addizione aritmetica
binaria di due interi mediante gli operatori bitwise (vedi esercizio 8.) nel caso gli operandi siano interi con
segno*/
#include <stdio.h>
#include <stdlib.h>
short sum(short op1, short op2);
int main()
{
    short op1, op2;

    printf("Inserisci il primo operando: ");
    scanf("%hd", &op1);
    printf("Inserisci il secondo operando: ");
    scanf("%hd", &op2);

    printf("\n FRATM La somma tra questi due numeri e' %hd.", sum(op1, op2));
}

short sum(short op1, short op2)
{
    short rip, sum;

    do
    {
        sum=op1^op2;
        rip=op1&op2;
        rip<<=1;
        op1=sum;    op2=rip;
    }while(op2!=0);

    return sum;
}
