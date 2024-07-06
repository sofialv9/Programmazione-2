#include <iostream>
using namespace std;
char isPositiveorNegative(int n);

int main()
{
    int n;
    cout << "Inserisci un intero relativo: ";
    cin >> n;
    cout << isPositiveorNegative(n) << endl;
    return 0;
}

char isPositiveorNegative(int n)
{
    if(n == 0 || n < 0)
        return 'N';
    else
        return 'P';
}