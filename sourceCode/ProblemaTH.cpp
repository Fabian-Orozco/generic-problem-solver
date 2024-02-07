
#include "ProblemaTH.h"
using namespace std; 

//PUBLICOS 

/**
 * @brief Obtiene el estado inicial EstadoTH del problema 
 * @return Puntero a Estado inicial 
 */
Estado* ProblemaTH::getEstadoInicial(){
	EstadoTH * inicio = new EstadoTH(); 
	return inicio; 
}

/**
 * @brief Determina si un estado es solucion 
 * @param e Puntero a Estado 
 * @return True Solo si e apunta a un EstadoTH y todas las posiciones en la ultima torre(columna 2) poseen un valor de fila+1 
 */
int ProblemaTH::esSolucion(Estado* estado){
	int esSolucion = 0; 
	EstadoTH * estadoTH = dynamic_cast<EstadoTH*>(estado); 
	if(estadoTH){
		esSolucion = 1; 
		int f = QPLATES -1; 
		while(esSolucion && f>= 0){
			if(estadoTH->matrix[f][2] != f+1){
				esSolucion = 0; 
			} else{
				f--; 
			}
		}
	}
	return esSolucion; 
}

/** 
 * @brief Determina la heuristica de un estado
 * @param e Puntero a Estado 
 * @return Valor de la heuristica
 */
int ProblemaTH::heuristica(Estado* actual){
	int heuristica = QPLATES*(QPLATES+1)/2; //sumatoria de valores de placas
	EstadoTH* estadoAc = dynamic_cast<EstadoTH*>(actual); 
	
	if(estadoAc){
		int base = estadoAc->getBase(); 
		int filaBase = QPLATES-1; 
		int columnaBase = 0; 
		int baseEsTop = 1; 
		
		//busca donde esta la columna base
		if(estadoAc->matrix[filaBase][columnaBase] != base){
			columnaBase = 1; 
		}      
		//le suma el valor de los platillos encima del platillo base 
		for(int position = filaBase-1; estadoAc->matrix[position][columnaBase] != 0 && position >= 0; position--){
			heuristica += estadoAc->matrix[position][columnaBase]; 
			if(baseEsTop){
				baseEsTop = 0; 
			}
		}
		if(baseEsTop){
			for(int p = QPLATES-1; p >= 0 && estadoAc->matrix[p][2] != 0; p--){
				heuristica += estadoAc->matrix[p][2]; 
			}
		}
		for(int fila  = QPLATES-1; estadoAc->matrix[fila][2] != 0 && fila >= 0; fila--){
			if(estadoAc->matrix[fila][2] == fila+1){
				heuristica -= fila+1; 
			}
		}
	}
	return heuristica; 
}

/**
 * @brief Determina todos los posibles estados siguientes apartir de un estado
 * @param e Puntero a Estado 
 * @return Puntero a Lista que contiene los estados siguientes a *e
 */
Lista* ProblemaTH::getSiguientes(Estado* base){
	Lista* siguientes = new Lista(); 
	EstadoTH* baseTH = dynamic_cast<EstadoTH*>(base); 
	if(baseTH){
		for(int c = 0; c <QTOWERS; c++){ //examina cada torre 
			for(int torre = 0; torre<QTOWERS; torre++){//examina la posibilidad de cada torre
				if(c != torre){ //se asgura que no este examinando quedarse igual como una posibilidad 
					EstadoTH* clone = baseTH->clonar(); 
					if(clone->mover(c, torre)){
						siguientes->push_back(clone); 
					}
					delete clone; 
				}
			}
		}
	}
	return siguientes; 
}