#include <iostream>

using namespace std;

static void printArray(const int* arr, const size_t size) // stampa l'array
{
	for (int i = 0; i < size; i++)
		cout << arr[i] << endl;
}

static void reinitArray(int* arr, const size_t size) // aggiunge 1 ad ogni elemento dell'array
{
	for (int i = 0; i < size; i++)
		arr[i] += 1;

}

int main()
{
	size_t size = 10;
	int* arr = new int[size]; // alloca dinamicamente l'array (di 10 interi)
	if (arr != NULL) 
		cout << arr << endl << endl; // stampa l'indirizzo dell'array
	
	cout << sizeof(arr) << endl << endl; // stampa la dimensione dell'array	

	// inizializza l'array
	for (int i = 0; i < size; i++)
		arr[i] = i;
	// stampa l'array
	for (int i = 0; i < size; i++)
		cout << arr[i] << endl;

	reinitArray(arr, size); // aggiorna i valori dell'array (lo "reinizializza")
	printArray(arr,size); // stampa l'array

    delete [] arr;		

    return 0;
}