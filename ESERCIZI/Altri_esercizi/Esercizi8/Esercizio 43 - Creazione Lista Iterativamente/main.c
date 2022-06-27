/*A partire dalla versione ricorsiva di costruzione di una lista in C, scriverne la versione iterativa*/
#include <stdio.h>
#include <stdlib.h>

struct lett
{
    char lettera;
    struct lett *p_next;
};

int main()
{
    char frase[]={"pazzoide"};
    char i=1;
    struct lett *head;
    head->lettera=frase[0];

    while(frase[i]!='\0')
    {
        struct lett *ptr;
        ptr=malloc(sizeof(lett));
        ptr->lettera=frase[i++];
        head->p_next

    }
}
