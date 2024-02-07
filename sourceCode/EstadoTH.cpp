#include "EstadoTH.h"
using namespace std; 

//PUBLICOS 

/**
 * @brief Constructor por omision (se crea matrix QPLATES x 3) 
 */
EstadoTH::EstadoTH(){
	for(int f = QPLATES-1; f>= 0; --f){
		matrix[f][0] = f+1; 
	}
	for(int f = 0; f < QPLATES; ++f){
		for(int c = 1; c <QTOWERS; ++c){
			matrix[f][c] = 0; 
		}
	}
}

/** 
 * @brief Clona this 
 * @return Puntero a EstadoTH (clon de this) 
 */
EstadoTH* EstadoTH::clonar(){
	EstadoTH * copia = new EstadoTH(); 
	for(int f = 0; f <QPLATES; ++f){
		for(int c = 0; c< QTOWERS; ++c){
			copia->matrix[f][c] = matrix[f][c]; 
		}
	}
	return copia; 
}

/**
 * @brief Carga el estado desde un istream 
 * @param entrada Istream del cual se carga el estado 
 * @return istream modificado 
 */
istream & EstadoTH::cargar(istream & entrada){
	for(int c = 0; c < QTOWERS; ++c){
		for(int f = QPLATES-1; f >= 0; f--){
			entrada >> matrix[f][c]; 
		}
	}
	return entrada; 
}

/**
 * @brief Pasa la informacion del estado a un ostream
 * @param salida Ostream al cual se imprime el estado 
 * @return Ostream modificado 
 */
ostream & EstadoTH::imprimir(ostream & salida){
	for(int f = 0; f < QPLATES; ++f){
		for(int c = 0; c < QTOWERS; ++c){
			char* buffer = new char[LINESIZE];
			salida << imprimirAux(matrix[f][c], buffer) << "   "; 
			delete buffer; 
		}
		salida << endl; 
	}
	return salida; 
}

/**
 * @brief Operador para determinar si dos estados son iguales
 * @param e Puntero a estado
 * @return True solo si e apunta a un EstadoTH y sus matrix son iguales
 */ 
int EstadoTH::operator==(Estado* estado){
	int iguales = 1; 
	EstadoTH * estadoEq = dynamic_cast< EstadoTH* > (estado); 
	if(estadoEq){
		int f = 0; 
		while(iguales && f < QPLATES){
			int c = 0; 
			while(iguales && c < QTOWERS){
				iguales = estadoEq->matrix[f][c] == matrix[f][c]; 
				c++; 
			}
			f++; 
		}
	} else{
		iguales = 0; 
	}
	return iguales; 
}

/**
 * @brief Operador para determinar si dos estados son distintos 
 * @param e Puntero a estado 
 * @return False solo si e apunta a un EstadoTH y sus matrix son iguales
 */ 
int EstadoTH::operator!=(Estado* estado){
	return !(*this == estado); 
}

//PRIVADOS

/*
 * Determina si el movimiento del ultimo platillo de la primera torre(columna) a la segunda(columna) indicada es valido
 */
int EstadoTH::mover(int torreO, int torreD){ //recibe torre origen y torre destino 
	int movidaValida = 0; 
	int filaO = getPrimeraVacia(torreO); 
	int filaD = getPrimeraVacia(torreD); 
	if(filaO < QPLATES-1){
		if(filaD == QPLATES -1){
			movidaValida = 1; 
		} else if(matrix[filaO+1][torreO] < matrix[filaD+1][torreD] && matrix){ 
			movidaValida = 1; 
		}
	}
	if(movidaValida){
		matrix[filaD][torreD] = matrix[filaO+1][torreO]; 
		matrix[filaO+1][torreO] = 0;
	}
	return movidaValida; 
}

/*
 * Devuelve la altura(fila) de la primera posicion vacia en la torre(columna) indicada
 */
int EstadoTH::getPrimeraVacia(int torre){ 
	int position = QPLATES-1; 
	while(position >= 0 && matrix[position][torre] != 0){
		position--; 
	}
	return position; 
}

/*
 * Devuelve el valor del platillo mas grande que no esta colocado en su estado se solucion
 */
int EstadoTH::getBase(){
	int base = QPLATES; 
	int position = 0; //4 
	int baseEncontrada = 0; 
	while(!baseEncontrada && position < QPLATES){
		if(matrix[position][2] == position+1){
			baseEncontrada = 1; 
			base = position; 
		} else{
			position++; 
		}
	}
	return base; 
}

/*
 * Modifica el char* proporcionado para representar la posicion en matrix indicada
 */
char* EstadoTH::imprimirAux(int base, char* & buffer){
	int endPosition = (QPLATES+1)*2; 	
	//coloca espacios vacios 
	for(int position = 0; position < QPLATES-base; position++){
		buffer[position] = ' '; 
		buffer[endPosition-position] = ' '; 
	}
	//coloca bases 
	buffer[QPLATES-base]  = '|';
	buffer[endPosition-QPLATES+base] = '|'; 
	for(int position = QPLATES-base+1; position< endPosition/2; position++){
		buffer[position] = '_'; 
		buffer[endPosition-position]= '_'; 
	}			
	if(base == 0){
		buffer[endPosition/2] = '|'; 
	} else{
		buffer[endPosition/2] = char(base+48); 
	}
	buffer[endPosition+1] = '\0'; 
	return buffer;
}