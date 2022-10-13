#include <iostream>
#include <cstring>
#include <vector>
#include <fstream>
#include <list>
#include "ArbolH.h"

using namespace std;
	list <list<char>> lsec;
    list <string>lid;
    list <char> code;
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
	list<list<char>>::iterator itrsec=lsec.begin();
	list<string>::iterator itrid=lid.begin();
	for(;itrsec!=lsec.end();itrsec++,itrid++)
	{
		list<char>var=*itrsec;
		list<char>::iterator itrvar=var.begin();
		cout << ">" << *itrid << endl;
		for(;itrvar!=var.end();itrvar++)
		{
			cout << *itrvar;
		}
		cout << endl;
	}
}

bool ver(char var, vector<char>vec){
	for(int i=0;i<vec.size();i++){
		if(vec[i]==var){
			return true;
		}
		else{
			return false;
		}
	}
	return true;
}

bool Secuencia::search(vector<char> vec, char dato){
	bool cond=false;
	for(int i=0;i<vec.size();i++){
		if(vec[i]==dato){
			cond=true;
		}
	}
	return cond;
}

vector<char> Secuencia::fill(){
	vector<char> vec;
	list<char>::iterator itrcode=code.begin();
	for(;itrcode!=code.end();itrcode++){
		if(vec.size()==0){
			vec.push_back(*itrcode);
		}
		else{
			if(!search(vec,*itrcode)){
				vec.push_back(*itrcode);
			}
		}
	}
	return vec;
}

vector<long> Secuencia::frecuencia(vector<char>ref){
	vector<long> vec;
	list<char>::iterator itrcode;
	int contador;
	for(int i=0;i<ref.size();i++){
		for(itrcode=code.begin();itrcode!=code.end();itrcode++){
			if(ref[i]==*itrcode){
				contador++;
			}
		}
		vec.push_back(contador);
		contador=0;
	}
	return vec;
}


void Secuencia::cifrar(){
	vector<char>datos=fill();
	vector<long>frecuencias=frecuencia(datos);
	arbol->generarArbol(datos, frecuencias);
	arbol->imprimirCodigos();
	//cout<<arbol->cifrar(code)<<endl;
}


void Secuencia::num_bases()
{
	bool cond=false;
	int total;
	list<list<char>> ::iterator itrsec=lsec.begin();
    list<string>::iterator itrid=lid.begin();
	for(;itrsec!=lsec.end();itrsec++, itrid++)
	{
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
			if(*itrtest=='R')
            {
                total+=2;
            }
            if(*itrtest=='Y')
            {
                total+=3;
            }
            if(*itrtest=='K')
            {
                total+=3;
            }
            if(*itrtest=='M')
            {
                total+=2;
            }
            if(*itrtest=='S')
            {
                total+=2;
            }
            if(*itrtest=='W')
            {
                total+=3;
            }
            if(*itrtest=='B')
            {
                total+=4;
            }
            if(*itrtest=='D')
            {
                total+=4;
            }
            if(*itrtest=='H')
            {
                total+=4;
            }
            if(*itrtest=='V')
            {
                total+=3;
            }
            if(*itrtest=='N')
            {
                total+=5;
            }
		}
			if(cond)
			{
				cout << "La secuencia " << *itrid << " contiene al menos " << total << " bases" << endl;
			}
			else
			{
				cout << "La secuencia " << *itrid << " contiene " << total << " bases" << endl;
			}
		total=0;
	}
}


void Secuencia::histograma(string secid)
{
	bool cond=false;
	list<list<char>> ::iterator itrsec=lsec.begin();
    list<string>::iterator itrid=lid.begin();
	for(;itrid!=lid.end();itrid++, itrsec++)
	{
			if(secid.compare(*itrid)==0)
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
	}
	if(cond)
	{
	    cout << "Las bases encontradas en la secuencia ->" << secid << "<- son:" << endl;
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
	vector<char> vec;
	char mask='X';
	list <char> lmirror;
	bool cond=false;
	list<list<char>>l_lmirror;
	list<list<char>>::iterator itrsec=lsec.begin();
	for(;itrsec!=lsec.end();itrsec++)
	{
		string mirror;
		list <char> var=*itrsec;
		list<char>::iterator itrvar=var.begin();
		for(;itrvar!=var.end();itrvar++)
		{
			mirror.push_back(*itrvar);
			vec.push_back(*itrvar);
		}

		size_t found=mirror.find(val_sec);
		while(found!=string::npos)
		{
			cond=true;
			contador++;
			for(int k=found;k<found+val_sec.size();k++)
			{
				vec[k]=mask;
			}
			found=mirror.find(val_sec, found+val_sec.size());
		}

		for(unsigned int i=0;i<vec.size();i++)
		{
			lmirror.push_back(vec[i]);
		}

		l_lmirror.push_back(lmirror);
		lmirror.clear();
		vec.clear();
	}
	lsec.clear();
	lsec=l_lmirror;


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


void Secuencia::auxcargar(string file){
	string line;
	ifstream input;
	char aux;
	input.open(file, ios::in);
	if(input.fail()){
		cout << "El archivo proporcionado no se pudo abrir, revise el nombre o los permisos" << endl;
	}
	else{
		while(input.eof()==false){
			input>>aux;
			code.push_back(aux);
		}
	}
}




void Secuencia::CargarSecuencia(string file)
{
    lsec.clear();
    lid.clear();
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
            list<char>sec;
			if(j==0)
			{
				input.ignore(1);
				j++;
			}
				getline(input,line,'\n');		// lectura de datos del ifstream
				lid.push_back(line);

				getline(input,line,'>');
				for(int i=0;i<line.size();i++)
				{
					sec.push_back(line[i]);
				}
			lsec.push_back(sec);
		}
		input.close();

		if(lsec.empty() && lid.empty())
		{
			cout << file << " no contiene ninguna secuencia" << endl;
		}
		else
		{
			cout <<  lid.size() <<" Secuencias cargadas correctamente desde " << file << endl;
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
        list<string>::iterator itrid=lid.begin();
		for(;itrid!=lid.end();itrsec++, itrid++)
		{
			list<char> varsec=*itrsec;
			list<char>::iterator itrvarsec=varsec.begin();
			output<< ">";
			output<<*itrid << '\n';
			for(;itrvarsec!=varsec.end();itrvarsec++)
			{
				output<<*itrvarsec;
			}
		}
		cout << "las secuencias han sido guardadas en " << file << endl;
	}


}

