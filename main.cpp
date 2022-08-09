#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <deque>
#include <list>

using namespace std;

int main() {

  int numero;
  srand(time(NULL));


//VECTORES
  
  vector<int> mivec;
  for(int i=0;i<25;i++){
    numero = 1 + rand() % (100 - 1);
    mivec.push_back(numero);
  }

  vector<int>::iterator miIt;
  for (miIt = mivec.begin(); miIt != mivec.end(); miIt++){
    cout << *miIt << std::endl;
  }

  vector<int>::reverse_iterator miRIt;
  for (miRIt = mivec.rbegin(); miRIt != mivec.rend(); miRIt++){
    cout << *miRIt << std::endl;
  }

  mivec.insert(mivec.begin()+18, numero=rand());
  mivec.erase(mivec.begin()+5);
  mivec.erase(mivec.begin()+9);
  for (miIt = mivec.begin(); miIt != mivec.end(); miIt++){
    cout << *miIt << std::endl;
  }

//DEQUES

  deque<int> mideq;
  for(int i=0;i<15;i++){
    numero = 1 + rand() % (100 - 1);
    mideq.push_back(numero);
    numero = 1 + rand() % (100 - 1);
    mideq.push_front(numero);
  }
  
  deque<int>::iterator miItD;
  for (miItD = mideq.begin(); miItD != mideq.end(); miItD++){
    cout << *miItD << std::endl;
  }

  deque<int>::reverse_iterator miRItD;
  for (miRItD = mideq.rbegin(); miRItD != mideq.rend(); miRItD++){
    cout << *miRItD << std::endl;
  }

  mideq.insert(mideq.begin()+18, numero=rand());
  mideq.erase(mideq.begin()+5);
  mideq.erase(mideq.begin()+10);
  for (miItD = mideq.begin(); miItD != mideq.end(); miItD++){
    cout << *miItD << std::endl;
  }
  
//List

  list<int> milist;
  for(int i=0;i<15;i++){
    numero = 1 + rand() % (100 - 1);
    milist.push_back(numero);
    numero = 1 + rand() % (100 - 1);
    milist.push_front(numero);

  }
  list<int>::iterator miItL;
  for (miItL = milist.begin(); miItL != milist.end(); miItL++){
    cout << *miItL << std::endl;
  }
  list<int>::reverse_iterator miRItL;
  for (miRItL = milist.rbegin(); miRItL != milist.rend(); miRItL++){
    cout << *miRItL << std::endl;
  }

  miItL=milist.begin();
  for(int i=0;i<18;i++){
    miItL++;
  }
  milist.insert(miItL,numero=rand());
  
  miItL=milist.begin();
  for(int i=0;i<5;i++){
    miItL++;
  }
  milist.erase(miItL);
  
  miItL=milist.begin();
  for(int i=0;i<10;i++){
    miItL++;
  }
  milist.erase(miItL);
  
   for (miItL = milist.begin(); miItL != milist.end(); miItL++){
    std::cout << *miItL << std::endl;
  }
  
  
}