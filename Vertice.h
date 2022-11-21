#ifndef __VERTICE__H__
#define __VERTICE__H__

using namespace std;

template <class T>
class Vertice
{
    protected:
        T dato;

    public:
        Vertice();
        Vertice(T dato);
        T* getDato();
        void setDato(T dato);
        bool operator <(Vertice<T>& ver);
};

#include "Vertice.hxx"
#endif