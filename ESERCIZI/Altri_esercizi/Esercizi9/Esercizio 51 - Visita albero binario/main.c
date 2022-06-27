/* Scrivere le function C per la visita (preorder, inorder e postorder) di un albero binario rappresentato
mediante array. */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct nodo
{
    char dato;
    short f_sx;
    short f_dx;
}NODO;

NODO b_tree[16];

int main()
{
    short n_nodi;
    printf(">> INSERISCI NUMERO LIVELLI ALBERO BINARIO <<\n\n->");
    scanf("%hd", &n_nodi);
    n_nodi=pow(2, n_nodi)-1;
    tree_create(n_nodi);

    system("PAUSE");
    system("cls");
    printf(">> VISITA PREORDER (RADICE->SX->DX) << \n");
    preorder_visit(1);
    system("PAUSE");
    system("cls");
    printf(">> VISITA POSTORDER (SX->DX->RADICE) << \n");
    postorder_visit(1);
    system("PAUSE");
    system("cls");
    printf(">> VISITA INORDER (SX->RADICE->DX) << \n");
    inorder_visit(1);
}
void tree_create(short n_nodi)
{
    system("cls");
    for(short i=1; i<=n_nodi; i++)
    {
        (i==1) ? printf(">>NODO RADICE<<\n") : printf(">> NODO %hd FIGLIO DI %c <<\n", i, b_tree[i/2].dato);
        printf("Inserisci dato: ");
        fflush(stdin); b_tree[i].dato=getchar();
        //ASSEGNAZIONE DATO

        b_tree[i].f_dx=(2*i<=n_nodi) ? 2*i : -1;
        b_tree[i].f_sx=(2*i+1<=n_nodi) ? 2*i+1 : -1;
        //ASSEGNAZIONE FIGLI
    }
}

void preorder_visit(short i)
{
    printf("Dato: %c\n", b_tree[i].dato);
    if(b_tree[i].f_dx==-1 && b_tree[i].f_sx==-1)
        return i/2;
    else
        preorder_visit(2*i);
        preorder_visit(2*i+1);
}

void postorder_visit(short i)
{
    if(b_tree[i].f_sx!=-1)
        postorder_visit(i*2);
    if(b_tree[i].f_dx!=-1)
        postorder_visit(i*2+1);

    printf("Dato: %c\n", b_tree[i].dato);
    return i/2;
}

void inorder_visit(short i)
{
    if(b_tree[i].f_sx!=-1)
        postorder_visit(i*2);

    printf("Dato: %c\n", b_tree[i].dato);

    if(b_tree[i].f_dx!=-1)
        postorder_visit(i*2+1);

    return 1/2;
}

