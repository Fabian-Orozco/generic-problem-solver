#include "FabricaLightsOut.h"
#include "LightsOut.h"

using namespace std;

/**
 * @brief Retorna un Puntero a LightsOut
 * @return Puntero a LightsOut construido por omisión
 */
LightsOut* FabricaLightsOut::producir(){
    LightsOut* lo = new LightsOut();
    return lo;
}
