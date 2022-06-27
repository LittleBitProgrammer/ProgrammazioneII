#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void inorder(char *array, short indice, short size);
void postorder(char *array, short indice, short size);
void preorder(char *array, short indice, short size);
int main()
{
    short i=0, size;
    char array[]="GDIBFHJACE";
    size=strlen(array);
    printf("\t<-----VISITA ALBERI BINARI CON ARRAY---->\n");
    printf("ARRAY IN INPUT\n");
    for(i=0;i<size;i++)
        printf("ELEMENTO %hd ->> %c\n",i,array[i]);
    printf("\n\t<---VISITE ALBERO--->\n");

    printf("\n\t<---INORDER--->\n");
    inorder(array,0,size);
    printf("\n\t<---PRORDER--->\n");
    preorder(array,0,size);
    printf("\n\t<---POSTORDER--->\n");
    postorder(array,0,size);
return 0;
}

void inorder(char *array, short indice, short size)
{
    if(indice>=size)
        return;
    inorder(array,2*indice+1,size);
    printf("%c ",array[indice]);
    inorder(array,2*indice+2,size);
}

void postorder(char *array, short indice, short size)
{
    if(indice>=size)
        return;
    postorder(array,2*indice+1,size);
    postorder(array,2*indice+2,size);
    printf("%c ", array[indice]);
}

void preorder(char *array, short indice, short size)
{
    if(indice>=size)
        return;
    printf("%c ",array[indice]);
    preorder(array,2*indice+1,size);
    preorder(array,2*indice+2,size);
}
