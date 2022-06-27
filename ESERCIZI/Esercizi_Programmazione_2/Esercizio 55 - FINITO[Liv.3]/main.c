#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 10
short sinistra(short i);
short destra(short i);
void swap(short *a, short *b);
void heapify(short array[], short i);
void max(short array[]);
int main()
{
    short array[]={2,6,18,3,42,12,55,44,94,79}, i;
    printf("\t\t<---COSTRUZIONE HEAP DI ALBERO BINARIO CON ARRAY--->\n");
    printf("\n<---ARRAY UTILIZATO--->\n");
    for(i=0;i<SIZE;i++)
        printf("ELEMENTO>> %hd - %hd\n", i, array[i]);
    max(array);
    printf("\n<---ARRAY HEAP--->\n");
    for(i=0;i<SIZE;i++)
        printf("ELEMENTO>> %hd - %hd\n", i, array[i]);
return 0;
}
short sinistra(short i)
{
    return(2*i)+1;
}
short destra(short i)
{
    return (2*i)+2;
}
void swap(short *a, short *b)
{
    short tmp;
    tmp=*a;
    *a=*b;
    *b=tmp;
}

void heapify(short array[], short i)
{
    short k=0, j=0, massimo=0;
    k=sinistra(i);
    j=destra(i);
    if(k<SIZE && array[k]>array[i])
        massimo=k;
    else
        massimo=i;
    if(j<SIZE && array[j]>array[massimo])
        massimo=j;
    if(massimo!=i)
    {
        swap(&array[i],&array[massimo]);
        heapify(array,massimo);
    }

}

void max(short array[])
{
    short i;
    for(i=(SIZE/2)-1;i>=0;i--)
        heapify(array,i);
}
