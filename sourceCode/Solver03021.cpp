/**
 * @file Solver03021.cpp
 * @author Fabián Orozco, Sofía Shum y Carolina Zamora.
 * @brief La Clase Solver03021 representa un solucionador genérico que busca la solución óptima de un problema que se resuelve por algorítmos de búsqueda.
 * @version 1.0
 * @date 2021-09-07
 * 
 * @copyright Copyright (c) 2021
 */

#include "Solver03021.h" 


/**
 * @brief Método que recibe un problema y se encarga de explorarlos con ayuda de la clase EstadoConRuta y el método 'busqueSolucion' con una técnica de implementación de Listas.
 * 
 * Busca la solución óptima de cada problema de la siguiente manera:
 * Posee una listaDeEstados que sirve temporalmente para inicializar los estadosConRuta iniciales.
 * Posee una frontera (COLA/FIFO) que representa los estados que deben verificarse si son solución y además que faltan de expandirse para obtener los siguientes.
 * Posee una lista de visitados para evitar agregar duplicados a la frontera.
 * 
 * Llama al método auxiliar 'busqueSolucion' para que se encargue de manejar (por ciclo while) las listas en la exploración.
 * De su manejo es prioridad la frontera ya que si encuentra solución, será el primer elemento de ella.
 * 
 * @param problema Recibe un puntero a Problema que se quiere solucionar.
 * @return Solucion* o 0 Devuelve una instancia de Solución que contiene la lista de estados desde el inicio hasta llegar a la solución del problema, esto en caso de haber hallado la solución. Retorna 0 en caso contrario.
 */
Solucion * Solver03021::solucione( Problema * problema){
    Lista * listaDeEstados = new Lista(); //contiene elementos tipo 'estadoDerivado'
    Lista * visitados = new Lista(); //contiene elementos tipo 'estadoDerivado'
    Estado * inicial = problema->getEstadoInicial(); 
    EstadoConRuta * inicialConRuta = new EstadoConRuta(inicial,*listaDeEstados);
    Lista * frontera = new Lista(); //contiene elementos tipo estadoConRuta (los que faltan por explorar)
    frontera->push_front(inicialConRuta);

    busqueSolucion(listaDeEstados,visitados,frontera,inicial,problema);

    if( !frontera->isEmpty() ){ //no está vacía y terminó la busqueda entonces hay solución
        EstadoConRuta * estadoSolucion = dynamic_cast <EstadoConRuta*> (*frontera->begin());
        if(estadoSolucion){

            Solucion * solucionado = new Solucion( new Lista ( *estadoSolucion->getRuta()) );
            
            //liberación de memoria
            if(inicial)
                delete inicial;
            if(listaDeEstados)
                delete listaDeEstados;
            if(visitados)
                delete visitados;
            if(frontera)
                delete frontera;
            
            return solucionado; //retorno de solución
        }
    }
    return 0;
}

/**
 * @brief Método que explora los estados del problema para hallar una solución óptima. 
 * En cada ciclo de while verifica si el primer estado de la frontera es solución y si quedan estados por explorar.
 * 
 * 
 * @param listaDeEstados Recibe una lista por puntero, representa la lista que sirve para inicializar al primer 'EstadoConRuta'.
 * @param visitados Recibe una lista por puntero, representa la lista de 'estadosDerivados' que ya han sido agregados a la frontera para evitar duplicados.
 * @param frontera Recibe una lista por puntero, representa la lista de 'estadosConRuta' tratada en forma de cola, con los estados que faltan por expandir.
 * @param inicial Recibe un Estado por puntero, representa el 'estadoDerivado' inicial del problema.
 * @param problema Recibe un Problema por puntero, representa el problema que se quiere solucionar.
 */
void Solver03021::busqueSolucion(Lista* listaDeEstados, Lista* visitados, Lista* frontera, Estado * inicial, Problema * problema){
    EstadoConRuta * evaluado = new EstadoConRuta(inicial,*listaDeEstados); //puntero 'estadoConRuta' que apunta al primer elemento de la frontera
    while( !frontera->isEmpty() && !problema->esSolucion( evaluado->getEstado() ) ){ //mientras no se haya terminado de recorrer y no haya solucion
        EstadoConRuta * actual = dynamic_cast <EstadoConRuta *> ( *frontera->begin() ); //verifico que el primer estado de la frontera sea estadoConRuta
        
        if(actual){
            visitados->push_front( actual->getEstado() );
            Lista * siguientes = problema->getSiguientes( actual->getEstado() );
            ordenarLista(siguientes,problema); //la ordena por heurística
            for(Lista::Iterador i = siguientes->begin(); i != siguientes->end(); ++i){ 
                if( (visitados->buscar( *i ) ) == visitados->end()){ //si el iterador es nulo (porque el estado no estaba en visitados)
                    EstadoConRuta * nuevo = new EstadoConRuta(*i, *(actual->getRuta()));
                    frontera->push_back(nuevo); //agrego el estado al final frontera para ser explorado luego
                    visitados->push_front( nuevo->getEstado() ); //lo agrega a visitados para evitar que se duplique en la frontera en un ciclo futuro.
                    delete nuevo;
                }
            }
            delete siguientes;
            
            //'evaluado' cambia y apunta al segundo estadoConRuta de la frontera
            if( (++(frontera->begin())) != 0){
                Lista::Iterador i = ++(frontera->begin());
                EstadoConRuta * cambio = dynamic_cast <EstadoConRuta*> (*i);
                if(cambio)
                    evaluado = cambio;
            }
            
            
            frontera->pop_front(); //elimina el primer elemento de la frontera porque no era solución y ya lo exploré.
        }
    }
}
/**
 * @brief Ordena la lista ascendentemente por la heurística determinada por el problema.
 * @param lista Recibe una lista por puntero, representa la lista que se quiere ordenar.
 * @param problema Recibe un Problema por puntero, representa el problema que se quiere solucionar.
 */

void Solver03021::ordenarLista(Lista * lista, Problema* problema){
	Lista ordenada;
    Lista::Iterador i;
    for(i = lista->begin(); i != lista->end(); ++i){
        if(ordenada.isEmpty()){
            ordenada.push_back(*i);
        }
        else{
            Lista::Iterador j;
            int insertado = 0;
            for(j = ordenada.begin(); j != ordenada.end() && !insertado; ++j){
                if(problema->heuristica(*i) < problema->heuristica(*j)){
                    ordenada.insertar(j, *i);
                    ++insertado;
                }
            }
            if(!insertado){
                ordenada.push_back(*i);
            }
        }
    }
    *lista = ordenada;
}
