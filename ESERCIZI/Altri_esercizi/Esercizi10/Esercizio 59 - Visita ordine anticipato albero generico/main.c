/*Scrivere function C per la visita in ordine anticipato di un albero qualsiasi.*/
#include <stdio.h>
#include <stdlib.h>

typedef struct nodo
{
    char nome;
    short grado;
    struct nodo *figli;
}NODO;

int main()
{
    NODO *nodo_radice;
    crea_albero(&nodo_radice);
    system("PAUSE");
    system("cls");
    visita_preorder(&nodo_radice);

}

void crea_albero(NODO **nodo)
{
    (*nodo)=malloc(sizeof(NODO));

    printf(">>NOME NODO: ");
    fflush(stdin); scanf("%c", &(*nodo)->nome);

    printf(">>NUMERO FIGLI DI %c: ", (*nodo)->nome);
    scanf("%hd", &(*nodo)->grado);

    (*nodo)->figli=malloc(sizeof(NODO)*(*nodo)->grado);

    for(short i=0; i<(*nodo)->grado; i++)
    {
        crea_albero(&(*nodo)->figli[i]);
    }
}

void visita_preorder(NODO **nodo)
{
    printf("NODO: %c\n", (*nodo)->nome);

    for(short i=0; i<(*nodo)->grado; i++)
    {
        visita_preorder((&(*nodo)->figli[i]));
    }
}
