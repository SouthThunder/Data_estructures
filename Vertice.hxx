template <class T>
Vertice<T>::Vertice(){}

template <class T>
Vertice<T>::Vertice(T dato)
{
    this->dato = dato;
}

template <class T>
T* Vertice<T>::getDato()
{
    return &dato;
}

template <class T>
void Vertice<T>::setDato(T dato)
{
    this->dato = dato;
}
template <class T>
bool Vertice<T>::operator <(Vertice<T>& ver)
{
    if(dato < ver.dato)
        return true;
    return false;
}