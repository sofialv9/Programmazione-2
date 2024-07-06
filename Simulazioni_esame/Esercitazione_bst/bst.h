#ifndef _bst_h_
#define _bst_h_

#include <iostream>
using namespace std;

class Studente 
{
public:
    Studente(int _matricola, const string& _nome, const string& _cognome, float _media) 
        : matricola(_matricola), nome(_nome), cognome(_cognome), media(_media) {}

    Studente(const Studente& stud) // costruttore di copia
        : matricola(stud.matricola), nome(stud.nome), cognome(stud.cognome), media(stud.media) {}

    // metodi get - il const in mezzo è facoltativo
    int GetMatricola() const {return matricola;}        
    const string& GetNome() const {return nome;}        
    const string& GetCognome() const {return cognome;}        
    float GetMedia() const {return matricola;}

    // Stampa a video
    void print() const {cout << matricola << ": " << nome << " " << cognome << " - media " << media << endl;}
private:
    int matricola;
    string nome;
    string cognome;
    float media;
};

class BST; // dichiarata prima di BSTNode poichè è menzionata all'interno di BSTNode

class BSTNode 
{
public:
    const Studente& GetData() {return data;}
private:
    BSTNode(const Studente& stud) : data(stud) {}
    Studente data;
    BSTNode* p;     // puntatore al genitore (parent)
    BSTNode* l;     // puntatore al figlio sinistro (left)
    BSTNode* r;     // puntatore al figlio destro (right)

    friend class BST;
};

class BST 
{
public:
    BST() : root(NULL) {}
    ~BST() {destroy(root);}
    
    void Insert(const Studente& stud);
    BSTNode* Search(int matricola);
    void print() const;
private:
    void print(BSTNode* node) const; // stampa ricorsiva inorder
    void destroy(BSTNode* node);
    BSTNode* root;
};


#endif //_bst_h_
