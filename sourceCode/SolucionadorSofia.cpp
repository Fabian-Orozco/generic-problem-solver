#include "SolucionadorSofia.h"
using namespace std;   

//PUBLIC 

/**
 * @brief Soluciona un problema 
 * @param problema Puntero a problema 
 * @return Puntero a Solucion con la solucion del problema
 */
Solucion* SolucionadorSofia::solucione(Problema* problema){
	cantidadPasos = 0; 
	Lista* listaSol = new Lista(); 
	Lista* listaVis = new Lista(); 
	solR(problema->getEstadoInicial(), problema, listaSol, listaVis);
	delete listaVis; 
	Solucion * solucion = 0; 
	if(!listaSol->isEmpty()){
		solucion = new Solucion(listaSol);
	}
	return solucion; 
}


//PRIVATE 

/*
 * Resuelve recursivamente el problema, auxiliar al metodo publico 'solucione'
 */
int SolucionadorSofia::solR(Estado* actual, Problema* problema, Lista* &listaSol, Lista* &listaVis){
	int cambiarRuta = 1;
	cantidadPasos++; 
	if(problema->esSolucion(actual)){
		cambiarRuta = 0; 
	} else if(listaVis->buscar(actual)!= listaVis->end()){
		cambiarRuta = 1; 
	} else{
		listaVis->push_front(actual); 
		Lista* listaSig = problema->getSiguientes(actual); 
		ordenarLista(listaSig, problema); 
		for(Lista::Iterador i = listaSig->begin(); i!= listaSig->end() && cambiarRuta; ++i){  
			cambiarRuta = solR(*i, problema, listaSol, listaVis); 
		}
		delete listaSig; 
	}
	if(!cambiarRuta){
		listaSol->push_front(actual); 
	}
	return cambiarRuta; 
}

/*
 * Ordena la lista de menor a mayor heuristica determinada por el problema 
 */
void SolucionadorSofia::ordenarLista(Lista* list, Problema* problem){
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
                if(problem->heuristica(*i) < problem->heuristica(*j)){
                    arr.insertar(j, *i);
                    placed = true;
                }
            }
            if(!placed){
                arr.push_back(*i);
            }
        }
    }
    *list = arr;

}

