#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
void righe(short a, short b, short c);
void colonne(short a, short b, short c);
int main()
{
    short a, b, c;
    printf("INIZIO PROGRAMMA\n");
    printf("Inserire N di RIGHE di A\n>>");
    scanf("%hd", &a);
    printf("\nInserire N di RIGHE di B e COLONNE di A\n>>");
    scanf("%hd", &b); /** RIGHE E COLONNE devono essereuguali **/
    printf("\nInserire N di COLONNE di B\n>>");
    scanf("%hd", &c);
    printf("\nCREAZIONE DELLE MATRICI PER RIGHE E PRODOTTO\n");
    system("PAUSE");
    righe(a,b,c); /** RICHIAMO procedura **/
    printf("\nCREAZIONE DELLE MATRICI PER COLONNE E PRODOTTO\n");
    system("PAUSE");
    colonne(a,b,c); /** RICHIAMO procedura **/
return 0;
}

void righe(short a, short b, short c)
{
    short i=0, j=0, k=0;
    int *matrice1, *matrice2, *pr; /** Dichiarazione delle matrici **/
    srand(time(0)); /** Seme numeri RANDOM **/
    LARGE_INTEGER ticksPerSecond, TICKS1, TICKS2; /** Variabili per contare il tempo **/
    double elapsed_time;
    QueryPerformanceFrequency(&ticksPerSecond);
    QueryPerformanceCounter(&TICKS1); /** VARIABILE TEMPORANEA 1 **/
    matrice1=malloc(a*b*sizeof(int)); /** MALLOC MATRICE1 **/
    QueryPerformanceCounter(&TICKS2); /** VARIABILE TEMPORANE 2**/
    elapsed_time=(double)(TICKS2.QuadPart-TICKS1.QuadPart)/(double)ticksPerSecond.QuadPart; /** DIFFERENZA TRA I TEMPI **/
    matrice2=malloc(b*c*sizeof(int)); /** MALLOC MATRICE2 **/
    pr=malloc(a*c*sizeof(int)); /** MALLOC DELLA MATRICE DEL PRODOTTO **/
    printf("\n\t<MATRICE 1>\n\t ");
    for(i=0;i<a;i++) /** GENERAZIONE della MATRICE 1 **/
    {
        for(j=0;j<b;j++)
        {
            printf("%d ", *(matrice1+i*b+j)=rand()*100/RAND_MAX);
        }
        printf("\n\t ");
    }
    printf("\n\t<MATRICE 2>\n\t ");
    for(i=0;i<b;i++) /** GENERAZIONE della MATRICE 2 **/
    {
        for(j=0;j<c;j++)
        {
            printf("%d ", *(matrice2+i*c+j)=rand()*100/RAND_MAX); /** Valori RANDOM **/
        }
        printf("\n\t ");
    }
    for(i=0;i<a;i++) /** Inzzializzazione di tutti gli elementi a 0 **/
        for(j=0;j<c;j++)
            *(pr+i*c+j)=0;
    printf("\n\tIl PRODOTTO per RIGHE E'\n");
    for(i=0;i<a;i++) /** FOR per il prodotto tra MATRICI **/
        for(j=0;j<b;j++)
            for(k=0;k<c;k++)
                *(pr+i*a+j)+=*(matrice1+i*a+k) * *(matrice2+k*b+j); /** Formula del prodotto accedendo alle righe **/
    printf("\t ");
    for(i=0;i<a;i++) /** Stampa della matrice PRODOTTO **/
    {
        for(j=0;j<c;j++)
            printf("%d ", *(pr+i*c+j));
        printf("\n\t ");
    }
    printf("\nIL TEMPO DELL'ALLOCAZIONE PER RIGHE E'\n---> %g", elapsed_time); /** Stampa del Tempo impiegato **/
}


void colonne(short a, short b, short c)
{
    short i=0, j=0, k=0;
    int **matrice3, **matrice4, **pc; /** Dichiarazione delle Matrici **/
    srand(time(0)); /** Seme della RAND **/
    LARGE_INTEGER ticksPerSecond, TICKS1, TICKS2; /** Variabile per contare il tempo **/
    double elapsed_time;
    QueryPerformanceFrequency(&ticksPerSecond);
    QueryPerformanceCounter(&TICKS1); /** VARIABILE TEMPORANEA 1 **/
    matrice3=(int **) malloc(a*sizeof(int *)); /** MALLOC MATRICE 3 (RIGHE) **/
    for(i=0;i<a;i++)
        matrice3[i]=(int *) malloc(b*sizeof(int)); /** MALLOC MATRICE (COLONNE) **/
    QueryPerformanceCounter(&TICKS2); /** VARIABIL TEMPORANEA 2 **/
    elapsed_time=(double)(TICKS2.QuadPart-TICKS1.QuadPart)/(double)ticksPerSecond.QuadPart; /** TOTALE TEMPO **/
    matrice4=(int **) malloc(b*sizeof(int *)); /** MALLOC MATRICE 4 (RIGHE) **/
    for(i=0;i<b;i++)
        matrice4[i]=(int *) malloc(c*sizeof(int)); /** MALLOC MATRICE 4 (COLONNE) **/
    pc=(int **) malloc(a*sizeof(int *));
    for(i=0;i<a;i++)
        pc[i]=(int *) malloc(c*sizeof(int));
    for(j=0;j<c;j++) /** INIZIALIZZO TUTTI I VALORI DEL PRODOTTO A 0 **/
        for(i=0;i<a;i++)
            pc[i][j]=0;
    printf("\n\t<MATRICE 3>\n\t ");
    for(j=0;j<b;j++) /** RANDOM VALORI **/
    {
        for(i=0;i<a;i++)
            printf("%d ", matrice3[i][j]=rand()*100/RAND_MAX);
        printf("\n\t ");
    }
    printf("\n\t<MATRICE 4>\n\t ");
    for(j=0;j<c;j++) /** RANDOM VALORI **/
    {
        for(i=0;i<b;i++)
            printf("%d ", matrice4[i][j]=rand()*100/RAND_MAX);
        printf("\n\t ");
    }
    printf("\n\tIL PRODOTTO PER COLONNE E'\n");
    for(i=0;i<a;i++) /** FOR per il prodotto tra MATRICI **/
        for(j=0;j<b;j++)
            for(k=0;k<c;k++)
                pc[i][j]+=matrice3[k][i] * matrice4[j][k]; /** FORMULA PER IL PRODOTTO ACCEDENDO DALLE COLONNE **/
    printf("\t ");
    for(i=0;i<a;i++)
    {
        for(j=0;j<c;j++)
            printf("%d ", pc[i][j]);
        printf("\n\t ");
    }
    printf("\nIL TEMPO DELL'ALLOCAZIONE PER COLONNE E'\n---> %g", elapsed_time); /** OUTPUT del TEMPO **/
}
