#include <iostream>
using namespace std;

double potenza(double b, int n)
{
    if(n == 0)
        return 1;
    else
        return b * potenza(b, n - 1);
}

int fibonacci(int n)
{
    if (n == 0 || n == 1) // 2 casi base
        return n;
    return fibonacci(n - 1) + fibonacci(n-2);
}

int max(int array[], size_t i, size_t j) {
    if(j == i) // se l'array contiene un solo elemento
        return array[i];
    
    size_t k = (j - i + 1) / 2 + i - 1; // indice dell'ultimo elemento del 1° insieme
    int max1 = max(array, i, k); // massimo della prima metà dell'array
    int max2 = max(array, k + 1, j); // massimo della seconda parte dell'array
    if(max1 > max2)
        return max1;
    return max2;
}

int MCD(int m, int n) // algoritmo di Euclide: MCD(a, b) -> if (b == 0) return a; else return (b, a % b);
{
    if(m < n)
        return MCD(n, m);
    if(n == 0)
        return m;
    else
        return MCD(n, m % n);
}

int main()
{
    int vettore[] = {5, 7, 3, 8, 2};
    cout << "Il massimo dell'array è: " << max(vettore, 0, sizeof(vettore)/sizeof(vettore[0]) - 1) << endl;

    int n = 22;
    int m = 14;
    cout << "Il massimo comune divisore tra " << m << " e " << n << " è: " << MCD(m, n) << "." << endl;

    return 0;

    double b = 2;
    int p = 4;
    cout << "La potenza di " << b << " elevato a " << p << " è: " << potenza(b, p) << endl;

    cout << "Il sesto numero della serie di Fibonacci è: " << fibonacci(6) << endl;
}