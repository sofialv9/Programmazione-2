// Funzione Arrotondamento che accetta un valore reale Quantità e un valore intero Decimali e restituisce il valore Quantità arrotondato al numero specificato di decimali.

#include <iostream>
#include <iomanip>
using namespace std;
double Arrotondamento(double Quantità, int Decimali);

int main()
{
    double n;
    int m;
    cout << "Inserire un numero reale e la precisione desiderata per la stampa." << endl;
    cin >> n >> m;
    cout << "Il numero stampato con la precisione inserita è: " << Arrotondamento(n, m) << endl;
    return 0;
}

double Arrotondamento(double Quantità, int Decimali){
    cout.precision(Decimali);
    return Quantità;
}