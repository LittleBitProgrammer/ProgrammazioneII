#include <iostream>
#include <bitset>

using std::cout;
using std::endl;

using std::bitset;

int main()
{
    int i;
    bitset<16> bits(-13);
    short inverse = 0;

    cout << "A = -13 -> Bits:  " << bits << endl;

    for(i = 0; i < (int)(bits.size()); i++)
    {
        inverse <<= 1;
        inverse |= bits[i];
    }

    bits = inverse;
    cout << "Inverse = " << inverse << " bits:  " << bits << endl;

    return 0;
}