// Legge le dimensioni di una matrice, legge e visualizza la matrice e trova gli elementi maggiore e minore della matrice e le loro posizioni.

#include <iostream>
using namespace std;

int main()
{
    int n, m;
    cout << "Inserire le dimensioni della matrice: ";
    cin >> n >> m;
    int matrice[n][m];
    cout << "Inserire i valori della matrice:" << endl;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> matrice[i][j];
        }
    }
    cout << "Matrice:" << endl;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cout << matrice[i][j] << " ";
        }
        cout << endl;
    }
    int max = matrice[0][0];
    int min = max;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(matrice[i][j] > max)
                max = matrice[i][j];
            if(matrice[i][j] < min)
                min = matrice[i][j];
        }
    }
    cout << "Massimo: " << max << ". Minimo: " << min << "." << endl;
}