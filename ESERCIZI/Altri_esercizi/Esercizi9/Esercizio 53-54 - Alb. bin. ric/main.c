/*Scrivere function C iterativa per la costruzione di un albero binario di ricerca rappresentato mediante
array. */
#include <stdio.h>
#include <stdlib.h>

typedef struct nodo
{
    short dato;
    struct nodo *f_sx, *f_dx;
}NODO;

short search_key(short key, NODO *nodo_corr);

int main()
{
    NODO *nodo_radice;
    short key;

    create_bst(&nodo_radice);
    system("PAUSE");
    system("cls");
    printf(">> CERCA LA TUA CHIAVE NELL'ALBERO BINARIO <<\n->");
    scanf("%hd", &key);
    if(search_key(key, nodo_radice)==1)
        printf("\nChiave trovata!\n");
    else
        printf("\nChiave non trovata!\n");
}

void create_bst(NODO **nodo_radice)
{
    short continua=1;
    NODO *nodo_corr,*nodo_da_ins;
    nodo_corr=malloc(sizeof(NODO));
    *nodo_radice=malloc(sizeof(NODO));
    printf(">> INSERISCI NODO RADICE <<\n->");
    scanf("%hd", &(*nodo_radice)->dato);

    (*nodo_radice)->f_dx=(*nodo_radice)->f_sx=NULL;

    while(continua==1)
    {
        nodo_corr=*nodo_radice;
        nodo_da_ins=malloc(sizeof(NODO));
        printf(">> INSERISCI DATO NODO <<\n->");
        scanf("%hd", &(nodo_da_ins)->dato);


        while(nodo_da_ins->dato <= nodo_corr->dato && nodo_corr->f_sx!=NULL)
            nodo_corr=nodo_corr->f_sx;

        while(nodo_da_ins->dato >= nodo_corr->dato && nodo_corr->f_dx!=NULL)
            nodo_corr=nodo_corr->f_dx;

        if(nodo_da_ins->dato <= nodo_corr->dato)
        {
            nodo_corr->f_sx=nodo_da_ins;
            nodo_da_ins->f_dx=nodo_da_ins->f_sx=NULL;
        }
        else
        {
            nodo_corr->f_dx=nodo_da_ins;
            nodo_da_ins->f_dx=nodo_da_ins->f_sx=NULL;
        }
        printf("\nVUOI INSERIRE ANCORA? 1[SI] - 0[NO]\n->");
        scanf("%hd", &continua);
    }

}

short search_key(short key, NODO *nodo_corr)
{
    if(nodo_corr==NULL)
        return 0;
    else if(nodo_corr->dato==key)
        return 1;
    else if(nodo_corr->dato<key)
        search_key(key, nodo_corr->f_dx);
    else
        search_key(key, nodo_corr->f_sx);
}
