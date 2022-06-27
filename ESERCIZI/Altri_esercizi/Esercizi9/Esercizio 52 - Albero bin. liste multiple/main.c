/*Scrivere function C per la costruzione e visita (preorder, inorder e postorder) di un albero binario
rappresentato mediante liste multiple. */
#include <stdio.h>
#include <stdlib.h>

typedef struct nodo
{
    char nome;
    struct nodo *f_sx, *f_dx;
}NODO;

void tree_create(NODO **nodo_corr);

int main()
{
    NODO *nodo_radice;
    tree_create(&nodo_radice);
    system("PAUSE");
    system("cls");
    printf(">> PREORDER VISIT <<\n");
    preorder_visit(&nodo_radice, 0);
    system("PAUSE");
    system("cls");
    printf(">> POSTORDER VISIT <<\n");
    postorder_visit(&nodo_radice, 0);
    system("PAUSE");
    system("cls");
    printf(">> INORDER VISIT <<\n");
    inorder_visit(&nodo_radice, 0);
    return 0;
}

void tree_create(NODO **nodo_corr)
{
    short scelta;
    *nodo_corr=malloc(sizeof(NODO));
    printf("\n>> INSERISCI NOME NODO <<\n-> ");
    fflush(stdin); (*nodo_corr)->nome=getchar();

    printf("\nNodo %c ha un figlio sinistro? 1[SI] - 0[NO]\n->", (*nodo_corr)->nome);
    scanf("%hd", &scelta);
    if(scelta==1) tree_create(&(*nodo_corr)->f_sx); else { (*nodo_corr)->f_sx=NULL;}

    printf("Nodo %c ha un figlio destro? 1[SI] - 0[NO]\n->", (*nodo_corr)->nome);
    scanf("%hd", &scelta);
    if(scelta==1) tree_create(&(*nodo_corr)->f_dx); else { (*nodo_corr)->f_dx=NULL;}
}

void preorder_visit(NODO **nodo_corr, char i)
{
    if(*nodo_corr!=NULL)
    {
        printf("Visita %hd - Dato: %c\n", i++, (*nodo_corr)->nome);
        preorder_visit(&(*nodo_corr)->f_sx, i);
        preorder_visit(&(*nodo_corr)->f_dx, i);
    }
}

void inorder_visit(NODO **nodo_corr, char i)
{
    if(*nodo_corr!=NULL)
    {
        inorder_visit(&(*nodo_corr)->f_sx, i);
        printf("Visita %hd - Dato: %c\n", i++, (*nodo_corr)->nome);
        inorder_visit(&(*nodo_corr)->f_dx, i);
    }
}

void postorder_visit(NODO **nodo_corr, char i)
{
    if(*nodo_corr!=NULL)
    {
        postorder_visit(&(*nodo_corr)->f_sx, i);
        postorder_visit(&(*nodo_corr)->f_dx, i);
        printf("Visita %hd - Dato: %c\n", i++, (*nodo_corr)->nome);
    }
}
