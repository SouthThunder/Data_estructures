#include <iostream>
#include <sstream> 
#include <string>  

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


void comand(std::string &first, std::string &last)
{
	std::string input;
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




int main()
{
	system("CLS");
	std::cout << "Bienvenido al programa de manipulacion de codigo genetico " << std::endl;
	std::cout << "----------------------------------------------------------" << std::endl;
	std::cout << "Porfavor indique la funcion a realizar, si necesita ayuda digite ""help"" para mostrar la lista de funciones disponibles " << std::endl;
	std::string first,last;
	bool cond=true;
	comand(first,last);
	system("CLS");	
	

	while(cond)
	{

		if(first=="help" || first=="Help" || first=="HELP")
		{
			std::cout << "Funcion                             Ejemplo de ejecucion" << std::endl;
			std::cout << "1.Cargar archivo de secuencia ---> cargar nombre_archivo\n2.Conteo de secuencias cargadas en memoria ---> conteo\n3.Imprimir informacion basica de la secuencia ---> listar_secuencias\n4.Imprimir el histograma de secuencia ---> histograma descripcion_secuencia\n5.Validacion de la secuencia ---> es_subsecuencia secuencia\n6.Enmascarar secuencia ---> enmascarar secuencia\n7.Guardar las secuencias ---> guardar nombre_archivo\n8.Salir" << std::endl;	
		}
		
				if(first==opc.cargar)
				{
					std::cout<< "This is cargar" << "\n";
				}
				if(first==opc.conteo)
				{
					std::cout<< "This is contar" << "\n";
				}
				if(first==opc.listar_secuencias)
				{
					std::cout<< "This is imprimir" << "\n";
				}
				if(first==opc.histograma)
				{
					std::cout<< "This is histograma" << "\n";
				}
				if(first==opc.es_subsecuencia)
				{
					std::cout<< "This is es_subsecuencia" << "\n";
				}
				if(first==opc.enmascarar)
				{
					std::cout<< "This is enmascarar" << "\n";
				}
				if(first==opc.guardar)
				{
					std::cout<< "This is guardar" << "\n";
				}
				if(first!=opc.cargar && first!=opc.conteo && first!=opc.listar_secuencias && first!=opc.histograma && first!=opc.es_subsecuencia && first!=opc.enmascarar && first!=opc.guardar && first!="salir" &&first!="help")
				{
					std::cout << "Comando no reconocido, porfavor revisar la lista de comandos permitidos e intentelo otra vez" << '\n';
				}
		comand(first,last);
		system("CLS");
		if(first=="salir" || first=="Salir" || first=="SALIR")
		{
			std::cout<<"Gracias por usar nuestro programa" << '\n';
			cond=false;
		}
	}
	
	return 0;
}