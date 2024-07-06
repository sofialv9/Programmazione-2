#include <iostream>
#include <climits>
using namespace std;

enum color_t {white, gray, black};

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

        bool isEmpty() {return (head == nullptr);}

        List& insertHead(const T& key) {
            Node<T>* p = new Node<T>(key);
            p->next = head;
            head = p;
            if (tail == nullptr)
                tail = p;
            return *this;
        }

        List& insertTail(const T& key)
        {
            Node<T>* p = new Node<T>(key);
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

        T removeNode(T key)
        {
            Node<T>* curr = head;
            Node<T>* prev = nullptr;
            while(curr)
            {
                if(curr->getKey() == key)
                {
                    if(prev) // elimina curr (= nodo interno alla lista)
                        prev->next = curr->next;
                    else // elimina la testa (prev == nullptr)
                        head = curr->next;
                    if(!curr->next) // si elimina la coda (curr == tail)
                        tail = prev;
                    delete curr;
                    return key;
                }
                prev = curr;
                curr = curr->next;
            }
            return T(); // nodo da eliminare non trovato
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
    void enqueue(T data) {this->insertTail(data);}
    T dequeue() {return this->removeHead();}
    bool IsEmpty() const {return List<T>::IsEmpty();}
};

class Arco;
class Grafo;

// Vertice del grafo
class Vertice {
    private:
        Citta* citta;
        List<Arco> archi; // Lista di archi uscenti
        // attributi per la BFS:
        color_t color;
        int d;
        int d_max;
        Vertice* pred;

        bool operator==(Vertice& v)
        {
            return (this->getCitta() == v.getCitta());
        }

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

        // stampa gli archi in sequenza per ogni vertice
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
//           una volta completate tutte le visite, la maggiore fra tutte le distanze massime trovate è    
//           il diametro del grafo.
// diametro = massima distanza tra tutte le coppie di vertici (es. da A a C si fa A-B-D-C, non A-C) - si deve conservare la distanza massima per ogni nodo sorgente con ogni altro nodo

        
        void BFS(Node<Vertice*>* a)
        {
            Node<Vertice*>* p = vertici.getHead();
            while(p) // inizializza tutti i vertici del grafo
            {
                p->getKey()->color = white;
                p->getKey()->d = INT_MIN;
                p->getKey()->d_max = INT_MIN;
                p->getKey()->pred = nullptr; // pred è di tipo Vertice*
                p = p->getNext();
            }
            Vertice* u = a->getKey();
            u->color = gray;
            Queue<Vertice*> q;
            q.enqueue(u);
            while(!q.isEmpty())
            {
                Vertice* v = q.dequeue();
                Node<Arco>* arco = v->archi.getHead();
                v->d = arco->getKey().getPeso();
                if(v->d > v->d_max)
                    v->d_max = v->d;
                Node<Arco>* next = arco->getNext();
                while(next)
                {
                    Vertice* v2 = arco->getKey().getV2();
                    if(v2->color == white)
                    {
                        v2->color = gray;
                        v2->d = v->d + next->getKey().getPeso();
                        if(v2->d > v2->d_max)
                            v2->d_max = v2->d;
                        v2->pred = v;
                        q.enqueue(v2);
                    }
                    arco = next;
                    next = next->getNext();
                }
                u->color = black;
            }
        }

        int diametro()
        {
            int diametro = 0;
            int distanza = 0;
            Node<Vertice*>* p = vertici.getHead();
            while(p)
            {
                BFS(p);
                distanza += p->getKey()->d_max;
                if(distanza > diametro)
                    diametro = distanza;
                p = p->getNext();
            }
            return diametro;
        }


        // rimuove un nodo in base alla provincia
        int removeNode(string provincia)
        {
            Node<Vertice*>* p = vertici.getHead();
            int removed = 0; // numero di nodi eliminati
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
                            Node<Arco>* b = a->getNext(); // conserva l'arco successivo
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

        // rimuove un nodo in base al numero di abitanti
        int removeNode(int n_abitanti)
        {
            Node<Vertice*>* p = vertici.getHead();
            int removed = 0;
            while(p)
            {
                Node<Vertice*>* next = p->getNext();
                if(p->getKey()->getCitta()->getAbitanti() < n_abitanti)
                {
                    removed++;
                    Vertice* v = vertici.removeNode(p->getKey());
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



        bool BFS_2(Node<Vertice*>* a)
        {
            bool found_ciclo = false;
            Node<Vertice*>* p = vertici.getHead();
            while(p) // inizializza tutti i vertici del grafo
            {
                p->getKey()->color = white;
                p->getKey()->d = INT_MAX;
                p->getKey()->pred = nullptr; // pred è di tipo Vertice*
                p = p->getNext();
            }
            Vertice* u = a->getKey();
            u->color = gray;
            u->d = 0;
            Queue<Vertice*> q;
            q.enqueue(u);
            while(!q.isEmpty())
            {
                Vertice* v = q.dequeue();
                Node<Arco>* arco = v->archi.getHead();
                while(arco)
                {
                    Vertice* v2 = arco->getKey().getV2();
                    if(v2->color == black) // Se durante la visita si incontra un vertice adiacente già scoperto
                        found_ciclo = 1;   // il grafo contiene almeno un ciclo
                    if(v2->color == white)
                    {
                        v2->color = gray;
                        v2->d = v->d + 1;
                        v2->pred = v;
                        q.enqueue(v2);
                    }
                    arco = arco->getNext();
                }
                u->color = black;
            }
            return found_ciclo;
        }

        bool findCiclo()
        {
            bool out = false;
            Node<Vertice*>* p = vertici.getHead();
            while(p)
            {
                out = BFS_2(p);
                p = p->getNext();
            }
            return out;
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

    cout << "Presenza di un ciclo: " << g.findCiclo() << endl;

    cout << endl;

    cout << "diametro: " << g.diametro() << endl;
    
    return 0;
    cout << endl;

    cout << g.removeNode("TT") << endl;
    cout << "Liste di adiacenza: " << endl;
    g.printEdges();

    cout << endl;

    cout << g.removeNode(1000) << endl;
    cout << "Liste di adiacenza: " << endl;
    g.printEdges();
}
