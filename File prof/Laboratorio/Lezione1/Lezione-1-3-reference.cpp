#include <iostream>

using namespace std;

int main()
{
	int i = 45;
	int &ref = i; // ref è un alias di i (ha il suo stesso valore)

	i = i + 1; // i = 46

	cout << "i" << endl;
	cout << i << endl;
	cout << &i << endl; // stampa l'indirizzo della variabile i

	cout << "Reference" << endl;

	cout << ref << endl; // stampa il valore di i (46)
	cout << &ref << endl; // stampa l'indirizzo di ref (uguale a quello di i)
	
	int* pointer = &i; // puntatore a i

	cout << "Pointer" << endl;
	cout << pointer << endl; // stampa il valore del puntatore (l'indirizzo di i)
	cout << &pointer << endl; // stampa l'indirizzo del puntatore
	cout << *pointer << endl; // dereferenzia il puntatore (stampa il valore di i)

	return 0;
}