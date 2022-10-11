#ifndef NODO_H
#define NODO_H

#include<iostream>
#include<string.h>
#include <queue>

using namespace std;

class NodoH
{
private:
    char dato;
    unsigned int freq;
    NodoH *der, *izq;
    
public:
    NodoH();
    NodoH(char dato, unsigned int freq);
    NodoH* obtenerHijoIzq();
    NodoH* obtenerHijoDer();
    void fijarHijoDer(NodoH* der);
    void fijarHijoIzq(NodoH* izq);
    unsigned int obtenerFreq();
    char obtenerDato();
    bool esHoja();

};


#include "NodoH.hxx"
#endif 
