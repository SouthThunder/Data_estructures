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

protected:
	std::vector <char> itsec;
	std::vector<std::string> id;
};

#endif