#include<iostream>
using namespace std;

template<class T>
class Node{
    public:
    T value;
    Node<T> *next;
};

template<class T>
class List{
    public:
    List(){this->head = nullptr;}

    bool insert(T value);
    bool isEmpty(){return this->head == nullptr;}
    Node<T>* search(T value);
    Node<T>* getHead(){return this->head;}
    void print();

    private:
    Node<T> *head;
};

template<class H>
class Graph{
    public:
    Graph(int maxNodes){
        this->maxNodes = maxNodes; 
        this->nodes = 0; 
        this->edges = 0; 
        this->k = new H*[maxNodes]; // array di puntatori a H (stringa)
        for(int i = 0; i < maxNodes; i++) k[i] = nullptr; // inizializza i nodi a nullptr
        adj = new List<int>*[maxNodes]; // array di puntatori a liste di interi
        for(int i = 0; i < maxNodes; i++) adj[i] = new List<int>; // inizializza le liste
    }

    Graph<H>* addNode(H value);
    Graph<H>* addEdge(H val1, H val2);
    void print();

    private:
    int findIndex(H value);
    int nodes;
    int edges;
    int maxNodes;
    List<int> **adj;
    H **k; // puntatore ad array di H (stringhe)
};

template<class T>
bool List<T>::insert(T value){
    Node<T>* newNode = new Node<T>;
    if(this->isEmpty()) newNode->next = nullptr;
    else newNode->next = this->head;
    this->head = newNode;
    newNode->value = value;
    
    return true;
}

template<class T>
Node<T>* List<T>::search(T value){
    Node<T>* cursor = this->head;

    while(cursor && (cursor->value != value)) cursor = cursor->next;
    if(cursor) return cursor;
    else return nullptr;
}

template<class T>
void List<T>::print(){
    Node<T> *cursor = this->head;

    while(cursor){
        cout << cursor->value << "\t";
        cursor = cursor->next;
    }

    cout << endl;
}

// serve per capire se c'è già un valore nel grafo
template<class H>
int Graph<H>::findIndex(H value){
    for(int i = 0; i < this->nodes; i++){
        if(*k[i] == value) 
        return i;
    }

    return -1;
}

template<class H>
Graph<H>* Graph<H>::addNode(H value){
    if(this->nodes == this->maxNodes) {
        cout << "Impossible to add node" << endl;
        return this;
    }

    if(findIndex(value) >= 0) return this; //gia c'è il valore nel grafo, non se ne può aggiungere un duplicato

    this->k[this->nodes++] = new H(value);
    return this;
}

template<class H>
Graph<H>* Graph<H>::addEdge(H val1, H val2){
    int idx1 = findIndex(val1); 
    int idx2 = findIndex(val2);

    if(idx1 < 0 || idx2 < 0){ // non c'è il nodo nel grafo
        cout << "Impossible addEdge operation" << endl;
        return this;
    }

    if(not adj[idx1]->search(idx2)) {adj[idx1]->insert(idx2); this->edges++;}

    return this;
}

template<class H>
void Graph<H>::print(){
    for(int i = 0; i < this->nodes; i++){
        cout << "(" << i << ", " << *k[i] << ")" << " : ";
        this->adj[i]->print();
        cout << endl;
    }
}

int main(void){
    Graph<string> *g = new Graph<string>(3);
    g->addNode("ciao")->addNode("come")->addNode("analisi 1");
    g->addEdge("ciao", "come")->addEdge("come", "analisi 1");

    g->print();
}