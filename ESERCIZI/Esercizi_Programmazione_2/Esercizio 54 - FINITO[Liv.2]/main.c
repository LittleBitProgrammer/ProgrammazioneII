#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 10
void heapify(short array[], short i);
void swap(short *a, short *b);
int main()
{
    short array[]={2,56,45,87,9,0,12,8,7,45}, i=0;
    printf("\t\t<----HEAPIFY PARTENDO DA ARRAY--->\n");
    printf("\t<---ARRAY UTILIZZATO--->\n");
    for(i=0;i<SIZE;i++)
        printf("ELEMENTO %hd - %hd\n", i, array[i]);
    heapify(array,i);
return 0;
}

void heapify(short array[], short i)
{
    i=-1;
    while(1)
    {
        i++;
        while(array[i]>array[i/2] && i!=0)
        {
            swap(&array[i],&array[i/2]);
            i/=2;
        }
        if(i==SIZE-1)
            break;
    }
    printf("\n\t<---VISITA HEAP--->\n");
    for(i=0;i<SIZE;i++)
        printf("ELEMENTO %hd - %hd\n",i,array[i]);
}

void swap(short *a,short *b)
{
    short ptr;
    ptr=*a;
    *a=*b;
    *b=ptr;
}
