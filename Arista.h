#ifndef __ARISTA__H__
#define __ARISTA__H__
#include "Vertice.h"
using namespace std;

template <class T>
class Arista
{
    protected:
        float peso;
        Vertice<T>* sucesor;
        
    public:
        Arista();
        Arista(Vertice<T>* verDes, float peso);
        float getPeso();
        Vertice<T>* getSucesor();
        void setPeso(float peso);
        void setSucesor(Vertice<T>* sucesor);
        bool operator <(Arista<T>& ar);
};

#include "Arista.hxx"
#endif