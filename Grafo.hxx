#include <queue>
template <class T>
Grafo<T>::Grafo(){}

template <class T>
list<Vertice<T>> Grafo<T>::getVertices()
{
    return this->vertices;
}

template <class T>
list<list<Arista<T>>> Grafo<T>::getConexiones()
{
    return this->conexiones;
}

template <class T>
void Grafo<T>::setVertices(list<Vertice<T> >vertices)
{
    this->vertices = vertices;
}

template <class T>
void Grafo<T>::setConexiones (list<list<Arista<T> > > conexiones)
{
    this->conexiones = conexiones;
}

template <class T>
bool Grafo<T>::esVacio()
{
    if(this->vertices.size() == 0 && this->conexiones.size() == 0)
       return true;
    return false;
}

template <class T>
int Grafo<T>::cantidadVertices()
{
    return this->vertices.size();
}

template <class T>
int Grafo<T>::cantidadAristas()
{
    int contador=0;
    typename list<list<Arista<T> > >::iterator it=conexiones.begin();
    for(; it!=conexiones.end(); it++)
    {
        contador+=it->size();
    }
    return contador;
}

template <class T>
bool Grafo<T>::insertarVertice(Vertice<T> vertice)
{ 

        vertices.push_back(vertice);
        list<Arista<T> > aux;
        conexiones.push_back(aux);
    return true;
}

template <class T>
bool Grafo<T>::insertarVertice(T dato)
{
    Vertice<T>* ver=new Vertice<T>(dato);
    if(insertarVertice(*ver))
        return true;
    return false;
}

template <class T>
bool Grafo<T>::estaVertice(Vertice<T> vertice)
{
    typename list<Vertice<T> >::iterator it=vertices.begin();
    for(; it!=vertices.end(); it++)
    {
        if(*vertice.getDato()==*it->getDato())
            return true;        
    }
        return false;
}

template <class T>
bool Grafo<T>::estaVertice(T dato)
{
    typename list<Vertice<T> >::iterator it=vertices.begin();
    for(; it!=vertices.end(); it++)
    {
        if(dato==*it->getDato())
        {
            return true;
        }
    }
    return false;
}

template <class T>
bool Grafo<T>::estaIndice(int i){
    if(i>=0 && i<vertices.size())
        return true;
    else
        return false;
}


template <class T>
Vertice<T>* Grafo<T>::buscarIndVertice(int ver_des){
    typename list<Vertice<T>>::iterator it=vertices.begin();
    for(int i=0; it!=vertices.end(); it++, i++){
        if(i==ver_des)
            return &(*it);
    }
    return NULL;
}



template <class T>
int Grafo<T>::insertarArista(int ver_org, int ver_des, double peso)
{
    if(!estaIndice(ver_org))
    {
        return 1;
    }
    else if(!estaIndice(ver_des))
    {
        return 2;
    }
    else
    {
        list<Arista<T> >* conex=obtenerConexionesVertice(ver_org);
        Vertice<T>* verDes=buscarIndVertice(ver_des);
        if(!insertarConexion(conex, verDes, peso))
        {
            return 3;
        }
        else
        {
            return 4;
        }
    }
    return 0;
}

template <class T>
list<Arista<T> >* Grafo<T>::obtenerConexionesVertice(int indice)
{
    int cont=0;
    typename list<list<Arista<T> > >::iterator it=conexiones.begin();
    for(; it!=conexiones.end(); it++)
    {
        if(cont==indice)
        {
            return &(*it);
        }
        cont++;
    }
    return NULL;
}

template <class T>
int Grafo<T>::obtenerIndice(T ver_org)
{
    typename list<Vertice<T> >::iterator it=vertices.begin();
    int cont=0;
    for(; it!=vertices.end(); it++)
    {
        if(*it->getDato()==ver_org)
            return cont;
        cont++;
    }
    return 0;
}

template <class T>
Vertice<T>* Grafo<T>::buscarVertice(T ver_des)
{
    typename list<Vertice<T> >::iterator it=vertices.begin();
    for(; it!=vertices.end(); it++)
    {
        if(*it->getDato()==ver_des)
        {
            return &(*it);
        }
    }
    return NULL;
}

