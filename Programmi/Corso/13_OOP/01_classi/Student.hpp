#ifndef _STUDENT_HPP_
#define _STUDENT_HPP_
class Student
{
    private:
        char matricola[11];
        char nome_cognome[51];
        unsigned int voto;
    
    public:
        /* Costruttore */
        Student(const char *matricola, const char *nome_cognome, unsigned int voto);
        Student();

        /* Distruttore */
        ~Student();
        
        /* Metodi */
        void inserisci_dati(const char *matricola, const char *nome_cognome, unsigned int voto);
        void visualizza_dati();
};

#endif