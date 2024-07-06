// Individuare un ciclo in una lista linkata - si suppone che il ciclo parta dall'ultimo nodo e che il numero dei nodi della lista sia noto (= 5)
#include <iostream>
using namespace std;

class Node
{
public:
    Node(int _data) : data(_data), next(nullptr) {}
    int getData() {return data;}
    Node* getNext() {return next;}
    void setNext(Node* n) {next = n;}

private:
    int data;
    Node* next;
};

class List
{
public:
    List(int _dim) : head(nullptr), dim(_dim) {}
    bool isEmpty() {return head == nullptr;}
    
    List& addNode(int data)
    {
        Node* newNode = new Node(data);
        if(isEmpty())
        {
            head = newNode;
            return *this;
        }
        Node* curr = head;
        Node* prev = nullptr;
        while(curr)
        {
            prev = curr;
            curr = curr->getNext();
        }
        prev->setNext(newNode);
        newNode->setNext(curr);
        return *this;
    }

    Node* search(int key)
    {
        Node* tmp = head;
        while(tmp && (tmp->getData() != key))
            tmp = tmp->getNext();
        return tmp;
    }

    bool detectAndRemoveLoop()
    {
        Node* tmp = head;
        for(int i = 1; i < dim; i++)
        {
            tmp = tmp->getNext();
        }
        if(tmp)
        {
            tmp->setNext(nullptr);
            return true;
        } else {
            return false;
        }
    }

    void printList()
    {
        Node* tmp = head;
        while(tmp)
        {
            cout << tmp->getData() << " ";
            tmp = tmp->getNext();
        }
        cout << endl;
    }

private:
    Node* head;
    int dim;
};

int main()
{
    List list(5);
    list.addNode(50).addNode(20).addNode(15).addNode(4).addNode(10);
    list.printList();
    list.search(10)->setNext(list.search(15));
    list.detectAndRemoveLoop();
    cout << "Lista linkata dopo la rimozione del ciclo:" << endl;
    list.printList();
    
}