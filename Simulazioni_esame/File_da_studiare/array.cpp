#include <iostream>
#include <array> // libreria standard array
using namespace std;

int main()
{
    // tipo standard array (statico)
    array<int, 3> arr = {3, 4, 5};

    // scansione lineare dell'array
    for(int i = 0; i < arr.size(); i++)
        cout << arr[i] << endl;

    // for-each (funziona con ogni tipo iterabile) - equivalente al for precedente
    for(int value : arr) 
        cout << value << endl;
}