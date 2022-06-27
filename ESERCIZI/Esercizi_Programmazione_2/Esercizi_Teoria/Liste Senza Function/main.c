#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    struct PERSONA{
            char nome[20];
            short eta;
            struct PERSONA *p_next;} *head, *punt;
    head=calloc(1,sizeof(struct PERSONA));
    strcpy(head->nome,"Bianchi Roberto");
    head->eta=22;
    head->p_next=calloc(1,sizeof(struct PERSONA));
    strcpy((head->p_next)->nome,"Rossi Maurizio");
    (head->p_next)->eta=25;
    (head->p_next)->p_next=calloc(1,sizeof(struct PERSONA));
    strcpy(((head->p_next)->p_next)->nome,"Verdi Gianluca");
    ((head->p_next)->p_next)->eta=18;
    ((head->p_next)->p_next)->p_next=NULL;
    punt=head;
    while(punt->p_next!=NULL)
    {
        printf("\nNOME= %s\tp_next=%hd\n",punt->nome,punt->p_next);
        punt=punt->p_next;
        printf("\nNOME= %s\tp_next=%hd\n",punt->nome,punt->p_next);
    }



return 0;
}
