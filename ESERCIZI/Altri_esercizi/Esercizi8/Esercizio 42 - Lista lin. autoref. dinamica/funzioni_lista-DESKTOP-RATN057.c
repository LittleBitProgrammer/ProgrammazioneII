#include "mioheader.h";

void show_list(Persona **head)
{
    char i=0;
    Persona *ptr=*head;

    system("cls");
    while(ptr!=NULL)
    {
        printf(">Persona %hd:\nNome: %sEta': %hd\n\n", i++, ptr->dati.nome, ptr->dati.eta);
        ptr=ptr->p_next;
    }
}

void *crea_lista()
{
    struct S_persona *head;
    head=NULL;
    return head;
}

void compila_dati()
{
    system("cls");
    fflush(stdin);
    printf("Inserisci il nome della persona: ");
    fgets(dati_buffer.nome, 12, stdin);
    fflush(stdin);
    printf("Inserisci l'eta' della persona: ");
    scanf("%hd", &dati_buffer.eta);
}

void ins_testa(Persona **head)
{
    compila_dati();

    Persona *ptr; //CREO UN PTR A STRUCT COSì DA POTERCI ALLOCARE MEMORIA
    ptr=malloc(sizeof(Persona));
    ptr->dati=dati_buffer;
    ptr->p_next=*head;
    *head=ptr;
}

void ins_mezzo(Persona **head)
{
    compila_dati();

    Persona *ptr;
    ptr=malloc(sizeof(Persona));
    ptr->dati=dati_buffer;
    ptr->p_next=(*head)->p_next;
    (*head)->p_next=ptr;
}

void elim_testa(Persona **head)
{
    system("cls");
    Persona *ptr;
    ptr=*head;
    *head=(*head)->p_next;
    free(ptr);
}


void elim_mezzo(Persona **head)
{
    system("cls");

}
