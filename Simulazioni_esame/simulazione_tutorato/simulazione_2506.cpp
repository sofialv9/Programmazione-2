#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;

class Animale
{
public:
    Animale(string _nome, float _peso) : nome(_nome), peso(_peso) {}
    string getNome() {return nome;}
    float getPeso() {return peso;}
    virtual string verso() = 0;

private:
    string nome;
    float peso;

    friend ostream& operator<<(ostream& os, Animale* a)
    {
        os << "Nome: " << a->getNome() << "; Peso: " << a->getPeso() << " kg; Verso: " << a->verso() << endl;
        return os;
    }
};

class Gatto : public Animale
{
public:
    Gatto(string _nome, float _peso) : Animale(_nome, _peso) {}
    virtual string verso() {return "Miao!";}
};

class Cane : public Animale
{
public:
    Cane(string _nome, float _peso) : Animale(_nome, _peso) {}
    virtual string verso() {return "Bau!";}
};

// Essendo esterno (cioè non un membro di una classe) l'operatore può essere binario ma non può avere puntatori come argomento
bool operator<(Animale& a1, Animale& a2)
{
    if(a1.getPeso() == a2.getPeso())
    {
        Gatto* gatto1 = dynamic_cast<Gatto*>(&a1);
        Gatto* gatto2 = dynamic_cast<Gatto*>(&a2);

        // Se il primo è un gatto gli diamo precedenza, se no diamo sempre precedenza al secondo
        if(gatto1)
            return true;
        return false;
    }
    return a1.getPeso() < a2.getPeso();
}

template <class T>
class OrderedLinkedList;

template <class T>
class Node
{
public:
    Node(T _data) : data(_data), next(nullptr) {}
    T getData() {return data;}
    Node<T>* getNext() {return next;}
    void setNext(Node<T>* _next) {next = _next;}

private:
    T data;
    Node<T>* next;
};

template <class T>
class OrderedLinkedList
{
public:
    OrderedLinkedList() : head(nullptr) {}
    ~OrderedLinkedList()
    {
        Node<T>* tmp = head;
        while(tmp != nullptr)
        {
            Node<T>* next = tmp->getNext();
            delete tmp;
            tmp = next;
        }
    }

    Node<T>* getHead() {return head;}

    void inserisci(T data)
    {
        Node<T>* newNode = new Node<T>(data);
        Node<T>* curr = head;
        Node<T>* prev = nullptr;
        // ci sono gli asterischi prima dei nodi in quanto l'operatore è stato sovraccaricato per Animale& e non per Animale*
        while(curr && (*curr->getData() < *newNode->getData()))
        {
            prev = curr;
            curr = curr->getNext();
        }
        if(prev == nullptr) // o la lista è vuota (curr == head == nullptr) oppure non si è entrati nel ciclo (*curr->getData() > *newNode->getData())
        {
            newNode->setNext(head);
            head = newNode;
        } else {
            prev->setNext(newNode);
            newNode->setNext(curr);
        }
    }

    void adotta(Node<T>* node)
    {
        if(!head) // lista vuota
            return;
        Node<T>* curr = head;
        Node<T>* prev = nullptr;
        while(curr && curr != node)
        {
            prev = curr;
            curr = curr->getNext();
        }
        if(!curr) // non è stato trovato il nodo nella lista
            return;
        if(!prev) // si deve eliminare la testa (non si è entrati nel ciclo)
            head = curr->getNext();
        else
            prev->setNext(curr->getNext());
        delete curr;
    }

    void stampa()
    {
        Node<T>* tmp = head;
        while(tmp != nullptr)
        {
            cout << tmp->getData();
            tmp = tmp->getNext();
        }
        cout << endl;
    }

private:
    Node<T>* head;
};

void gatti(OrderedLinkedList<Animale*>* l)
{
    cout << "Stampo i gatti della lista:" << endl;
    Node<Animale*>* curr = l->getHead();
    Node<Animale*>* prev = nullptr;
    while(curr)
    {
        prev = curr;
        Gatto* g = dynamic_cast<Gatto*>(curr->getData());
        if(g)
            cout << g;
        curr = curr->getNext();     
    }
}

void cani(OrderedLinkedList<Animale*>* l)
{
    cout << "Stampo i cani della lista:" << endl;
    Node<Animale*>* curr = l->getHead();
    Node<Animale*>* prev = nullptr;
    while(curr)
    {
        prev = curr;
        Cane* c = dynamic_cast<Cane*>(curr->getData());
        if(c)
            cout << c;
        curr = curr->getNext();     
    }
}

int main()
{
    srand(time(NULL));

    ifstream stream("input.txt");
    OrderedLinkedList<Animale*> list;
    while(!stream.eof() && stream.good())
    {
        string nome;
        stream >> nome;
        bool n = rand() % 2;
        Animale* animale;
        if(n == 0)
        {
            animale = new Gatto(nome, (float) (3 + rand() % 2));
        } else {
            animale = new Cane(nome, (float) (2 + rand() % 18));
        }
        list.inserisci(animale);
    }
    list.stampa();

    // elimina il secondo nodo della lista
    Node<Animale*>* node = list.getHead()->getNext();
    cout << "Elimino l'animale -> " << node->getData() << endl;
    list.adotta(node);
    list.stampa();

    gatti(&list);
    cout << endl;
    cani(&list);

    cout << endl << "Verifico il funzionamento dell'operatore sovraccaricato:" << endl;
    Cane* cane = new Cane("Poldo", 3.0);
    list.inserisci(cane);
    list.stampa();
}