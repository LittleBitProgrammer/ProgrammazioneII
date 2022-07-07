#include "Veicolo.hpp"

void Veicolo::set_ruote (int num_ruote)
{
    this->num_ruote = num_ruote;
}

void Veicolo::set_pass (int num_passeggeri)
{
    this->num_passegeri = num_passeggeri;
}

int Veicolo::get_pass ()
{
    return this->num_passegeri;
}

int Veicolo::get_ruote() 
{
    return this->num_ruote;
}

Veicolo::Veicolo(){}

Veicolo::Veicolo(int num_ruote, int num_passeggeri) : num_ruote(num_ruote), num_passegeri(num_passegeri){}

Veicolo::Veicolo(const Veicolo &veicolo)
{
    this->num_passegeri = veicolo.num_passegeri;
    this->num_ruote = veicolo.num_ruote;
}

Veicolo::~Veicolo(){};
