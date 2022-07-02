#include <iostream>
#include <bitset>

using std::cout;
using std::endl;

using std::bitset;

int main()
{
    /* 8 bit inizializzati a 0: 0000 0000 */
    bitset<8> bits;
    cout << "Bits = " << bits << endl;

    /* Accende il bit in posizione 3: 0000 1000 */
    bits.set(3);
    cout << "Bits = " << bits << endl;

    /* Accende tutti i bit: 1111 1111 */
    bits.set();
    cout << "Bits = " << bits << endl;

    /* Inverte il bit in posizione 2: 1111 1011 */
    bits.flip(2);
    cout << "Bits = " << bits << endl;

    /* Inverte tutti i bit: 0000 0100 */
    bits.flip();
    cout << "Bits = " << bits << endl;

    /* Spegne tutti i bit: 0000 0000 */
    bits.reset();
    cout << "Bits = " << bits << endl;

    return 0;
}