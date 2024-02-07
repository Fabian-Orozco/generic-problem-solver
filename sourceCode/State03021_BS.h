#ifndef STATE03021_BS
#define STATE03021_BS

#include "Estado.h"
#include "Matriz03021_BS.h"

class State03021_BS : public Estado {
    
    friend class Problem03021_BS;

    private:
    
        Matriz03021_BS * matrizEstado;

    public:
        istream& cargar( istream& );
        ostream& imprimir( ostream& );

        State03021_BS();
        State03021_BS( Matriz03021_BS & );
        ~State03021_BS();

        State03021_BS * clonar();
        int operator==( Estado * );
        int operator!=( Estado * );

};

#endif
