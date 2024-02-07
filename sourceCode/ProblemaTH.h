#ifndef _PROBLEMATH_
#define _PROBLEMATH_

#include "Problema.h"
#include "EstadoTH.h"
#include "Estado.h"
#include <iostream> 
#include "Lista.h"

/**
 * @brief Clase derivada de Problema, representa problema Torres de Hanoi
 */
class ProblemaTH: public Problema{
	public: 
		/**
		 * @brief Obtiene el estado inicial EstadoTH del problema 
		 * @return Puntero a Estado inicial 
		 */
		Estado* getEstadoInicial(); 
		/**
		 * @brief Determina si un estado es solucion 
		 * @param e Puntero a Estado 
		 * @return True Solo si e apunta a un EstadoTH y todas las posiciones en la ultima torre(columna 2) poseen un valor de fila+1 
		 */
		int esSolucion(Estado *e); 
		/** 
		 * @brief Determina la heuristica de un estado
		 * @param e Puntero a Estado 
		 * @return Valor de la heuristica
		 */
		int heuristica(Estado *e); 
		/**
		 * @brief Determina todos los posibles estados siguientes apartir de un estado
		 * @param e Puntero a Estado 
		 * @return Puntero a Lista que contiene los estados siguientes a *e
		 */
		Lista* getSiguientes(Estado *e); 
}; 

#endif