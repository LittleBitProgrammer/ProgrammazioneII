#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct 
{
    
} Persona;

int main()
{
    struct Persona
    {
        char name[20];
        short eta;
        struct Persona *p_next;
    };

    struct Persona *head, *punt;

    /* head */
    head = (struct Persona *)calloc(1, sizeof(struct Persona));
    strcpy(head->name, "Bianchi Roberto");
    head->eta = 22;
    head->p_next = (struct Persona *)calloc(1, sizeof(struct Persona));

    /* head->p_next */
    strcpy((head->p_next)->name, "Rossi Maurizio");
    (head->p_next)->eta = 25;
    (head->p_next)->p_next = (struct Persona *)calloc(1, sizeof(struct Persona));
    
    /* head->p_next->p_next */
    strcpy(((head->p_next)->p_next)->name, "Verdi Gianluca");
    ((head->p_next)->p_next)->eta = 18;
    ((head->p_next)->p_next)->p_next = NULL;

    /* Algoritmo di visita */
    punt = head;

    while(punt->p_next != NULL)
    {
        printf("nome = %s\teta = %hd\tp_next = %p\n",punt->name, punt->eta, punt->p_next);
        punt = punt->p_next;
    }
    printf("nome = %s\teta = %hd\tp_next = %p\n",punt->name, punt->eta, punt->p_next);

    return 0;
}