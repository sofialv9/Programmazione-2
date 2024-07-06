//FILE - lettura

#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    fstream stream("es1.txt"); // apre il file
    if(stream.is_open())
    {
        // stampa i caratteri contenuti nel file uno ad uno
        char c;

        /* while(stream.good()) // fino a quando lo stream è attivo (= è possibile leggere dallo stream)
        {
            stream.get(c); // stampa l'ultimo carattere 2 volte (stream.good() ritorna true anche se incontra l'EOF e quindi stream.get() stampa l'ultimo carattere disponibile nel buffer)
            cout << c << endl;
        } */

        // alternativa (non stampa l'ultimo carattere 2 volte)
        /* while(stream.get(c))
        {
            cout << c << endl;
        }*/

        // stampa le parole una ad una
       /* string s;
        while(stream >> s) // si usa l'operatore di stream
        {
            cout << s << endl;
        } */

        // stampa le righe una ad una
        string s;
        while(getline(stream, s))
        {
            cout << s << endl;
        }
        
    }
    stream.close(); // chiusura dello stream
    return 0;
}