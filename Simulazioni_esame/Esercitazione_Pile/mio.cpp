#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Studente
{
public:
    Studente(int _matricola, const string& _nome, const string& _cognome, float _media) : matricola(_matricola), nome(_nome), cognome(_cognome), media(_media) {}

    int getMatricola() const {return matricola;}
    const string& getNome() const {return nome;}
    const string& getCognome() const {return cognome;}
    float getMedia() const {return media;}
    virtual void stampa()
    {
        cout << matricola << ": " << nome << " " << cognome << " - media " << media;
    }

private:
    int matricola;
    string nome;
    string cognome;
    float media;
};

class BorsaDiStudio
{
public:
    BorsaDiStudio(int _importo, int _durata) : importo(_importo), durata(_durata) {}

    int getImporto() const {return importo;}
    int getDurata() const {return durata;}
    void setImporto(int _importo) {importo = _importo;}
    void setDurata(int _durata) {durata = _durata;}

private:
    int importo;
    int durata;
};

class StudenteBorsista : public Studente
{
public:
    StudenteBorsista(int _matricola, string _nome, string _cognome, float _media, int _importo, int _durata) : Studente(_matricola, _nome, _cognome, _media)
    {
        borsa = new BorsaDiStudio(_importo, _durata);
    }
    ~StudenteBorsista() {if (borsa) delete borsa;}

    int getImportoBorsa() const
    {
        if(borsa != nullptr)
            return borsa->getImporto();
        else return 0;
    }

    virtual void stampa()
    {
        Studente::stampa();
        if (borsa != nullptr)
            cout << " [borsa di " << borsa->getImporto() << " euro]";
    }

private:
    BorsaDiStudio* borsa;
};

class Pila;

class Node
{
public:
    Node(Studente* _data) : data(_data), next(nullptr) {}
    Studente* getData() const {return data;}
    Node* getNext() const {return next;}

private:
    Studente* data;
    Node* next;

    friend class Pila;
};

class Pila
{
public:
    Pila() : head(nullptr) {}
    ~Pila() {while(!isEmpty()) pop();}

    bool isEmpty() {return head == nullptr;}
    Node* getHead() {return head;}

    Pila& push(Studente* stud)
    {
        Node* newNode = new Node(stud);
        newNode->next = head;
        head = newNode;
        return *this;
    }

    Studente* pop()
    {
        if(isEmpty())
            return nullptr;
        Node* tmp = head;
        head = head->getNext();
        Studente* out = tmp->getData();
        delete tmp;
        return out;
    }

    void rimuovi(Node* node)
    {
        if(node == head)
        {
            pop();
        }
        Node* prec = head;
        while(prec->next && prec->next != node)
            prec = prec->next;
        if(prec->next != node) // prec->next == null
            return;
        prec->next = node->next; // prec->next = node
        delete node;
    }

    void stampa()
    {
        Node* tmp = head;
        while(tmp != nullptr)
        {
            tmp->getData()->stampa();
            cout << endl;
            tmp = tmp->getNext();
        }
    }

private:
    Node* head;
};

void readInput(Pila& pila, string fname)
{
    fstream stream(fname);
    while(!stream.eof() && stream.good())
    {
        int matricola;
        string nome;
        string cognome;
        float media;
        int importo;
        int durata;

        stream >> matricola >> nome >> cognome >> media >> importo >> durata;

        if(importo == 0)
        {
            Studente* stud = new Studente(matricola, nome, cognome, media);
            pila.push(stud);
        } else {
            StudenteBorsista* stud = new StudenteBorsista(matricola, nome, cognome, media, importo, durata);
            pila.push(stud);
        }
    }
}

int main()
{
    Pila pila;
    readInput(pila, "input.txt"); // legge gli studenti dal file e li inserisce nella pila
    
/* 
In questo modo gli elementi della seconda pila sono in ordine inverso rispetto a quelli della seconda pila
    Pila pila2;
    while(!pila.isEmpty())
    {
        Studente* out = pila.pop();
        if(out->getMedia() < 25)
            cout << "Studente insufficiente rimosso: " << out->getNome() << " " << out->getCognome() << " - Matricola: " << out->getMatricola() << endl;
        else
            pila2.push(out);
    }
*/

// Elimina dalla pila gli studenti con media inferiore a 25 e stampa un messaggio di avviso
    Node* tmp = pila.getHead();
    while(tmp != nullptr)
    {
        Studente* out = tmp->getData();
        Node* next = tmp->getNext();
        if(out->getMedia() < 25)
        {
            pila.rimuovi(tmp);
            cout << "Studente insufficiente rimosso: " << out->getNome() << " " << out->getCognome() << " - Matricola: " << out->getMatricola() << endl;
        }
        tmp = next;
    }
    if(tmp == nullptr)
        cout << "Pila vuota" << endl;
    else pila.stampa();

// Calcola il totale degli importi delle borse di studio assegnate agli studenti borsisti presenti nella pila
    int totImporti = 0;
    while(!pila.isEmpty())
    {
        Studente* stud = pila.pop();
        StudenteBorsista* studB = dynamic_cast<StudenteBorsista*>(stud);
        if(studB) // se il dynamic cast è andato a buon fine
            totImporti += studB->getImportoBorsa();
    }

    cout << endl << "Totale importi borse di studio: " << totImporti << " euro." << endl;


    return 0;
}