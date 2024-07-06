// Determina se 2 numeri interi positivi sono amici, coè se la somma dei divisori diversi da se stesso di ognuno di loro coincide con l'altro numero (es. 284 e 220)

#include <iostream>
using namespace std;
bool isFriends(int a, int b);

int main()
{
    int n = 0, m = 0;
    cout << "Inserisci 2 numeri interi positivi e ti dirò se sono amici: ";
    cin >> n >> m;

    if(isFriends(n, m))
        cout << "I numeri " << n << " e " << m << " sono amici." << endl;
    else
        cout << "I numeri " << n << " e " << m << " non sono amici." << endl;

    return 0;
}

int sumDivisori(int n)
{
    int sum = 0;
    for(int i = 1; i < n; i++)
    {
        if(n % i == 0)
            sum += i;
    }
    return sum;
}

bool isFriends(int a, int b)
{
    int sumA, sumB;
    sumA = sumDivisori(a);
    sumB = sumDivisori(b);
    if(sumA == b && sumB == a)
        return true;
    else
        return false;
}
