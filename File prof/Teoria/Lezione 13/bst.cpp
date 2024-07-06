#include "bst.hpp"


// Metodo pubblico
template <typename T>
BST<T>& BST<T>::Insert(T val)
{
    BSTNode<T>* curr = root;
    BSTNode<T>* prec = NULL;
    while (curr != NULL) // scorre l'albero finché prec non punta all'ultimo nodo
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
    if (node!=NULL)
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

// La prima funzione Search (pubblica) richiama la seconda funzione Search (privata) passandole come primo nodo la radice dell'albero
template <typename T>
BSTNode<T>* BST<T>::Search(T val)
{
    return Search(val, root);
}

// Ritorna un puntatore al nodo con il valore cercato
template <typename T>
BSTNode<T>* BST<T>::Search(T val, BSTNode<T>* node)
{
    if(node == NULL || val == node->val)
        return node;
    else if (val < node->val) // se il valore del nodo cercato è minore di quello del nodo corrente
        return Search(val, node->left); // cerca nel sottoalbero sinistro
    else
        return Search(val, node->right); // altrimenti cerca nel sottoalbero destro
}

// La ricerca del minimo corrisponde alla ricerca del nodo più a sinistra
// Ritorna un puntatore al nodo
// Metodo pubblico
template <typename T>
BSTNode<T>* BST<T>::Min(BSTNode<T>* p)
{
    if (p == NULL)
        p = root;
    if (p == NULL)
        return NULL;
    // si scorre l'albero per trovare il nodo più a sinistra
    while(p->left != NULL)
        p = p->left;
    return p;
}

// Metodo pubblico
// Ricerca del successore (= più piccolo nodo maggiore del nodo in input)
// 2 casi: il sottoalbero destro del nodo è non vuoto (caso banale), altrimenti si deve cercare il minor antenato del nodo che abbia come figlio sinistro un antenato del nodo (il puntatore ritornato è proprio a questo figlio trovato)
// Se p (che non ha figlio destro) è figlio sinistro del padre allora il successore è il padre, altrimenti il successore è l'ultimo antenato per cui p si trova nel suo sottoalbero sinistro
template <typename T>
BSTNode<T>* BST<T>::Next(BSTNode<T>* p)
{
    // precondizione: assumiamo che p != NULL
    if (p->right)
        return Min(p->right); // ritorna il nodo minore (cioè più a sinistra) del sottoalbero destro
    // si risale l'albero fino a trovare un figlio sinistro del genitore 
    BSTNode<T>* parent = p->parent;
    // finché il parent non è null e p non è figlio sinistro di suo padre
    while (parent != NULL && p != parent->left)
    {
        p = parent;
        parent = p->parent;
    }
    return parent; // ritorna il padre (ogni nodo è padre di se stesso)
}

// Metodo privato
// Permette di spostare sottoalberi
template <typename T>
BSTNode<T>* BST<T>::Trapianta(BSTNode<T>* dest, BSTNode<T>* src)
{
    if (dest->parent == NULL) // se dest è la radice
        root = src; // src diventa la nuova radice
    else if (dest == dest->parent->left) // se dest è figlio sinistro di suo padre
        dest->parent->left = src;
    else
        dest->parent->right = src;
    if (src != NULL) // aggiorna il padre di src
        src->parent = dest->parent;
    return dest;
}

template <typename T>
void BST<T>::Remove(BSTNode<T>* p)
{  // precondizione: p != NULL e deve essere un puntatore valido

    // se p non ha figli
    if ((p->left == NULL) && (p->right == NULL))
        // questo caso si potrebbe anche evitare in quanto è automaticamente gestito dal caso successivo
        // e un'implementazione opportuna di Trapianta
        if (p->parent == NULL) // se p era la radice
            root = NULL; // si imposta il puntatore alla radice a NULL
        else if (p->parent->left == p) // se p era figlio sinitro
            p->parent->left = NULL;
        else
            p->parent->right = NULL;
    else if (p->right == NULL) // p non ha figlio destro
        Trapianta(p, p->left); // si sposta il figlio sinistro di p al posto di p
    else if (p->left == NULL)
        Trapianta(p, p->right);
    else
    {
        BSTNode<T>* next = Min(p->right); // successore di p
        if (next->right) // se il nodo da trapiantare ha un figlio destro (cioè non è figlio di p)
        {
            Trapianta(next, next->right); // si sostituisce next con il suo figlio destro
            next->right = p->right; // si aggiorna il figlio destro a quello di p
            p->right->parent = next; // si aggiorna il padre del figlio destro
        }
        Trapianta(p, next); // si sposta next al posto di p
        next->left = p->left; // si aggiorna il figlio sinistro
        next->left->parent = next; // si aggiorna il padre del figlio sinistro
    }
    delete p;
}

// Metodo privato
// Usato nel distruttore per cancellare un intero albero
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
    bst.print(os, bst.root); // si deve scrivere "bst." per richiamare il metodo print di BST
    return os;
}
