/*Scrivere function C per implementare l’algoritmo Merge Sort su un array in versione iterativa e
ricorsiva.*/
#include <stdio.h>
#include <stdlib.h>


int main()
{
    short a[5]={4,7,2,5,10};
    mergesort(a, 0, 5);

    for(short i=0; i<5; i++)
        printf("%hd ", a[i]);

}

void mergesort(short *a, short inizio, short fine)
{
    if(inizio<fine)
    {
        short mediano=(inizio+fine)/2;
        mergesort(a, inizio, mediano);
        mergesort(a, mediano+1, fine);
        merge(a, inizio, mediano, fine);
    }
}

void merge(short *a, short inizio, short mediano, short fine)
{
    short i=inizio, j=mediano+1, k=0;
    short b[fine-inizio+1];

    while(i<=mediano && j<=fine)
    {
        if(a[i]<=a[j])
            b[k++]=a[i++];
        else
            b[k++]=a[j++];
    }

    while(i<=mediano)
        b[k++]=a[i++];

    while(j<=fine)
        b[k++]=a[j++];

    for(k=inizio; k<=fine; k++)
        a[k]=b[k-inizio];
}

