#include <iostream>
using namespace std;

#include "figura.hpp"

// Operazioni sulle figure

int main()
{
    // Non si può istanziare un'istanza di Figura essendo essa una classe astratta ma si può definire un puntatore a Figura
    Quadrato* q = new Quadrato();
    q->setLato(2.0);
    
    // Array di puntatori a Figura
    // Il lato del 1° quadrato viene automaticamente inizializzato a 0
    Figura* figura[] = {new Cerchio(5.0), new Quadrato(), q};

    // figura[1]->setLato(); NON valido - il compilatore non sa che tipo di figura sia
    
    //sizeof(figura) ritorna la dimensione dell'array, diviso per sizeof(Figura*) ritorna il numero di elemento degli array (che non si conosce a priori)
    for(int i = 0; i < sizeof(figura)/sizeof(Figura*); i++)
    {
        figura[i]->stampa();
        cout << "L'area della figura è: " << figura[i]->calcolaArea() << ". Il perimetro è: " << figura[i]->calcolaPerimetro() << "." << endl;
    }

    return 0;
}