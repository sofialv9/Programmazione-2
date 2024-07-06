#include "hanoi.hpp"

Hanoi::Hanoi(int n)
{
    for(; n > 0; n--)
        sinistra.push(n);
}

void Hanoi::risolvi()
{
    // visualizza lo stato iniziale
    stampa();
    // chiamata ricorsiva
    risolvi_ricorsivamente(sinistra, destra, centrale, sinistra.size()); // sinistra.size() ritorna il numero di dischi
}

void Hanoi::risolvi_ricorsivamente(Pila<int>& iniziale, Pila<int>& finale, Pila<int>& appoggio, int n)
{
    if(n == 1) {// caso base
        int disco = iniziale.pop();
        cout << "Sposto il disco " << disco << endl << endl;
        finale.push(disco); // si sposta l'unico disco dalla pila iniziale a quella finale
        // Visualizzo lo stato dei dischi
        stampa();
        return;
    }
    
    // supponiamo di saperlo risolvere per n - 1
    risolvi_ricorsivamente(iniziale, appoggio, finale, n - 1); // spostiamo n - 1 dischi dalla pila iniziale a quella di appoggio
    risolvi_ricorsivamente(iniziale, finale, appoggio, 1); // prendiamo l'unico disco rimasto nella pila iniziale alla pila finale
    risolvi_ricorsivamente(appoggio, finale, iniziale, n - 1); // spostiamo n - 1 dischi dalla pila di appoggio a quella finale
}

void Hanoi::stampa() // Visualizzo lo stato dei dischi
{
    cout << "Disco sinistro: "; sinistra.stampa();
    cout << "Disco centrale: "; centrale.stampa();
    cout << "Disco destro: "; destra.stampa();
    cout << endl;
}