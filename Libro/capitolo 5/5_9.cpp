// Determina se una stringa di caratteri è palindroma

#include <iostream>
#include <cstring>
using namespace std;
bool isPalindroma(char* s);

int main()
{
    char* s = new char;
    cout << "Inserisci una stringa e io ti dirò se è palindroma: ";
    cin >> s;
    if(isPalindroma(s))
        cout << "La stringa \"" << s << "\" è palindroma." << endl;
    else
        cout << "La stringa \"" << s << "\" non è palindroma." << endl;
    return 0;
}

bool isPalindroma(char* s)
{
    bool result = false;

    for(int i = 0; i < strlen(s); i++)
    {
        if(s[i] == s[strlen(s) - i - 1])
            result = true;
        else
            result = false;
    }

    return result;
}