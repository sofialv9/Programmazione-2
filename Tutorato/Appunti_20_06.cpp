// BST - bilanciamento duplicati
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;


template <class T>
class Node
{
public:
    Node(T _key) : key(_key), left(nullptr), right(nullptr), parent(nullptr) {} // costruttore con chiave
    Node() : key(T()), left(nullptr), right(nullptr), parent(nullptr) {} // costruttore di default
    ~Node()
    {
        delete left;
        delete right;
        delete parent;
    }

    T getKey() {return key;}
    Node<T>* getLeft() {return left;}
    Node<T>* getRight() {return right;}
    Node<T>* getParent() {return parent;}
    void setKey(T _key) {key = _key;}
    void setLeft(Node<T>* _left) {left = _left;}
    void setRight(Node<T>* _right) {right = _right;}
    void setParent(Node<T>* _parent) {parent = _parent;}


    bool operator==(Node<T>& n) {return key == n.getKey();} // ritorna true se le chiavi dei 2 nodi sono uguali
    bool operator<(Node<T>& n) {return key < n.getKey();}
    friend ostream& operator<<(ostream& os, Node<T>* n)
    {
        os << n->getKey();
        return os;
    }


private:
    T key;
    Node<T>* parent;
    Node<T>* left;
    Node<T>* right;
};

template <class T>
class BalancedBST
{
public:
    BalancedBST() : root(nullptr) {}

    void insert(T key) // Inserimento iterativo
    {
        bool insertOnRight = false; // flag - se è true si deve inserire il nodo a destra
        Node<T>* newNode = new Node(key);
        Node<T>* current = root;
        if(current == nullptr) // albero vuoto
        {
            root = newNode;
            return;
        }
        
        while(current != nullptr)
        {
            if(*newNode == *current)
            {
                if(insertOnRight)
                {
                    if(current->getLeft() == nullptr)
                    {
                        current->setLeft(newNode);
                        newNode->setParent(current);
                        return;
                    } else {
                        current = current->getLeft();
                    }
                } else {
                    if(current->getRight() == nullptr)
                    {
                        current->setRight(newNode);
                        newNode->setParent(current);
                        return;
                    } else {
                        current = current->getRight();
                    }
                }
                insertOnRight = !insertOnRight;
            } else if(*newNode < *current){ // chiama l'overload dell'operatore < sul nodo
                if(current->getLeft() == nullptr)
                {
                    current->setLeft(newNode);
                    newNode->setParent(current);
                    return;
                } else {
                    current = current->getLeft();
                }
            } else {
                if(current->getRight() == nullptr)
                {
                    current->setRight(newNode);
                    newNode->setParent(current);
                    return;
                } else {
                    current = current->getRight();
                }
            }
        }
    }

    void _insertRecursive(Node<T>* parent, Node<T>* current, bool insertOnRight) // insert ricorsivo
    {
    }

    void insertRecursive(Node<T>* current, T key) // insert ricorsivo
    {
        Node<T>* newNode = new Node(key);
        if(root == nullptr)
        {
            root = newNode;
            return;
        }
        _insertRecursive(newNode, root, nullptr, false); // current->parent == root->parent == nullptr
    }

    void _inorder(Node<T>* node)
    {
        if(node == nullptr)
            return;
        _inorder(node->getLeft());
        cout << node << " ";
        _inorder(node->getRight());
    }

    void inorder()
    {
        _inorder(root);
        cout << endl;
    }

private:
    Node<T>* root;
};

int main()
{
    srand(time(NULL));
    BalancedBST<int> bst;
    vector<int> keys;

    for(int i = 0; i < 10; i++)
    {
        int key = rand() % 100;
        keys.push_back(key);
    }
    
    for(int i = 0; i < 30; i++)
    {
        int index = rand()% keys.size();
        bst.insert(keys[index]);
    }
    
    bst.inorder();
}
