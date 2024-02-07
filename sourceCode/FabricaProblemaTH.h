#ifndef FABRICA_PROBTH
#define FABRICA_PROBTH

#include <iostream> 
#include "Fabrica.h"
#include "ProblemaTH.h"

using namespace std; 

/**
 * @brief Clase derivada de Fabrica, produce un puntero a ProblemaTH
 */
class FabricaProblemaTH: public Fabrica{
	public: 
		/**
		 * @brief Retorna un puntero a ProblemaTH
		 * @return Puntero a ProblemaTH construido por omision 
		 */
		ProblemaTH* producir(); 
}; 

#endif