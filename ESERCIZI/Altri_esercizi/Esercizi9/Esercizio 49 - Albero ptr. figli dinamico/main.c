/*Scrivere function C per la costruzione e visita per livelli di un albero qualsiasi rappresentato mediante
array. [Suggerimento: gli indici dei figli di un nodo risiedono in un array dinamicamente allocato e indirizzato dall’unico
campo puntatore del nodo dell’albero (pt_figli) come nella figura che segue]*/
#include <stdio.h>
#include <stdlib.h>

typedef struct nodo_albero
{
    char nome;
    short grado;
    short padre;
    short *figli[];
}NODO;

NODO albero[30];
short indice_padre;

int main()
{
    short n_nodi;
   printf(">> INSERISCI IL NUMERO TOTALE DI NODI <<\n-> ");
   scanf("%hd", &n_nodi);
   costruisci_array_albero(n_nodi);
   visita_albero();
}

void costruisci_array_albero(short n_nodi)
{
    system("cls");
    for(short i=0; i<n_nodi; i++)
    {
        printf(">> INSERISCI NOME NODO <<\nNome: ");
        fflush(stdin); albero[i].nome=getchar();

        printf("Padre: ");
        scanf("%hd", &albero[i].padre);
        printf("\n");
    }

    completa_nodi_albero(n_nodi);
    system("cls");
    for(short i=0; i<n_nodi; i++)
    {
        printf(">>NODO %hd:\n", i);
            printf("Grado: %hd\n",albero[i].grado);
            for(short k=0; k<albero[i].grado; k++)
            {
                printf("Figlio %hd: %hd\n\n",k, albero[i].figli[k]);
            }
        printf("\n");
    }
    system("PAUSE");
    system("cls");

}

void completa_nodi_albero(short n_nodi)
{
    for(short i=0; i<n_nodi; i++)
    {
        if(albero[i].padre!=-1)
        {
            albero[albero[i].padre].grado++;
            realloc(albero[albero[i].padre].figli, (albero[albero[i].padre].grado)*sizeof(short));
            albero[albero[i].padre].figli[(albero[albero[i].padre].grado)-1]=i;
        }
        else
            indice_padre=i;
    }
}

void visita_albero()
{
    short coda[3];
    short testa=0, n_elementi=1, indice_lavoro, i=0;

    coda[testa]=indice_padre;//INIZIALIZZO LA CODA

    printf(">> VISITA TRAMITE CODA <<\n\n");

    while(n_elementi!=0)
    {
        indice_lavoro=coda[testa];
        n_elementi--;
        testa++; testa%=3;

        printf(">>NODO %hd:\n", i++);

        for(short k=0; k<albero[indice_lavoro].grado; k++)
        {
            short figlio=albero[indice_lavoro].figli[k];
            printf("Figlio %hd: %c\n", k, albero[figlio].nome);
            coda[(testa+n_elementi++)%3]=albero[indice_lavoro].figli[k];
        }
        printf("\n");
    }

}
