/* 
 * File:   main.cpp
 * Author: Casco
 *
 */

#include <iostream>
#include <iomanip>

#include "Pila.h"
#include "funcionesPila.h"
#define N 8

using namespace std;

int red[N][N] = {  {0, 10, 10, 10, 0, 10, 10},
                   {10, 0, 20, 30, 0, 20, 40},
                   {0, 0, 0, 0, 0, 100, 0},
                   {0, 0, 0, 0, 0, 80, 0},
                   {50, 10, 5, 10, 0, 100, 4},
                   {100, 0, 0, 0, 0, 0, 0},
                   {0, 0, 0, 0, 0, 0, 0}};

int buscarServer(int n){
   Pila server;
   int a, b;
   
   construir(server);
   for (int i = 1; i < n; i++) apilar(server, i);
   
   while(server.lista.longitud > 1){
       a = desapilar(server);
       b = desapilar(server);
       
       if (red[a][b] != 0) apilar(server, a);
       else apilar(server, b);
   }
   int candidato = desapilar(server);
   for (int i = 0; i < N; i++)
       if ((i != candidato) and (!red[candidato][i] or red[i][candidato])) return -1;
   return candidato + 1;
}

int main(int argc, char** argv) {
    int n = N;
    cout << buscarServer(n);
    return 0;
}

