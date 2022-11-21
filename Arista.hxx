template <class T>
Arista<T>::Arista(){}

template <class T>
Arista<T>::Arista(Vertice<T>* verDes, float peso)
{
    this->peso = peso;
    sucesor = verDes;
}

template <class T>
float Arista<T>::getPeso()
{
    return this->peso;
}
template <class T>
Vertice<T>* Arista<T>::getSucesor()
{
    return sucesor;
}

template <class T>
void Arista<T>::setPeso(float peso)
{
    this->peso = peso;
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