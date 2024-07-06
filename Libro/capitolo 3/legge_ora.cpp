// Legge l'ora in notazione di 24 ore e la restituisce in notazione di 12 ore

#include <iostream>
using namespace std;

int main(){
    int hours, minutes;
    char c;
    cout << "Inserire l'orario in notazione di 24 ore con 5 caratteri: ";
    cin >> hours >> c >> minutes;
    cout << "L'orario in notazione di 12 ore è: " << (hours > 12 ? hours - 12 : hours) << c << minutes << (hours > 12 ? " PM" : " AM") << endl;
    return 0;
}
