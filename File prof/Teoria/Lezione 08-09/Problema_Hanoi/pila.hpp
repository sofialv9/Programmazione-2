#ifndef pila_hpp
#define pila_hpp

#include <iostream>
using namespace std;

// Classe template - gestisce tipi generici
template <typename T>
class Pila
{
public:
    Pila() : n(0) {}
    
    // v è l'elemento in cima alla pila
    void push(T v) {array[n] = v; n++;}
    T pop() {n--; return array[n];}

    int size() {return n;}
    void stampa();
    
private:
    T array[100];
    int n; // numero di elementi (inizializzato dal costruttore a 0)
};

// Poichè i metodi di classe template sono risolti dal compilatore si inserisce qui l'include del file .cpp (e non nel linker)
#include "pila.cpp"

#endif /* pila_hpp */
