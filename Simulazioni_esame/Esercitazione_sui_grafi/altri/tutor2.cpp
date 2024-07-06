#include <iostream>
#include <climits>
using namespace std;

class Citta {
    private:
        string nome;
        string provincia;
        int abitanti;

    public:
        Citta(string n, string p, int a) : nome(n), provincia(p), abitanti(a) {}
        string getNome() const { return nome; }
        string getProvincia() const { return provincia; }
        int getAbitanti() const { return abitanti; }

        // Operator ==
        bool operator==(const Citta& c) const {
            return nome == c.nome;
        }
};

ostream& operator<<(ostream& os, const Citta& c) {
    os << c.getNome() << " (" << c.getProvincia() << ") - " << c.getAbitanti() << " abitanti";
    return os;
}

template <typename T>
class List;

template <typename T>
class Node {
    private:
        T key;
        Node* next;

    public:
        Node(const T& _key) : key(_key), next(nullptr) {}
        T& getKey() { return key; }
        Node* getNext() const { return next; }

        friend class List<T>;
};

template <typename T>
class List {
    private:
        Node<T>* head;
        Node<T>* tail;

    public:
        List() : head(nullptr), tail(nullptr) {}
        ~List() {
            Node<T>* p = head;
            while (p != nullptr) {
                Node<T>* next = p->next;
                delete p;
                p = next;
            }
        }

        List& insertHead(const T& key) {
            Node<T>* p = new Node<T>(key);
            p->next = head;
            head = p;
            if (tail == nullptr)
                tail = p;
            return *this;
        }

        List& insertTail(const T& key) {
            Node<T>* p = new Node<T>(key);
            p->next = nullptr;
            if (tail != nullptr)
                tail->next = p;
            tail = p;
            if (head == nullptr)
                head = p;
            return *this;
        }

        Node<T>* getHead() const { return head; }

        T removeHead() {
            if (head == nullptr)
                throw runtime_error("List is empty");
            Node<T>* p = head;
            T key = p->key;
            head = p->next;
            if (head == nullptr)
                tail = nullptr;
            delete p;
            return key;
        }

        T removeNode(T v){
            Node<T>* p = head;
            Node<T>* prev = nullptr;
            while(p)
            {
                if(p->key == v)
                {
                    if(prev)
                        prev->next = p->next;
                    else
                        head = p->next;
                    if(!p->next)
                        tail = prev;
                    delete p;
                    return v;
                }
                prev = p;
                p = p->next;
            }
            return T();
        }
        
        // Operator <<
        friend ostream& operator<<(ostream& os, const List<T>& l) {
            Node<T>* p = l.head;
            while (p != nullptr) {
                os << p->key << " ";
                p = p->next;
            }
            return os;
        }
};

template<class T>
class Queue : public List<T>
{
public:
    Queue() : head(nullptr), tail(nullptr) {}
    Queue<T>& enqueue(T data) {this->insertTail(data); return *this;}
    T dequeue() {return this->removeHead();}
    bool isEmpty() {return head == nullptr;}

private:
    Node<T>* head;
    Node<T>* tail;
};

class Arco;
class Grafo;

// Vertice del grafo
class Vertice {
    private:
        Citta* citta;
        List<Arco> archi; // Lista di archi uscenti

    public:
        Vertice(Citta* c) : citta(c) {}
        const Citta* getCitta() const { return citta; }

        friend class Grafo;
        
};

// Arco del grafo
class Arco {
    private:
        Vertice* v1;
        Vertice* v2;
        int peso;

    public:
        Arco() : v1(nullptr), v2(nullptr), peso(0) {}
        Arco(Vertice* _v1, Vertice* _v2, int _peso) : v1(_v1), v2(_v2), peso(_peso) {}
        Vertice* getV1() const { return v1; }
        Vertice* getV2() const { return v2; }
        int getPeso() const { return peso; }

    bool operator!=(Arco& a)
    {
        return ((this->getPeso() != a.getPeso()) && (this->getV1() != a.getV1()) && (this->getV2() != a.getV2()));
    }

    bool operator==(Arco& a)
    {
        return ((this->getPeso() == a.getPeso()) && (this->getV1() == a.getV1()) && (this->getV2() == a.getV2()));
    }
};

class Grafo {
    private:
        List<Vertice*> vertici;

    public:
        // ritorna numero dei vertici
        int getN()
        {
            int n = 0;
            Node<Vertice*>* v = vertici.getHead();
            while(v)
            {
                n++;
                v = v->getNext();
            }
            return n;
        }

        Grafo& addNode(Citta* c) // aggiunge un nodo contenente la città in input
        {
            Vertice* v = new Vertice(c);
            vertici.insertTail(v);
            return *this;
        }

