#include "SolucionadorCarolina.h"
#include "Problema.h"

using namespace std;

/**
 * @brief Encuentra la solución de un problema
 * @param problema Puntero a problema
 * @return Puntero a Solución con la solución del problema
 */
Solucion* SolucionadorCarolina::solucione(Problema *problem){
    Lista* sol = new Lista();
    Estado* initial = problem->getEstadoInicial();
    solve(problem, initial, sol);
    if(sol->isEmpty()){
        sol = 0;
    }
    Solucion* solution = 0;
    if(sol){
        solution = new Solucion(sol);
    }
    delete initial;
    return solution;
}

/*
 * Agrega e a la Lista si no estaba antes:
 * set U {e}
 */
void SolucionadorCarolina::setAdd(Lista& set, Estado* e){
    bool isElement = false;
    Lista::Iterador i;
    for(i = set.begin(); i != set.end() && !isElement; ++i){
        isElement = *e == *i;
    }
    if(!isElement){
        set.push_back(e);
    }
}

/*
 * Retorna la resta de conjuntos set \ excluded en una Lista
 */
Lista* SolucionadorCarolina::difference(Lista& set, Lista& excluded){
    Lista* diff = new Lista(set);
    Lista::Iterador i;
    for(i = diff->begin(); i != diff->end(); ++i){
        bool isExcluded = false;
        Lista::Iterador j;
        for(j = excluded.begin(); j != excluded.end() && !isExcluded; ++j){
            isExcluded = **i==*j;
        }
        if(isExcluded){
            diff->borrar(i);
        }
    }
    return diff;
}

/*
 * Resuelve el problema (problem), escribiendo la solución en sol
 * a partir del estado inicial (initial)
 */
void SolucionadorCarolina::solve(Problema* problem, Estado* initial, Lista* sol){
    Lista visited;
    sol->push_back(initial);
    visited.push_back(initial);
    if(!solveR(problem, initial, sol, visited)){
		cout << initial << endl;
		sol->pop_back();
	}
}

/*
 * sol es la lista de la "solución" (es el path para llegar hasta current,
 * el método determina recursivamente si en efecto es una solución o tiene que hacer backtracking)
 */
/*
 * visited es una "Lista" de los estados que ya ha visitado, con el propósito
 * de que no los vuelva a visitar y así no se quede en un ciclo (es de tipo Lista,
 * pero en realidad conceptualmente es un conjunto de estados porque no se repiten los elementos)
 */
/*
 * Una "ruta sin salida" es una forma particular de Lista de estados en la cual el último
 * estado "e" cumple cualquiera de estas:
 * a) la lista de estados siguientes de e está vacía (ya no se puede mover por las reglas del problema),
 * b) todos los elementos de la lista de estados siguientes de e están en visited (ya no se puede mover 
 *     porque si se moviera sería redundante y se podría enciclar)
 */
/*
 * Entonces, cuando no se ha hallado una solución, el que la ruta sea una ruta sin salida
 * determina una condición de parada: en este punto es que hay que hacer backtracking
 * (hay que eliminar el último estado agregado e)
 * Una vez que se devuelve al estado "padre" de e, si todos los siguientes estados de padre ya han
 * sido visitados y ninguno condujo a una solución, entonces la ruta que termina en padre también
 * es una ruta sin salida, y se debe hacer backtracking desde padre también.
 * Es decir, la propiedad de ser una "ruta sin salida" funciona para la recursión, en la tarea
 * de determinar cuándo un estado lleva a una solución.
 * Si la lista que solo contiene el estado inicial es una ruta sin salida, el problema
 * que se ha proporcionado no tiene solución.
 */

bool SolucionadorCarolina::solveR(Problema* problem, Estado* current, Lista* sol, Lista& visited){
    bool solved = current && problem->esSolucion(current); //otra condición de parada: current es una solución
    if(!solved){ //si no es solución, tiene que seguir inspeccionando la rama con todos los posibles siguientes estados
        Lista* next = problem->getSiguientes(current);
        Lista* diff = difference(*next, visited); // diff = siguientes \ visited
        *next = *diff; //elimina de los posibles siguientes estados los que ya visitó (no es necesario volver a analizarlos)
        delete diff;
        arrange(problem, next); //reordena la lista de siguientes estados de menor a mayor heurística
        Lista::Iterador i;
        for(i = next->begin(); i != next->end() && !solved; ++i){ //recorre los siguientes estados mientras que no se haya encontrado una solución
            //solo analiza el estado (apuntado por *i) si no está en visited:
            if(visited.buscar(*i) == visited.end()){
				/*
				 * (Se tiene que volver a revisar porque de una iteración a otra al explorar
				 * toda la rama bajo *i puede visitarse alguno de los otros estados de la lista next)
				 */
                sol->push_back(*i); //se agrega el estado *i a la ruta de solución para ver si conduce a una solución
                setAdd(visited, *i); //se agrega *i a visited usando setAdd, que lo que hace es:
                //visited U {*i} (unión de conjuntos - solo agrega *i si no estaba antes)
                solved = solveR(problem, *i, sol, visited);
                //Ahora llama al método recursivo para explorar toda la rama que surge del estado *i, viendo si hay una solución (solved = true)
                //o si se trata de una ruta sin salida (solved = false)
                if(!solved){
					/*
					 * backtracking (que arriba se justifica por qué sirve con la recursión)
					 */
                    sol->pop_back();
                }
            }
        }
        
        delete next;
    }
    return solved;
}

/*
 * Ordena la lista de menor a mayor heurística determinada por el problema
 */
void SolucionadorCarolina::arrange(Problema* problem, Lista* list){
    Lista arr;
    Lista::Iterador i;
    for(i = list->begin(); i != list->end(); ++i){
        if(arr.isEmpty()){
            arr.push_back(*i);
        }
        else{
            Lista::Iterador j;
            bool placed = false;
            for(j = arr.begin(); j != arr.end() && !placed; ++j){
                if(*i && problem->heuristica(*i) < problem->heuristica(*j)){
                    arr.insertar(j, *i);
                    placed = true;
                }
            }
            if(!placed && *i){
                arr.push_back(*i);
            }
        }
    }
    *list = arr;
}
