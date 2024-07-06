#include <iostream>
using namespace std;

int main()
{
    int* n = new int(2); // allocazione dinamica di un intero
    delete n; // libera la memoria allocata dinamicamente

    size_t size = 5;
    int* arr = new int[size]; // alloca un array dinamico di 5 interi
    delete[] arr; // dealloca l'array dinamico
}