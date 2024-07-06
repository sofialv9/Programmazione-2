//FILE - scrittura (out)

#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ofstream stream("es1-out.txt"); // apre il file in scrittura
    if(stream.is_open())
    {
        string messaggio = "Lezione di Prog 2";
        stream << messaggio; // se il file esiste lo sovrascrive, altrimenti lo crea
    }
    stream.close();
    return 0;
}