template <class T>
bool Grafo<T>::insertarConexion(list<Arista<T> >* conex, Vertice<T>* verDes, double peso)
{
    typename list<Arista<T> >::iterator it=conex->begin();
    for(; it!=conex->end(); it++)
    {
        if(it->getSucesor()==verDes)
        {
            return false;
        }
    }
    Arista<T>* aris=new Arista<T>(verDes, peso);
    conex->push_back(*aris);
    conex->sort();
return true;
}

template <class T>
int Grafo<T>::eliminarConexionesEnEliminarVertice(list<Arista<T> >* c,T  dato)
{
    typename list<Arista<T> >::iterator it=c->begin();
    typename list<Arista<T> >::iterator itAux;
    bool encontrado=false;
    for(; it!=c->end(); it++)
    {
        if(*it->getSucesor()->getDato()==dato)
        {
            itAux=it;
            encontrado=true;
        }
    }
    if(encontrado)
    {
        c->erase(itAux);
        return 1;
    }
    else
        return 0;
}

template <class T>
bool Grafo<T>::eliminarVertice(T dato)
{
    if(estaVertice(dato))
    {
        int indice=obtenerIndice(dato);
        int cont=0;
        int contAristas=0;
        typename list<list<Arista<T> > >::iterator it2=conexiones.begin();
        typename list<list<Arista<T> > >::iterator itAux;
        for(; it2!=conexiones.end(); it2++)
        {
            if(cont==indice)
            {
                itAux=it2;
            }
            contAristas+=eliminarConexionesEnEliminarVertice(&(*it2), dato);
            cont++;
        }
        cout<<"Se han eliminado "<<contAristas<<" conexiones con ("<<dato<<") como destino"<<endl;
        conexiones.erase(itAux);
        typename list<Vertice<T> >::iterator it=vertices.begin();
        typename list<Vertice<T> >::iterator itAux2;
        for(; it!=vertices.end(); it++)
        {
            if(*it->getDato()==dato)
            {
                itAux2=it;

            }
        }
        vertices.erase(itAux2);
        return true;
    }
    else
        return false;
}

template <class T>
void Grafo<T>::imprimiAristas()
{
    typename list<Vertice<T> >::iterator itVertices=vertices.begin();
    int cont=0;
    for(; itVertices!=vertices.end(); itVertices++)
    {
        list<Arista<T> >* aristasDelVertice=obtenerConexionesVertice(cont);
        typename list<Arista<T> >::iterator itConexiones=aristasDelVertice->begin();
        for(; itConexiones!=aristasDelVertice->end(); itConexiones++)
        {
            cout << "\t(" << itVertices->getDato() << "," << itVertices->getDato() << ")"; 
            cout << "\t  (" << itConexiones->getSucesor()->getDato() << "," << itConexiones->getSucesor()->getDato() << ")"; 
            cout << "\t" << itConexiones->getPeso() << endl;
        }
            
        
        cout<<endl;
        cont++;
    }
}

template <class T>
void Grafo<T>::imprimirVertices()
{
    typename list< Vertice<T> >:: iterator it = vertices.begin();
    advance(it,1);
    for(; it != vertices.end(); ++it)
        cout << "\t\t(" << it->getDato()->X << "," << it->getDato()->Y << ")" << endl;
}
template <class T>
bool Grafo<T>::eliminarConexion(list<Arista<T> >* conex, Vertice<T>* verDes)
{
    typename list<Arista<T> >::iterator it=conex->begin();
    for(; it!=conex->end(); it++)
    {
        if(it->getSucesor()==verDes)
        {
            conex->erase(it);
            return true;
        }
    }
    return false;
}

template <class T>
int Grafo<T>::eliminarArista(T ver_org, T ver_des)
{
    if(!estaVertice(ver_org))
    {
        return 1;
    }
    else if(!estaVertice(ver_des))
    {
        return 2;
    }
    else
    {
        int indice=obtenerIndice(ver_org);
        list<Arista<T> >* conex=obtenerConexionesVertice(indice);
        Vertice<T>* verDes=buscarVertice(ver_des);
        if(!eliminarConexion(conex, verDes))
            return 3;
        
        else
            return 4;
    }
}

