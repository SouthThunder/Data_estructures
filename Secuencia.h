
#ifndef __SECUENCIA__H__
#define __SECUENCIA__H__

#include <string>
#include <list>
#include <vector>
#include "NodoH.h"
#include "ArbolH.h"

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
	void histograma(std::string secid);
	void es_subsecuencia(std::string val_sec);
	void enmascarar(std::string val_sec);
	void guardar_secuencia(std::string file);
	void setBases();
	void cifrar();
protected:
	NodoH *node;
	ArbolH *arbol= new ArbolH();
	std::list <std::string> lid;
	std::list <std::list<char>> lsec;
};

#include "Secuencia.cxx"
#endif
