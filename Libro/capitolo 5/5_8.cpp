// Prende in input una stringa di caratteri e la restituisce in modo inverso

#include <iostream>
#include <cstring>
using namespace std;
char* reverse(char* s);

int main()
{
    char* s = new char;
    cout << "Inserisci una stringa per invertirne l'ordine dei caratteri: ";
    cin >> s;
    cout << reverse(s) << endl;
    return 0;
}

char* reverse(char* s)
{
    char* s1 = new char;
    for(int j = 0; j < strlen(s); j++)
    {
        s1[j] = s[strlen(s) - 1 - j];
    }
    return s1;
}