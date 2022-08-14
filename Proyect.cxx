#include <iostream>
#include <sstream> 
#include <string> 
#include <fstream>
#include <vector>
#include <cstring>
#include "Secuencia.h"

using namespace std; 

Secuencia secuen;

struct
{
	std::string conteo="conteo";
	std::string cargar="cargar";
	std::string listar_secuencias="listar_secuencias";
	std::string histograma="histograma";
	std::string es_subsecuencia="es_subsecuencia";
	std::string enmascarar="enmascarar";
	std::string guardar="guardar";
}opc;


void comand(std::string &first, std::string &last, string &input)
{
	std::cout << "$";
	std::getline(std::cin,input);
	std::stringstream X(input);
	int i=0;
	for(std::string line;std::getline(X,line, ' ');)
	{
		if(i==0)
		{
			first=line;
		}
		if(i==1)
		{
			last=line;
		}
		i++;
	}
}

void user_helper(string first, string last, string line)
{
			if(line=="help "+opc.cargar)
			{
				cout << "Posibles salidas de la funcion:" << endl;
				cout << "(Archivo vacio) nombre_archivo no contiene ninguna secuencia.\n(Archivo erroneo) nombre_archivo no se encuentra o no puede leerse.\n(Una sola secuencia) 1 secuencia cargada correctamente desde nombre_archivo.\n(Varias secuencias) n secuencias cargadas correctamente desde nombre_archivo." << endl;
				cout << "-------------------------------------------------------------------" << endl;
				cout << "Comando de ejecucion" << endl;
				cout << "--->cargar + nombre_archivo<---"<< endl;
			}
			if(line=="help "+opc.conteo)
			{
				cout << "Posibles salidas de la funcion:" << endl;
				cout << "(No hay secuencias cargadas) No hay secuencias cargadas en memoria.\n(Una sola secuencia) 1 secuencia en memoria.\n(Varias secuencias) n secuencias en memoria." << endl;
				cout << "-------------------------------------------------------------------" << endl;
				cout << "Comando de ejecucion" << endl;
				cout << "--->conteo<---"<< endl;
			}
			if(line=="help "+opc.listar_secuencias)
			{
				cout << "Posibles salidas de la funcion" << endl;
				cout << "(No hay secuencias cargadas) No hay secuencias cargadas en memoria.\n(Secuencia completa de archivo no vacío) Secuencia descripcion_secuencia contiene b bases.\n(Secuencia incompleta de archivo no vacío) Secuencia descripcion_secuencia contiene al menos b bases." << endl;
				cout << "-------------------------------------------------------------------" << endl;
				cout << "Comando de ejecucion" << endl;
				cout << "--->listar_secuencias<---" << endl;
			}
			if(line=="help "+opc.histograma)
			{
				cout << "Posibles salidas de la funcion" << endl;
				cout << "(La secuencia no existe) Secuencia inválida.\n(La secuencia existe) A : frecuencia_A \n C : frecuencia_C \n ..."<<endl;
				cout << "-------------------------------------------------------------------" << endl;
				cout << "Comando de ejecucion"<<endl;
				cout << "--->histograma + descripcion_secuencia<---" << endl;
			}
			if(line=="help "+opc.es_subsecuencia)
			{
				cout << "Posibles salidas de la funcion" << endl;
				cout << "(No hay secuencias cargadas) No hay secuencias cargadas en memoria.\n(La secuencia no existe) La secuencia dada no existe.\n(Varias secuencias) La secuencia dada se repite s veces." << endl;
				cout << "-------------------------------------------------------------------" << endl;
				cout << "Comando de ejecucion" << endl;
				cout << "--->es_subsecuencia + secuencia<---" << endl;
			}
			if(line=="help "+opc.enmascarar)
			{
				cout << "Posibles salidas de la funcion" << endl;
				cout <<"(No hay secuencias cargadas) No hay secuencias cargadas en memoria.\n(No se enmascararon subsecuencias) La secuencia dada no existe, por tanto no se enmascara nada.\n(Una subsecuencia enmascarada) 1 secuencia ha sido enmascarada.\n(Varias subsecuencias esmascaradas) s secuencias han sido enmascaradas."<<endl;
				cout << "-------------------------------------------------------------------" << endl;
				cout << "Comando de ejecucion"<< endl;
				cout << "--->enmascarar + secuencia<---" << endl;
			}
			if(line=="help "+opc.guardar)
			{
				cout << "Posibles salidas de la funcion" << endl;
				cout << "(No hay secuencias cargadas) No hay secuencias cargadas en memoria.\n(Escritura exitosa) Las secuencias han sido guardadas en nombre_archivo \n(Problemas en archivo) Error guardando en nombre_archivo " << endl;
				cout << "-------------------------------------------------------------------" << endl;
				cout << "Comando de ejecucion" << endl;
				cout << "--->guardar + nombre_archivo<---" << endl;
			}
			if(line=="help" || line=="Help" || line=="HELP")
		{
			std::cout << "Funcion                             Ejemplo de ejecucion" << std::endl;
			std::cout << "1.Cargar archivo de secuencia ---> cargar nombre_archivo\n2.Conteo de secuencias cargadas en memoria ---> conteo\n3.Imprimir informacion basica de la secuencia ---> listar_secuencias\n4.Imprimir el histograma de secuencia ---> histograma descripcion_secuencia\n5.Validacion de la secuencia ---> es_subsecuencia secuencia\n6.Enmascarar secuencia ---> enmascarar secuencia\n7.Guardar las secuencias ---> guardar nombre_archivo\n8.Salir" << std::endl;	
		}
}

