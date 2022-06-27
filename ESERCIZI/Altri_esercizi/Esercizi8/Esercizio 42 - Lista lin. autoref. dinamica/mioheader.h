#ifndef MIOHEADER_H_INCLUDED
#define MIOHEADER_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char nome[12];
    short eta;
}INFO;

typedef struct
{
    INFO dati;
    struct S_persona *p_next;
}Persona;

INFO dati_buffer; //CREO UNA STRUCT CHE MI SERVE DA BUFFER PER I DATI DA INSERIRE NELLA LISTA

#endif // MIOHEADER_H_INCLUDED
