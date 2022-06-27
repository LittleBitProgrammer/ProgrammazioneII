/* Scrivere function C per la costruzione e visita per livelli di un albero qualsiasi rappresentato mediante
array. [Suggerimento: la struct che definisce il generico nodo dell’albero, come nella figura sotto, deve
contenere i seguenti campi: l'informazione, il grado del nodo ed un array di puntatori (ai nodi figli) di
dimensione pari al massimo grado dei nodi, che si suppone noto]*/

#include <stdio.h>
#include <stdlib.h>
#define MAX_FIGLI 3

typedef struct nodo
{
    char nome;
    short padre;
}NODO_input;

typedef struct nodo_albero
{
    char nome;
    short grado;
    short figli[MAX_FIGLI];
}NODO_output;

NODO_input albero_input[20];
NODO_output albero_output[20];

short indice_padre;
int main()
{
    crea_albero();
    visita_albero();
}

void crea_albero()
{
    short i=0, scelta=1, n;

    printf(">> INSERISCI NUMERO NODI TOTALI DELL'ALBERO <<\n");
    scanf("%hd", &n);

    while(i<n)
    {
        printf("\n>> INSERISCI NODO %hd <<\nNOME: ", i);
        fflush(stdin);albero_input[i].nome=getchar();
        printf(">> INSERISCI PADRE <<\nPADRE :", i);
        scanf("%hd", &albero_input[i].padre);
        i++;
    }
    i=0;
    system("PAUSE");
    system("cls");

    printf("\n\t>> DATI IN INPUT <<\n");
    while(i<n)
    {
        printf("\n>> NODO %hd <<\nNOME= %c\nPADRE= %hd\n", i, albero_input[i].nome, albero_input[i].padre);
        i++;
    }

    ordina_array(n);
    i=0;
    printf("\n\t>> DATI IN OUTPUT <<\n");
    while(i<n)
    {
        printf("\n>> NODO %hd <<\nNOME= %c\nGRADO= %hd\n", i, albero_output[i].nome, albero_output[i].grado);
        for(char k=1; k<=albero_output[i].grado; k++)
        {
            printf("FIGLIO %hd= %c\n", k, albero_input[albero_output[i].figli[k-1]].nome);
        }
        printf("\n");
        i++;
    }

    system("PAUSE");
    system("cls");
}

void ordina_array(short n)
{
    short padre, grado;
    for(short i=0; i<n; i++)
    {
        strcpy(&albero_output[i].nome, &albero_input[i].nome);
        if(albero_input[i].padre!=-1)
        {
            padre=albero_input[i].padre;
            grado=++albero_output[padre].grado;
            albero_output[padre].figli[grado-1]=i;
        }
        else
            indice_padre=i;
    }
}

void visita_albero()
{
    short coda[MAX_FIGLI];
    short testa=0, n_elementi=1;
    coda[testa]=indice_padre;
    short indice_lavoro, i=0;

     printf(">> VISITA TRAMITE CODA <<\n\n");

    while(n_elementi!=0)
    {
        indice_lavoro=coda[testa];
        n_elementi--;
        testa++;
            testa%=MAX_FIGLI;
        printf("\nNODO %hd\n", i++);
        for(char k=0; k<albero_output[indice_lavoro].grado; k++)
        {
            printf("FIGLIO %hd= %c\n", k, albero_input[albero_output[indice_lavoro].figli[k]].nome);
            coda[(testa +n_elementi++)%MAX_FIGLI]=albero_output[indice_lavoro].figli[k];
        }
    }

}

