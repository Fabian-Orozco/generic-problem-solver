#ifndef SEPARADOR_H
#define SEPARADOR_H

#include <iostream>

/**
 * Esta clase tiene métodos para separar hileras de caracteres y liberar la
 * memoria ocupada por una hilera separada
 */
class Separador{
	public:		
		char** separar(const char* hilera);
		void liberar(char** p);
	private:
		/*
		 * Determina la longitud del string que recibe (cantidad de chars antes de '\0')
		 */
		int strlen(const char* string);
		/*
		 * Cuenta las separaciones del string que recibe (cantidad de grupos de espacios
		 * o tabulaciones sucesivas)
		 * Por ejemplo, "a\t\t b" tiene una sola separación
		 */
		int contarSeparaciones(const char* string);
		/*
		 * Copia los chars del string ref en el string buffer, hasta que llega a
		 * la posición len-1. Asigna '\0' a buffer[len-1].
		 */
		void copiarString(char* buffer, const char* ref, int len);
};

#endif
