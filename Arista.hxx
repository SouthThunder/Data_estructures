template <class T>
Arista<T>::Arista(){}

template <class T>
Arista<T>::Arista(Vertice<T>* verDes, double peso, int ind)
{
    this->peso = peso;
    sucesor = verDes;
    this->indice_sucesor=ind;
}

template <class T>
double Arista<T>::getPeso()
{
    return this->peso;
}
template <class T>
Vertice<T>* Arista<T>::getSucesor()
{
    return sucesor;
}

template <class T>
void Arista<T>::setPeso(double peso)
{
    this->peso = peso;
}

template <class T>
void Arista<T>::setIndice(int indice)
{
    this->indice_sucesor = indice;
}

template <class T>
int Arista<T>::getIndice(){
    return indice_sucesor;
}

template <class T>
void Arista<T>::setSucesor(Vertice<T>* sucesor)
{
    this->sucesor = sucesor;
}

template <class T>
bool Arista<T>::operator <(Arista<T>& ar)
{
    if(*sucesor<*ar.getSucesor())
            return true;
    return false;
}