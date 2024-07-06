#include <iostream>
#include <vector> // !!!
#include <iterator> // !!!
using namespace std;

int main()
{
    // vettore = array la cui dimensione può essere modificata in runtime
    vector<int> vect(5);

    // come gli array
    vect.size();
    vect.at(i);
    
    vect.push_back(2); // aggiunge 2 alla fine del vettore
    vect.pop_back(); // toglie l'ultimo elemento
    vect.clear(); // cancella gli elementi presenti nel vettore
    vect.insert(vect.begin() + 3, 900); // inserisce il numero 900 nella posizione 3 del vettore

    // iteratore = variabile che maschera un puntatore
    // begin ritorna un puntatore al 1° elemento del vettore
    // stampa i valori del vettore seguiti dall'indice di posizione (del valore all'interno del vettore)
    for(vector<int>::iterator it = vect.begin(); it != vect.end(); it++) 
        cout << *it << " " << distance(vect.begin(), it) << endl; 
}