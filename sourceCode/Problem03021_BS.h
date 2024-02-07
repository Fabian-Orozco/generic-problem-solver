#ifndef PROBLEM03021_BS
#define PROBLEM03021_BS

#include "Problema.h" 
#include "State03021_BS.h" 

class Problem03021_BS : public Problema {
    
    private:
        
        State03021_BS * estadoInicial;

    public:

        Problem03021_BS();

        Estado * getEstadoInicial();
        int esSolucion( Estado * );
        int heuristica( Estado * );
        Lista * getSiguientes( Estado * );

};

#endif