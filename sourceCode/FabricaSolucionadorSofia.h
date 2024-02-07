#ifndef FABRICA_SOLSOFIA
#define FABRICA_SOLSOFIA

#include "Fabrica.h"
#include "SolucionadorSofia.h"
#include <iostream> 

using namespace std; 

/**
 * @brief Clase derivada de Fabrica, produce un puntero a SolucionadorSofia
 */
class FabricaSolucionadorSofia: public Fabrica{
	public: 
		/**
		 * @brief Retorna un puntero a SolucionadorSofia 
		 * @return Puntero a SolucionadorSofia construido por omision
		 */
		SolucionadorSofia* producir(); 
}; 

#endif 