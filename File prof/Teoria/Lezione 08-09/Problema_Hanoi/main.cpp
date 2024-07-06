#include <iostream>
#include "hanoi.hpp"
using namespace std;


/*
Problema di Hanoi:
    - se n = 1 spostare l'unico disco dal piatto iniziale al piatto finale
    - se n > 1
        1) Spostare n-1 dischi dal piatto iniziale al piatto centrale (piatto finale di appoggio);
        2) Spostare il disco più grande dal piatto iniziale al piatto finale (piatto centrale di appoggio);
        3) Spostare gli n-1 dischi dal piatto centrale al piatto finale (piatto iniziale di appoggio).
*/


int main()
{
    Hanoi hanoi(5); // problema di Hanoi con 5 dischi
    hanoi.risolvi();

    return 0;
}