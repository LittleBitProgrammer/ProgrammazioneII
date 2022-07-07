#ifndef _Veicolo_HPP_
#define _Veicolo_HPP_

class Veicolo{
    private:
        int num_ruote;
        int num_passegeri;

    public:
        /* Setter */
        void set_ruote(int num_ruote);
        void set_pass(int num_passeggeri);

        /* Getter */
        int get_ruote();
        int get_pass();

        /* Constructor */
        Veicolo(int num_ruote, int num_passeggeri);
        Veicolo();
        /* Copy Constructor */
        Veicolo(const Veicolo &veicolo);

        /* Destructor */
        ~Veicolo();

};
#endif  