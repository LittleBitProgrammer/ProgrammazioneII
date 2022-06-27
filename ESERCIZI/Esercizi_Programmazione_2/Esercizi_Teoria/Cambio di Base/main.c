#include <stdio.h>
#include <stdlib.h>
void conver_int(int x, int *r);
void conver_float(float y, int *r, int n);
int main()
{
    int x, scelta, n;
    int r[16];
    float y;
    printf("PROGRAMMA PER IL CAMBIO DI BASE ( BASE 10 --> BASE 2 ) \n");
    printf("\nInserire:\n[0] EXIT\n[1] CONVERSIONE INTERA\n[2] CONVERSIONE FLOAT");
    printf("\n>>");
    scanf("%d", &scelta);
    switch(scelta){
        case 0: exit(0); break;
        case 1: printf("\nInserire il numero INTERO");
                printf("\n>>");
                scanf("%d",&x);
                conver_int(x,r);break;
        case 2: printf("\nInserire il numero FLOAT");
                printf("\n>>");
                scanf("%f", &y);
                printf("\nInserire il grado di precisione al quale si vuole convertire");
                printf("\n>>");
                scanf("%d", &n);
                conver_float(y,r,n);break;
        default:exit(1);break;
    }
return 0;
}
void conver_int(int x, int *r)
{
    int j=0,i=0, x1;
    while(x>0)
    {
        j++;
        x1=x/2;
        r[j]=x-x1*2;
        x=x1;
    }
    printf("\nL'INPUT in BINARIO e': ");
    for(i=j;i>0;i--)
        printf("%d", r[i]);

}

void conver_float(float y, int *r, int n)
{
    int j=1, i=0;
    for(j=0;j<n;j++)
    {
        y=y*2;
        r[j]=(int)y;
        y=y-r[j];
    }
    printf("\nLa parte frazionaria dell'INPUT in BINARIO e': ");
    for(i=0;i<j;i++)
        printf("%d", r[i]);
}