        Grafo& addEdge(Citta* c1, Citta* c2, int peso) // aggiunge un arco tra 2 nodi già presenti nel grafo
        {
            // scorre la lista di vertici per trovare i 2 tra cui inserire l'arco
            Node<Vertice*>* p = vertici.getHead();
            Node<Vertice*>* v1 = nullptr;
            Node<Vertice*>* v2 = nullptr;
            while (p != nullptr) {
                if (p->getKey()->getCitta() == c1)
                    v1 = p;
                if (p->getKey()->getCitta() == c2)
                    v2 = p;
                p = p->getNext();
            }
            if (v1 == nullptr || v2 == nullptr)
                throw runtime_error("Nodi non trovati");
            // aggiunge gli archi nella lista di archi uscenti all'interno di entrambi i vertici
            v1->getKey()->archi.insertTail(Arco(v1->getKey(), v2->getKey(), peso));
            v2->getKey()->archi.insertTail(Arco(v2->getKey(), v1->getKey(), peso));
            return *this;
        }
        
        // stampa i nomi dei nodi in sequenza
        void printNodes() {
            Node<Vertice*>* p = vertici.getHead();
            while (p != nullptr) {
                cout << p->getKey()->getCitta()->getNome() << " ";
                p = p->getNext();
            }
            cout << endl;
        }

        // stamp agli archi in sequenza per ogni vertice
        void printEdges() {
            Node<Vertice*>* p = vertici.getHead();
            while (p != nullptr) {
                cout << p->getKey()->getCitta()->getNome() << ": ";
                Node<Arco>* a = p->getKey()->archi.getHead();
                while (a != nullptr) {
                    cout << "(" << a->getKey().getV2()->getCitta()->getNome() << "," << a->getKey().getPeso() << ") ";
                    a = a->getNext();
                }
                cout << endl;
                p = p->getNext();
            }
        }

// DIAMETRO: compiere tante visite quanti sono i vertici, partendo da ciascuno di essi; 
//           alla fine di ogni visita individuare la distanza massima trovata dalla visita; 
//          una volta completate tutte le visite, la maggiore fra tutte le distanze massime trovate è il diametro del grafo.


        int diametro()
        {
            int diametro = 0;
            Node<Vertice*>* p = vertici.getHead();
            while(p)
            {
                int sum = 0;
                Node<Arco>* a = p->getKey()->archi.getHead();
                while (a != nullptr)
                {
                    sum += a->getKey().getPeso();
                    a = a->getNext();
                    //cout << " Somma parziale " << sum << endl;
                }
                //cout << " Somma totale " << sum << endl;
                if(sum > diametro)
                    diametro = sum;
                p = p->getNext();
            }
            return diametro;
        }

        // rimuove un nodo in base alla provincia
        int removeNode(string provincia)
        {
            Node<Vertice*>* p = vertici.getHead();
            int removed = 0;
            while(p)
            {
                Node<Vertice*>* next = p->getNext(); // Conservo il prossimo nodo
                if(p->getKey()->getCitta()->getProvincia() == provincia) // Controlla se la provincia del nodo corrente è uguale a quella in input
                {
                    removed++;
                    // Rimuove il nodo dalla lista di vertici e lo salva in v
                    Vertice* v = vertici.removeNode(p->getKey());
                    // Scorre la lista di vertici per rimuovere tutti gli archi che puntano a v
                    Node<Vertice*>* q = vertici.getHead();
                    while(q)
                    {
                        Node<Arco>* a = q->getKey()->archi.getHead();
                        while(a)
                        {
                            Node<Arco>* b = a->getNext();
                            if(a->getKey().getV2() == v){
                                cout << "Rimuovo arco tra " << q->getKey()->getCitta()->getNome() << " e " << a->getKey().getV2()->getCitta()->getNome() << endl;
                                q->getKey()->archi.removeNode(a->getKey());
                            }
                            a = b;
                        }
                        q = q->getNext();
                    }
                }
                p = next;
            }
            return removed;
        } 
};

int main()
{
    /* Genero le città:
    -	A, CC, 1000;
    -	B, CC, 2300;
    -	C, TT, 1200;
    -	D, CC, 2990;
    -	E, CC, 990; 
    */
    Citta A("A", "CC", 1000);
    Citta B("B", "CC", 2300);
    Citta C("C", "TT", 1200);
    Citta D("D", "CC", 2990);
    Citta E("E", "CC", 990);

    /* Creo il grafo delle città e aggiungo gli archi:
    A-B, A-C, A-D, B-C, B-D, C-D, C-E
    Con pesi rispettivamente
    5, 1, 10, 2, 8, 3, 4
    */

    Grafo g;
    g.addNode(&A).addNode(&B).addNode(&C).addNode(&D).addNode(&E);
    g.addEdge(&A, &B, 5).addEdge(&A, &C, 1).addEdge(&A, &D, 10).addEdge(&B, &C, 2).addEdge(&B, &D, 8).addEdge(&C, &D, 3).addEdge(&C, &E, 4);
    cout << "Nodi: ";
    g.printNodes();
    cout << "Liste di adiacenza: " << endl;
    g.printEdges();


    //cout << g.diametro() << endl; // = 21 ma non credo sia corretto

    cout << g.removeNode("TT") << endl;
    cout << "Liste di adiacenza: " << endl;
    g.printEdges();


}
