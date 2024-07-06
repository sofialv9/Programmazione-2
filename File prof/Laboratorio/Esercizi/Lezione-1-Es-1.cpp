#include<iostream>

using namespace std;

const struct 
{
	string vowels="aAeEiIoOuU";
} vowels;

int countVowel(string& message) // funziona anche senza &
{
  int counter = 0;
  for (char c : message) // scorre i caratteri della stringa in input
   for (char v : vowels.vowels) // scorre la stringa contenente le vocali
	if (c == v)
	{
	  counter++;
	  break;
	}
  return counter;
}

int main()
{
	string message;
	int counter = 0;
	cout << "Inserisci una stringa per ottenere il numero di vocali in essa contenute:" << endl;
	getline(cin, message); // legge una stringa
	cout << message << endl; // stampa la stringa in input a schermo
	counter = countVowel(message); // calcola il numero d vocali
	cout << counter << endl;
	return 0;
}