/*
   Leggere il contenuto del file "es1.txt" tokenizzandolo sul simbolo "," e ".".
   I token devono essere salvati su un array.
   Scrivere sul file chiamato "es1-out.txt" il numero di token ottenuti.
*/

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

// Calcola il numero di token separati da "," o da "." presenti nel file
static int computeTokensNum(const string &filename)
{
	ifstream file(filename); // apre il file in modalità di lettura
	int num = 0;
	if (file.is_open()) // se il file si è aperto correttamente
	{	
		char c;			
		while (file.get(c)) // mentre legge i caratteri nel file
		{		
		  if(c == '.' || c == ',') // se il carattere è uguale a "," o a "." ...
			num++;  //... aumenta di 1 il contatore dei token
			   
		}
	}	
	file.close();
	return num;
}

static void tokenize(vector<string>* tokens, const string& filename)
{
	ifstream file(filename); // apre il file in lettura
	int i = 0;
	if (file.is_open())
	{		
		string token = ""; // inizializza una stringa vuota per conservarci un token
		char c;
		while (file.get(c))
		{						
			if (c != '\n' && c != '\r') // se il carattere è diverso da \n e da \r
			{				
				token += c; // aggiunge il carattere all'interno del token
				if (c == '.' || c == ',') // se il carattere è uguale a quelli di tokenizzazione
				{
					tokens->at(i) = token; // salva il token all'interno del vettore tokens all'indice i				
					i++; // incrementa l'indice corrente del vettore
					token = ""; // reinizilizza il token a una stringa vuota per leggere il prossimo			
				}
			}
		}
		cout << token << endl; // stampa \n (lascia una riga di spazio)
	}
	file.close();
}

static void writeNumTokens(const string name, const int num)
{
	ofstream file(name);
	file << num;
	file.close();
}

int main()
{
	string filename = "es1.txt"; // file di input
	string fileout = "es1-out.txt"; // file di output
	int num = computeTokensNum(filename); // calcola il numero di token presenti nel file 	
	if (num > 0) // se il numero di token è maggiore di 0
	{
		//string* tokens = new string[num];
		vector<string>* tokens = new vector<string>(num); // alloca un vettore di stringhe con un numero di elementi pari al numero di token
		cout << num << endl; // stampa il numero di token ottenuti
		tokenize(tokens, filename); // inserisce i token letti nel file all'interno del vettore
		for (int i = 0; i < num; i++)
		{	
			string s = tokens->at(i);
			cout << i;
			if(s[0] != ' ')
				cout << " ";
			cout << s << endl; // stampa i token con l'indice del vettore corrispondente
			/* 
			Versione in cui stampa anche gli spazi iniziali:
				cout << i << " " << tokens->at(i) << endl
			*/
		}
		writeNumTokens(fileout, num); // scrive sul file di output il numero di token ottenuti
		delete tokens;
	}	
	return 0;
}
