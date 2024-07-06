// FILE: append

#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ofstream stream("es1-out.txt", ios_base::app); // apre il file in modalità append (aggiunge testo alla fine del file)
    if(stream.is_open())
    {
        string messaggio = "\nLezione di Prog 2";
        stream << messaggio;
    }
    stream.close();
    return 0;
}