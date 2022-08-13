#include <iostream>
#include "Secuencia.h"
#include <cstring>
#include <vector>
#include <fstream>
#include <list>

using namespace std;
	list <char> sec;
	list <string> id;
	list <list<char>> lsec;
	list <list <string>> lid; 
	int UniID;

Secuencia::Secuencia(){

}

bool Secuencia::check()
{
	if(sec.empty())
	{
		return true;
	}
	
	return false;
}



int Secuencia::sec_size()
{
	return sec.size();
}





int Secuencia::id_size()
{
	return id.size();
}




void Secuencia::ObtenerSecuencia()
{
	list <char> ::iterator itr=sec.begin();
	for(;itr!=sec.end();itr++)
	{
		cout << *itr;
	}
	cout << endl;
}


int Secuencia::num_bases()
{
	int total;
	list <char>::iterator itr=sec.begin();
	for(int i=0;i<sec.size();i++)
	{
		if(*itr=='A' || *itr=='C' || *itr=='G' || *itr=='T')
		{
			total++;
		}
	}
	return total;
}




void Secuencia::CargarSecuencia(string file)
{
	
	int i=0;
	string line;
	ifstream input;
	input.open(file, ios::in);
	if(input.fail())
	{
		cout << "El archivo proporcionado no se pudo abrir, revise el nombre o los permisos" << endl;
	}
	else
	{
		while(input.eof()==false)
		{
			if(i==0)
			{
				input.ignore(1);
				i++;
			}
				getline(input,line,'\n');
				id.push_back(line);

				getline(input,line,'>');
				for(int i=0;i<line.size();i++)
				{
					sec.push_back(line[i]);
				}
				//posible solucion, crear un identificador universal para definir la posición del identificador 
				lsec.push_back(sec);
				lid.push_back(id);
		}
		if(sec.empty() && id.empty())
		{
			cout << file << " no contiene ninguna secuencia" << endl;
		}
		else
		{
			cout << "Secuencias cargadas correctamente desde " << file << endl;
		}
	}
}