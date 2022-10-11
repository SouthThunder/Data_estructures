NodoH::NodoH(char dato, unsigned int freq) {
    this->der = NULL;
    this->izq = NULL;
    this->dato = dato;
    this->freq = freq;
}
NodoH::NodoH() {
    this->der = NULL;
    this->izq = NULL;
}
NodoH* NodoH::obtenerHijoIzq (){
    return this->izq;
}
NodoH* NodoH::obtenerHijoDer (){
    return this->der;
}
unsigned int NodoH::obtenerFreq(){
    return this->freq;
}
void NodoH::fijarHijoDer(NodoH* der){
    this->der = der;
}
void NodoH::fijarHijoIzq(NodoH* izq){
    this->izq = izq;
}
char NodoH::obtenerDato(){
    return this->dato;
}
bool NodoH::esHoja(){
    return (this->der == NULL && this->izq == NULL);
}