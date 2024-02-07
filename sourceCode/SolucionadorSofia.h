#ifndef _SOLUCIONADORSV_
#define _SOLUCIONADORSV_

#include "Solucionador.h"
 
using namespace std; 

/**
 * @brief Solucionador de Sofia, clase derivada de Solucionador
 */
class SolucionadorSofia: public Solucionador{
	private: 
		/*
		 * Ordena la lista de menor a mayor heuristica determinada por el problema 
		 */
		void ordenarLista(Lista*, Problema*);
		/*
		 * Resuelve recursivamente el problema, auxiliar al metodo publico 'solucione'
		 */
		int solR(Estado*, Problema*, Lista* &, Lista* &); 
	public: 
		/**
		 * @brief Contador para la cantidad de pasos en los cuales se soluciono el problema
		 */
		int cantidadPasos; 
		/**
		 * @brief Soluciona un problema 
		 * @param problema Puntero a problema 
		 * @return Puntero a Solucion con la solucion del problema
		 */
		Solucion* solucione(Problema *problema); 
		
}; 

#endif