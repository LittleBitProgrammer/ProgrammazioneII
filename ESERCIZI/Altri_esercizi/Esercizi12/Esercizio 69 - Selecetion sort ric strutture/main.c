/*Scrivere due function C (rispettivamente iterativa e ricorsiva) per implementare l’algoritmo Selection
Sort su un array di struttura, sia mediante scambi reali sia mediante scambi virtuali.
*/
#include <stdio.h>
#include <stdlib.h>

short search_max_ind(short*, short);
void max_sel_sort(short *a, short size);
int main()
{
    short a[6]={6,5,7,3,2,1};

    max_sel_sort(a, 6);

    for(short i=0; i<6; i++)
    {
        printf("%hd ", a[i]);
    }

}

short search_max_ind(short *a, short size)
{
    short max=0;
    for(short i=1; i<size; i++)
    {
        if(*(a+i)>(*a+max))
            max=i;
    }

    return max;
}

void max_sel_sort(short *a, short size)
{
    short max_i, tmp;

    if(size==1) return;

    max_i=search_max_ind(a, size);
    tmp=*(a+max_i);
    *(a+max_i)=a[0];
    a[0]=tmp;

    max_sel_sort((a+1), size-1);

}
