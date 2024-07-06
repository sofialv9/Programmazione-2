#include "ciao.hpp"
#include <iostream>
using namespace std;

void Prodotto::leggi(const char* fname, int dim, Prodotto* array)
{
    ifstream stream;
    stream.open(fname, ios::in);
    while(!stream.eof())
    {
        size_t pos = 0;
        size_t newpos;
        string line;
        getline(stream, line);
        for(int i = 0; i < dim; i++) // dim = numero di elementi da leggere (= coppie di codice e prezzo)
        {
            newpos = line.find(",", pos);
            array[i].codice = stoi(line.substr(pos, newpos-pos));
            pos = newpos + 1; // salta lo spazio dopo la virgola
            newpos = line.find(";", pos);
            array[i].prezzo = stod(line.substr(pos, newpos-pos));
            pos = newpos + 1;
        }
    }
    return;
}

void Venditore::leggi(const char* fname, int dim, Venditore* array)
{
    ifstream stream;
    stream.open(fname, ios::in);
    while(!stream.eof())
    {
        size_t pos = 0;
        size_t newpos;
        string line;
        getline(stream, line);
        for(int i = 0; i < dim; i++)
        {
            newpos = line.find(",", pos);
            array[i].codiceVenditore = stoi(line.substr(pos, newpos-pos));
            pos = newpos + 1;
            newpos = line.find(";", pos);
            array[i].numeroProdotti = stoi(line.substr(pos, newpos-pos));
            pos = newpos + 1;
        }
    }
    return;
}

ostream& operator<<(ostream& os, Prodotto& prodotto)
{
    os << "Codice prodotto: " << prodotto.getCodice() << " Prezzo: " << prodotto.getPrezzo() << endl;
    return os;
}

ostream& operator<<(ostream& os, Venditore& venditore)
{
    os << "Codice venditore: " << venditore.getCodice() << endl << "Elenco prodotti venduti: " << endl;
    for(int i = 0; i < venditore.numeroProdotti; i++)
    {
        os << " - " << venditore.prodottiVenduti[i];
    }
    os << endl;
    return os;
} 

void Prodotto::operator=(const Prodotto& p)
{
    codice = p.codice;
    prezzo = p.prezzo;
}


void Venditore::operator=(const Venditore& v)
{
    codiceVenditore = v.codiceVenditore;
    numeroProdotti = v.numeroProdotti;
    prodottiVenduti.clear();
    for(int i = 0; i < v.prodottiVenduti.size(); i++)
    {
        prodottiVenduti.push_back(v.prodottiVenduti[i]);
    }
}

double Venditore::calcolaPrezzoTotale()
{
    double totale = 0;
    for(int i = 0; i < this->numeroProdotti; i++)
    {
        totale += this->prodottiVenduti[i].getPrezzo();
    }
    return totale;
}

bool operator>(Venditore& a, Venditore& b)
{
    return a.calcolaPrezzoTotale() > b.calcolaPrezzoTotale();
}

bool operator<(Venditore& a, Venditore& b)
{
    return a.calcolaPrezzoTotale() < b.calcolaPrezzoTotale();
}

void swap(Venditore& a, Venditore& b)
{
    Venditore temp(a);
    a = b;
    b = temp;
}

void printCrescente(Venditore* array, int dim)
{
    for(int i = 0; i < dim - 1; i++)
    {
        for(int j = 0; j < dim - 1; j++)
        {
            if(array[j] > array[j + 1])
                swap(array[j], array[j + 1]);
        }
    }

    for(int i = 0; i < dim; i++)
    {
       cout << "Codice Venditore: " << array[i].getCodice() << "  Prezzo totale: " << array[i].calcolaPrezzoTotale() << endl;
    }
} 

void printDecrescente(Venditore* array, int dim)
{
    for(int i = 0; i < dim - 1; i++)
    {
        for(int j = 0; j < dim - 1; j++)
        {
            if(array[j] < array[j + 1])
                swap(array[j], array[j + 1]);
        }
    }

    for(int i = 0; i < dim; i++)
    {
       cout << "Codice Venditore: " << array[i].getCodice() << "  Prezzo totale: " << array[i].calcolaPrezzoTotale() << endl;
    }
} 

