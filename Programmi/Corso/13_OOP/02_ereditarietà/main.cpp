#include <iostream>
#include "Veicolo.hpp"
#include "Camion.hpp"
#include "Automobile.hpp"

int main(){
    Camion scania(2, 8, 3);
    Automobile fiat(4, 5, utilitaria);
    Automobile bmw(4, 7, suv);

    scania.show();
    fiat.show();
    bmw.show();

    return 0;
}