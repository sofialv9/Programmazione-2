// esempi in C++ per Programmazione II

#include <iostream>

using namespace std;

#include "persona.hpp"

int main()
{
    Persona p("Giacomo","Rossi", 19);
    Studente s1("Mario","Bianchi",23,29.5);
    Studente s2("Mario","Bianchi",23,29.5);
    Professore prof("Carmelo", "Pappalardo",45);
    Assistente ass("Gisella", "Catania", 30, 30.0);


// Se non si usa lo specificatore virtual nella classe condivisa dalle classi base per evitare ambiguità si deve specificare a quale funzione "getNome" ci si sta riferendo, se quello della classe Studente o della classe Professore
    a.Studente :: getNome();  
// Se si usa virtual
    a.getNome();

    
    Persona* persona[6]; // array di puntatori a Persona
// Ad un riferimento (o puntatore) a una classe base (Persona) si può assegnare un oggetto di una classe derivata (Studente). Non vale il viceversa. es. Studente& studente = p NON è valido
    persona[0] = &p;
    persona[1] = &s1;
    persona[2] = &s2;
    persona[3] = &prof;
    persona[4] = &ass;
    persona[5] = new Persona("Filippo","Rossi",34); // allocazione dinamica
    
    for (int i=0; i<6; i++) {
    // Definendo la funzione "stampa" come virtual questo codice chiama la funzione corrispondente al tipo dell'oggetto (binding dinamico), altrimenti chiama sempre la funzione stampa di Persona (cioè della classe base - binding statico di default). 
        persona[i]->stampa();
        cout << endl;
    }
    
    delete persona[5]; // disallocazione dell'oggetto allocato dinamicamente

    return 0;
}


