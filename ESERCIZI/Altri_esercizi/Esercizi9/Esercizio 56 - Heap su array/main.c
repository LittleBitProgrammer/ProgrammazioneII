/* Scrivere function C iterativa per la costruzione di un heap rappresentato mediante array. */
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 20

short heap[MAX_SIZE]={0};

int main()
{
    char size;
    printf("Inserisci il numero di nodi della struttura heap (<20)\n->");
    scanf("%hd", &size);
    heap_construction(size);
    system("cls");
    for(short i=1; i<=size; i++)
    {
        printf("Elemento %hd -> Padre %hd: %hd\n", i, i/2, heap[i]);
    }

}

void heap_construction(char size)
{
    for(short i=1; i<=size; i++)
    {
        printf("Inserisci l'elemento %hd: ", i);
        scanf("%hd", &heap[i]);

        if(i!=1)
            heapify(i);
        if(i>4)
            heapify(i/2);
    }
}

void heapify(short i)
{
    short temp;
    if(i%2==0)
    {
        if(heap[i]>heap[i+1] && heap[i]>heap[i/2])
        {
            temp=heap[i/2];
            heap[i/2]=heap[i];
            heap[i]=temp;
        }
    }
    else
    {
        if(heap[i]>heap[i-1] && heap[i]>heap[i/2])
        {
            temp=heap[i/2];
            heap[i/2]=heap[i];
            heap[i]=temp;
        }
    }
}
