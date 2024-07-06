#include "ciao.hpp"
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    // Lettura prodotti da standard input
    Prodotto prodotti[5];
    for(int i = 0; i < 5; i++)
    {
        prodotti[i].leggi("prodotti.txt", 5, prodotti);
    }

    Venditore venditori[4];
    for(int i = 0; i < 4; i++)
    {
        venditori[i].leggi("venditori.txt", 4, venditori);
    }

    for(int i = 0; i < 4; i++)
    {
        int n = venditori[i].getNumeroProdotti();
        for(int j = 0; j < n; j++)
        { 
            venditori[i].aggiungiProdotto(prodotti[j]);
        }
    }

  cout << "Inserire 1 per stampare i venditori con prezzi in ordine crescente, inserire 2 per stampare i venditori con i prezzi in ordine decrescente:" << endl;
  int n;
  cin >> n;
  // inserire lo switch nel do...while permette di continuare a prendere input dall'utente finché non inserisce un numero valido
  do { 
      switch(n)
      {
        case 1:
          cout << "Venditori in ordine crescente:" << endl;
          printCrescente(venditori, 4);
          break;
        case 2:
        cout << "Venditori in ordine decrescente:" << endl;
          printDecrescente(venditori, 4);
          break;
        default:
          cout << "Inserire un numero valido." << endl;
          cin >> n;
          break;
      }
  } while (n != 1 && n != 2);
    

  return 0;
}