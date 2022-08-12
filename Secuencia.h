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
	std::list <char> itsec;
	std::list<std::string> id;
};

#endif