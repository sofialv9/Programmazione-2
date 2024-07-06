#include "graph.hpp"
#include <climits>

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
    if(tail == nullptr)
        tail = p;
    return *this;
}

List& List::InsertTail(int node)
{
    ListElem* p = new ListElem(node);
    p->next = nullptr;
    if(tail != nullptr)
        tail->next = p;
    tail = p;
    if(head == nullptr)
        head = p;
    return *this;
}


int List::RemoveHead()
{
    if(head == nullptr)
        return -1;
    ListElem* p = head;
    head = head->next;
    if(head == nullptr)
        tail = nullptr;
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

ostream& operator<<(ostream& os, const Graph& graph)
{
    for(int i = 0; i < graph.GetN(); i++)
        os << "Nodo " << i << " connesso a: " << graph.GetAdj(i) << endl;
    return os;
}

void Graph::PrintShortestPath(int s, int v)
{
    // 3 array dinamici di lunghezza pari al numero di nodi
    color = new color_t[n];
    d = new int[n];
    pred = new int[n];

    BFS(s);
    cout << "Il cammino minimo tra " << s << " e " << v << " ha lunghezza " << d[v] << " ed è il seguente: ";
    PrintPath(cout, s, v);
    cout << endl;

    delete [] color;
    delete [] d;
    delete [] pred;
}

// Nel ciclo iniziale colora tutti i nodi di bianco, imposta il pred a -1 e la distanza a INT_MAX. Colora s di grigio, imposta la distanza a 0, istanzia una coda e vi inserisce s. Finché la pila non è vuota si estrae un elemento u dalla coda e si estrae il primo elemento della sua lista di adiacenza. Finché questo elemento non è null ne si estrae il valore. se il colore corrispondente è bianco il nodo è colorato di grigio, la distanza impostata a d[u]+1, il pred a u e viene inserito nella coda. Infine il colore di u è impostato a nero.
void Graph::BFS(int s)
{
    for(int i = 0; i < n; i++)
    {
        color[i] = white;
        d[i] = INT_MAX;
        pred[i] = -1;
    }
    color[s] = gray;
    d[s] = 0;
    Queue q;
    q.Enqueue(s);
    while(!q.IsEmpty())
    {
        int u = q.Dequeue();
        // Si scorre la lista di adiacenza di u
        const ListElem* p = adj[u].GetHead();
        while(p != nullptr)
        {
            int v = p->GetNode();
            if(color[v] == white)
            {
                color[v] = gray;
                d[v] = d[u] + 1;
                pred[v] = u;
                q.Enqueue(v);
            }
            p = p->GetNext();
        }
        color[u] = black;
    }
}

// Stampa ricorsiva del cammino tra 2 nodi
void Graph::PrintPath(ostream &os, int s, int v)
{
    if(v == s)
        os << s << " ";
    else if(pred[v] == -1)
        os << "Nessun path da" << s << " a " << v;
    else
    {
        PrintPath(os, s, pred[v]);
        os << v << " ";
    }
}
