// Legge una collezione di stringhe di caratteri di lunghezza arbitraria e, per ogni stringa letta, deve: stampare la lunghezza della stringa; contare il numero di occorrenze di parole di 4 lettere; sostituire ogni parola di 4 lettere con una stringa di 4 asterischi e stampare la nuova stringa.

#include <iostream>
#include <cstring>
#define MAX 100
using namespace std;

int main()
{
    char s[MAX];
    char* word = new char;
    int count = 0;
    cout << "Inserire una collezione di stringhe di lunghezza arbitraria:" << endl;
    cin.getline(s, MAX);
    cout << "La lunghezza della stringa estratta è: " << strlen(s) << endl;

        int i = strlen(s);
        /*while(i > 0)
        {
            word = getline(s, ' ');
            if(strlen(word) == 4)
            {
                count++;
                strcpy(word, "****");
            }
            i--;
        }*/
        cout << "La stringa ottenuta è: " << s << endl;  
        return 0;
    }