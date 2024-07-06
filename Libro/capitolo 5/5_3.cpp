// Funzione ricorsiva che calcola i primi N numeri primi - IN REALTà STAMPA I NUMERI MINORI DI N

#include <iostream>
#include <cmath>
using namespace std;
bool NumeroPrimo(int n);

int main()
{
    int N;
    cout << "Inserire la quantità di numeri primi che si vuole visualizzare:";
    cin >> N;
    for(int i = 2; i < N; i++){
        if(NumeroPrimo(i))
        {
            cout << i << endl;
        }
    }
    
    return 0;
}

bool NumeroPrimo(int n)
{
    int i = 2;
    int lim = (int)sqrt(n);
    bool primo = true;

    while(primo && (i <= lim))
    {
        primo = ! (n % i == 0);
        i++;
    }
    return primo;
}