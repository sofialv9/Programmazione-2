// Legge una tabella di 4 righe per 5 colonne di elementi interi e la visualizza sullo schermo

#include <iostream>
using namespace std;

int main()
{
    int matrice[4][5];
    cout << "Immetti una tabella di 4 righe per 5 colonne di elementi interi:" << endl;
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            cin >> matrice[i][j];
        }
    }

    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            cout << matrice[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}