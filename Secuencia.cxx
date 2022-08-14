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
	if(lsec.empty())
	{
		return true;
	}
	
	return false;
}



int Secuencia::sec_size()
{
	return lsec.size();
}





int Secuencia::id_size()
{
	return lid.size();
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


void Secuencia::num_bases()
{
	bool cond=false;
	int total;
	list<list<char>> ::iterator itrsec=lsec.begin();
	list<list<string>>::iterator itrid=lid.begin();
	for(;itrsec!=lsec.end();itrsec++)
	{
		list<string>testid=*itrid;
		list<string>::iterator itrtestid=testid.begin();

		list<char>test=*itrsec;
		list<char>::iterator itrtest=test.begin();

		for(;itrtest!=test.end();itrtest++)
		{
			if(*itrtest=='-')
			{
				cond=true;
			}
			if(*itrtest=='A' || *itrtest=='C' || *itrtest=='G' || *itrtest=='T')
			{
				total++;
			}
		}
		 
		if(cond)
		{
			cout << "La secuencia " << *itrtestid << " contiene al menos " << total << " bases" << endl;
		}
		else
		{
			cout << "La secuencia " << *itrtestid << " contiene " << total << " bases" << endl;
		}
		total=0;
		itrid++;
	}
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
			lsec.push_back(sec);
			lid.push_back(id);
				for(int i=0;i<line.size();i++)
				{
					sec.pop_back();
				}
				for(int i=0;i<id.size();i++)
				{
					id.pop_back();
				}
		}
		
		if(lsec.empty() && lid.empty())
		{
			cout << file << " no contiene ninguna secuencia" << endl;
		}
		else
		{
			cout << "Secuencias cargadas correctamente desde " << file << endl;
		}
	}
}



void Secuencia::testing()
{
	int i=0;
	list<list<string>>::iterator fuck=lid.begin();
	list<list<char>> ::iterator itrsec=lsec.begin();
	for(;itrsec!=lsec.end();itrsec++)
	{
		list<string>shit=*fuck;
		list<string>::iterator itrshit=shit.begin();

		list<char>idk=*itrsec;
		list <char>::iterator itridk=idk.begin();
		if(i==0)
		{
			/*for(;itridk!=idk.end();itridk++)
			{
				cout << *itridk;
			}*/
		}
		else
		{
			for(;itridk!=idk.end();itridk++)
			{
				cout << *itridk;
			}
		}		
		i++;
		fuck++;
	}
	cout << endl;
	cout << i << endl;
}