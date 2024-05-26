/* 
 * File:   main.cpp
 * Author: AdiosCasco
 *
 */

#include <iostream>
#include <fstream>
using namespace std;
#include "Estructuras.h"
#include "funciones.h"


void ingresoDeDatos(ostream &output, istream &input, int &nTipos, struct Producto *&productos){
    output << "Ingreso de datos:" << endl << "Cantidad de productos a ingresar: " << endl;
    input >> nTipos;
    output << nTipos << endl;
    
    productos = new struct Producto [nTipos];
    for (int i = 0; i < nTipos; i++){
        output << "Tipo de producto: ";
        input >> productos[i].tipo;
        output << productos[i].tipo;
        output << endl << "Calorías de los productos " << productos[i].tipo << ": ";
        construir(productos[i].listaDeProductos);
        int dato = 1;
        while (true){
            input >> dato;
            output << dato;
            if (dato == 0) break;
            else{
                insertarAlFinal(productos[i].listaDeProductos, dato);
            }
            output << ' ';
        }
        output << endl;
    }
}

void ingresoDeMedicinas(ostream &output, istream &input, int &nTiposMed, struct Medicina *&medicinas){
    output << "Ingreso de restricciones: " << endl;
    output << "Ingrese la cantidad de tipos de productos de la formula: ";
    input >> nTiposMed;
    output << nTiposMed << endl;
    medicinas = new struct Medicina[nTiposMed];
    for(int i = 0; i < nTiposMed; i++){
        output << "Tipo de Producto: ";
        input >> medicinas[i].tipo;
        output << medicinas[i].tipo << endl << "Total de calorías máxima de todos los productos " << medicinas[i].tipo << ": ";
        input >> medicinas[i].maxDatos;
        output << medicinas[i].maxDatos << endl << "Total de calorías máxima de todos los productos " << medicinas[i].maxDatos << ": ";
        input >> medicinas[i].maxCalorias;
        output << medicinas[i].maxCalorias << endl;
    }
}

bool comprobarExistePosibilidad(int &nTiposMed, struct Medicina *&medicinas, int &nTipos, struct Producto *&productos){
    for(int i = 0; i < nTiposMed; i++){
        for(int j = 0; j < nTipos; j++){
            if (medicinas[i] == productos[j]) {
                medicinas[i].productoCorrespondiente = productos[j].listaDeProductos;
                break;
            }
        }
    }
    
}

int main(int argc, char** argv) {
    ifstream input("IngresoDeDatos.txt", ios::in);
    ofstream output("reporte.txt", ios::out);
    int nTipos, nTiposMed;
    struct Producto *productos;
    struct Medicina *medicinas;
    ingresoDeDatos(output, input, nTipos, productos);
    output << endl;
    ingresoDeMedicinas(output, input, nTiposMed, medicinas);
    return 0;
}

//Ingreso de datos:
/* Cantidad de productos a ingresar:
 * 4
 * Tipo de Producto: 
 * Calorías de los productos A: 120 145 230 247 285 0
 * Tipo de Producto:
 * Calorías de los productos D: 182 240 300 0
 * Tipo de Producto: 
 * Calorías de los productos B: 58 120 247 278 0
 * Tipo de Producto:
 * Calorías de los productos H: 128 236 354 540 782 0
 * Ingrese la cantidad de tipos de productos de la formula:
 * Tipo de Producto:
 * Cantidad de Productos del Tipo A: 2
 * Total de calorías máxima de todos los productos A: 674
 * Tipo de Producto: H
 * Cantidad de Productos del Tipo H: 3
 * Total de calorías máxima de todos los productos H: 952
 * 
 */

