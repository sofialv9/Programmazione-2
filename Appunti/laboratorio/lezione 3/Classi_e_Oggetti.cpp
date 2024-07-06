// Classi e oggetti, ereditarietà, metodi virtual e friend, casting di oggetti, sovraccaricamento di operatori per oggetti

#include <iostream>
using namespace std;
// Code segment -  della memoria in cui vi sono le definizioni delle funzioni e delle classi
// Metodi statici - la loro definizione si trova, nella memoria, insieme all'oggetto della classe a cui appartengono

class Manoscritto // classe base
{
private:
    string titolo;
    string autore;
public:
    // Costruttore - metodo che deve avere lo stesso nome della classe e non ha valori di ritorno - l'inizializzazione si può effettuare all'interno del corpo della funzione o con il vettore di inizializzazione
    Manoscritto(string titolo, string autore) : titolo{titolo}, autore{autore}
    {/*
        this->titolo = titolo; // assume il valore del puntatore all'oggetto
        this->autore = autore;
    */}
    // Distruttore
    ~Manoscritto() {cout << "Oggetto distrutto." << endl;}

    // metodi get: ritornano il valore degli attributi
    string getTitolo() const {return titolo;}
    string getAutore() const {return autore;}

    // metodi set: modificano gli attributi
    void setTitolo(string titolo) {this->titolo = titolo;}
    void setAutore(string autore) {this->autore = autore;}
    virtual string getLabel() const
    {
        return "Titolo: " + getTitolo() + "; Autore: " + getAutore();
    }

    // x == y è equivalente a x.operator==(y)
    bool operator==(const Manoscritto &y) const // firma dell'operatore == sovraccaricato per confrontare oggetti di tipo Manoscritto; y è un riferimento(!), non un indirizzo; il const finale indica che si tratta di un operatore.
    { 
        return this->getAutore() == y.getAutore() && this->getTitolo() == y.getTitolo();
    } 

    // friend può accedere anche agli attributi privati
    friend ostream& operator<<(ostream& stream, const Manoscritto& y)
    {
        stream << y.getLabel();
        return stream;
    }
};

class Romanzo : public Manoscritto // classe derivata
{
// using Manoscritto::Manoscritto; -> Usa il costruttore di Manoscritto - usato nelle classi alias (classi derivate che non fanno nulla di diverso rispetto alla classe base)

private:
    int data;
    string editore;

public:
// Il costruttore di Romanzo chiama il costruttore di Manoscritto per gli attributi che le 2 classi hanno in comune
    Romanzo(string titolo, string autore, int data, string editore): Manoscritto(titolo, autore), data{data}, editore{editore} {}

    int getData() const {return data;}
    string getEditore() const {return editore;}
    void setData(int data) {this->data = data;}
    void setEditore(string editore) {this->editore = editore;}
    // "override" indica la sovrascrittura di un metodo virtuale
    string getLabel() const override
    {
        // La data, che è un intero, deve essere convertita a stringa per essere concatenata con altre stringhe
        return Manoscritto::getLabel() + "; Data: " + to_string(getData()) + "; Editore: " + getEditore() + "\n";
    }

    bool operator==(const Romanzo &y) const
    {
        // all'inizio si passa il riferimento y alla funzione di Manoscritto -- è possibile inviare un riferimento a Romanzo perché il down-cast è sempre possibile
        return Manoscritto::operator==(y) && this->getData() == y.getData() && this->getEditore() == y.getEditore();
    } 

    // non ha senso chiamare la getLabel di Manoscritto poiché Romanzo ha la sua
    friend ostream& operator<<(ostream& stream, const Romanzo& romanzo)
    {
        stream << romanzo.getLabel();
        return stream;
    }
};

int main()
{
    Manoscritto* manoscritto1 = new Manoscritto("Il Signore degli Anelli", "Tolkien");
    Romanzo* romanzo1 = new Romanzo("Programmare in C++", "UNICT", 2024, "Università di Catania");
    Romanzo* romanzo2 = new Romanzo("Programmazione in Python", "UNICT", 2022, "Università di Catania");
    
    cout << (*romanzo1 == *romanzo2) << endl; // si può fare sovraccaricando l'operatore ==
    cout << *romanzo1 << endl; // sovraccarico operatore di stream <<
    


/*
    Manoscritto* cast = dynamic_cast<Manoscritto*>(rom1); // up-cast 
    Romanzo* cast = dynamic_cast<Romanzo*>(manoscritto1); // down-cast
    if(cast != nullptr)
    {
        cout << cast->getLabel() << endl;
    }
    else
        cout << "Non è possibile fare down-cast." << endl;


    Manoscritto manoscritto1("Il Signore degli Anelli", "Tolkien");
    Romanzo romanzo1("Programmare in C++", "UNICT", 2024, "Università di Catania");

    Romanzo cast = static_cast<Manoscritto>(romanzo1); ERRORE-> il down-cast non si può mai fare
    Manoscritto cast = static_cast<Manoscritto>(romanzo1); //l'upper cast si può fare

    
    cout << manoscritto1.getAutore() << " " << manoscritto1.getTitolo() << endl;
    manoscritto1.setAutore("J.R.R. Tolkien");
    cout << manoscritto1.getAutore() << " " << manoscritto1.getTitolo() << endl;
    cout << manoscritto1.getLabel() << endl;

    cout << "Visualizziamo un Romanzo" << endl << endl;

    
    cout << romanzo1.getTitolo() << endl;
    cout << romanzo1.getEditore() << endl;
    cout << romanzo1.getLabel() << endl; // metodo ereditato da Manoscritto

    Manoscritto* catalogo[] = {&manoscritto1, &romanzo1};
    // Poiché il romanzo è stato dichiarato come Manoscritto se si chiama su di esso il metodo getLabel() sarà eseguito il metodo della classe Manoscritto (senza virtual)
    for(int i = 0; i < 2; i++)
        cout << "Catalogo: " << catalogo[i]->getLabel() << endl;

*/

    return 0;
}

// virtual table (o vtable) - si fa un'associazione tra la classe e i metodi che sono virtual
/* Se non si ha un puntatore all'oggetto della classe virtuale non si può accedere ai metodi virtuali (il puntatore all'oggetto nasconde il puntatore alla virtual table) - senza puntatore il binding rimane statico.
es. se sopra ci fosse scritto Manoscritto catalogo[] = {manoscritto1, romanzo1} e catalogo[i].getLabel() per la stampa del romanzo verrebbe eseguito il metodo di Manoscritto */