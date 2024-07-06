/*
    Si implementi una classe “Prodotto” contenente gli attributi “nome”, “id”, “prezzo” e “categoria” del tipo che si ritiene più opportuno. Un esempio di prodotto è:
        Nome: “Lenovo Yoga 920”;
        ID: “EC72890132”;
        Prezzo: “1800”;
        Categoria: “Laptop”.
    Si implementi un albero binario di ricerca la cui funzione di ordinamento è applicata al prezzo dei prodotti ed ogni nodo dell’albero contiene una lista di prodotti della stessa categoria, ordinati per ID.
*/

#include <iostream>
using namespace std;

class Prodotto
{
public:
    Prodotto(string _nome, int _id, int _prezzo, string _categoria) : nome(_nome), id(_id), prezzo(_prezzo), categoria(_categoria) {}

    string getNome() {return nome;}
    int getId() {return id;}
    float getPrezzo() {return prezzo;}
    string getCategoria() {return categoria;}

private:
    string nome;
    int id;
    float prezzo;
    string categoria;

    friend ostream& operator<<(ostream& os, Prodotto* p)
    {
        os << "ID: " << p->getId() << "; Nome: " << p->getNome() << "; Prezzo: " << p->getPrezzo() << "; Categoria: " << p->getCategoria() << "." << endl;
        return os;
    }
};

class List;

class ListNode
{
public:
    ListNode(Prodotto* _data) : data(_data), next(nullptr) {}
    Prodotto* getData() {return data;}
    ListNode* getNext() {return next;}
    void setNext(ListNode* _next) {next = _next;}

private:
    Prodotto* data;
    ListNode* next;

    friend class List;
};


class List
{
public:
    List() : head(nullptr), tail(nullptr), prezzo(0) {}
    ~List() // distruttore della lista
    {
        ListNode* tmp = head;
        while(tmp != nullptr)
        {
            ListNode* next = tmp->getNext(); // conservo il nodo successivo
            delete tmp;
            tmp = next;
        }
    }
    bool isEmpty() {return head == nullptr;}
    ListNode* getHead() {return head;}
    int getPrezzo() {return prezzo;}
    string getCategoria() {return categoria;}

    // inserimento in ordine di ID
    List* insertOrdered(Prodotto* p)
    {
        ListNode* newNode = new ListNode(p);
        if(isEmpty()) // se è vuota
        {
            head = newNode;
            tail = newNode;
            // si impostano prezzo e categoria a quello del 1° elemento
            prezzo = newNode->getData()->getPrezzo();
            categoria = newNode->getData()->getCategoria();
            return this;
        }
        ListNode* prev = nullptr;
        ListNode* curr = head;
        // se l'ID del nuovo elemento è minore di quello della testa
        if(p->getId() < curr->getData()->getId())
        {
            newNode->setNext(curr);
            curr = curr->getNext();
            head = newNode; // il nuovo elemento diventa la testa
            return this;
        }
        // altrimenti si scorre la lista e si inserisce l'elemento tra prev e curr
        while(curr != nullptr && p->getId() >= curr->getData()->getId())
        {
            prev = curr;
            curr = curr->getNext();            
        }
        prev->setNext(newNode);
        newNode->setNext(curr);
        if(curr == nullptr) // se si è raggiunta la fine della lista (prev = tail e curr = nullptr)
            tail = newNode;
        return this;
    }

private:
    ListNode* head;
    ListNode* tail;
    // Gli elementi nella lista hanno stesso prezzo e categoria
    int prezzo;
    string categoria;

    friend ostream& operator<<(ostream& os, List* l) // stampa la lista
    {
        ListNode* tmp = l->getHead();
        while(tmp != nullptr)
        {
            os << tmp->getData();
            tmp = tmp->getNext();
        }
        os << endl;
        return os;
    }
};

class BST;

class BSTNode
{
public:
    BSTNode() : right(nullptr), left(nullptr)
    {
        data = new List(); // segmentation fault se si antepone il tipo di dato (List*)
    }
    //void addProdotto(Prodotto* p) {data->insertOrdered(p);}
    List* getData() {return data;}
    BSTNode* getRight() {return right;}
    BSTNode* getLeft() {return left;}

private:
    List* data; // lista di prodotti
    BSTNode* right;
    BSTNode* left;
    // non serve il parent

    friend class BST;
};

class BST
{
public:
    BST() : root(nullptr) {}
    ~BST(){destroy(root);} // distruttore
    void destroy(BSTNode* node)
    {
        if(node != nullptr) // C'è IF, non WHILE
        {
            destroy(node->left);
            destroy(node->right);
            delete node;
        }
    }

    // inserimento ordinato in base al prezzo
    BST* insertOrdered(Prodotto* p)
    {
        if(root == nullptr) // se l'albero è vuoto
        {
            BSTNode* newNode = new BSTNode(); // si crea un nuovo nodo...
            newNode->getData()->insertOrdered(p); //...si inserisce il prodotto...
            root = newNode; //...e il nuovo nodo diventa la radice
            return this;
        }
        // altrimenti si scorre l'albero
        BSTNode* curr = root;
        BSTNode* prev = nullptr;
        while(curr != nullptr)
        {
            prev = curr;
            // se prezzo e categoria coincidono
            if(p->getPrezzo() == curr->data->getPrezzo() && p->getCategoria() == curr->data->getCategoria())
            {
                curr->getData()->insertOrdered(p); // si inserisce il prodotto nella lista contenuta in curr
                return this;
            }
            else if(p->getPrezzo() < curr->data->getPrezzo())
                curr = curr->left;
            else    
                curr = curr->right;
        }
        // se si è arrivati qui significa che si è arrivati alla fine dell'albero e non si è trovato un nodo con la lista della stessa categoria del nuovo elemento e quindi si deve creare un nuovo nodo in cui inserire quest'ultimo
        BSTNode* newNode = new BSTNode();
        newNode->getData()->insertOrdered(p);
        // il nuovo nodo viene aggiunto alla fine dell'albero (curr = nullptr)
        if(p->getPrezzo() < prev->data->getPrezzo())
            prev->left = newNode;
        else
            prev->right = newNode;
        return this;
    }

    void _printInorder(BSTNode* node)
    {
        if(node != nullptr) // attenzione: è if, non while (altrimenti va il loop infinito)
        {
            _printInorder(node->left);
            cout << node->getData(); // adopera l'operatore sovraccaricato per List
            _printInorder(node->right);
        }
    }
    void printInorder()
    {
        _printInorder(root);
    }

private:
    BSTNode* root;
};

int main()
{
    Prodotto* p1 = new Prodotto("a", 10, 10, "x");
    Prodotto* p2 = new Prodotto("b", 20, 2, "x");
    Prodotto* p3 = new Prodotto("c", 5, 30, "x");
    Prodotto* p4 = new Prodotto("d", 15, 4, "x");
    Prodotto* p5 = new Prodotto("e", 8, 10, "x");
    Prodotto* p6 = new Prodotto("f", 25, 2, "x");
    Prodotto* p7 = new Prodotto("g", 10, 30, "x");
    Prodotto* p8 = new Prodotto("h", 20, 4, "x");

    BST* bst = new BST();
    bst->insertOrdered(p1)->insertOrdered(p2)->insertOrdered(p3)->insertOrdered(p4)->insertOrdered(p5)->insertOrdered(p6)->insertOrdered(p7)->insertOrdered(p8);
    bst->printInorder();
    
    return 0;
}