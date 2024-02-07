#include "FabricaSolucionadorCZ.h"
#include "SolucionadorCarolina.h"

using namespace std;

/**
 * @brief Retorna un Puntero a SolucionadorCarolina
 * @return Puntero a SolucionadorCarolina construido por omisión
 */
SolucionadorCarolina* FabricaSolucionadorCZ::producir(){
    SolucionadorCarolina* r = new SolucionadorCarolina;
    return r;
}
