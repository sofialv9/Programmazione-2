// Header file - contiene le definizioni delle classi e i prototipi dei metodi


#ifndef persona_hpp
#define persona_hpp

class Persona {
public:
    // Costruttore con vettore di inizializzazione
    Persona(const char* vnome,const char* vcognome,int veta) : maggiore_eta(18), eta(veta)
    {
        setNome(vnome);
        setCognome(vcognome);
    }
    
    ~Persona() { // distruttore
        delete [] nome;
        delete [] cognome;
    }
    
    // Le funzioni pubbliche sono accessibili dall'esterno e possono quindi essere usate nel main
    const char* getNome();
    const char* getCognome();

    // La parola "virtual" abilita il binding dinamico - se viene chiamata per un oggetto di una classe derivata chiama la funzione stampa() della classe derivata
    virtual void stampa();
    
    void setEta(int valeta);
    int getEta();
    bool maggiorenne();
private: // dati membro non accessibili dall'esterno
    char* nome;
    char* cognome;
    int eta;
    const int maggiore_eta;
protected: // accessibili dalle classi derivate
    void setNome(const char* nome);
    void setCognome(const char* cognome);
};

// Ereditarietà virtuale: se ci sono più classi base da cui si deriva uno stesso stato quest'ultimo viene derivato una sola volta
class Studente : virtual public Persona
{
public:
    Studente(const char* nome, const char* cognome, int eta, float vmedia)
        : Persona(nome, cognome, eta), media(vmedia)
    {} // Costruttore (chiama il costruttore di Persona)
    
    float getMedia() {return media;}

    virtual void stampa();
    
private:
    float media;
};

class Professore : virtual public Persona
{
public:
    Professore(const char* nome, const char* cognome, int eta)
        : Persona(nome,cognome,eta)
    {}
    
    virtual void stampa();
};

class Assistente : public Professore, public Studente
{
public:
    Assistente(const char* nome, const char* cognome, int eta, float vmedia)
    : Persona(nome,cognome,eta), Professore(nome,cognome,eta), Studente(nome,cognome,eta,vmedia) {}
    
    virtual void stampa();
};

#endif /* persona_hpp */
