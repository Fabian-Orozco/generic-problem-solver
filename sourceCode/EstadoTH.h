#ifndef _ESTADOTH_
#define _ESTADOTH_

#include <iostream> 
#include "Estado.h"

#define QPLATES 4 //cantidad de platillos 
#define QTOWERS 3 //cantidad de torres
#define LINESIZE 25 //tamanio de buffer para recibir chars 

using namespace std; 

/**
 * @brief Clase derivada de Estado, representa tres torres con platillos (matrix) del problema Torres de Hanoi
 */
class EstadoTH : public Estado{
	
	friend class ProblemaTH; 
	
	private:
		/*
		 * int[][] que representa el matrix (torres) 
		 */
		int matrix[QPLATES][QTOWERS]; 
		/*
		 * Determina si el movimiento del ultimo platillo de la primera torre(columna) a la segunda(columna) indicada es valido
		 */ 
		int mover(int, int); 
		/*
		 * Devuelve la altura(fila) de la primera posicion vacia en la torre(columna) indicada
		 */
		int getPrimeraVacia(int);
		/*
		 * Devuelve el valor del platillo mas grande que no esta colocado en su estado se solucion
		 */
		int getBase(); 
		/*
		 * Modifica el char* proporcionado para representar la posicion en matrix indicada
		 */
		char* imprimirAux(int, char* &); 

	public:
		/**
		 * @brief Constructor por omision (se crea matrix QPLATES x 3) 
		 */
		EstadoTH(); 
		/** 
		 * @brief Clona this 
		 * @return Puntero a EstadoTH (clon de this) 
		 */
		EstadoTH* clonar(); 
		/**
		 * @brief Carga el estado desde un istream 
		 * @param entrada Istream del cual se carga el estado 
		 * @return istream modificado 
		 */
		istream & cargar(istream &entrada); 
		/**
		 * @brief Pasa la informacion del estado a un ostream
		 * @param salida Ostream al cual se imprime el estado 
		 * @return Ostream modificado 
		 */
		ostream & imprimir(ostream &salida);
		/**
		 * @brief Operador para determinar si dos estados son iguales
		 * @param e Puntero a estado
		 * @return True solo si e apunta a un EstadoTH y sus matrix son iguales
		 */ 
		int operator==(Estado *e); 
		/**
		 * @brief Operador para determinar si dos estados son distintos 
		 * @param e Puntero a estado 
		 * @return False solo si e apunta a un EstadoTH y sus matrix son iguales
		 */ 
		int operator!=(Estado *e);
	
}; 
#endif
