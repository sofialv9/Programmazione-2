#include <iostream>
#include <typeinfo>

using namespace std;

class Frutto {
    private:
        string nome;
        string colore;
        string stagione;
    public:
        Frutto(string nome, string colore, string stagione) {
            this->nome = nome;
            this->colore = colore;
            this->stagione = stagione;
        }
        string getNome() {
            return this->nome;
        }
        string getColore() {
            return this->colore;
        }
        string getStagione() {
            return this->stagione;
        }

        void stampa() {
            cout << "Nome: " << this->nome << endl;
            cout << "Colore: " << this->colore << endl;
            cout << "Stagione: " << this->stagione << endl;
        }

        virtual string get_sapore() = 0;

        //Overload <<
        friend ostream& operator<<(ostream& os, const Frutto& f) {
            os << "Nome: " << f.nome << endl;
            os << "Colore: " << f.colore << endl;
            os << "Stagione: " << f.stagione << endl;
            return os;
        }
};

class Mela : public Frutto {
    private:
        string sapore;
    public:
        Mela(string nome, string colore, string stagione, string sapore) : Frutto(nome, colore, stagione) {
            this->sapore = sapore;
        }
        string get_sapore() {
            return this->sapore;
        }
        void stampa() {
            Frutto::stampa();
            cout << "Sapore: " << this->sapore << endl;
        }

        //Overload <<
        friend ostream& operator<<(ostream& os, const Mela& m) {
            os << static_cast<const Frutto&>(m);
            os << "Sapore: " << m.sapore << endl;
            return os;
        }
};

class Arancia : public Frutto {
    private:
        string sapore;
    public:
        Arancia(string nome, string colore, string stagione, string sapore) : Frutto(nome, colore, stagione) {
            this->sapore = sapore;
        }
        string get_sapore() {
            return this->sapore;
        }
        void stampa() {
            Frutto::stampa();
            cout << "Sapore: " << this->sapore << endl;
        }

        //Overload <<
        friend ostream& operator<<(ostream& os, const Arancia& a) {
            os << static_cast<const Frutto&>(a);
            os << "Sapore: " << a.sapore << endl;
            return os;
        }
};

template <class T>
class Node {
    private:
        T data;
        Node<T>* next;
    public:
        Node<T>(T data) {
            this->data = data;
            this->next = nullptr;
        }

        void setData(T data) {
            this->data = data;
        }
        T getData() {
            return this->data;
        }
        Node<T>* getNext() {
            return this->next;
        }
        void setNext(Node<T>* next) {
            this->next = next;
        }
};

template <class T>
class Queue{
    private:
        Node<T>* head;
        Node<T>* tail;
        int size;
    public:
        Queue() {
            head = nullptr;
            tail = nullptr;
            size = 0;
        }
        
        ~Queue() {
            while (head != nullptr) {
                Node<T>* temp = head;
                head = head->getNext();
                delete temp;
            }
        }

        void enqueue(T data) {
            Node<T>* newNode = new Node<T>(data);
            if (head == nullptr) {
                head = newNode;
                tail = newNode;
            } else {
                tail->setNext(newNode);
                tail = newNode;
            }
            size++;
        }

        void dequeue() {
            if (head == nullptr) {
                return;
            }
            Node<T>* temp = head;
            head = head->getNext();
            delete temp;
            size--;
        }

        T front() {
            if (head == nullptr) {
                return T();
            }
            return head->getData();
        }

        void print(){
            Node<T>* temp = head;
            while (temp != nullptr) {
                cout << *temp->getData() << " ";
                temp = temp->getNext();
            }
            cout << endl;
        }
};


int main() {
    /*  Inserisco
    Granny Smith, Verde, Autunno, sapore Aspro
    Tarocco, Arancione, Inverno, sapore Dolce
    Golden Delicious, Giallo, Autunno, sapore Dolce
    Navel, Arancione, Inverno, sapore Dolce-Acido
    Fuji, Rosso, Autunno, sapore Dolce
    Valencia, Arancione, Estate, sapore Acido
    */

    Frutto* mela1 = new Mela("Granny Smith", "Verde", "Autunno", "Aspro");
    Frutto* arancia1 = new Arancia("Tarocco", "Arancione", "Inverno", "Dolce");
    Frutto* mela2 = new Mela("Golden Delicious", "Giallo", "Autunno", "Dolce");
    Frutto* arancia2 = new Arancia("Navel", "Arancione", "Inverno", "Dolce-Acido");
    Frutto* mela3 = new Mela("Fuji", "Rosso", "Autunno", "Dolce");
    Frutto* arancia3 = new Arancia("Valencia", "Arancione", "Estate", "Acido");

    Queue<Frutto*> queue;
    queue.enqueue(mela1);
    queue.enqueue(arancia1);
    queue.enqueue(mela2);
    queue.enqueue(arancia2);
    queue.enqueue(mela3);
    queue.enqueue(arancia3);

    //Mmh, qui però non stampa il sapore, perché? E come faccio a stampare il sapore?
    queue.print();

    cout << "Scegli tra Arancia e Mela: " << endl;
    string tipo;
    cin >> tipo;
    if(tipo == Arancia)

    queue.print();
}

/*
    SI implementi una classe BST in cui le chiavi duplicate vanno inserite nei sottoalberi destro e sinistro della chiave già presente nel BST in modo alternato. Nel main istanziare un BST di char e int e testare il corretto funzionamento dei metodi implementati.
*/