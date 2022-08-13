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
	int num_bases();
protected:
	std::list <std::string> id;
	std::list <char> sec;
	std::list <std::list<char>> lsec;
	std::list<std::list<std::string>> lid;
};

#endif