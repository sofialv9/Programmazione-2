#include <iostream>

using namespace std;

int main()
{
	const size_t size = 3;
	int arr[size] = {1, 3, 5};
	for (int i = 0; i < sizeof(arr)/sizeof(int); i++) // sizeof(arr)/sizeof(int) == 3
		cout << arr[i] << endl;
	
	for (int i : arr) // foreach
		cout << i << endl;

	int matrix[2][4] = { { 1, 2, 3, 4 },  { 5, 6, 7, 8} };

	for (int i = 0; i < 2; i++) // stampa la matrice
	{
		for (int j = 0; j < 4; j++)
			cout << matrix[i][j] << " ";
		cout << endl;
	}


	return 0;
}