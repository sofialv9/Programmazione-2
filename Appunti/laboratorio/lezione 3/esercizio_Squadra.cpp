/* Creare una classe Squadra caratterizzata da un nome e un anno di fondazione (scrivere costruttore, distruttore, set e get).
Una Squadra può essere o una SquadraClub, caratterizzata  da sede legale e nazionalità, o una SquadraNazionale, caratterizzata dalla nazione.
Creare una classe Torneo che contiene una lista ((== array C-style) di Squadre e che fornisca la possibilità di aggiungere una squadra.
Un TorneoClub può essere per squadre di tipo SquadraClub mentre un TorneoNazionale per quelle di tipo SquadraNazionale.
Un TorneoClub consente di stabilire quanti club nel torneo sono di una specifica nazionalità.
Un TorneoNazionale non consente di inserire due club provenienti dalla stessa nazione. */

#include <iostream>
using namespace std;

class Squadra{
public:
    Squadra(string nome, int anno) : nome{nome}, anno{anno} {};
    virtual ~Squadra() {} // rendo polimorfico il distruttore per creare una virtual table e rendere quindi polimorfica la classe Squadra (ciò serve nel cast della funzione addSquadra)

    /* // metodi get
    string getNome() const {return nome;}
    const int getAnno() const {return anno;}

    // metodi set
    void setNome(string nome) {this->nome = nome;}
    void setAnno(int anno) {this->anno = anno;} */
private:
    string nome;
    int anno;
};

class SquadraClub : public Squadra {
public:
    SquadraClub(string nome, int anno, string sede, string nazionalità) : Squadra(nome, anno), sede{sede}, nazionalità{nazionalità} {}
    string getNazionalità() const {return nazionalità;}

    /* ~SquadraClub() {cout << "Oggetto della classe SquadraClub distrutto." << endl;}

    string getSede() {return sede;}
    
    void setSede(string sede) {this->sede;}
    void setNazionalità(string nazionalità) {this->nazionalità;} */

private:
    string sede;
    string nazionalità;
};

class SquadraNazionale : public Squadra{
public:
    SquadraNazionale(string nome, int anno, string nazione) : Squadra(nome, anno), nazione{nazione} {}
    string getNazionalità() {return nazione;}

    /* ~SquadraNazionale() {cout << "Oggetto della classe SquadraNazionale distrutto." << endl;}

    void setNazione(string nazione) {this->nazione;} */

private:
    string nazione;
};

class Torneo {
public:
    Torneo(size_t capacità) : capacità{capacità}, size{0} // il numero iniziale di squadre presenti è 0
    {
        lista = new Squadra*[capacità]; // array di lunghezza pari a capacità di puntatori a Squadra  (si usano i puntatori a Squadra poichè le Squadre vengono definite prima di creare il torneo)
    };
    ~Torneo() {delete[] lista;} // rimuove la lista ma non le squadre

    virtual bool addSquadra(Squadra* squadra)
    {
        if(size < capacità) // se c'è ancora spazio nella lista
        {
            lista[size] = squadra; // aggiunge la squadra nella prima posizione libera
            size++;
            return true;
        }
        return false;
    }

    size_t getSize() const { return size; }
    size_t getCapacità() const { return capacità; }

protected:
    Squadra** getLista() const {return lista;} // serve per aver accesso alla lista nelle classi derivate

private:
    Squadra** lista;
    size_t size; // numero di squadre presenti
    size_t capacità; // numero massimo di squadre inseribili
};

class TorneoClub : public Torneo
{
    using Torneo::Torneo; // si definisce una classe alias usando il costruttore di Torneo poichè le classi Torneo e TorneoClub hanno gli stessi attributi
    
public:
    bool addSquadra(Squadra* squadra) override
    {
        SquadraClub* club = dynamic_cast<SquadraClub*>(squadra);
        if(club != nullptr)
        {
            return Torneo::addSquadra(squadra);
        }
        return false;
    }

    size_t contaClub(const string &nazionalità) const
    {
        size_t contatore = 0;
        Squadra** sq = getLista(); // il metodo getLista è ereditato dalla classe base
        for(size_t i = 0; i < this->getCapacità(); i++)
        {
            SquadraClub* club = dynamic_cast<SquadraClub*>(sq[i]);
            if(club != nullptr && club->getNazionalità() == nazionalità) // si controlla comunque che il cast sia andato a buon fine (il puntatore non è null)
                contatore++;
        }
        return contatore;
    }
};

class TorneoNazionale : public Torneo
{
    using Torneo::Torneo; // si definisce una classe alias usando il costruttore di Torneo poichè le classi Torneo e TorneoClub hanno gli stessi attributi
    
public:
    bool addSquadra(Squadra* squadra) override
    {
        SquadraNazionale* nazionale = dynamic_cast<SquadraNazionale*>(squadra);
        if(nazionale != nullptr)
        {
            Squadra** lista = getLista(); // prendiamo la lista
            for(size_t i = 0; i < this->getCapacità(); i++) // scorriamo la lista per controllare che la nazionalità della squadra da inserire sia diversa da quella di ogni squadra già presente
            {
                SquadraNazionale* nz = dynamic_cast<SquadraNazionale*>(lista[i]);
                if(nz != nullptr && nz->getNazionalità() == nazionale->getNazionalità())
                    return false;
            }
            return Torneo::addSquadra(squadra);
        }
        return false;
    }
};

int main(){
    SquadraClub* juve = new SquadraClub("Juventus", 1897, "Torino", "italiana");
    SquadraClub* catania = new SquadraClub("Catania", 1946, "Catania", "italiana");
    SquadraNazionale* italia = new SquadraNazionale("Italia", 1899, "Italia");
    SquadraNazionale* italia2 = new SquadraNazionale("Italia", 1899, "Italia");
    TorneoClub* serieA = new TorneoClub(10); // torneo di 10 squadre
    TorneoNazionale* europeo = new TorneoNazionale(5);

    cout << "Add squadra: " << serieA->addSquadra(juve) << endl;
    cout << "Add squadra: " << serieA->addSquadra(catania) << endl;
    cout << "Add squadra: " << serieA->addSquadra(italia) << endl; // deve ritornare 0 poichè non si deve poter aggiungere una squadra nazionale ad un torneo club
    cout << "Add nazione: " << europeo->addSquadra(italia) << endl;
     cout << "Add nazione: " << europeo->addSquadra(italia2) << endl; //0 (c'é già una squadra di nazionalità italiana)
    cout << "Add nazione: " << europeo->addSquadra(juve) << endl; // 0
    cout << "Nazionalità italiana: " << serieA->contaClub("italiana") << endl; // squadre club di nazionalità italiana

    return 0;
}