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
	int adenina;
	int citosina;
	int guanina;
	int timina;
	int uracilo;

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

			if(*itrtest=='A')
			{
				total++;
			}
			if(*itrtest=='C')
			{
				total++;
			}
			if(*itrtest=='G')
			{
				total++;
			}
			if(*itrtest=='T')
			{
				total++;
			}
			if(*itrtest=='U')
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


void Secuencia::histograma(string secid)
{
	bool cond=false;
	list<list<char>> ::iterator itrsec=lsec.begin();
	list<list<string>>::iterator itrid=lid.begin();

	for(;itrid!=lid.end();itrid++)
	{
		list<string>testid=*itrid;
		list<string>::iterator itrtestid=testid.begin();
		for(;itrtestid!=testid.end();itrtestid++)
		{
			if(secid.compare(*itrtestid)==0)
			{
				cond=true;
				list<char>test=*itrsec;
				list<char>::iterator itrtest=test.begin();
				for(;itrtest!=test.end();itrtest++)
				{
					if(*itrtest=='A')
					{
						adenina++;
					}
					if(*itrtest=='C')
					{
						citosina++;
					}
					if(*itrtest=='G')
					{
						guanina++;
					}
					if(*itrtest=='T')
					{
						timina++;
					}
					if(*itrtest=='U')
					{
						uracilo++;
					}
				}
			}
			itrsec++;
		}
	}
	if(cond)
	{
		cout << "A: " << adenina << endl;
		cout << "C: " << citosina << endl;
		cout << "G: " << guanina << endl;
		cout << "T: " << timina << endl;
		cout << "U: " << uracilo << endl;
	}
	else
	{
		cout << "La secuencia: " << secid << " no fue encontrada, porfavor revise el identificador" << endl;
	}
	adenina=0;
	citosina=0;
	guanina=0;
	timina=0;
	uracilo=0;
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
