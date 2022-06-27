#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void fill_and_show(short **m, short r, short c);
int main()
{
    short **matry;
    short rows, columns;

    printf("Inserisci il numero di righe: ");
    scanf("%hd", &rows);
    printf("Inserisci il numero di colonne: ");
    scanf("%hd", &columns);
    matry=(short**)malloc(rows*sizeof(short*));

    fill_and_show(matry, rows, columns);

}

void fill_and_show(short **m, short r, short c)
{
    //RIEMPIO LA MIA MATRICE RIGHE PER COLONNE


    printf("matrice allocata\n");
    srand(time(NULL));

    for(int i=0; i<r; i++){
        m[i]=(short*)malloc(c*sizeof(short));
        for(int j=0; j<c; j++){
            m[i][j]=rand()%2+48;
        }
    }


    for(char i=0; i<r; i++)
    {
        printf("\t");
        for(char j=0; j<c; j++)
        {
             printf("%hd ", m[i][j]);
        }
        printf("\n");
    }
}
