#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef enum{falso,vero}bool;
struct info{
        char d;
        short grado;
        };
typedef struct info INFO_FIELD;
struct nodo{
        INFO_FIELD dato;
        struct nodo *son;
        struct nodo *bro;
        };
typedef struct nodo nodo;
typedef nodo *NODO;
struct coda{
        short cnt;
        NODO front;
        NODO rear;
        };
typedef struct coda coda;
typedef coda *CODA;
/** FUNCTION **/
void inizializza(CODA );
bool vuoto(const CODA );
void enqueue(INFO_FIELD , CODA );
INFO_FIELD dequeue(CODA );
void ini_nodo(NODO , INFO_FIELD );
INFO_FIELD set_info(INFO_FIELD , short );
void agg_nodo(INFO_FIELD , NODO * );
NODO crea_albero(NODO , CODA );
void visita(NODO );
int main()
{
    NODO tree, punt;
    CODA queue;
    INFO_FIELD info;
    punt=(NODO)malloc(sizeof(nodo));
    tree=(NODO)malloc(sizeof(nodo));
    queue=(CODA)malloc(sizeof(coda));
    inizializza(queue);
    printf("\t\t<---COSTRUZIONE ALBERO--->\n");
    printf("Inserisci RADICE ALBERO\n>>");
    fflush(stdin);
    info.d=getchar();
    printf("Inserisci GRADO RADICE ALBERO\n>>");
    fflush(stdin);
    scanf("%hd",&info.grado);
    enqueue(info,queue);
    ini_nodo(tree,info);
    punt=crea_albero(tree,queue);
    printf("\n\t\t<---ALBERO CREATO---->\n");
    printf("\nVISITA ALBERO->>>\n");
    visita(punt);

    free(punt);
    free(tree);
    free(queue);
return 0;
}

void inizializza(CODA c)
{
    c->cnt=0;
    c->front=NULL;
    c->rear=NULL;
}

bool vuoto(const CODA c)
{
    return ((bool)(c->cnt==0));
}

void enqueue( INFO_FIELD info, CODA c)
{
    NODO ptr;
    ptr=(NODO)malloc(sizeof(nodo));
    ini_nodo(ptr,info);
    if(!vuoto(c))
    {
        c->rear->bro=ptr;
        c->rear=ptr;
    }
    else
        c->front=c->rear=ptr;
    c->cnt++;
}

INFO_FIELD dequeue(CODA c)
{
    NODO ptr;
    INFO_FIELD info;
    ptr=c->front;
    info=ptr->dato;
    c->front=c->front->bro;
    c->cnt--;
    free(ptr);
    return info;
}

void ini_nodo(NODO tree, INFO_FIELD info)
{
    tree->dato.d=info.d;
    tree->dato.grado=info.grado;
    tree->son=NULL;
    tree->bro=NULL;
}

INFO_FIELD set_info(INFO_FIELD nodo, short i)
{
    INFO_FIELD info;
    printf("Inserisci %d FIGLIO DI %c\n>>", i+1,nodo.d);
    fflush(stdin);
    info.d=getchar();
    printf("Inserisci il GRADO di %c\n>>", info.d);
    fflush(stdin);
    scanf("%hd",&info.grado);
return info;
}

void agg_nodo(INFO_FIELD info, NODO *testa)
{
    NODO ptr;
    ptr=(NODO)malloc(sizeof(nodo));
    ini_nodo(ptr,info);
    (*testa)->bro=ptr;
    ptr->bro=NULL;
    (*testa)=ptr;
}

NODO crea_albero(NODO tree, CODA queue)
{
    NODO tmp,ptr,punt;
    INFO_FIELD info, temp;
    short i, grado=0;
    punt=(NODO) malloc(sizeof(nodo));
    ptr=(NODO) malloc(sizeof(nodo));
    punt=tree;
    while(!vuoto(queue))
    {
        tmp=(NODO) malloc(sizeof(nodo));
        info=dequeue(queue);
        ini_nodo(tmp,info);
        grado=info.grado;
        ptr=tmp;
        for(i=0;i<grado;i++)
        {
            temp=set_info(info,i);
            agg_nodo(temp,&tmp);
            enqueue(temp,queue);
        }
        if(grado>0)
        {
            tree->son=ptr;
            tree=ptr;
        }
    }
    free(tmp);
    free(ptr);
    return punt;
}

void visita(NODO tree)
{
    NODO tmp;
    tmp=(NODO) malloc(sizeof(nodo));
    tmp=tree;
    while(tree->son!=NULL)
    {
        while(tmp!=NULL)
        {
            printf("\t%c\n",tmp->dato.d);
            tmp=tmp->bro;
        }
        tree=tree->son;
        tmp=tree->bro;
    }
    while(tmp!=NULL)
    {
        printf("\t%c\n", tmp->dato.d);
        tmp=tmp->bro;
    }

}
