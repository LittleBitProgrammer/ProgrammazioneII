/*Scrivere una function C che restituisca la matrice C prodotto righecolonne [vedi pdf delle dispense] di
due matrici rettangolari A e B le cui dimensioni sono stabilite in input (usare per tutte le matrici l’allocazione
dinamica e generarle come numeri reali random). C’è qualche preferenza nell’usare malloc() o calloc()
rispettivamente per A, B o C? Verificare se i tempi di esecuzione, per la sola allocazione e totali, sono gli
stessi. */
#include <stdio.h>
#include <stdlib.h>
void fill_matrix(short *m);
int main()
{
    short *a, *b;

    a=b=(short *)malloc(3*3*sizeof(short));

    printf("Inserire i valori della matrice A\n\n");
    fill_matrix(a);
    system("cls");
    printf("Inserire i valori della matrice B\n\n");
    fill_matrix(b);

    prod_r_c(a, b);
}

void fill_matrix(short *m)
{
    for(char i=0; i<3; i++)
    {
        for(char j=0; j<3; j++)
        {
            printf("Inserisci l'elemento [%hd][%hd]: ", i, j);
            scanf("%hd", (&m+i*3+j));
        }
    }
}

void prod_r_c(short *a, short *b)
{
    short *tot;
    tot=(short *)malloc(3*3*sizeof(short));

    for(char i=0; i<3; i++)
    {
        for(char j=0; j<3; j++)
        {
            for(char k=0; k<3; k++)
                *(tot+i*3+j)+=&(a+i*3+k)*(&(b+k*3+j));
        }
    }

    system("cls");

    for(char e=0; e<3; e++)
    {
        printf("\n");
        for(char w=0; w<3; w++)
        {
            printf("\t%hd", *(tot+e*3+w));
        }
    }

}
