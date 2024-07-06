#include <iostream>
using namespace std;

void initArray(int* arr, const size_t size)// funzione non produttiva (non restituisce nulla)
{
    for(size_t i = 0; i < size; i++)
        arr[i] = i;
    // return; - non è necessario
}

int main()
{
    int* p = new int(2); // allocazione dinamica di un intero
    cout << *p << endl; // stampa 2
    delete p; // libera la memoria allocata dinamicamente

    size_t size = 5;
    int* arr = new int[size]; // alloca un array di 5 interi
    for(size_t i = 0; i < size; i++) // inizializza l'array
        arr[i] = i;
    for(size_t i = 0; i < size; i++) // stampa l'array
        cout << arr[i] << " ";
    cout << endl;
    delete[] arr; // dealloca l'array

    int* arr = new int[size]; // è meglio allocare la memoria nel main e non nella funzione (concetto di "separation of concerns")
    initArray(arr, size);
    for(size_t i = 0; i < size; i++) // stampa l'array
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}