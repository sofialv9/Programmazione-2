#include<iostream>
using namespace std;

template<class T>
struct NodeL{
    T value;
    NodeL *next;
};

template<class H>
struct NodeB{
    H value;
    NodeB *sx;
    NodeB *dx;
    NodeB *parent;
};

class Product{
    public:
    Product(string category, int id, double price) : category(category), id(id), price(price){}

    string getCategory(){return this->category;}
    int getId(){return this->id;}
    double getPrice(){return this->price;}
    void print(){cout << this->getId() << " " << this->getCategory() << " " << this->getPrice() << endl;}

    private:
    string category;
    int id;
    double price;
};

template<class T>
class List{
    public:
    List(){this->head = nullptr;}

    bool isEmpty(){return this->head == nullptr;}
    List<T>* insert(T value);
    T remove();
    double sumPrice();

    private:
    NodeL<T> *head;
};

template<class T>
List<T>* List<T>::insert(T value){
    NodeL<T> *newNode = new NodeL<T>;
    newNode->value = value;
    newNode->next = nullptr;

    if(isEmpty()) this->head = newNode;
    else{
        NodeL<T> *cursor = this->head;
        NodeL<T> *prec = nullptr;

        while(cursor && value > cursor->value){
            prec = cursor;
            cursor = cursor->next;
        }

        prec->next = newNode;
        newNode->next = cursor;
    }

    return this;
}

bool operator>(Product& x, Product& y){
    return x.getId() > y.getId();
}

template<class T>
T List<T>::remove(){
    if(isEmpty()) return T(0);

    T value = this->head->value;
    this->head = this->head->next;
    return value;
}



template<class T>
double List<T>::sumPrice() {
    NodeL<T> *cursor = this->head;
    T tot; 
    double x = 0;
    while (cursor) {
        x = x + *(cursor->value); 
        cursor = cursor->next;
    }

    return x;
}

double operator+(double& x, Product& y) {
    return x + y.getPrice();
}


template<class H>
class BST{
    public:
    BST(){this->root = nullptr;}

    BST<H>* insert(H value);
    NodeB<H>* getRoot(){return this->root;}
    void inOrder(NodeB<H> *p);
    void preOrder(NodeB<H> *p);
    void postOrder(NodeB<H> *p);

    private:
    NodeB<H> *root;
};

template<class H>
BST<H>* BST<H>::insert(H value){
    NodeB<H> *newNode = new NodeB<H>;
    newNode->value = value;
    newNode->sx = nullptr;
    newNode->dx = nullptr;

    NodeB<H> *cursor = this->root;
    NodeB<H>* prec = nullptr;

    while(cursor){
        prec = cursor;
        if(value < cursor->value) cursor = cursor->sx;
        else cursor = cursor->dx;
    }

    newNode->parent = prec;

    if(!prec) this->root = newNode;
    else if(value < prec->value) prec->sx = newNode;
    else prec->dx = newNode;
    return this;
}

bool operator<(List<Product*>& x, List<Product*>& y){
    return x.sumPrice() < y.sumPrice();
}

template<class H>
void BST<H>::inOrder(NodeB<H> *p){
    if(p){
        inOrder(p->sx);
        cout << *(p->value) << endl;
        inOrder(p->dx);
    }
}

ostream& operator<<(ostream& out, List<Product*>& x){
    while(!x.isEmpty()) x.remove()->print();
    return out;
}

int main(void){
    BST<List<Product*>*> *tree = new BST<List<Product*>*>();

    List<Product*> *list = new List<Product*>();
    Product *x = new Product("laptop", 100, 1004);
    Product *x1 = new Product("laptop", 101, 1005);
    Product *x2 = new Product("laptop", 102, 10000);
    Product *x3 = new Product("laptop", 103, 4004);
    Product *x4 = new Product("laptop", 104, 8004);

    list->insert(x)->insert(x1)->insert(x4)->insert(x3)->insert(x2);
    
    List<Product*> *list1 = new List<Product*>();
    Product *xa = new Product("lavatrice", 200, 2004);
    Product *xa1 = new Product("lavatrice", 201, 2005);
    Product *xa2 = new Product("lavatrice", 202, 20000);
    Product *xa3 = new Product("lavatrice", 203, 4004);
    Product *xa4 = new Product("lavatrice", 204, 8004);

    list1->insert(xa)->insert(xa1)->insert(xa4)->insert(xa3)->insert(xa2);


    List<Product*> *list2 = new List<Product*>();
    Product *xb = new Product("laptop", 300, 3004);
    Product *xb1 = new Product("laptop", 303, 3005);
    Product *xb2 = new Product("laptop", 302, 30000);
    Product *xb3 = new Product("laptop", 303, 4004);
    Product *xb4 = new Product("laptop", 304, 8004);

    list2->insert(xb)->insert(xb1)->insert(xb4)->insert(xb3)->insert(xb2);

    List<Product*> *list3 = new List<Product*>();
    Product *xc = new Product("laptop", 400, 4004);
    Product *xc1 = new Product("laptop", 404, 4005);
    Product *xc2 = new Product("laptop", 402, 40000);
    Product *xc3 = new Product("laptop", 403, 4004);
    Product *xc4 = new Product("laptop", 404, 8004);

    list3->insert(xc)->insert(xc1)->insert(xc4)->insert(xc3)->insert(xc2);


    List<Product*> *list4 = new List<Product*>();
    Product *xd = new Product("laptop", 500, 5004);
    Product *xd1 = new Product("laptop", 505, 5005);
    Product *xd2 = new Product("laptop", 502, 50000);
    Product *xd3 = new Product("laptop", 503, 4004);
    Product *xd4 = new Product("laptop", 504, 8004);

    list4->insert(xd)->insert(xd1)->insert(xd4)->insert(xd3)->insert(xd2);

    tree->insert(list1)->insert(list3)->insert(list2)->insert(list4)->insert(list);

    tree->inOrder(tree->getRoot());
}