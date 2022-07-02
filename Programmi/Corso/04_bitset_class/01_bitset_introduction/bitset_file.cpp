#include <iostream>
#include <bitset>

/* iostream */
using std::cout;
using std::endl;

/* bitset */
using std::bitset;

int main()
{
    /* Array di 8 bit */
    bitset<8> A = 'A';
    bitset<8> a = 'a';
    bitset<8> B = 'B';
    bitset<8> r;

    cout << "A =     " << A << endl;
    cout << "a =     " << a << endl;

    r = A ^ a;

    cout << "A ^ a = " << r << endl;
    cout << "dec =   " << r.to_ulong() << endl;

    cout << "\nA =     " << A << endl;
    cout << "B =     " << B << endl;

    r = A & B;

    cout << "A & B = " << r << endl;
    cout << "dec =   " << r.to_ulong() << endl;

    cout << "\nA =          " << A << endl;

    r = A << 2;

    cout << "A << 2 =     " << r << endl;
    cout << "dec =   " << r.to_ulong() << endl;

    cout << "\na =          " << a << endl;

    r = a >> 3;

    cout << "a >> 3 =     " << r << endl;
    cout << "dec =   " << r.to_ulong() << endl;

    cout << "\nNumero di bit = " << r.size() << endl;
    cout << "Bit accesi = " << r.count() << endl;

    return 0;
}