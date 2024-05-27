/* 
 * File:   main.cpp
 * Author: AdiosCasco
 *
 */

#include <iostream>

using namespace std;
#include "funcionesArbolesBinarios.h"
#include "ArbolBinario.h"

void generarArbolBinario(struct NodoArbol *&nodoCima, int arreglo[], int inicio, int fin, int binario){
    if (inicio == fin){
        nodoCima = crearNuevoNodoArbol(nullptr, arreglo[inicio], nullptr, binario);
        return;
    }
    struct NodoArbol *arbolIzq, *arbolDerecha;
    generarArbolBinario(arbolIzq, arreglo, inicio + 1, fin, 0);
    generarArbolBinario(arbolDerecha, arreglo, inicio + 1, fin, 1);
    if (inicio == -1){
        nodoCima = crearNuevoNodoArbol(arbolIzq, 0, arbolDerecha, binario);
    }else nodoCima = crearNuevoNodoArbol(arbolIzq, arreglo[inicio], arbolDerecha, binario);
}

void imprimirPosibles(struct NodoArbol *cromosoma, int maximo, int ini, int fin, int sumaBin, bool &esSolucion, bool &yaInicio){
    if (ini == fin){
        if (sumaBin + (cromosoma->binario*cromosoma->elemento) == maximo){
            cout << '[' ;
            if (cromosoma->binario == 1){
                cout << cromosoma->elemento;
                yaInicio = true;
            }else yaInicio = false;
            esSolucion = true;
        }else esSolucion = false; 
        return;
    }
    imprimirPosibles(cromosoma->izquierda, maximo, ini + 1, fin, sumaBin + (cromosoma->binario*cromosoma->elemento), esSolucion, yaInicio);
    if (esSolucion){
        if (cromosoma->binario == 1 and yaInicio) cout << ',' << cromosoma->elemento;
        else if (cromosoma->binario == 1){
            cout << cromosoma->elemento;
            yaInicio = true;
        }
        if (ini == 1)cout << ']' << endl;
        else{
            esSolucion = true;
            return;
        }
    }
    imprimirPosibles(cromosoma->derecha, maximo, ini + 1, fin, sumaBin + (cromosoma->binario*cromosoma->elemento), esSolucion, yaInicio);
    if (esSolucion){
        if (cromosoma->binario == 1 and yaInicio) cout << ',' << cromosoma->elemento;
        else if (cromosoma->binario == 1){
            cout << cromosoma->elemento;
            yaInicio = true;
        }
        if (ini == 1)cout << ']' << endl;
        else{
            esSolucion = true;
            return;
        }
    }
    esSolucion = false;
}

int main(int argc, char** argv) {
    int arreglo[] = {10, 50, 20, 30, 40};
    int n = 5;
    struct ArbolBinario cromosoma;
    construir(cromosoma);
    struct NodoArbol *nodoIzq, *nodoDer;
    generarArbolBinario(cromosoma.raiz,arreglo, -1, 4, 0);
    bool esSolucion = false, yaInicio = false;
    imprimirPosibles(cromosoma.raiz, 70, 0, 5, 0, esSolucion, yaInicio);
    return 0;
}

