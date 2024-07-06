#ifndef figura_hpp
#define figura_hpp

#include <iostream>
using namespace std;

// Classe astratta - ha almeno un metodo che non ha implementazione (indicato dal "= 0")
class Figura
{
public:
    virtual double calcolaArea() = 0; // Il calcolo dell'area dipende dal tipo di figura, quindi si inserisce "virtual"
    virtual double calcolaPerimetro() = 0; 
    virtual void stampa() = 0;
};

class Cerchio : public Figura
{
public:
    Cerchio(double valraggio) : raggio(valraggio), pigreco(3.14) {} // si usa il prefisso "val" per distinguere il parametro in input dal dato membro

    virtual double calcolaArea() {return pigreco * raggio * raggio;}
    virtual double calcolaPerimetro() {return 2 * pigreco * raggio;} 
    virtual void stampa() {cout << "Cerchio di raggio: " << raggio << endl;}
private:
    double raggio;
    const double pigreco;
};

class Quadrato : public Figura
{
public:
    void setLato(double val_lato) {lato = val_lato;}
    virtual double calcolaArea() {return lato * lato;}
    virtual double calcolaPerimetro() {return 4 * lato;} 
    virtual void stampa() {cout << "Quadrato di lato: " << lato << endl;}
private:
    double lato;
};


#endif /* figura_hpp */