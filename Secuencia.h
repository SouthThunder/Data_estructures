
#ifndef __SECUENCIA__H__
#define __SECUENCIA__H__

#include <string>
#include <list>
#include <vector>
#include "NodoH.h"
#include "ArbolH.h"
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
	void auxcargar(std::string file);
	void histograma(std::string secid);
	void es_subsecuencia(std::string val_sec);
	void enmascarar(std::string val_sec);
	void guardar_secuencia(std::string file);
	void cifrar(std::string file);
	bitset<16> first(int aux);
	std::string Reverse(std::string str);
	std::vector<bitset<8>> second(vector<pair<char,string>> codigos);
	std::vector<bitset<64>> secondp(vector<pair<char,string>> codigos);
	bitset<36> tercero(int size);
	void decifrar(std::string file);
	vector<bitset<64>> quinto();
	vector<bitset<16>> sexto();
	std::vector<std::string> binary_code();
	void fabin(std::string file, bitset<16> bs1, std::vector<bitset<8>> bs2, std::vector<bitset<64>> bs2p, bitset<36>bs3, std::vector<bitset<16>>bs4, std::vector<string>bs4as, std::vector<bitset<64>>bs5, std::vector<bitset<16>>bs6, std::vector<std::string> cifr);
protected:
	NodoH *node;
	ArbolH *arbol= new ArbolH();
	std::list <std::string> lid;
	std::list <std::list<char>> lsec;
};

#include "Secuencia.cxx"
#endif
