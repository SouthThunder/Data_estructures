#ifndef __SECUENCIA__H__
#define __SECUENCIA__H__

#include <string>
#include <list>
#include <vector>

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
protected:
	std::list <std::string> id;
	std::list <char> sec;
	std::list <std::list<char>> lsec;
	std::list<std::list<std::string>> lid;
	int adenina;
	int citosina;
	int guanina;
	int timina;
	int uracilo;
};

#endif