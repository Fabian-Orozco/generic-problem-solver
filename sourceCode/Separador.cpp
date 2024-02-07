#include "Separador.h"

using namespace std;

/**
 * @brief Separa una hilera de caracteres
 * 
 * Separa un array de chars por grupos de espacios o tabulaciones
 * @param hilera puntero al primer char de la hilera que se separa
 * @return array de punteros a char, cada uno apunta a una de las "palabras"
 * de la hilera original, el último tiene una hilera formada por "\0"
 */
char** Separador::separar(const char* hilera){
	int palabras = contarSeparaciones(hilera) + 1;
	char**resultado = new char*[palabras + 1];
	int posicionResultado = 0;
	char* inicio = (char*) hilera;
	char* fin;
	bool enSeparacion = true;
	bool esFinal = false;
	for(fin = inicio; !esFinal; ++fin){
		if(*fin == ' ' || *fin == '\t' || *fin == '\0'){
			if(!enSeparacion){
				resultado[posicionResultado] = new char[fin - inicio + 1];
				copiarString(resultado[posicionResultado], inicio, fin - inicio + 1);
				++posicionResultado;
				enSeparacion = true;
				esFinal = *fin == '\0';
			}
			else{
				esFinal = *fin == '\0';
			}
		}
		else{
			if(enSeparacion){
				inicio = fin;
			}
			enSeparacion = false;
		}
	}
	resultado[palabras] = new char[1]{};
	return resultado;
}

/**
 * @brief Libera la memoria ocupada por un array de hileras de chars
 * @param p Array de hileras de chars cuya memoria se libera
 */
void Separador::liberar(char** p){
	bool esFinal = false;
	int i = 0;
	while(!esFinal){
		//cout << "se va a borrar p[" << i << "]: " << p[i] << endl;
		esFinal = p[i][0] == '\0';
		delete[] p[i];
		++i;
	}
	
	delete[] p;
}

/*
 * Determina la longitud del string que recibe (cantidad de chars antes de '\0')
 */
int Separador::strlen(const char* string){
	char* mov = (char*) string;
	while(*mov){
		++mov;
	}
	return mov-string + 1;
}

/*
 * Cuenta las separaciones del string que recibe (cantidad de grupos de espacios
 * o tabulaciones sucesivas)
 * Por ejemplo, "a\t\t b" tiene una sola separación
 */
int Separador::contarSeparaciones(const char* string){
	int len = strlen(string);
	int separaciones = 0;
	bool enSeparacion = true;
	for(int i = 0; i < len-1; ++ i){
		if(string[i] == ' ' || string[i] == '\t'){
			if(!enSeparacion){
				++separaciones;
				enSeparacion = true;
			}
		}
		else{
			enSeparacion = false;
		}
	}
	if(enSeparacion && separaciones){
		separaciones -= 1;
	}
	//cout << "Separaciones: " << separaciones << endl;
	return separaciones;
}

/*
 * Copia los chars del string ref en el string buffer, hasta que llega a
 * la posición len-1. Asigna '\0' a buffer[len-1].
 */
void Separador::copiarString(char* buffer, const char* ref, int len){
	for(int i = 0; i < len; ++i){
		buffer[i] = ref[i];
	}
	buffer[len-1] = '\0';
}
