// esempi in C++ per Programmazione II

#include <iostream>

using namespace std;

#include "pila.hpp"
#include "figura.hpp"

// Funzione template - al posto di typename si può scrivere "class" - il parametro T indica un tipo qualsiasi di dato
template <typename T>
void scambia(T& a, T& b)
{
    T t = a;
    a = b;
    b = t;
}

int main()
{
    float x = 5.5;
    float y = 7.7;
    scambia <float> (x,y); // se non si specifica il tipo di dato per cui si chiama la funzione esso viene dedotto dai parametri in input

    // Si deve specificare che tipo di pila si vuole usare (non può essere dedotto dal compilatore)
    Pila<float> pila;
    
    pila.push(3.5);
    pila.push(4.6);
    pila.push(5.3);
    
    cout << pila.pop() << " " << pila.pop() << " "<< pila.pop() << endl;

    Pila<Quadrato> pila_quadrati;
    // Se si vuole inserire tipi eterogenei all'interno di una pila si deve utilizzare il polimorfismo, non i template
    
    return 0;
}


