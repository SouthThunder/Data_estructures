#include <iostream>
#include "Secuencia.h"
#include <cstring>
#include <vector>
#include <fstream>

using namespace std;

	vector <char> itsec;
	vector <string> id; 

Secuencia::Secuencia(){

}

bool Secuencia::check()
{
	if(itsec.empty())
	{
		return true;
	}
	
	return false;
}



int Secuencia::sec_size()
{
	return itsec.size();
}





int Secuencia::id_size()
{
	return id.size();
}




void Secuencia::ObtenerSecuencia()
{
	for(int i=0;i<itsec.size();i++)
	{
		cout << itsec[i];
	}
	cout << endl;
}


int Secuencia::num_bases()
{
	int total;
	for(int i=0;i<itsec.size();i++)
	{
		if(itsec[i]=='A' || itsec[i]=='C' || itsec[i]=='G' || itsec[i]=='T')
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
					itsec.push_back(line[i]);
				}
		}
		if(itsec.empty() && id.empty())
		{
			cout << file << " no contiene ninguna secuencia" << endl;
		}
		else
		{
			cout << "Secuencias cargadas correctamente desde " << file << endl;
		}
	}
}