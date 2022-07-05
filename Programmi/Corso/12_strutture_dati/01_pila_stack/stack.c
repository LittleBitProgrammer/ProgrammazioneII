#include <stdio.h>

/* Grandezza dello stack */
#define MAX_STACK_SIZE 100

/* Prototipi di funzione */
void inverse_array(char[], short);
void push_stack(char, char[], short *);
void pop_stack(char *, char[], short *);

int main()
{
    char character_array[] = {'A','B','C','D','E','F','G','H','I','L'};
    short array_length = 10;
    short i;

    /* Stampa prima dell'array */
    puts("Array prima dell'inversione:");
    for(i = 0; i < array_length; i++)
    {
        printf("character_array[%d] = %c\n", i, character_array[i]);
    }

    /* Inversione dell'array */
    inverse_array(character_array, array_length);

    /* Stampa dopo l'inversione dell'array */
    puts("\nArray dopo l'inversione:");
    for(i = 0; i < array_length; i++)
    {
        printf("character_array[%d] = %c\n", i, character_array[i]);
    }

    return 0;
}

/* Definizioni di funzioni */

/**
 * @brief Inverte l'array sfruttando l'implementazione dello stack
 * @param character_array array di caratteri da invertire
 * @param array_len lunghezza dell'array da invertire
 */
void inverse_array(char character_array[], short array_len)
{
    char temp[MAX_STACK_SIZE];
    short i;
    short head = -1; /* - 1 indica che lo stack è vuoto */

    /* Popoliamo lo stack */
    for(i = 0; i < array_len; i++)
    {
        push_stack(character_array[i], temp, &head);
    }

    /* Svuotiamo lo stack per invertire l'array */
    for(i = 0; i < array_len; i++)
    {
        pop_stack(character_array + i, temp, &head);
    }
}

/**
 * @brief Simula l'operazione di inserimento in uno stack
 * 
 * @param item_to_insert elemento da inserire nello stack
 * @param stack stack all'interno della quale vogliamo inserire l'elemento
 * @param head testa dello stack
 */
void push_stack(char item_to_insert, char stack[], short *head)
{
    *(stack + ++(*head)) = item_to_insert;
}
/**
 * @brief Simula l'operazione di cancellazione di un elemento dalla cima dello stack
 * 
 * @param item_output elemento rimosso (parametro di output)
 * @param stack stack sulla quale vogliamo effettuare l'operazione di pop
 * @param head testa dello stack
 */
void pop_stack(char *item_output, char stack[], short *head)
{
    *item_output = *(stack + (*head)--);
}