#include <iostream>
#include "Student.hpp"

using std::cout;
using std::endl;

int main()
{
    Student array_students[3];

    array_students[0] = Student("0124001", "Bianchi Aldo", 26);
    array_students[1].inserisci_dati("0124002", "Rossi Maria", 28);
    array_students[2].inserisci_dati("0124003", "Versi Marco", 24);
    
    for(Student &student : array_students)
    {
        student.visualizza_dati();
    }

    return 0;
}