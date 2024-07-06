#include <iostream>
#include <array>
#include <vector>
#include <iterator>

using namespace std;

int main()
{
  cout << "Static-Memory array" << endl;
  const size_t size = 8;
  array<int, size> myarr;
  cout << "Array size: " << myarr.size() << endl;

  for (int i = 0; i < myarr.size(); i++) // inizializza l'array con i numeri da 1 a 10 (gli indici da 0 a 7 ognuno + 1)
	  //myarr[i] = i + 1;
	  myarr.at(i) = i + 1;

  cout << "Printing array" << endl;
  for (int i : myarr) // stampa gli elementi dell'array uno per uno
	  cout << i << endl;

  cout << "Printing array" << endl;
  for (array<int,8>::iterator it = myarr.begin(); it != myarr.end(); it++) // stampa gli elementi dell'array con il proprio indice (= distanza tra l'inizio dell'array e l'elemento corrente) accanto
  {
	  cout << *it << " " << distance(myarr.begin(), it) << endl;
  }

  cout << "Dynamic-Memory Array" << endl;
  const size_t size2 = 8;
  array<int, size2> *dynarr = new array<int, size2>(); // puntatore ad un array dinamico
  cout << "Array Size: " << dynarr->size() << endl; // stampa la dimensione dell'array dinamico

  for (int i = 0; i < dynarr->size(); i++) // inizializza l'array com valore dell'indice + 3 (da 3 a 10)
  {
	  //(*dynarr)[i] = i + 3;
	  dynarr->at(i) = i + 3;
  }

  for (int i : *dynarr) // stampa l'array dinamico
	  cout << i << endl;

  delete dynarr; // dealloca l'array

  size_t size3 = 8;
  vector<int> vect = vector<int>(size3);
  cout << vect.size() << endl;

  for (int i = 0; i < vect.size(); i++) // inizializza il vettore con i valori da 0 a 7
	  vect.at(i) = i;
  vect.push_back(39); // aggiunge il numero 39 alla fine dell'array
  vect.push_back(89); // come sopra
  vect.insert(vect.begin() + 2, 66); // aggiunge il numero 66 nella posizione 2 del vettore
  cout << vect.size() << endl; // la dimensione del vettore è passata da 8 a 11 (si sono aggiunti 3 numeri)
  cout << vect.at(0) << endl; // stampa il primo valore dlel'array (cioè 0)
  
  for (vector<int>::iterator it = vect.begin(); it != vect.end(); it++) // stampa gli elementi del vettore con accanto i rispettivi indici
	  cout << *it << " "<< distance(vect.begin(), it) << endl;
  
  for (auto i : vect) // stampa i valori del vettore (deduce il tipo di dato dell'elemento)
	  cout << i << endl;

  return 0;
}