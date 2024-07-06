//  graph.hpp

#ifndef graph_hpp
#define graph_hpp

#include <iostream>

using namespace std;

class List;

class ListElem
{
public:
    const ListElem* GetNext() const {return next;}
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

class Queue : private List
{
public:
    void Enqueue(int node) {InsertTail(node);}
    int Dequeue() {return RemoveHead();}
    bool IsEmpty() const {return List::IsEmpty();}
};

class Stack : private List
{
public:
    void Push(int node) {InsertHead(node);}
    int Pop() {return RemoveHead();}
    bool IsEmpty() const {return List::IsEmpty();}
};

class Graph
{
public:
    Graph(int _n) : n(_n) {adj = new List[n];}
    ~Graph() {delete [] adj;}
    Graph& AddEdge(int u, int v) {adj[u].InsertTail(v); adj[v].InsertTail(u); return *this;}
    int GetN() const {return n;}
    const List& GetAdj(int v) const {return adj[v];}
    
    void PrintShortestPath(int s, int v);
private:
    enum color_t {white,gray,black};
    
    void BFS(int s);
    void PrintPath(ostream& os, int s, int v);
    
    color_t* color;
    int* d;
    int* pred;
private:
    List* adj;
    int n;
};

ostream& operator<<(ostream& os, const List& list);
ostream& operator<<(ostream& os, const Graph& graph);


#endif /* graph_hpp */
