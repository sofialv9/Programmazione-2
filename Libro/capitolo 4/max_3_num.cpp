// Determina il maggiore tra 3 numeri

#include <iostream>
using namespace std;

int main()
{
    int a, b, c;
    cout << "Inserire tre numeri interi, io determinerò il maggiore." << endl;
    cin >> a >> b >> c;
    int max = a;
    if(b > max)
        max = b;
    if (c > max)
        max = c;
    cout << "Il numero maggiore è " << max << endl;
    return 0;
}