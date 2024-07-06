#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    string fname;
    fstream stream(fname); // apre il file
    // oppure
    fstream stream;
	stream.open(fname);

    stream.is_open(); // == true se il file si è aperto correttamente
    stream.good(); // == true se il file è attivo

    // stampa i caratteri uno ad uno
    char c;
    while(stream.get(c))
    {
        cout << c << endl;
    }

    // stampa le parole una ad una
    string s;
    while(stream >> s) // si usa l'operatore di stream
    {
        cout << s << endl;
    }

    // stampa le righe una ad una
    string s;
    while(getline(stream, s))
    {
        cout << s << endl;
    }
    
    stream.close(); // chiude lo stream

    ofstream stream("file.txt"); // apre il file in scrittura - se il file esiste lo sovrascrive, altrimenti lo crea
    ofstream stream("file.txt", ios_base::app); // apre il file in modalità append (aggiunge testo alla fine del file)
}