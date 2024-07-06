// Visualizza tutte le potenze di un intero n minori di un valore specificato letto in input
#include <iostream>
using namespace std;

int main()
{
    int n = 2;
    int m = 1;
    int max;
    cout << "Questo programma stampa le potenze di 2. Inserisci il numero massimo da visualizzare: ";
    cin >> max;
    while((m *= n) < max){
        cout << m << endl;
    }

    return 0;
}