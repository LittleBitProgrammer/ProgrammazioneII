#include <stdio.h>
#include <stdlib.h>
#define N 5

struct adiacenze{
            char dato;
            struct adiacenze *p_next;
            };
typedef struct adiacenze adiacenze;
typedef adiacenze *ADIACENZE;

struct grafo{
        char dato;
        ADIACENZE vertice;
        };
typedef struct grafo grafo;
typedef grafo *GRAFO;
void add_nodo(char , ADIACENZE *);
int main()
{
    grafo vertici[N];
    ADIACENZE tmp, ptr;
    char dato;
    short i, j, MAX=0;
    ptr=(ADIACENZE)malloc(sizeof(adiacenze));
    printf("\t\t<---GRAFO NON ORIENTATO CON LISTE DI ADIACENZA--->\n");
    for(i=0;i<N;i++)
    {
        vertici[i].dato=65+i;
        vertici[i].vertice=NULL;
    }
    printf("<---NODI GRAFO--->\n\t");
    for(i=0;i<N;i++)
        printf("%c ",vertici[i].dato);
    for(i=0;i<N;i++)
    {
        printf("\n\nInserisci NUMERO ADIACENZE del nodo %c\n>>",vertici[i].dato);
        fflush(stdin);
        scanf("%hd",&MAX);
        j=0;
        if(MAX>0)
        {
            printf("INSERIRE adiacenza %hd del nodo %c\n>>",j+1,vertici[i].dato);
            fflush(stdin);
            dato=getchar();
            if(dato>=65 && dato<=65+N)
            {
                tmp=(ADIACENZE)malloc(sizeof(adiacenze));
                add_nodo(dato,&tmp);
                ptr=tmp;
                j++;
            }
            else
            {
                printf("\n\t<---NODO NON ESISTE\n--->\n");
                j=MAX;
                i--;
            }
            while(j!=MAX)
            {
                printf("\nInserire adiacenza %hd del nodo %c\n>>",j+1,vertici[i].dato);
                fflush(stdin);
                dato=getchar();
                if(dato>=65 && dato<65+N)
                {
                    add_nodo(dato,&tmp);
                    j++;
                }
                else
                {
                    printf("\n\t<---NODO NON ESISTE--->\n");
                }
            }
            vertici[i].vertice=ptr;
        }
    }
    printf("\n\n<---VISITA DEL GRAFO--->\n");
    for(i=0;i<N;i++)
    {
        tmp=vertici[i].vertice;
        printf("\nNODO >> %c\t ADIACENZE >> ",vertici[i].dato);
        while(tmp!=NULL)
        {
            printf("%c",tmp->dato);
            tmp=tmp->p_next;
        }
    }
    free(tmp);
    free(ptr);
return 0;
}

void add_nodo(char info, ADIACENZE *head)
{
    ADIACENZE ptr;
    ptr=(ADIACENZE)calloc(1,sizeof(adiacenze));
    ptr->dato=info;
    ptr->p_next=NULL;
    (*head)->p_next=ptr;
    ptr->p_next=NULL;
    (*head)=ptr;
}
