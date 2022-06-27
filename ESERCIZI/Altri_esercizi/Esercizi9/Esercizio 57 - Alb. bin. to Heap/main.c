/*Scrivere function C iterativa per la trasformazione in un heap di un albero binario rappresentato
mediante array. */
#include <stdio.h>
#include <stdlib.h>

short heapify(short i, short *heap);
void tree_to_heap(short size, short *a);

int main()
{
    short albero[8]={0,2,6,18,3,42,12,55};
    tree_to_heap(8, albero);

    for(short i=1; i<=8; i++)
    {
        printf("Elemento %hd -> Padre %hd: %hd\n", i, i/2, albero[i]);
    }
}

void tree_to_heap(short size, short *a)
{
    char check=1, i;
    while(check!=0)
    {
        i=size-1;
        while(i-2>0)
        {
            check=heapify(i, a);
            i-=2;
        }

    }
}

short heapify(short i, short *heap)
{
    short temp;
    if(i%2==0)
    {
        if(heap[i]>heap[i+1] && heap[i]>heap[i/2])
        {
            temp=heap[i/2];
            heap[i/2]=heap[i];
            heap[i]=temp;
            return 1;
        }
    }
    else
    {
        if(heap[i]>heap[i-1] && heap[i]>heap[i/2])
        {
            temp=heap[i/2];
            heap[i/2]=heap[i];
            heap[i]=temp;
            return 1;
        }
    }

    return 0;
}
