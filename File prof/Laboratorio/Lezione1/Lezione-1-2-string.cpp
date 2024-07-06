#include<iostream>
#include <limits>


using namespace std;

int main()
{
	string s = "Primo Messaggio";
	string s1 = "Secondo Messaggio";
	cout << s << endl;
	string s2 = s + " "+ s1; // s2 è la concatenazione di s e s1 con uno spazio in mezzo alle 2 stringhe
	cout << s2 << endl;
	cout << s2.at(3) << endl; // stampa 'm'
	cout << s2.size() << endl; // stampa la lunghezza di s2 (33)
	cout << s2.length() << endl; // uguale a size()

	string s3 = s2;
	//strcpy(s3, s2);
	s2.resize(10); // taglia s2 al decimo carattere
	cout << s2 << endl; // stampa "Primo Mess"
	s2.clear(); // cancella la stringa s2
	cout << s2 << endl; // non stampa nulla
	cout << s3 << endl;

	cout << s3.find("Messaggio") << endl; // trova la posizione della prima occorrenza della parola Messaggio (posizione 6)
	cout << s3 <<" Find M:" << s3.find('M') << endl; // trova la prima occorrenza della lettera M (6)
	cout << "Substring:" << s3.substr(0, s3.find('M')) << endl; // seleziona la sottostringa compresa tra la posizione 0 e la prima occorrenza di M (stampa "Primo")

	string s4(10, 'g'); // crea una stringa formata da 10 g
	cout << s4 << endl; // gggggggggg
	
	cout << "Insert a message (1)" << endl;
	string message;
	cin >> message; // legge fino allo spazio
	cout << message << endl;
	cin.ignore(numeric_limits <streamsize> ::max(), '\n'); //flush - per usarlo si deve includere la libreria <limits> - ignora il resto dell'input dell'utente fino al carattere \n
	cout << "Insert a message (2)" << endl;
	getline(cin, message); // legge tutto l'input (anche gli spazi)
	cout << message << endl;

	cout << "Insert a message (3)" << endl;
	char c;	
	do 
	{
	  cin.get(c);
	  cout << c << endl;	 
	} while (c != '\n'); // stampa la stringa inserita carattere per carattere (uno sopra l'altro)
	
}