#ifndef hanoi_hpp
#define hanoi_hpp

#include "pila.hpp"

class Hanoi {
public:
    Hanoi(int n);
    void risolvi();

private:
    void risolvi_ricorsivamente(Pila<int>& iniziale, Pila<int>& finale, Pila<int>& appoggio, int n);
    void stampa();
private:
    Pila<int> sinistra;
    Pila<int> centrale;
    Pila<int> destra;
};

#endif /* hanoi_hpp */