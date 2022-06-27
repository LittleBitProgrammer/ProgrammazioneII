#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 20
struct nodo{
        char dato;
        char adiacenze[20];
        };
typedef struct nodo INPUT;
void set_info(INPUT *set, short N, short i, short j);
void ins_ad(short *MATRICE, INPUT *set, short N, short i, short j);
void stampa(short *MATRICE, short N);
void cerca_arco(char dato, short *MATRICE, short N, short *entra, short *esce);
int main()
{
    INPUT *set;
    char dato;
    short i=0, j=0, N=0, *MATRICE, entra=0, esce=0;
    printf("\t<---COSTRUZIONE GRAFO NON ORIENTATO MEDIANTE MATRICE DI ADIACENZE--->\n");
    printf("INSERIRE numero di nodi:\n>>");
    fflush(stdin);
    scanf("%hd",&N);
    set=malloc(sizeof(INPUT)*N);
    MATRICE=calloc(N*N,sizeof(short));
    set_info(set,N,i,j);
    ins_ad(MATRICE,set,N,i,j);
    stampa(MATRICE,N);
    printf("\nINSERIRE NOME NODO PER CERCARE SUE ADIACENZE\n>>");
    fflush(stdin);
    dato=getchar();
    cerca_arco(dato,MATRICE,N,&entra,&esce);
    printf("\nARCHI ENTRANTI>> %hd\n",entra);
    printf("ARCHI USCENTI>> %hd\n",esce);

return 0;
}

void set_info(INPUT *set, short N, short i, short j)
{
    short adiacenze=0;
    for(i=0;i<N;i++)
    {
        set[i].dato=65+i;
        for(j=0;j<SIZE;j++)
            set[i].adiacenze[j]=0;
    }
    printf("\n\t<---STAMPA NODI INPUT--->\n");
    for(i=0;i<N;i++)
        printf(" %c ",set[i].dato);
    printf("\n\n");
    for(i=0;i<N;i++)
    {
        printf("\nINSERIRE numero di NODO RAGGIUNGIBILI del NODO %c\n>>",set[i].dato);
        fflush(stdin);
        scanf("%hd",&adiacenze);
        j=0;
        for(j=0;j<adiacenze;j++)
        {
            printf("\nINSERIRE NODO %hd RAGGIUNGIBILE DAL nodo %c:\n>>", j+1, set[i].dato);
            fflush(stdin);
            scanf("%c",&set[i].adiacenze[j]);
        }
    }
    printf("\n\n<-NODI----RAGGIUNGIBILE->");
    for(i=0;i<N;i++)
    {
        printf("\n %c -->>",set[i].dato);
        j=0;
        while(set[i].adiacenze[j]!=0)
        {
            printf(" %c",set[i].adiacenze[j]);
            j++;
        }
        printf("\n");
    }
}

void ins_ad(short *MATRICE, INPUT *set, short N, short i, short j)
{
    short indice=0;
    for(i=0;i<N;i++)
    {
        j=0;
        while(set[i].adiacenze[j]!=0)
        {
            indice=set[i].adiacenze[j]-65;
            *(MATRICE+i*N+indice)=1;
            j++;
        }
    }
}

void stampa(short *MATRICE, short N)
{
    short i, j;
    printf("\n\t<---MATRICE DI ADIACENZE--->\n");
    printf(" |  ");
    for(i=0;i<N;i++)
        printf("%c ",65+i);
    printf("|\n");
    for(i=0;i<N;i++)
    {
        printf(" |%c ",65+i);
        for(j=0;j<N;j++)
            printf("%hd ",*(MATRICE+i*N+j));
    printf("|\n");
    }
}

void cerca_arco(char dato, short *MATRICE, short N, short *entra, short *esce)
{
    short i=0;
    dato=dato-65;
    for(i=0;i<N;i++)
        if(*(MATRICE+dato*N+i)==1)
            (*esce)++;
    for(i=0;i<N;i++)
        if(*(MATRICE+i*N+dato)==1)
            (*entra)++;
}
