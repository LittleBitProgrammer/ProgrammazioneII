#include <iostream>
#include <cstring>
#include "Student.hpp"

/* iostream */
using std::cout;
using std::endl;

/* cstring */
using std::strcpy;

Student::Student(const char *matricola, const char *nome_cognome, unsigned int voto)
{
    strcpy(this->matricola, matricola);
    strcpy(this->nome_cognome, nome_cognome);
    this->voto = voto;
}

Student::Student()
{
    cout << "Istanza" << endl;
}

Student::~Student()
{
    cout << "Distruttore" << endl;
}

void Student::inserisci_dati(const char *matricola, const char *nome_cognome, unsigned int voto)
{
    strcpy(this->matricola, matricola);
    strcpy(this->nome_cognome, nome_cognome);
    this->voto = voto;
}

void Student::visualizza_dati()
{
    cout << "Matricola: " << this->matricola << "\tnome: " << this->nome_cognome 
         << "\tvoto: " << this->voto << endl;
}