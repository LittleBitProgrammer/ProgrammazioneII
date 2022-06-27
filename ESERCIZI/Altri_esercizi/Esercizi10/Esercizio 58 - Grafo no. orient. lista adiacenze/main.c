/*Scrivere function C per la costruzione di un grafo non orientato mediante liste di adiacenze: in input per
ogni nodo sono specificati quelli adiacenti.*/
#include <stdio.h>
#include <stdlib.h>
#define MAX_NODI 10

typedef struct nodo
{
    char nome;
    struct nodo *adiacenti;
}NODO;

NODO grafo[MAX_NODI];

int main()
{
    char n_nodi;

    printf("Quanti nodi ha il tuo grafo? (<10)\n-> ");
    scanf("%hd", &n_nodi);

    crea_grafo(n_nodi);
}

void crea_grafo(short n_nodi)
{
    char c='A', c_ad;
    short grado;
    NODO *nodo_corr;

    system("cls");
    for(short i=0; i<n_nodi; i++)
    {
        grafo[i].nome=c++;
        printf(">> GRADO NODO %c: ", grafo[i].nome);
        scanf("%hd", &grado);

        for(short j=0; j<grado; j++)
        {
            printf("Nodo adiacente %hd: ", j+1);
            fflush(stdin);scanf("%c", &c_ad);
            if(j==0)
            {
                grafo[i].adiacenti=grafo+c_ad-'A';
                nodo_corr=grafo[i].adiacenti;
            }
            else
            {
                nodo_corr->adiacenti=grafo+c_ad-'A';
                nodo_corr=nodo_corr->adiacenti;
                nodo_corr->adiacenti=NULL;
            }
        }
        nodo_corr=grafo[i].adiacenti;
        printf("Primo nodo adiacente = %c\n\n", nodo_corr->nome);
    }
}
