#ifndef FABRICALIGHTSOUT_H
#define FABRICALIGHTSOUT_H

#include "Fabrica.h"
#include "LightsOut.h"


/**
 * @brief Clase derivada de Fabrica, para producir un puntero a LightsOut
 */
class FabricaLightsOut : public Fabrica {
    public:
        LightsOut* producir();
};

#endif
