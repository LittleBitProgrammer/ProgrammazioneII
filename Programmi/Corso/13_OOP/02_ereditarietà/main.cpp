#include "Veicolo.hpp"
#include "Camion.hpp"
#include "Automobile.hpp"
#include <vector>
#include <iostream>
using std::vector;
using std::cout;
using std::endl;

int main(){
    Camion scania(2, 8, 3);
    Automobile fiat(4, 5, utilitaria);
    Automobile bmw(4, 7, suv);

    scania.show();
    fiat.show();
    bmw.show();

    std::vector<int> x(2,3);
    // is very different from
    std::vector<int> y{2,3};

    for(int i = 0; i < 2; i++)
    {
        cout << "x: " << x.at(i) << endl;
        cout << "y: " << y.at(i) << "\n" << endl;
    }

    return 0;
}