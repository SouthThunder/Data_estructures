#ifndef ALT__HUFFMAN__H
#define ALT__HUFFMAN__H
#include "NodoH.h"
#include <utility>
#include <vector>

class alt_huffman{
private: 
	NodoH *raiz;
	vector <pair <char,string>> codigos;

public:
    ArbolH();
    void generarArbol(char dato[], long freq[],int size);
    struct comparar;
    void guardarCodigos(NodoH *inicio, string str);
    void imprimirCodigos();
    string obtenerCodigo(char caracter);
    string cifrar(string secunecia);
    string desCifrar(string cif, long longiSec);
    NodoH * deCodificar(NodoH *nodo, char dir, int &cont, string &des);
    NodoH * getRaiz();
};

#include "ArbolH.hxx"
}