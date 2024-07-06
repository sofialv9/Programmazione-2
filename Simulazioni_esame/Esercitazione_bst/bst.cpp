#include "bst.h"

void BST::Insert(const Studente& stud)
{
    BSTNode* p = root;
    BSTNode* old = NULL;
    while (p != NULL)
    {
        old = p;
        if (p->GetData().GetMatricola() > stud.GetMatricola())
            p = p->l;
        else
            p = p->r;
    }
    BSTNode* pnew = new BSTNode(stud);
    pnew->p = old;
    if (old == NULL)
        root = pnew;
    else
    {
        if (old->GetData().GetMatricola() > stud.GetMatricola())
            old->l = pnew;
        else
            old->r = pnew;
    }
}

BSTNode* BST::Search(int matricola) 
{
    BSTNode* p = root;
    while ((p != NULL) && (matricola != p->GetData().GetMatricola()))
    {
        if (matricola < p->GetData().GetMatricola()) 
            p = p->l;
        else
            p = p->r;
    }
    return p;
}

void BST::print() const
{
    print(root);
}

void BST::print(BSTNode* p) const // inorder
{
    if (p != NULL)
    {
        print(p->l);
        p->GetData().print();
        print(p->r);
    }
}

void BST::destroy(BSTNode* p)
{
    if (p != NULL)
    {
        destroy(p->l);
        destroy(p->r);
        delete p;
    }   
}
