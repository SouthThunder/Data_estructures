
#ifndef __SECUENCIA__H__
#define __SECUENCIA__H__

#include <string>
#include <list>
#include <vector>
#include "NodoH.h"
#include "ArbolH.h"
#include "Grafo.h"
#include "Vertice.h"
#include <bitset>

class Secuencia
{
public:
	Secuencia();
	void ObtenerSecuencia();
	void CargarSecuencia(std::string file);
	bool check();
	int sec_size();
	int id_size();
	void num_bases();
	void testing();
	int freq(char dato, vector<char> fuck);	
	string toBinary(int n);
	bool search(std::vector<char>vec, char dato);
	int longi(list<char>idk);
	std::vector<char>fill_fuck();
	std::vector<char> fill();
	std::vector<long> frecuencia(std::vector<char>ref);
	void histograma(std::string secid);
	void es_subsecuencia(std::string val_sec);
	void enmascarar(std::string val_sec);
	void guardar_secuencia(std::string file);
	void cifrar(std::string file);
	void generar();
	bitset<16> first(int aux);
	std::string Reverse(std::string str);
	std::vector<bitset<8>> second(vector<pair<char,string>> codigos);
	std::vector<bitset<64>> secondp(vector<pair<char,string>> codigos);
	bitset<32> tercero(int size);
	void decifrar(std::string file);
	vector<bitset<64>> quinto();
	vector<bitset<16>> sexto();
	std::vector<std::string> binary_code();
	void setIden();
	void empcons();
	void insertar_grafo(std::list<char>sec, std::string id);
	void vecinos(std::string id);
	char list_char(int i, list<Vertice<char>> aux);
	int hptasapo(std::list<char> vaca);
	int indice(std::string id);
	void imp();
	char inversa(int ind);
	std::list<char>indice_secuencia(int cont);
	double tranformacion(char ij, char xy);
	void ruta_mas_corta(std::string id, std::vector<char>params);
	void fabin(std::string file, bitset<16> bs1, std::vector<bitset<8>> bs2, std::vector<bitset<64>> bs2p, bitset<32>bs3, std::vector<bitset<16>>bs4, std::vector<string>bs4as, std::vector<bitset<64>>bs5, std::vector<bitset<16>>bs6, std::vector<std::string> cifr);
protected:
	int adenina, citosina, guanina, timina, uracilo;
	NodoH *node;
	Vertice<char> *vert=new Vertice<char>();
	ArbolH *arbol= new ArbolH();
	Grafo<char> *grafo=new Grafo<char>();
	std::list <std::string> lid;
	std::list <std::list<char>> lsec;
	std::vector<int>iden;
	std::list <char> code;

	struct{
		int n;
		std::vector<char>ci;
		std::vector<long>fi;
		int ns;
		std::vector<int>li;
		std::vector<std::vector<char>>sij;
		std::vector<int>wi;
		std::vector<int>xi;
		std::list<std::list<char>>binary;
	}dec;
};

#include "Secuencia.cxx"
#endif