template <class T>
Arista<T>* Grafo<T>::buscarArista(T ver_org, T ver_des)
{
    int indice=obtenerIndice(ver_org);
    list<Arista<T> >* conex=obtenerConexionesVertice(indice);
    typename list<Arista<T> >::iterator it=conex->begin();
    for(; it!=conex->end(); it++)
    {
        if(*it->getSucesor()->getDato()==ver_des)
        {
            return &(*it);
        }
    }
    return NULL;
}

template <class T>
bool Grafo<T>::verticeVisitado(list<Vertice<T>* > lista, T dato)
{
    typename list<Vertice<T>* >::iterator it=lista.begin();
    for(; it!=lista.end(); it++)
    {
        if(*(*it)->getDato()==dato)
        {
            return true;
        }
    }
    return false;
}

template <class T>
double Grafo<T>::recorridoPrim(vector<double>* distancias, vector<T> *S,T dato){

    double suma = 0;
    int indice = obtenerIndice(dato);

    if (estaVertice(dato))
    {    
        vector <bool> visitados;
        visitados.resize(cantidadVertices());

        struct compare {
            public: 
                bool operator()(pair<double, int> x, pair<double, int>y)
                {
                    return x.first > y.first;
                }
        };
        priority_queue<pair<double, int>, vector <pair<double, int>>, compare> cola;
        cola.push({0,indice});

        while(!cola.empty())
        {
            pair<double, int> curr =  cola.top();
            cola.pop();
            if(!visitados[curr.second])
            {
                list<Vertice<T>> v = getVertices();
                typename list<Vertice<T>>::iterator itV = v.begin();
                advance(itV,curr.second); 
                
                S->push_back(*itV->getDato());
                distancias->push_back(curr.first);
                visitados[curr.second] = true;
                suma += curr.first;

                list<Arista<T> >* aristas = obtenerConexionesVertice(curr.second);
                typename list<Arista<T> >::iterator it = aristas->begin();  
                for(; it!=aristas->end(); it++)
                {
                    int indice2 = obtenerIndice(*it->getSucesor()->getDato());
                  
                    cola.push({it->getPeso(), indice2});
                }  
            }   
        }
    }
    else
        cout << "El vertice no existe" << endl;

    return suma;
}

template <class T>
Vertice<T> Grafo<T>::mindistance(list<Vertice<T> >* todosLosVertices, vector<double> distancias)
{
    typename list<Vertice<T> >::iterator it=todosLosVertices->begin();
    typename list<Vertice<T> >::iterator itAux=todosLosVertices->begin();
    int menor = numeric_limits<int>::max();
    for(; it!=todosLosVertices->end(); it++)
    {
        int indice=obtenerIndice(*it->getDato());
        if(distancias.at(indice)<menor)
        {
            itAux=it;
            menor=distancias.at(indice);
        }
    }
    todosLosVertices->erase(itAux);
    return (*itAux);
}

template <class T>
double Grafo<T>::recorridoDijkstra(vector<double>* distancias, vector<Vertice<T> >* prede, vector<T> *S, T dato)
{
    double suma = 0;
  
    int indice = obtenerIndice(dato);
    distancias->at(indice) = 0;
    prede->at(indice) = dato;

    list<Vertice<T> > Q(vertices.begin(), vertices.end());

    while(!Q.empty())
    {
        Vertice<T> minimo = mindistance(&Q, *distancias);
        S->push_back(*minimo.getDato());
    
        int indice = obtenerIndice(*minimo.getDato());
        list<Arista<T> >* aristas = obtenerConexionesVertice(indice);
        
        typename list<Arista<T> >::iterator it=aristas->begin();  
        for(; it!=aristas->end(); it++)
        {
            int indice2 = obtenerIndice(*it->getSucesor()->getDato());
            int posibleMinimo = (distancias->at(indice) + it->getPeso());
            
            if(distancias->at(indice2) > posibleMinimo)
            {
                distancias->at(indice2) = posibleMinimo;
                prede->at(indice2) = minimo;
                suma += posibleMinimo;

            }
        }
    }
    return suma;
}
template <class T>
void Grafo<T>::imprimirPredecesores(vector<Vertice<int> > lista)
{
    typename vector<Vertice<int> >::iterator it=lista.begin();
    for(; it!=lista.end(); it++)
    {
        cout << *it->getDato() << " - ";
    }
    cout << endl << endl;
}