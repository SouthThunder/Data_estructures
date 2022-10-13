#ifndef ARBOL__H__
#define ARBOL__H__

#include "NodoH.h"
#include <utility>
#include <list>
#include <vector>
using namespace std;

class ArbolH
{
private:
    NodoH *raiz;
    vector <pair <char,string>> codigos;

public:
    ArbolH();
    void generarArbol(std::vector<char>i, std::vector<long>);
    struct comparar;
    void guardarCodigos(NodoH *inicio, string str);
    void imprimirCodigos();
    string obtenerCodigo(char caracter);
    string cifrar(list<char> secunecia);
    string desCifrar(string cif, long longiSec);
    NodoH * deCodificar(NodoH *nodo, char dir, int &cont, string &des);
    NodoH * getRaiz();
};

#include "ArbolH.hxx"
#endif 