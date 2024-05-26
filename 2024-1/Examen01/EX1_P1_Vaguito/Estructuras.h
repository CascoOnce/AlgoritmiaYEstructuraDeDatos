/* 
 * File:   Estructuras.h
 * Author: AdiosCasco
 *
 */

#include "Lista.h"

#ifndef ESTRUCTURAS_H
#define ESTRUCTURAS_H

struct Producto{
   char tipo;
   struct Lista listaDeProductos;
};

struct Medicina{
    char tipo;
    int maxDatos;
    int maxCalorias;
    int valorBinario;
    struct Lista productoCorrespondiente;
};


#endif /* ESTRUCTURAS_H */

