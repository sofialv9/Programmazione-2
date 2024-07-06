// LISTA
// Ricordati: i casi in cui si aggiunge la testa e la coda è vuota, o viceversa.

class List;

class ListElem
{
public:
    const ListElem* GetNext() const {return next;};
    int GetNode() const {return node;}

private:
    ListElem(int _node) : node(_node) {}
    int node;
    ListElem* next;

    friend class List;
};


class List
{
public:
    List() : head(nullptr), tail(nullptr) {}
    ~List();
    List& InsertHead(int node);
    List& InsertTail(int node);
    int RemoveHead();
    const ListElem* GetHead() const {return head;}
    bool IsEmpty() const {return (head == nullptr);}

private:
    ListElem* head;
    ListElem* tail;
};

// ricerca di un elemento
Node<T>* searchKey(T key) // oppure ritorna bool
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

List::~List()
{
    ListElem* p = head;
    while(p != nullptr)
    {
        ListElem* next = p->next;
        delete p;
        p = next;
    }
}

List& List::InsertHead(int node)
{
    ListElem* p = new ListElem(node);
    p->next = head;
    head = p;
    if(tail == nullptr) // coda vuota
        tail = p;
    return *this;
}

List& List::InsertTail(int node)
{
    ListElem* p = new ListElem(node);
    p->next = nullptr;
    if(tail != nullptr) // coda non vuota
        tail->next = p;
    tail = p;
    if(head == nullptr) // testa vuota
        head = p;
    return *this;
}


int List::RemoveHead()
{
    if(head == nullptr) // lista vuota
        return -1;
    ListElem* p = head;
    head = head->next;
    if(head == nullptr) // la nuova testa è vuota...
        tail = nullptr; // ...la lista diventa vuota
    int node = p->node;
    delete p;
    return node;
}


ostream& operator<<(ostream& os, const List& list)
{
    const ListElem* p = list.GetHead();
    while(p != nullptr)
    {
        os << p->GetNode() << " ";
        p = p->GetNext();
    }
    return os;
}

// CODA
class Queue : private List // ereditarietà privata: un oggetto di tipo Queue non può accedere ai membri di List (nemmeno quelli pubblici)
{
public:
    void Enqueue(int node) {InsertTail(node);}
    int Dequeue() {return RemoveHead();}
    bool IsEmpty() const {return List::IsEmpty();} // richiama la funzione della classe base
};

// PILA
class Stack : private List
{
public:
    void Push(int node) {InsertHead(node);}
    int Pop() {return RemoveHead();}
    bool IsEmpty() const {return List::IsEmpty();} 
};