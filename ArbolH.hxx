NodoH *init;
vector <pair <char,string>> codigos;

ArbolH::ArbolH()
{
    init = NULL;
}
struct ArbolH::comparar
{
    bool operator()(NodoH *l, NodoH *r)

    {
        return (l->obtenerFreq() > r->obtenerFreq());
    }
};


void ArbolH::generarArbol(vector<char>dato, vector<long>freq)
{
    NodoH *left, *right, *top;

    priority_queue<NodoH *, vector<NodoH *>, comparar> minHeap;
    priority_queue<NodoH *, vector<NodoH *>, comparar> minAux;
    for(int i = 0; i < minHeap.size();++i){
        minHeap.pop();
    }
    for (int i = 0; i < dato.size(); i++)
    {
        minHeap.push(new NodoH(dato[i], freq[i]));
    }
    while (minHeap.size() != 1)
    {
        left = minHeap.top();
        minHeap.pop();
        right = minHeap.top();
        minHeap.pop();

        unsigned int nuevaFreq = left->obtenerFreq() + right->obtenerFreq();

        top = new NodoH(' ', nuevaFreq);
        top->fijarHijoDer(right);
        top->fijarHijoIzq(left);
        minHeap.push(top);
    }
    NodoH *aux= new NodoH();
    aux=minHeap.top();
    init = aux;
    guardarCodigos(init, "");
    

}


void ArbolH::guardarCodigos(NodoH *inicio, string str)
{
    if (!inicio)
        return;
    if (inicio->obtenerDato() != ' ')
    {
        codigos.push_back(make_pair(inicio->obtenerDato(), str));
    }
    this->guardarCodigos(inicio->obtenerHijoIzq(), str + "0");
    this->guardarCodigos(inicio->obtenerHijoDer(), str + "1");
}
void ArbolH::imprimirCodigos()
{
    vector<pair<char, string>>::iterator it;
    for (it = codigos.begin(); it != codigos.end(); ++it)
    {
        cout << it->first << ": " << it->second << endl;
    }
}
string ArbolH::obtenerCodigo(char caracter)
{
    string codigo = "";
    bool encontrado = false;
    vector<pair<char, string>>::iterator it;
    for (it = codigos.begin(); it != codigos.end() && !encontrado; ++it)
    {
        if (it->first == caracter)
            codigo = it->second;
    }
    return codigo;
}
string ArbolH::cifrar(list<char>sec)
{
    list<char>::iterator itrsec=sec.begin();
    string cifrado;
    for (;itrsec!=sec.end();itrsec++)
    {
        cifrado += this->obtenerCodigo(*itrsec);
    }
    int tama = cifrado.size() % 8;
    if(tama != 0){
        for (int i = 0; i < 8 - tama; i++){
            cifrado += "0";
        }
    }
    return cifrado;
}
string ArbolH::desCifrar(string sec, long longiSec)
{
    NodoH *nodo = init;
    string desCifrado = "";
    int contador = 0;
    for (int i = 0; i < sec.size() +1; i++)
    {
        if (nodo->esHoja())
        {
            desCifrado += nodo->obtenerDato();
            nodo = init;
            contador++;
            if(contador == longiSec){
                break;
            }
        }
        if (sec[i] == '1')
        {
            nodo = nodo->obtenerHijoDer();
        }
        else
        {
            nodo = nodo->obtenerHijoIzq();
        }
    }
    return desCifrado;
}
NodoH * ArbolH::getRaiz(){
    return init;
}
NodoH * ArbolH::deCodificar(NodoH *nodo, char dir, int &cont, string &des)
{
    if(nodo->esHoja()){
        des+= nodo->obtenerDato();
        nodo = init;
        cont++;
    }
    if(dir == '1'){
        nodo = nodo->obtenerHijoDer();
    }
    else if(dir == '0'){
        nodo = nodo->obtenerHijoIzq();
    }
    return nodo;
}