void afile(string file)
{
	secuen.CargarSecuencia(file);
}

void imp()
{
	secuen.ObtenerSecuencia();
}

void hist(string last)
{
	secuen.histograma(last);
}



void list_secs()
{
	secuen.num_bases();
}




void count()
{
	if(secuen.check()==true)
	{
		cout << "No hay secuencias cargadas en memoria" << endl;
	}
	else
	{
		cout << secuen.id_size() << " secuencias en memoria" << endl;
	}
}

/*void safe(string file)
{
	Secuencia secuen;
	if(secuen.check())
	{
			cout << "No hay secuencias cargadas en memoria" << endl;
	}
	else
	{
		ofstream output;
		output.open(file, ios::in | ios::out);
		if(output.fail())
		{
			cout << "Error al abrir el archivo porfavor comprobar el nombre" << endl;
		}
		else
		{
			for(int i=0;i<secuen.id_size();i++)
			{
				output<<secuen.id_size();
				output<<secuen.ObtenerSecuencia();	
			}
		}
	}	

}*/
void idktesting()
{
	secuen.testing();
}


void interface(bool &cond, string &first, string &last, string &line)
{
	system("CLS");
				if(first=="help" || first=="Help" || first=="HELP")
				{
					user_helper(first, last, line);
				}
				if(first==opc.cargar)
				{
					if(last=="")
					{
						cout << "Parametro adicional esperado, porfavor escriba help para ver los comandos permitidos" << endl;
					}
					else
					{
						afile(last);	
						//idktesting();
					}
				}
				if(first==opc.conteo)
				{
					if(last=="")
					{
						count();
					}
					else
					{
						std::cout<< "Parametro adicional no reconocido, por favor escriba help para ver los comandos permitidos" << "\n";
					}
				}
				if(first==opc.listar_secuencias)
				{
					if(last=="")
					{
						list_secs();
					}
					else
					{
						std::cout<< "Parametro adicional no reconocido, por favor escriba help para ver los comandos permitidos" << "\n";
					}
				}
				if(first==opc.histograma)
				{
					if(last=="")
					{
						cout << "Parametro adicional esperado, porfavor escriba help para ver los comandos permitidos" << endl;
					}
					else
					{
						hist(last);
					}
				}
				if(first==opc.es_subsecuencia)
				{
					if(last=="")
					{
						cout << "Parametro adicional esperado, porfavor escriba help para ver los comandos permitidos" << endl;
					}
					else
					{
						cout << "This is es_subsecuencia" << endl;	
					}
				}
				if(first==opc.enmascarar)
				{
					if(last=="")
					{
						cout << "Parametro adicional esperado, porfavor escriba help para ver los comandos permitidos" << endl;
					}
					else
					{
						cout << "This is enmascarar" << endl;	
					}
				}
				if(first==opc.guardar)
				{
					if(last=="")
					{
						cout << "Parametro adicional esperado, porfavor escriba help para ver los comandos permitidos" << endl;
					}
					else
					{
						cout << "This is guardar" << endl;	
					}
				}
				if(first!=opc.cargar && first!=opc.conteo && first!=opc.listar_secuencias && first!=opc.histograma && first!=opc.es_subsecuencia && first!=opc.enmascarar && first!=opc.guardar && first!="salir" && first!="Salir" && first!="SALIR" &&first!="help" && first!="Help" && first!="HELP")
				{
					std::cout << "Comando no reconocido, porfavor revisar la lista de comandos permitidos e intentelo otra vez" << '\n';
				}
				if(first=="salir" || first=="Salir" || first=="SALIR")
				{
					std::cout<<"Gracias por usar nuestro programa" << '\n';
					cond=false;
				}
				if(cond)
				{
					first="";
					last="";
					line="";
					comand(first,last, line);
				}
}







int main()
{
	system("CLS");
	std::cout << "Bienvenido al programa de manipulacion de codigo genetico " << std::endl;
	std::cout << "----------------------------------------------------------" << std::endl;
	std::cout << "Porfavor indique la funcion a realizar, si necesita ayuda digite ""help"" para mostrar la lista de funciones disponibles " << std::endl;
	std::string first,last, line;
	bool cond=true;
	comand(first,last,line);
	system("CLS");	
	while(cond)
	{
		interface(cond, first, last, line);
	}
	return 0;
}