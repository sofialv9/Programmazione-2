// Acquisire dall'utente tre numeri finché questi non sono positivi e l'ultimo numero è maggiore della somma dei primi due.

#include <iostream>
using namespace std;

int* readData()
{
	int* arr = new int[3] {0, 0, 0}; // alloca e inizializza un array dinamico di 3 interi
	int index = 0;
	do
	{
		int i;
		cin >> i; // legge un intero
		if (i > 0) // se è maggiore di 0 - non accetta numeri negativi in input
		{
		  if (index == 2)
			{
				if (i > arr[0] + arr[1])
				{
					arr[2] = i;
					index++;
				}
			}
		  else
		  {				
				arr[index] = i;
				index++;
		  }
		}
	} while (index != 3);
	return arr;
}

int main()
{
	int* arr = readData();
	cout << "Inserted " << arr[0] << " " << arr[1] << " " << arr[2] << endl;
	delete[] arr;
	return 0;
}