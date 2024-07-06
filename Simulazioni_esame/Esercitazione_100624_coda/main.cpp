// Coda di Pazienti
#include <iostream>
using namespace std;

class Patient
{
public:
    Patient(int _id, string _name, string _condition) : id(_id), name(_name), condition(_condition) {}

    int getId() {return id;}
    string getName() {return name;}
    string getCondition() {return condition;}

    void setId(int _id) {id = _id;}
    void setName(string _name) {name = _name;}
    void setCondition(string _condition) {condition = _condition;}

    void print()
    {
        cout << "ID: " << id << ", Name: " << name << ", Condition: " << condition << "." << endl;
    }

private:
    int id;
    string name;
    string condition;
};

template<class T>
class Node // ERRORE: non scrivere <T> dopo il nome della classe
{
public:
    Node<T>(T _data) : data(_data) {}

    T getData() {return data;}
    Node<T>* getNext() {return next;}
    Node<T>* getPrev() {return prev;}
    void setData(T _data) {data = _data;}
    void setNext(Node<T>* _next) {next = _next;}
    void setPrev(Node<T>* _prev) {prev = _prev;}

private:
    T data;
    Node<T>* next;
    Node<T>* prev;
};

// coda doppiamente linkata (con prev e next)
template<class T>
class Queue
{
public:
    Queue<T>() : head(nullptr), tail(nullptr), dim(0) {}

    Queue<T>& enqueue(T newData)
    {
        Node<T>* newNode = new Node(newData);
        newNode->setNext(nullptr);
        if(tail != nullptr)
            tail->setNext(newNode);
            newNode->setPrev(tail);
        tail = newNode;
        if(head == nullptr)
            head = tail;
        dim++;
        return *this;
    }

    T dequeue()
    {
        if(head == nullptr)
            return T();
        Node<T>* tmp = head;
        head = head->getNext();
        head->setPrev(nullptr);
        if(head == nullptr)
            tail = nullptr;
        T outData = tmp->getData();
        dim--;
        delete tmp;
        return outData;
    }

    Queue<T>& enqueuePriority(T patient, int priority)
    {
        // se la coda è vuota o la priorità inserita è 0
        if(head == nullptr || priority == 0)
        {
            enqueue(patient);
            return *this;
        }
        Node<T>* newNode = new Node(patient);
        Node<T>* prev = nullptr;
        Node<T>* it = tail; // parte dalla tail...
        for(int i = 0; i < priority; i++) //... e scorre la coda da sinistra a destra
        {
            prev = it;
            it = it->getPrev();
        }
        if(it == nullptr) // se si è raggiunta la fine della coda inserisce il nodo in testa
        {
            newNode->setNext(head);
            head->setPrev(newNode);
            newNode->setPrev(nullptr);
            head = newNode;
            return *this;
        }
        // altrimenti inserisce il nodo tra prev e it (it -> newNode -> prev)
        prev->setPrev(newNode);
        newNode->setNext(prev);
        newNode->setPrev(it);
        it->setNext(newNode);
        return *this;
    }

    void printQueue()
    {
        Node<T>* tmp = head;
        while(tmp != nullptr)
        {
            (tmp->getData())->print();
            tmp = tmp->getNext();
        }
        cout << endl;
        return;
    }

private:
    Node<T>* head;
    Node<T>* tail;
    int dim;
};

int main()
{
    Patient* p1 = new Patient(1, "Mario", "Influenza");
    Patient* p2 = new Patient(2, "Anna", "Cefalea");
    Patient* p3 = new Patient(3, "Claudia", "Ematoma");
    Patient* p4 = new Patient(4, "Marco", "Stiramento");

    Queue<Patient*> q;

    // Controllo:
    //   q.enqueue(p1).enqueue(p2).enqueue(p3).enqueue(p4);
    //   q.printQueue();
    
    q.enqueue(p1).enqueue(p2).enqueuePriority(p3, 1).enqueuePriority(p4, 2);
    q.printQueue();

    return 0;
}
