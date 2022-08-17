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
					if(*itrtest=='R')
					{
						adenina++;
						guanina++;
					}
					if(*itrtest=='Y')
					{
						citosina++;
						timina++;
						uracilo++;
					}
					if(*itrtest=='K')
					{
						guanina++;
						timina++;
						uracilo++;
					}
					if(*itrtest=='M')
					{
						adenina++;
						citosina++;
					}
					if(*itrtest=='S')
					{
						citosina++;
						guanina++;
					}
					if(*itrtest=='W')
					{
						adenina++;
						citosina++;
					}
					if(*itrtest=='B')
					{
						citosina++;
						guanina++;
						timina++;
						uracilo++;
					}
					if(*itrtest=='D')
					{
						adenina++;
						guanina++;
						timina++;
						uracilo++;
					}
					if(*itrtest=='H')
					{
						adenina++;
						citosina++;
						timina++;
						uracilo++;
					}
					if(*itrtest=='V')
					{
						adenina++;
						citosina++;
						guanina++;
					}
					if(*itrtest=='N')
					{
						adenina++;
						citosina++;
						timina++;
						guanina++;
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


void Secuencia::es_subsecuencia(string val_sec)
{
	string mirror;
	bool cond=false;
	unsigned int contador=0;
	list<list<char>>::iterator itrsec=lsec.begin();
	for(;itrsec!=lsec.end();itrsec++)
	{
		list <char> var=*itrsec;
		list<char>::iterator itrvar=var.begin();
		for(;itrvar!=var.end();itrvar++)
		{
			mirror.push_back(*itrvar);
		}
	}
	size_t found=mirror.find(val_sec);
	while(found!=string::npos)
	{
		cond=true;
		contador++;
		found=mirror.find(val_sec, found+val_sec.size());
	}

	if(!lsec.empty())
	{
		if(cond)
		{
			cout << "La secuencia dada se repite: " << contador << " veces" << endl;
		}
		else
		{
			cout << "La secuencia dada no existe" << endl;
		}
	}
	else
	{
		cout << "No hay secuencias cargadas en memoria" << endl;
	}
	contador=0;
}	



void Secuencia::enmascarar(string val_sec)
{
	unsigned long contador=0;
	char mask='X';
	string mirror;
	bool cond=false;
	list<list<char>>::iterator itrsec=lsec.begin();
	for(;itrsec!=lsec.end();itrsec++)
	{
		list <char> var=*itrsec;
		list<char>::iterator itrvar=var.begin();
		for(;itrvar!=var.end();itrvar++)
		{
			mirror.push_back(*itrvar);
		}
		size_t found=mirror.find(val_sec);
	while(found!=string::npos)
	{
		cond=true;
		contador++;
		mirror[found]=mask;
		found=mirror.find(val_sec, found+val_sec.size());
	}
	}
	
	if(!lsec.empty())
	{
		if(cond)
		{
			if(contador==1)
			{
				cout << "1 secuencia ha sido enmascarada" << endl;
			}
			else
			{
				cout << contador << " secuencias han sido enmascaradas" << endl;
			}
		}
		else
		{
			cout << "La secuencia dada no existe, por tanto no se enmascara nada." << endl;
		}
	}
	else
	{
		cout << "No hay secuencias cargadas en memoria" << endl;
	}
	contador=0;
}





void Secuencia::CargarSecuencia(string file)
{	
	int j=0;
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
			if(j==0)
			{
				input.ignore(1);
				j++;
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
		input.close();
		
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

void Secuencia::guardar_secuencia(string file)
{
	ofstream output;
	output.open(file, ios::out);
	if(output.fail())
	{
		cout << "El archivo proporcionado no se pudo abrir porfavor revise el nombre o los permisos del arhivo" << endl;
	}
	else
	{
		list<list<char>>::iterator itrsec=lsec.begin();
		list<list<string>>::iterator itrid=lid.begin();
		for(;itrid!=lid.end();itrsec++, itrid++)
		{
			list<char> varsec=*itrsec;
			list<char>::iterator itrvarsec=varsec.begin();
			list<string> varid=*itrid;
			list<string>::iterator itrvarid=varid.begin();
			output<< ">";
			output<<*itrvarid << '\n';
			for(;itrvarsec!=varsec.end();itrvarsec++)
			{
				output<<*itrvarsec;
			}
		}
		cout << "Archivo guardado correctamente" << endl;
	}
	
	
}
