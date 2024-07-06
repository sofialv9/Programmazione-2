// NON FUNZIONA --> ritorna 0 o -nan

#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int a, b, c;
    cout << "Inserire la lunghezza dei 3 cateti: ";
    cin >> a >> b >> c;
    double p = (a + b + c) / 2;
    cout << "L'area del triangolo è pari a: " << sqrt(p * (p - a) * (p - b) * (p - c)) << endl;
    return 0;
}