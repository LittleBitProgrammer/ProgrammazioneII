#ifndef _CAMION_HPP_
#define _CAMION_HPP_

#include "Veicolo.hpp"

class Camion : public Veicolo
{
    private:
        int peso_rimorchio;

    public:
        /* Setter */
        void set_peso(int peso_rimorchio);

        /* Getter */
        int get_peso();

        /* Constructor */
        Camion(int num_ruote, int num_passeggeri, int peso_rimorchio);
        Camion();
        Camion(const Camion &camion);

        /* Destructor */
        ~Camion();   

        /* Show */
        void show();
};

#endif 