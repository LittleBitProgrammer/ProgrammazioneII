#include <iostream>
#include <bitset>

using std::cout;
using std::endl;

using std::bitset;

int main()
{
    unsigned short N = 125;
    unsigned short M = 3;
    bitset<8> bits(N);
    bitset<8> bits_2 = M;

    cout << "Bits = " << bits << endl;
    cout << "Bits_2 = " << bits_2 << endl;
}
