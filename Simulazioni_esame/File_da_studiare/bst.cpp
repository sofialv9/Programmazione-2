template<typename T>
class BST;
template<typename T>
class BSTNode;

template <typename T>
class BSTNode
{
public:
    int GetValue() {return val;}

private:
    BSTNode<T>(T _val) : val(_val), left(NULL), right(NULL) {}
    T val;
    BSTNode<T>* left;
    BSTNode<T>* right;
    BSTNode<T>* parent;
    
    friend class BST<T>;
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


template <typename T>
BST<T>& BST<T>::Insert(T val)
{
    BSTNode<T>* curr = root; // si usa solo per scorrere l'albero
    BSTNode<T>* prec = NULL;
    while (curr != NULL)
    {
        prec = curr;
        if(val < curr->val)
            curr = curr->left;
        else
            curr = curr->right;
    }
    BSTNode<T>* newnode = new BSTNode(val);
    newnode->parent = prec;
    if (prec == NULL)
        root = newnode;
    else if (val < prec->val)
        prec->left = newnode;
    else
        prec->right = newnode;
    return *this;
}

// Metodo privato
template <typename T>
void BST<T>::print(ostream& os, BSTNode<T>* node) const // Inorder
{
    if (node != NULL)
    {
        print(os,node->left);
        os << node->GetValue() << " ";
        print(os,node->right);
    }
}

// Metodo privato
template <typename T>
void BST<T>::printPreorder(ostream& os, BSTNode<T>* node) const
{
    if (node != NULL)
    {
        os << node->GetValue() << " ";
        printPreorder(os, node->left);
        printPreorder(os,node->right);
    }
}

template <typename T>
BSTNode<T>* BST<T>::Search(T val)
{
    return Search(val, root);
}

// Procedura ricorsiva che ritorna un puntatore al nodo con il valore cercato
template <typename T>
BSTNode<T>* BST<T>::Search(T val, BSTNode<T>* node)
{
    if(node == NULL || val == node->val)
        return node;
    else if (val < node->val)
        return Search(val, node->left);
    else
        return Search(val, node->right);
}


template <typename T>
BSTNode<T>* BST<T>::Min(BSTNode<T>* p)
{
    if (p == NULL)
        p = root;
    if (p == NULL)
        return NULL;
    while(p->left != NULL)
        p = p->left;
    return p;
}


// Ricerca del successore 
template <typename T>
BSTNode<T>* BST<T>::Next(BSTNode<T>* p)
{
    // assumiamo che p != NULL
    if (p->right)
        return Min(p->right);
    BSTNode<T>* parent = p->parent;
    while (parent != NULL && p != parent->left)
    {
        p = parent;
        parent = p->parent;
    }
    return parent;
}

// Metodo privato
// Sposta sottoalberi
template <typename T>
BSTNode<T>* BST<T>::Trapianta(BSTNode<T>* dest, BSTNode<T>* src)
{
    if (dest->parent == NULL)
        root = src;
    else if (dest == dest->parent->left)
        dest->parent->left = src;
    else
        dest->parent->right = src;
    if (src != NULL)
        src->parent = dest->parent;
    return dest;
}

template <typename T>
void BST<T>::Remove(BSTNode<T>* p)
{  // precondizione: p != NULL
    if ((p->left == NULL) && (p->right == NULL)) // non ha figli
        if (p->parent == NULL) // è la radice
            root = NULL;
        else if (p->parent->left == p)
            p->parent->left = NULL;
        else
            p->parent->right = NULL;
    else if (p->right == NULL) // non ha figli destri
        Trapianta(p, p->left);
    else if (p->left == NULL) // non ha figli sinistri
        Trapianta(p, p->right);
    else
    {
        BSTNode<T>* next = Min(p->right);
        if (next->right)
        {
            Trapianta(next, next->right);
            next->right = p->right;
            p->right->parent = next;
        }
        Trapianta(p, next);
        next->left = p->left;
        next->left->parent = next;
    }
    delete p;
}

// Usato nel distruttore
template <typename T>
void BST<T>::Delete(BSTNode<T>* p)
{
    if(p != NULL)
    {
        Delete(p->left);
        Delete(p->right);
        delete p;
    }
}

template <typename T>
ostream& operator<< (ostream& os, const BST<T>& bst)
{
    bst.print(os, bst.root);
    return os;
}