#include <iostream>
using namespace std;

int main() // firma della funzione
{
    int x = 5; // variabile non costante non volatile
    x = 35; // non dà errori

    volatile int x = 5;
    x = 35; // non dà errori

    const int x = 5;
    x = 35; // errore di compilazione

    /////////////////////////////////////

    string s = "Programmazione 2";
    string nuovas = " esame";
    string combo = s + nuovas;
    cout << sizeof(s); // ritorna 32
    cout << combo.size(); // ritorna il numero di caratteri della stringa combo (tranne il carattere di terminazione), cioè 21 - la funzione size è inclusa nel tipo string
    cout << combo.lenght(); // uguale alla funzione size
    string s = "stringa" + endl; // non si può scrivere
    string s = "stringa" + '\n'; // si può scrivere
    return 0;
}


