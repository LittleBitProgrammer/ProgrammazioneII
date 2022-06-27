#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 30
struct info{
            char nome;
            };
typedef struct info INFO_FIELD;
struct nodo{
            INFO_FIELD info;
            int grado;
            };
typedef struct nodo NODO;
void costruisci_albero(NODO albero[]);
void visita();
void enqueue(NODO coda[], char info, short grado, short *fondo);
void dequeue(NODO coda[], char *info, short *grado, short *testa);
int main()
{
    NODO albero[MAX];
    costruisci_albero(albero);
    visita();
return 0;
}

void enqueue(NODO coda[], char info, short grado, short *fondo)
{
    coda[*fondo].info.nome=info;
    coda[*fondo].grado=grado;
    *fondo+=1;
}

void dequeue(NODO coda[], char *info, short *grado, short *testa)
{
    *info=coda[*testa].info.nome;
    *grado=coda[*testa].grado;
    *testa+=1;
}

void costruisci_albero(NODO albero[])
{
    short i=0,k, grado_nodo, testa=0, fondo=0;
    char stringa;
    NODO coda[MAX];
    printf("\t\t<----CREAZIONE E VISITA ALBERO---->\n");
    printf("\nInserire RADICE\n>>");
    fflush(stdin);
    albero[i].info.nome=getchar();
    printf("\nInserire GRADO RADICE\n>>");
    fflush(stdin);
    scanf("%d",&albero[i].grado);

    enqueue(coda,albero[i].info.nome,albero[i].grado,&fondo);
    printf("\n\t<----RADICE INSERITA---->\n");
    while(fondo!=testa)
    {
        dequeue(coda,&stringa,&grado_nodo,&testa);
        for(k=0;k<grado_nodo;k++)
        {
            printf("\n<---FIGLIO %hd DI %c--->\n", k+1, stringa);
            printf("Inserire NOME FIGLIO:\n>>");
            fflush(stdin);
            albero[i].info.nome=getchar();
            printf("\nInserire GRADO FIGLIO:\n>>");
            fflush(stdin);
            scanf("%d",&albero[i].grado);
            enqueue(coda,albero[i].info.nome,albero[i].grado,&fondo);
            printf("\n\t<---NODO INSERITO--->\n");
        }
    }
    printf("\n\t<---CREAZIONE ALBERO AVVENUTA CON SUCCESSO---->\n");
    system("PAUSE");
    system("cls");
}

void visita()
{
    short i=0,k,grado_nodo, testa=0, fondo=0;
    char stringa;
    NODO albero[MAX];
    NODO coda[MAX];
    printf("\n\t<---ALBERO--->\n");
    printf("\nRADICE:\n>>  %c\n", albero[i].info.nome);
    enqueue(coda,albero[i].info.nome,albero[i].grado,&fondo);
    while(fondo!=testa)
    {
        dequeue(coda,&stringa,&grado_nodo,&testa);
        for(k=0;k<grado_nodo;k++)
        {
            i++;
            printf("\n %d: %c", i, albero[i].info.nome);
            enqueue(coda,albero[i].info.nome,albero[i].grado,&fondo);
        }
    }
    printf("\n\t<---ALBERO VISITATO--->\n");
}
