#include <stdio.h>
#include <stdlib.h>
#define N 6 /** COLONNE **/
#define M 4 /** RIGHE **/
void statica(int A[N][M]); /** FUNCTION PER ALLOCAZIONE STATICA **/
void dinamica(int *pa); /** FUNCTION PER L'ALLOCAZIONE DINAMICA **/
int main()
{
    int A[N][M], *pa;
    short scelta;
    pa=malloc(M*N*sizeof(int)); /** CREAZIONE DINAMICA DELLA MATRICE **/
    printf("INIZIO PROGRAMMA\n");
    printf("Scegliere tra:\n[0]EXIT\n[1]ALLOCAZIONE STATICA\n[2]ALLOCAZIONE DINAMICA\n>>");
    scanf("%hd", &scelta);
    switch(scelta){
        case 0:exit(0);break;
        case 2:dinamica(pa);break;
        case 1:statica(A);break;
        default:exit(1);break;
    }
return 0;
}

void statica(int A[N][M])
{
    short i=0,j=0;
    for(i=0;i<M;i++) /** SCORRO LE RIGHE **/
        for(j=0;j<N;j++) /** SCORRO LE COLONNE **/
        {
            A[j][i]=j+1;
        }
    for(i=0;i<M;i++) /** STAMPO SCORRENDO LE RIGHE PRIMA DELLE COLONNE **/
    {
        for(j=0;j<N;j++)
            printf("%d ",A[j][i]);
        printf("\n");
    }
}

void dinamica(int *pa)
{
    short i=0, j=0;
    for(i=0;i<M;i++)
        for(j=0;j<N;j++)
        {
            *(pa+i*N+j)=j+1; /** ASSEGNO AD OGNI ELEMENTO DELLA MATRICE UN VALORE CON L'UTILIZZO DEI PUNTATORI **/
        }
    for(i=0;i<M;i++)
    {
        for(j=0;j<N;j++)
            printf("%d ",*(pa+i*N+j)); /** STAMPO GLI ELEMENTI DELL'ARRAY UTILIZZANDO I PUNTATORI **/
        printf("\n");
    }
}
