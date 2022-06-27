#include <iostream>

using namespace std;
/*costruire n suoni diversi
la classe suono deve essere modificata in modo che ad
ogni suono venga associato automaticamente un codice
progressivo in fase di creazione*/

class suono
{
    public:
        void origine() {posizione=0;};
        short get_freq_max(){return freq_max;};
        void forward();
        void forward(int);
        void backward();
        void backward(int);
        double play() {return posizione;};
        suono(short l, short fmx, short fmn) {lunghezza=l; freq_max=fmx; freq_min=fmn;};
        ~suono(){delete *lunghezza; delete *freq_max; delete *freq_min;};

    private:
        void verifica_dimensione();
        short lunghezza;
        short freq_max;
        short freq_min;
        int posizione;
        string tipo_suono;
        double* sound;
};

int main()
{
    suono x1(1,3,3);
    cout << "Freq= " <<x1.get_freq_max()<< endl;
    x1.~suono();
    cout << "Freq= " <<x1.get_freq_max()<< endl;
    return 0;
}
