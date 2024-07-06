/*
Si consideri la classe virtuale Animale con i seguenti attributi privati:
• nome (stringa)
• peso (float)

La classe Animale deve avere i seguenti metodi pubblici:
• Costruttore che inizializza nome e peso come attributi privati.
• Metodi get.
• Metodo virtuale puro verso(): restituisce una stringa rappresentante il verso dell'animale.
• Overload dell'operatore << per stampare le informazioni dell'animale.

Creare due classi derivate da Animale:
• Gatto: Implementa il metodo verso() per restituire "Miao!".
• Cane: Implementa il metodo verso() per restituire "Bau!".

Si consideri una classe template OrderedLinkedList che rappresenta una lista concatenata ordinata di elementi di tipo T. La classe ha solo la testa come attributo privato e i seguenti metodi pubblici:
• costruttore, distruttore
• inserisci: inserisce un elemento nella lista
• adotta: prende in input un puntatore a nodo e lo rimuove
• stampa: stampa tutti gli elementi tramite operatore <<

Si scriva un programma che prenda almeno 10 stringhe da console. Per ogni stringa, crei dei cani o dei gatti ciascuno con una probabilità del 50% e assegni la stringa al nome. Inoltre, il peso viene generato casualmente tenendo conto del fatto che I gatti possono avere un peso casuale tra i 3 e i 5 kg, mentre i cani tra i 2 e i 20kg.

Inserire gli animali nella lista. Per ordinare gli animali sarà necessario implementare l’overload dell’operatore < che ordini per peso, dando precedenza ai gatti in caso di parità.

Si creino inoltre i seguenti metodi che prendono come input un puntatore a OrderedLinkedList di tipo puntatore ad Animale:
• gatti: stampa tutti i nomi dei gatti
• cani: stampa tutti i nomi dei cani
Fornire degli esempi per tutte le funzionalità implementate.
*/

#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>

using namespace std;

template <typename T>
class Node {
    private:
        T data;
        Node<T>* next;

    public:
        Node(T data, Node<T>* next = nullptr) : data(data), next(next) {}

        T getData() { return data; }
        Node<T>* getNext() { return next; }

        void setNext(Node<T>* next) { this->next = next; }
};

template <typename T>
class OrderedLinkedList {
    private:
        Node<T>* head;

    public:
        OrderedLinkedList() : head(nullptr) {}
        ~OrderedLinkedList() {
            Node<T>* current = head;
            while(current != nullptr) {
                Node<T>* next = current->getNext();
                delete current;
                current = next;
            }
        }

        void insert(T data) {
            Node<T>* newNode = new Node<T>(data);
            // La lista è vuota
            if(head == nullptr) {
                head = newNode;
                return;
            }

            // current contiene il nodo corrente, prev il nodo precedente
            Node<T>* current = head;
            Node<T>* prev = nullptr;
            // Scorro la lista finché non trovo un nodo con un valore maggiore di quello da inserire
            while(current != nullptr && !(*newNode->getData() < *current->getData())) {
                prev = current;
                current = current->getNext();
            }

            // Se prev è nullptr, il nodo da inserire è la nuova testa
            if(prev == nullptr) {
                newNode->setNext(head);
                head = newNode;
            } else { // Altrimenti inserisco il nodo tra prev e current (che è maggiore di newNode)
                prev->setNext(newNode);
                newNode->setNext(current);
            }
        }

        // adopt = remove
        void adopt(Node<T>* node) {
            if(head == nullptr) return;

            Node<T>* current = head;
            Node<T>* prev = nullptr;
            while(current != nullptr && current != node) {
                prev = current;
                current = current->getNext();
            }

            if(current == nullptr) return;

            if(prev == nullptr) {
                head = current->getNext();
            } else {
                prev->setNext(current->getNext());
            }

            delete current;
        }

        void print() {
            Node<T>* current = head;
            while(current != nullptr) {
                cout << *current->getData() << std::endl;
                current = current->getNext();
            }
        }
};

class Animale {
private:
    string nome;
    float peso;

public:
    Animale(string nome = "", float peso = 0) : nome(nome), peso(peso) {}

    // Getters
    string getNome() const { return nome; } 
    float getPeso() const { return peso; }  
    virtual string verso() const = 0;

    // Overload dell'operatore <<
    friend ostream& operator<<(ostream& os, const Animale& a) {
        os << "Nome: " << a.nome << ", Peso: " << a.peso << " kg, Verso: " << a.verso(); 
        return os;
    }
};

class Gatto : public Animale {
    public:
        Gatto(string nome = "", float peso = 0) : Animale(nome, peso) {}
        string verso() const override { return "Miao!"; }
};

class Cane : public Animale {
    public:
        Cane(string nome = "", float peso = 0) : Animale(nome, peso) {}
        string verso() const override { return "Bau!"; }
};

bool operator<(const Animale& a1, const Animale& a2) {
    if (a1.getPeso() == a2.getPeso()) {
        const Gatto* gatto1 = dynamic_cast<const Gatto*>(&a1);
        const Gatto* gatto2 = dynamic_cast<const Gatto*>(&a2);

        if (gatto1) {
            return true;  // Se il primo è un gatto, gli diamo precedenza, se no diamo sempre precedenza al secondo, non ci interessa
        }
        return false;
    }
    // Gli animali hanno peso diverso
    return a1.getPeso() < a2.getPeso();
}

int main() {
    srand(time(nullptr));
    OrderedLinkedList<Animale*> lista;

    for(int i = 0; i < 100; i++) {
        string nome;
        for(int j = 0; j < 5; j++) {
            nome += 'a' + rand() % 26;
        }

        float peso = 0;
        Animale *a;
        if(rand() % 2 == 0) {
            peso = 3 + rand() % 3;
            a = new Gatto(nome, peso);
            lista.insert(a);
        } else {
            peso = 2 + rand() % 18;
            a = new Cane(nome, peso);
            lista.insert(a);
        }
    }
    lista.print();
}