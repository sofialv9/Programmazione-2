// Tabelline

#include <iostream>
using namespace std;

int main()
{
    int n, m;
    for(n = 1; n <= 10; n++){
        for(m = 10; m >= 1; m--)
            cout << n << " volte " << m << " = " << n * m << endl;
    }
    return 0;
}