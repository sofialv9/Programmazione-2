#include <iostream>
using namespace std;

class Matrice
{
public:
    Matrice(int _rows, int _columns) : rows(_rows), columns(_columns)
    {
        elements = new int*[rows]; // SE SI ANTEPONE IL TIPO DI DATO SI HA SEGMENTATION FAULT, BESTIA, CI HO MESSO ORE A RISOLVERE STA COSA
        for(int i = 0; i < rows; i++)
        {
            elements[i] = new int[columns];
            for(int j = 0; j < columns; j++)
            {
                elements[i][j] = 0;
            }
        }
    }

    int getRows() {return rows;}
    int getColumns() {return columns;}

    // acquisisce la matrice dall'input dell'utente
    void acquisisci()
    {
        int dim = columns * rows;
        cout << "Inserire i (" << dim << ") elementi della matrice " << rows << "X" << columns << " in sequenza: ";
        int input;
        for(int i = 0; i < rows; i++)
        {
            for(int j = 0; j < columns; j++)
            {
                cin >> input;
                elements[i][j] = input;        
            }
        }
    }

    // somma gli elementi di 2 matrici in modo puntuale
    Matrice& operator+(const Matrice& mtx)
    {
        for(int i = 0; i < rows; i++)
        {
            for(int j = 0; j < columns; j++)
            {
                this->elements[i][j] += mtx.elements[i][j];
            }
        }
        return *this;
    }

    // moltiplica gli elementi di 2 matrici in modo puntuale
    Matrice& operator*(const Matrice& mtx)
    {
        // se la matrice viene moltiplicata per la prima volta
        if(this->elements[0][0] == 0)
        {
            for(int i = 0; i < rows; i++)
            {
                for(int j = 0; j < columns; j++)
                {
                    // si inizializzano tutti gli elementi a 1
                    this->elements[i][j] = 1;
                }
            }
        }
        
        for(int i = 0; i < rows; i++)
        {
            for(int j = 0; j < columns; j++)
            {
                this->elements[i][j] *= mtx.elements[i][j];
            }
        }
        return *this;
    }

    Matrice& operator=(const Matrice& mtx)
    {
        this->columns = mtx.columns;
        this->rows = mtx.rows;
        for(int i = 0; i < rows; i++)
        {
            for(int j = 0; j < columns; j++)
            {
                this->elements[i][j] = mtx.elements[i][j];
            }
        }
        return *this;
    }


private:
    int** elements;
    int columns;
    int rows;

    friend ostream& operator<<(ostream& os, const Matrice& mtx)
    {
        for(int i = 0; i < mtx.rows; i++)
        {
            for(int j = 0; j < mtx.columns; j++)
            {
                os << mtx.elements[i][j];
                if(mtx.elements[i][j] > 9)
                    cout << "   ";
                else
                    cout << "    ";
            }
            os << endl;
        }
        return os;
    }
};

int main()
{
    Matrice A(2, 3);
    A.acquisisci();
    Matrice B(2, 3);
    B.acquisisci();
    cout << "Matrice A:" << endl;
    cout << A << endl;
    cout << "Matrice B:" << endl;
    cout << B << endl;

    Matrice C(2, 3);
    cout << "C = A + B" << endl;
    C + A + B;
    cout << C << endl;

    Matrice D(2, 3);
    cout << "D = (A * C)" << endl;
    (D * A) * C;
    cout << D << endl;

    Matrice E(2, 3);
    cout << "E = A" << endl;
    E = A;
    cout << E << endl;
}