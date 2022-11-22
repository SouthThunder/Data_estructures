#ifndef __ARISTA__H__
#define __ARISTA__H__
#include "Vertice.h"
using namespace std;

template <class T>
class Arista
{
    protected:
        double peso;
        Vertice<T>* sucesor;
        int indice_sucesor;
        
    public:
        Arista();
        Arista(Vertice<T>* verDes, double peso, int ind);
        double getPeso();
        int getIndice();
        void setIndice(int in);
        Vertice<T>* getSucesor();
        void setPeso(double peso);
        void setSucesor(Vertice<T>* sucesor);
        bool operator <(Arista<T>& ar);
};

#include "Arista.hxx"
#endif