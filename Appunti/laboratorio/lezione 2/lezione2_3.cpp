#include <iostream>
#include <array>
using namespace std;

int main()
{
    array<int, 3> arr = {3, 4, 5}; // tipo standard array

    for(int i = 0; i < arr.size(); i++) // scansione lineare dell'array
        cout << arr[i] << endl;
    
    for(int value : arr) // for each - per ogni valore di arr stamparlo - funziona con ogni tipo iterabile
        cout << value << endl;
    return 0;
}