// Array: struttura dati sequenziale - l'accesso agli elementi avviene attraverso indici e impiega tempo costante ma non si possono inserire elementi - per questo motivo si introducono le liste.
// Linked list (simple): elementi allocati non sequenzialmente - il riferimento al 1° elemento è la testa, quello all'ultimo elemento è la coda - ogni elemento punta al successivo - ha 2 varianti:  Simple, in cui si memorizza solo il 1° elemento; Double Linked in cui si memorizza sia il 1° che l'ultimo. La lista circolare può essere sia semplice che doppiamente linkata.
// Operazioni - 3 tipi: inserimento (insertHead - inserimento in testa, insertTail, insertBefore, insertAfter, insertOrder); cancellazione (deleteHead, deleteTail, deleteKey); ricerca (searchKey - prima si chiama una funzione di ordinamento).
// Node - attributi: Key e Next

#include <iostream>
using namespace std;

template<class T> class Node
{
  private:
    T key; // dato
    Node<T>* next; // puntatore all'elemento successivo

  public:
// costruttori e distruttore
    Node<T>() : next{ nullptr } {} // non si può scrivere key{ NULL } poichè vi sono tipi di dati che non sono nullable (ad es. se T = int darebbe errore)
    Node<T>(T key) : key{ key }, next{ nullptr } {}
    ~Node<T>() {}

// metodi get
    T getKey() const { return key; }
    Node<T>* getNext() const { return next; }
// metodi set
    void setKey(T key) { this->key = key; }
    void setNext(Node<T>* next) { this->next = next; }

// sovraccaricamento operatori
    friend ostream& operator<<(ostream& os, const Node<T>& node)
    {
        os << node.getKey();
        return os;
    }
};

template<class T> class LinkedList
{
  private:
    Node<T>* head;
    Node<T>* tail;
    size_t size; // numero elementi

  protected:
    void setHead(Node<T>* node)
    {
        if(isEmpty()) // se la lista è vuota il nodo diventa sia testa che coda
        {
            head = node;
            tail = node;
        }
        else
        {
            node->setNext(head);
            head = node;
        }
    }

    void setTail(Node<T>* node)
    {
        if(isEmpty())
        {
            head = node;
            tail = node;
        }
        else
        {
            getTail()->setNext(node);
            tail = node;
        }
    }

  public:
    LinkedList<T>() : head{ nullptr }, tail{ nullptr }, size{ 0 } {}
    LinkedList<T>(Node<T>* node) : head{ node }, tail{ node }, size{ 1 } {} // inizializzazione con un nodo che diventa il primo della lista
    LinkedList<T>(T key) : head{ new Node<T>(key) }, tail{ head }, size{ 1 } {} // inizializzazione con un dato
// metodi get
    Node<T>* getHead() const { return head; }
    Node<T>* getTail() const { return tail; }
    size_t getSize() const { return size; }

    bool isEmpty() const
    {
        return head == nullptr; // oppure return size == 0;
    }

//metodi di inserimento
    LinkedList<T>* insertHead(Node<T>* node)
    {
        setHead(node);
        return this;
    }

    LinkedList<T>* insertHead(T key)
    {
        return insertHead(new Node<T>(key));
    }

    LinkedList<T>* insertTail(Node<T>* node)
    {
        setTail(node);
        return this;
    }

    LinkedList<T>* insertTail(T key)
    {
        return insertTail(new Node<T>(key));
    }

// metodi di cancellazione
    Node<T>* deleteHead() // oppure LinkedList<T>* deleteHead(Node<T>** oldHead)
    {
        if(isEmpty())
            return nullptr;

        Node<T>* temp = head; // conservo la vecchia testa
        head = head->getNext(); // aggiorno il puntatore alla testa
        if(head == nullptr) // se la lista aveva un solo elemento (e ora è vuota)
            tail = nullptr;
        temp->setNext(nullptr); // cancella il puntatore all'elemento successivo della vecchia testa
        return temp; // ritorna la vecchia testa
    }

    Node<T>* deleteTail()
    {
        if(isEmpty())
            return nullptr;
        Node<T>* it = head;
        if(it->getNext() == nullptr) // se la lista aveva un solo elemento
        {
            head = tail = nullptr;
            return it;
        }
        while(it->getNext() != getTail()) // finisce quando it punta all'elemento prima della coda (che sarà la nuova coda)
        {
            it = it->getNext();
        }

        tail = it; // aggiorna la coda a quella nuova
        it = it->getNext(); // it = vecchia coda
        tail->setNext(nullptr);
        return it; // ritorna la vecchia coda

    }

    Node<T>* searchKey(T key) // possibili output: bool (dice solo se l'elemento è presente all'interno della lista) || Node<T>* (ritorna un puntatore all'elemento)
    {
        Node<T>* it = head;
        while(it != nullptr)
        {
            if(key == it->getKey())
                break;
            it = it->getNext();
        }
        return it; // se l'elemento non viene trovato ritorna nullptr
    }

    friend ostream& operator<<(ostream& os, LinkedList<T>& list)
    {
        Node<T>* it = list.getHead();
        while(it != nullptr)
        {
            os << *it << " ";
            it = it->getNext();
        }
        return os;
    }
};

// Pila come classe derivata da LinkedList - classe alias (eredita tutti i dati e le funzioni membro)
template<class T> class Stack : public LinkedList<T>
{
    using LinkedList<T>::LinkedList; // usa il costruttore di LinkedList

public:
    Node<T>* pop()
    {
        return LinkedList<T>::deleteHead(); // la risoluzione di visibilità è necessaria per il match
    }

    /*
        ESERCIZIO: COME FARE?
        La push così definita non compila: insertHead restituisce un puntatore a LinkedList (classe base). Noi vogliamo un riferimento alla classe derivata.
    */

    Stack* push(Node<T>* node)
    {
        return insertHead(node);
    }
    Stack* push(T key)
    {
        return static_cast<Stack<int>*>(this->insertHead(key));
    }
};




int main() {
    Node <int>* node = new Node<int>(7);
    cout << *node << endl;  // equivalente a: node->getKey()
    LinkedList<int>* list = new LinkedList<int>(node);

    list->insertHead(8)->insertTail(10)->insertTail(0)->insertHead(1);
    cout << "Head: " << *list->getHead() << endl;
    cout << "Tail: " << *list->getTail() << endl;
    cout << "Lista 1: " << *list << endl;

    Node<int>* searchKey = list->searchKey(909);
    cout << ((searchKey == nullptr) ? "Chiave non presente" : to_string(searchKey->getKey())) << endl;
    
    cout << *list->deleteTail() << endl; // potenzialmente unsafe
    cout << *list->deleteTail() << endl;
    cout << *list->deleteTail() << endl;
    cout << *list->deleteTail() << endl;
    cout << *list->deleteTail() << endl;
    Node<int>* temp = list->deleteTail();
    cout << ((temp == nullptr) ? "Lista vuota" : "* temp") << endl; // il controllo rende l'istruzione safe (non si rischia di dereferenziare nullptr e avere errore)
    /* if(temp == nullptr)
        cout << "Lista Vuota" << endl;
    else
        cout << *temp << endl;
    */

    LinkedList<int>* listKey = new LinkedList<int>(10);
    cout << "Lista 2: " << *listKey << endl;
    Node<int>* searchList = list->searchKey(9);
    cout << *searchList << endl;

    Stack<int>* stack = new Stack<int>();
    stack->push(11);
    stack->pop();

    return 0;
}