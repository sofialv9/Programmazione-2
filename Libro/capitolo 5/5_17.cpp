// Determina massimo comune divisore (più grande divisore comune ad entrambi) e minimo comune multiplo (più piccolo numero divisibile per entrambi) di 2 numeri

#include <iostream>
using namespace std;
int MCD(int a, int b);
int mcm(int a, int b);

int main()
{
    int n, m;
    cout << "Inserisci 2 numeri interi e io ne calcolerò il MCD e il mcm: ";
    cin >> n >> m;
    cout << "MCD: " << MCD(n, m) << endl;
    cout << "mcm: " << mcm(n, m) << endl;
    return 0;
}

int MCD(int a, int b){
    int MCD = 0, max = 0;
    if(a > b)
        max = a;
    else
        max = b;
    
    for(int i = 1; i < max; i++){
        if(a % i == 0 && b % i == 0){
            MCD = i;
        }
    }
    return MCD;
}

int mcm(int a, int b)
{
    int mcm = 0, i = 1;
    bool found = false;
    while(!found)
    {
        if(i % a == 0 && i % b == 0)
            found = true;
        else
            i++;
    }
    return i;
}