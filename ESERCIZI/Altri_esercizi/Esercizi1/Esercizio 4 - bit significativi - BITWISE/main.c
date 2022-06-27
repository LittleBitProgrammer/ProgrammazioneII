/*Scrivere una function C per estrarre dalla variabile intera X i k bit più significativi (k>0) o meno
significativi (k<0), dove X e k sono i parametri di input, usando:
1) Una maschera.
2) L’operatore di shift (>> o <<).
3) Il prodotto o la divisione per potenze di 2.
Scrivere una function per ognuna delle metodologie precedenti.*/

#include <stdio.h>
#include <stdlib.h>
void bitwise(short x, short n_bit, short bit[]);
void view_bit(short y, short bit[]);
int main()
{
    short var;
    short bit_to_view, bit[32]={0};

    printf("Inserisci il numero di cui vuoi visualizzare i bit piu o meno significativi\n|-----> ");
    scanf("%hd", &var);

    printf("Quanti bit vuoi visualizzare?\n[ - = meno significativi]\n[+ = piu significativi]\n|-----> ");
    scanf("%hd", &bit_to_view);

    bitwise(var, bit_to_view, bit);


}

void view_bit(short y, short bit[])
{
    for(short i=0; i<16; i++)
    {
        bit[i]=y&1;
        y>>=1;
    }

    for(int i=32; i>0; i--)
    {
        printf("%hd", bit[i]);
    }

}

void bitwise(short x, short n_bit, short bit[])
{
    if(n_bit>0)
    {
        x>>=16-n_bit;

        for(short i=1; i<=n_bit; i++)
        {
            printf("%hd", x&1);
            x>>=1;
        }
    }
    else
    {
        n_bit=n_bit*-1;
        x<<=16-n_bit;
        x>>=16-n_bit;
        for(short i=1; i<=n_bit; i++)
        {
            printf("%hd", x&1);
            x>>=1;
        }
    }
}
