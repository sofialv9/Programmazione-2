// Legge la data e la visualizza come 3 numeri

#include <iostream>
using namespace std;

int main(){
    int giorno, mese1, anno;
    char* mese2;
    cout << "Inserire la data: ";
    cin >> giorno >> mese2 >> anno;
    if(mese2 == "Gennaio"){
        mese1 = 1;
    }
    cout << giorno << mese1 << anno << endl;
    return 0;
}