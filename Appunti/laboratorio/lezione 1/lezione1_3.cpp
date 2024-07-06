#include <iostream>
using namespace std;

int main()
{
    string s = "un ";
    string s1 = "messaggio a tutti voi";
    string nuovastringa = s + s1; // l'operatore + è sovraccaricato quindi funziona anche con le stringhe per concatenarle
    cout << nuovastringa << endl;

    cout << nuovastringa.at(3) << endl; // stampa la lettera m (in posizione 3)

    nuovastringa = nuovastringa.append(" nuova linea"); // la funzione append aggiunge la stringa tra parentesi alla fine della stringa nuovastringa
    nuovastringa.resize(10); // taglia la stringa a 10 caratteri (fino alla 2a g)
    nuovastringa.clear(); // la memoria viene liberata (ma non cancellata)
    return 0;
}