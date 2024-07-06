// Determina se un numero è perfetto

#include <iostream>
using namespace std;
bool isPerfetto(int n);

int main()
{
    int n;
    cout << "Inserisci un numero intero è ti dirò se è perfetto: ";
    cin >> n;
    if(isPerfetto(n))
        cout << "Il numero " << n << " è perfetto." << endl;
    else
        cout << "Il numero " << n << " non è perfetto." << endl;
    return 0;
}

bool isPerfetto(int n)
{
    int sum = 0;
    for(int i = 1; i < n; i++){
        if(n % i == 0)
            sum += i;
    }
    if(sum == n)
        return true;
    else
        return false;
}