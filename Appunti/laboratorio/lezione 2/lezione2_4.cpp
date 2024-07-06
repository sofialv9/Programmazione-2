#include <iostream>
#include <vector> // array la cui dimensione può essere modificata in runtime
using namespace std;

int main()
{
    vector<int> vect(5);
    for(int i = 0; i < vect.size(); i++)
        vect.at(i) = i * 2;

    cout << vect.size() << endl;
    vect.push_back(67); // si aggiunge un elemento al vettore in runtime - il vettore viene deallocato e reallocato nella memoria - non si possono concatenare più istruzioni push.back
    cout << vect.size() << endl;
    vect.pop_back(); // toglie l'ultimo elemento - non prende parametri in input
    cout << vect.size() << endl;
    // vect.clear(); // cancella gli elementi presenti nel vettore

    for(int value : vect) // al posto di int si può usare il tipo "auto"
        cout << value << " ";
    cout << endl;

    vect.insert(vect.begin() + 3, 900); // inserisce il numero 900 nella posizione 3 del vettore

    // iteratore - variabile che maschera un puntatore
    // al posto di "vector<int>::iterator" si può scrivere "auto" per lasciare al compilatore il compito di dedurre il tipo della variabile
    for(vector<int>::iterator it = vect.begin(); it != vect.end(); it++) // iterator associato al tipo vector int - begin ritorna un puntatore all'inizio (= al 1° elemento) del vettore
        cout << *it << " " << distance(vect.begin(), it) << endl; // stampa i valori del vettore seguiti dall'indice di posizione (del valore all'interno del vettore)

    return 0;
}