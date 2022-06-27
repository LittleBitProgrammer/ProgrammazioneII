#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
void prodotto(int *matrice1, int *matrice2, int *matrice3, short a, short b, short c); /** FUNCTION **/
int main()
{
    LARGE_INTEGER ticksPerSecond, TICKS1, TICKS2;
    double elapsed_time;
    QueryPerformanceFrequency(&ticksPerSecond);
    short a, b, c, i=0, j=0;
    int *matrice1, *matrice2, *matrice3; /** Dichiarazione dei puntatori alle MATRICI **/
    printf("INIZIO PROGRAMMA\n");
    printf("Inserisci N di RIGHE di A\n>>");
    scanf("%hd", &a);
    printf("\nInserisci N Righe di B e COLONNE di A\n>>");
    scanf("%hd", &b); /** Il numero di RIGHE DI B deve ssere uguale al numero delle COLONNe di A **/
    printf("\nInserisci N di COLONNE di B\n>>");
    scanf("%hd", &c);
    QueryPerformanceCounter(&TICKS1);
    matrice1=malloc(a*b*sizeof(int)); /** MALLOC della prima MATRICE **/
    QueryPerformanceCounter(&TICKS2);
    elapsed_time=(double)(TICKS2.QuadPart-TICKS1.QuadPart)/(double)ticksPerSecond.QuadPart;
    printf("\nGenerazione PRIMA MATRICE\n");
    for(i=0;i<a;i++) /** GENERAZIONE della MATRICE 1 **/
    {
        for(j=0;j<b;j++)
        {
            printf("%d ", *(matrice1+i*b+j)=rand()*100/RAND_MAX);
        }
        printf("\n");
    }
    matrice2=malloc(b*c*sizeof(int)); /** MALLOC della MATRICE 2 **/
    printf("\nGenerazione SECONDA MATRICE\n");
    for(i=0;i<c;i++) /** GENERAZIONE della MATRICE 2 **/
    {
        for(j=0;j<b;j++)
        {
            printf("%d ", *(matrice2+i*c+j)=rand()*100/RAND_MAX);
        }
        printf("\n");
    }
    matrice3=malloc(a*c*sizeof(int)); /** MALLOC della MATRICE 3 **/
    prodotto(matrice1,matrice2,matrice3,a,b,c);
    printf("\nPRODOTTO TRA LE DUE MATRICI\n");
    for(i=0;i<a;i++) /** Stampa della MATRICE PRODOTTO **/
    {
        for(j=0;j<c;j++)
        {
            printf("%d ", *(matrice3+i*c+j));
        }
        printf("\n");
    }
    printf("\nIl tempo della MALLOC risulta:\n---->%g", elapsed_time);
return 0;
}

void prodotto(int *matrice1, int *matrice2, int *matrice3, short a, short b, short c) /** FUNCTION **/
{
    short i=0, j=0, k=0;
    for(i=0;i<a;i++) /** INIZIALLIZO la MATRICE 3 con 0 **/
        for(j=0;j<b;j++)
            *(matrice3+i*a+j)=0;
    for(i=0;i<a;i++) /** FOR per il prodotto tra MATRICI **/
        for(j=0;j<b;j++)
            for(k=0;k<c;k++)
                *(matrice3+i*a+j)+=*(matrice1+i*a+k) * *(matrice2+k*b+j);

}
