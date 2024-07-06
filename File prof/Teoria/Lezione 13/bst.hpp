#ifndef bst_hpp
#define bst_hpp

#include <iostream>

using namespace std;

// Tutte le classi (e gli operatori) sono template
template<typename T>
class BST; // definita qui perché amica di BTSNode

template<typename T>
class BSTNode;

template<typename T>
ostream& operator<<(ostream& os, const BST<T>& bst); // definito qui perché friend di BST

template <typename T>
class BSTNode
{
  public:
    int GetValue() {return val;}

  private:
    BSTNode(T _val) : val(_val), left(NULL), right(NULL) {}
    T val;
    BSTNode<T>* left;
    BSTNode<T>* right;
    BSTNode<T>* parent;
    
    friend class BST<T>; // BSTha accesso ai membri privati di BSTNode
};

template <typename T>
class BST
{
  public:
    BST() : root(NULL) {}
    ~BST() {Delete(root);}
    BST& Insert(T val);
    BSTNode<T>* Search(T val);
    BSTNode<T>* Min(BSTNode<T>* p = NULL);
    BSTNode<T>* Next(BSTNode<T>* p);
    void Remove(BSTNode<T>* p);

  private:
    void print(ostream& os, BSTNode<T>* node) const;
    void printPreorder(ostream& os, BSTNode<T>* node) const;
    BSTNode<T>* Search(T val, BSTNode<T>* node);
    BSTNode<T>* Trapianta(BSTNode<T>* dest, BSTNode<T>* src);
    void Delete(BSTNode<T>* p);

    BSTNode<T>* root;

    friend ostream& operator<< <T>(ostream& os, const BST<T>& node);
};

#include "bst.cpp" // indispensabile poiché si usano delle classi template (i metodi sono risolti dal compilatore e non dal linker)

#endif /* bst_hpp */
