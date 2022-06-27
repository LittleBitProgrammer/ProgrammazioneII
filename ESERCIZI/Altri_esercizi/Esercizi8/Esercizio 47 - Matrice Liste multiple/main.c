/*ESERCIZIO DI PROVA CON LE LISTE MULTIPLE, CREO:
-FUNCTION CHE MI RIEMPIE LA MATRICE DI LISTE
-FUNCTION CHE MI VISUALIZZA LA MATRICE

HO SCELTO DI ACCEDERVI PER RIGHE*/
#include <stdio.h>
#include <stdlib.h>

typedef struct elem
{
    short elemento;
    short row;
    short col;
    struct elem *next_col;
    struct elem *next_row;
}ELEMENTO;

short check_node(ELEMENTO *el, short i, short j);

int main()
{
    short row, col;
    ELEMENTO *head=malloc(sizeof(ELEMENTO));

    printf("Quante righe e colonne deve avere la tua matrice?\n");
    printf("Righe: "); scanf("%hd", &row);
    printf("Colonne: "); scanf("%hd", &col);

    crea_liste_multiple(row, col, &head);
    show_multiple_list(row, col, &head);
    printf("\nel1=%hd\n", head->next_col->elemento);
}

void crea_liste_multiple(short row, short col, ELEMENTO **head)
{
    short el_da_ins;

    ELEMENTO *curr_col;
    curr_col=(*head);

    ELEMENTO *curr_row;
    curr_row=(*head);

    for(char i=0; i<row; i++)
    {
        for(char j=0; j<col; j++)
        {
            printf("Inserisci l'elemento [%hd][%hd]= ", i, j);
            scanf("%hd", &el_da_ins);

            if(el_da_ins!=0)
            {
                curr_col=curr_col->next_col;
                curr_col=malloc(sizeof(ELEMENTO));
                curr_col->row=i;
                curr_col->col=j;
                curr_col->elemento=el_da_ins;
                printf("inserito %hd\n", curr_col->elemento);
            }

        }
        curr_row=curr_row->next_row;
        curr_row=malloc(sizeof(ELEMENTO));
        curr_col=curr_row;

    }
}

void show_multiple_list(short row, short col, ELEMENTO **head)
{
    ELEMENTO *curr_col;
    curr_col=*head;
    ELEMENTO *curr_row;
    curr_row=*head;

    printf("\nELEMENTI DELLA LISTA MULTIPLA\n");

    for(short i=0; i<row; i++)
    {
        printf("\n\t");
        for(short j=0; j<col; j++)
        {
            printf("%hd ", curr_col->elemento/*check_node(curr_col, i, j)*/);
            curr_col=curr_col->next_col;
        }
        curr_row=curr_row->next_row;
        curr_col=curr_row;
    }
}

short check_node(ELEMENTO *el, short i, short j)
{
    if(el->row==i && el->col==j)
    {
        return el->elemento;
    }
    else return 0;
}
