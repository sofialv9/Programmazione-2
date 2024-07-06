#ifndef ciao_hpp
#define ciao_hpp

#include <vector>
#include <fstream>
#include <iostream>
using namespace std;

class Prodotto {
public:
    Prodotto() : codice(0), prezzo(0.0) {}
    Prodotto(int _codice, double _prezzo) : codice(_codice), prezzo(_prezzo) {}
    int getCodice() {return codice;}
    double getPrezzo() {return prezzo;}
    void setCodice(int _codice) {codice = _codice;}
    void setPrezzo(double _prezzo) {prezzo = _prezzo;}
    void leggi(const char* fname, int dim, Prodotto* array);

    void operator=(const Prodotto& p);

private:
    int codice;
    double prezzo;

    friend ostream& operator<<(ostream& os, Prodotto& prodotto);
};

class ProdottoAlimentare : public Prodotto
{
public:
    ProdottoAlimentare(int _codice, double _prezzo, int _scadenza) : Prodotto(_codice, _prezzo) , scadenza(_scadenza) {}
    bool verifica(ProdottoAlimentare _prodotto);
private:
    int scadenza;
};

class ProdottoPerBambini : public Prodotto
{
    ProdottoPerBambini(int _codice, double _prezzo, string _fasciaEtà) : Prodotto(_codice, _prezzo) , fasciaEtà(_fasciaEtà) {}
private:
    string fasciaEtà;
};

class Venditore
{
public:
    Venditore() : codiceVenditore(0), numeroProdotti(0) {}
    Venditore(int _codiceVenditore) : codiceVenditore(_codiceVenditore) {}
    Venditore(Venditore& v) : codiceVenditore(v.codiceVenditore), prodottiVenduti(v.prodottiVenduti), numeroProdotti(v.numeroProdotti) {} // costruttore di copia

    int getCodice() {return codiceVenditore;}
    int getNumeroProdotti() {return this->numeroProdotti;}

    double calcolaPrezzoTotale();
    //double calcolaValoreMagazzino();
    Venditore& aggiungiProdotto(Prodotto& p) {prodottiVenduti.push_back(p); return *this;}
    void leggi(const char* fname, int dim, Venditore* array);

    void operator=(const Venditore& v);
    

private:
    int codiceVenditore;
    vector<Prodotto> prodottiVenduti;
    int numeroProdotti;

    friend ostream& operator<<(ostream& os, Venditore& venditore);
    friend bool operator<(Venditore& a, Venditore& b);
    friend bool operator>(Venditore& a, Venditore& b);
    friend void printCrescente(Venditore* array, int dim);
    friend void printDecrescente(Venditore* array, int dim);
    friend void swap(Venditore& a, Venditore& b);
}; 

#endif /* ciao_hpp */