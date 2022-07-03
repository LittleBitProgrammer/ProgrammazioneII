#include <iostream>
#include <bitset>

using std::cout;
using std::endl;

using std::bitset;

int main()
{
    int i;
    bitset<8> bits(-13);
    bitset<8> bits2;
    char odd = 0;

    cout << "A = -13 -> Bits:  " << bits << endl;

    for(i = 0; i < (int)(bits.size()); i += 2)
    {
        bits2[i/2] = bits[i];
    }
    odd = bits2.to_ulong();

    cout << "bits: " << bits2 << "\nbits: " << bits << endl;
    cout << "odd = " << (int)(odd) << endl;
    
    return 0;
}