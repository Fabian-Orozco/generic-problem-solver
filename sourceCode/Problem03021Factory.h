#ifndef PROBLEM03021Factory
#define PROBLEM03021Factory

#include "Fabrica.h"
#include "Problem03021_BS.h"

class Problem03021Factory : public Fabrica {
    
    public:
       
        ~Problem03021Factory();
        Problem03021_BS * producir();

};

#endif
