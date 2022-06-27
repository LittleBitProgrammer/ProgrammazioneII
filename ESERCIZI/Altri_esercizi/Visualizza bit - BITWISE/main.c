/*[liv.1] Visualizza i bit di una valore che può essere char, short o int.*/

#include <stdio.h>
#include <stdlib.h>
typedef union
{
    char c;
    short s;
    int i;
} dato;

void bit_valore(int n, int bit[]);
int main()
{
    unsigned short scelta, i=0;
    dato tipo;
    int bit[32];

    printf("Che tipo di carattere vuoi inserire?\n[1] Char;\n[2] Short;\n[3] Int;\n|-----> ");
    scanf("%hd", &scelta);
    fflush(stdin);
    system("cls");

    switch(scelta)
    {
                case 1:
                    printf("Inserisci il carattere: ");
                    scanf("%c", &tipo.c);
                    bit_valore(tipo.c, bit);
                    break;

                case 2:
                    printf("Inserisci il carattere: ");
                    scanf("%hd", &tipo.s);
                    bit_valore(tipo.s, bit);
                    break;

                case 3:
                    printf("Inserisci il carattere: ");
                    scanf("%d", &tipo.i);
                    bit_valore(tipo.i, bit);
                    break;

                default:
                    printf("Inserisci una scelta valida.\n");
    }

    do
    {
        printf("%d", bit[i++]);
    }while(i<=31);

}

void bit_valore(int n, int bit[])
{
    short j=31;

    do
    {
        bit[j--]=n&1;
        n>>=1;
    }while(n!=0 && j>=0);

    if(j>=0)
    {
        do
            bit[j--]=0;
        while(j>=0);
    }
}
