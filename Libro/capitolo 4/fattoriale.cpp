#include <iostream>
using namespace std;
int fattoriale (int n);

int main()
{
    int n;
    cout << "Inserisci un numero e io ne calcolerò il fattoriale." << endl;
    cin >> n;
    cout << "Il fattoriale di " << n << " è " << fattoriale(n) << "." << endl;
    return 0;
}

int fattoriale(int n){
    if (n == 1) {
        return n;
    } else {
        return n * fattoriale(n - 1);
    }
}