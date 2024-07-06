#include <iostream>
using namespace std;

int main()
{
    string s1, s2;
    string s = s1 + s2; // concatena le 2 stringhe

    cout << s.at(3) << endl; // stampa la lettera in posizione 3 (cioè la quarta)

    s = s.append("aaa"); // aggiunge la stringa tra parentesi alla fine della stringa s

    s.resize(10); // taglia la stringa a 10 caratteri

    s.clear(); // libera la memoria (ma non la cancella)

    s.size(); // stampa la lunghezza di s
	s.length(); // uguale a size()

    s.find("aaa"); // trova la posizione della prima occorrenza della stringa tra parentesi all'interno di 2

    s.substr(0, 10); // seleziona la sottostringa che inizia in posizione 0 e lunga 10 caratteri

    string s2(10, 'g'); // crea una stringa formata da 10 g
}