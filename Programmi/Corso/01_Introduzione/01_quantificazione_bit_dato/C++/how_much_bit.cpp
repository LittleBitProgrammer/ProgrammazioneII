/**
 * @file how_much_bit.cpp
 * @author Roberto Vecchio
 * @brief Tale programma ha lo scopo di quantificare lo spazio occupato da un determinato tipo di dato in memoria
 * @version 1
 * @date 2022-06-27
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>

/* Namespace */

/* Standard library */
using std::cout;
using std::endl;

int main()
{
    /* Stampa del numero di byte (8 bit) per ogni dato */
    cout << endl << "sizeof(char)          = " << sizeof(char) << endl;
    cout << "sizeof(short)         = " << sizeof(short) << endl;
    cout << "sizeof(int)           = " << sizeof(int) << endl;
    cout << "sizeof(long int)      = " << sizeof(long) << endl;
    cout << "sizeof(long long int) = " << sizeof(long long) << endl;
    cout << "sizeof(float)         = " << sizeof(float) << endl;
    cout << "sizeof(double)        = " << sizeof(double) << endl;
    cout << "sizeof(long double)   = " << sizeof(long double) << endl;
    cout << "sizeof(char *)        = " << sizeof(char *) << endl;

    /* Denota la corretta terminazione del programma */
    return 0;
}


