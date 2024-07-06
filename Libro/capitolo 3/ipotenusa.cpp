#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int a, b;
    cout << "Inserire la luneghezza dei 2 cateti: ";
    cin >> a >> b;
    cout << "La lunghezza dell'ipotenusa è: " << sqrt(pow(a, 2) + pow(b, 2)) << endl;
}