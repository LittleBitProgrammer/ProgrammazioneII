#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct nodo{
        short dato;
        short chiave; /** Se uguale ad 1 indica la presenza dell'elemento nell'albero **/
        };
typedef struct nodo NODO;
void crea_albero(NODO albero[], short array[]);
int main()
{
    NODO albero[21];
    short i, array[]={5,7,8,1,6,0,3,4,9,2};
    for(i=0;i<=21;i++)
        albero[i].chiave=0;
    printf("\t\t<---CREAZIONE ALBERO BINARIO DI RICERCA--->\n");
    printf("\n<---ARRAY IN INPUT--->\n");
    for(i=0;i<10;i++)
        printf("ELEMENTO %hd - %hd\n", i, array[i]);
    crea_albero(albero,array);
return 0;
}

void crea_albero(NODO albero[], short array[])
{
    short nodo_corrente=0, i=0, nuovo_nodo=0;
    /** INSERISCO LA RADICE **/
    albero[1].dato=array[i];
    albero[1].chiave=1;
    while(1)
    {
        i++;
        nuovo_nodo=array[i];
        nodo_corrente=albero[1].dato;
        while(nuovo_nodo <= albero[nodo_corrente].dato && albero[2*nodo_corrente].chiave==1)
            nodo_corrente=2*nodo_corrente;
        while(nuovo_nodo >= albero[nodo_corrente].dato && albero[(2*nodo_corrente)+1].chiave==1)
            nodo_corrente=(2*nodo_corrente)+1;
        if(nuovo_nodo>=albero[nodo_corrente].dato)
        {
            albero[(2*nodo_corrente)+1].dato=nuovo_nodo;
            albero[(2*nodo_corrente)+1].chiave=1;
        }
        else
        {
            albero[2*nodo_corrente].dato=nuovo_nodo;
            albero[2*nodo_corrente].chiave=1;
        }
        if(i==9)
            break;
    }
    printf("\n<---ALBERO BINARIO DI RICERCA--->\n");
    for(i=1;i<=21;i++)
        if(albero[i].chiave==1)
            printf("ELEMENTO %hd\n",albero[i].dato);
}
