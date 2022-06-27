/*Scrivere function C per la costruzione di un grafo non orientato mediante matrice di adiacenze: in input
per ogni nodo sono specificati quelli adiacenti. Scegliendo in input un nodo, scrivere una function C che
restituisca il suo grado.*/
#include <stdio.h>
#include <stdlib.h>

short matrice_adiacenze[8][8]={0};
void creazione_grafo(short n);
short grado_nodo(short n, short size);

int main()
{
    short n,n1;

    printf("Quanti nodi ci sono nel grafo? (<8)\n-> ");
    scanf("%hd", &n);
    system("cls");
    creazione_grafo(n);
    system("PAUSE");
    system("cls");
    printf("Di quale nodo vuoi verificare il grado?\n->");
    scanf("%hd", &n1);

    printf("Il grado del nodo %hd e' %hd.\n", n1, grado_nodo(n1, n));
}

void creazione_grafo(short n)
{
    short n2, nodo_adiacente;

    for(short i=0; i<n; i++)
    {
        printf(">>Nodo %hd, e' adiacente a quanti nodi?\n-> ", i+1);
        scanf("%hd", &n2);
        for(short j=0; j<n2; j++)
        {
            printf("Inserisci nodo adiacente: ");
            scanf("%hd", &nodo_adiacente);
            matrice_adiacenze[i][nodo_adiacente-1]=1;
            matrice_adiacenze[nodo_adiacente-1][i]=1;
        }
    }
}

short grado_nodo(short n, short size)
{
    short grado=0;
    for(short i=0; i<size; i++)
    {
        if(matrice_adiacenze[n-1][i]==1)
            grado++;
    }
    return grado;
}
