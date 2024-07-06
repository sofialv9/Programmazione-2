// File di implementazione - contiene la definizione dei metodi

#include <iostream>
#include <cstring>

using namespace std;

#include "persona.hpp"

void Persona::setNome(const char* valnome) {
    size_t len = strlen(valnome);
    nome = new char[len + 1];
    strncpy(nome, valnome, len + 1);
}

const char* Persona::getNome()
{
    return nome;
}

void Persona::stampa() {
    cout << "L'età della persona " << getNome() << " " << getCognome() << " è " << getEta() << " anni." << endl;
    cout << "La persona è maggiorenne:" << maggiorenne() << endl;
}

void Persona::setCognome(const char* valcognome) {
    size_t len = strlen(valcognome);
    cognome = new char[len + 1];
    strncpy(cognome, valcognome, len + 1);
}

const char* Persona::getCognome()
{
    return cognome;
}

void Persona::setEta(int valeta) {
    eta = valeta;
}

int Persona::getEta() {
    return eta;
}

bool Persona::maggiorenne() {
    return (eta >= maggiore_eta);
}

void Studente::stampa()
{
    cout << "Questa persona è uno studente" << endl;
    Persona::stampa(); // richiamo la funzione "stampa" della classe base
    cout << "La media è " << media << endl;
}

void Professore::stampa()
{
    cout << "Questa persona è un professore" << endl;
}

void Assistente::stampa()
{
    cout << "Questa persona è un assistente che eredita sia da Studente che da Professore." << endl;
    // Chiamo entrambe le funzioni stampa della classe base, quindi visualizzero sia le informazioni di studente che di professore
    Studente::stampa();
    Professore::stampa();
}

