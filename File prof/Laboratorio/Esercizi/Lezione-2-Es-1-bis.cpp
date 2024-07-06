// Diversamente dalla prima versione permette di non contare prima il numero di token presenti nel file + non include gli spazi all'interno dei token

#include<iostream>
#include<fstream>

using namespace std;

void expand(string**& arr, const size_t& oldcapacity, const size_t& newcapacity)
{
	string** newarr = new string * [newcapacity]; // alloca dinamicamente un nuovo array con la nuova lunghezza (uguale al doppio di quella vecchia)
	for (size_t i = 0; i < oldcapacity; i++) // copia gli elementi presenti nel vecchio array all'interno del nuovo array
	{
		newarr[i] = arr[i];
	}
	delete arr; // cancella il vecchio array
	arr = newarr; // associa all'indirizzo del vecchio array quello del nuovo array
}

void store(string* s, string**& arr, size_t& capacity, size_t& size)
{
	if (size == capacity) // se il numero di token ha eguagliato la lunghezza dell'array
	{
		capacity *= 2; // duplica la lunghezza dell'array
		expand(arr, size, capacity); // espande l'array con la nuova lunghezza
	}
	arr[size] = s; // salva il token all'interno dell'array
	size++; // incrementa il numero di token

}


void tokenize(const string& source, string**& arr, size_t& size, size_t& capacity)
{
	ifstream stream(source); // apre il file da tokenizzare
	if (stream.is_open())
	{
		string acc;
		char c;
		while (stream.get(c))
		{
			if (c != '\n' && c != '\r' && (acc.size() != 0 || c != ' '))
				acc += c; // salva il carattere nella stringa acc
			if (c == ',' || c == '.')
			{
				string* token = new string(acc); // alloca dinamicamente la stringa corrispondente al token
				store(token, arr, capacity, size); // conserva il token all'interno dell'array
				acc.clear(); // cancella la stringa contenuta in acc
			}
		}
		stream.close();
	}
}



int main()
{
	size_t capacity = 10; // inizializza la dimensione dell'array di stringhe
	size_t size = 0; // inizializza il numero di token letti
	string** arr = new string * [capacity]; // alloca un array dinamico contenente 10 stringhe
	tokenize("es1.txt", arr, size, capacity);
	for (size_t i = 0; i < size; i++) // stampa i token contenuti nell'array
		cout << *arr[i] << endl;

	return 0;
}