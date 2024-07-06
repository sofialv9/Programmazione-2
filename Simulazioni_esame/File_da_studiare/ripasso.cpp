class ListNode
{
public:
    ListNode(int _data) : data(_data), next(nullptr) {}
    int getData() {return data;}
    ListNode* getNext() {return next;}

private:
    int data;
    ListNode* next;
};

class List
{
public:
    List() : head(nullptr), tail(nullptr) {}
    ~List()
    {
        ListNode* tmp = head;
        while(tmp)
        {
            ListNode* next = tmp->getNext();
            delete tmp;
            tmp = next;
        }
    }

    bool isEmpty() {return head == nullptr;}

    const ListNode* getHead() const {return head;}

    void InsertTail(int data)
    {
        ListNode* newNode = new ListNode(data);
        if(tail != nullptr)
            tail = tail->getNext();
        tail = newNode;
        if(head == nullptr)
            head = tail;
    }

    int removeHead()
    {
        if(isEmpty())
            return -1;
        ListNode* tmp = head;
        head = head->getNext();
        if(!head)
            tail = nullptr;
        int out = tmp->getData();
        delete tmp;
        return out;
    }

private:
    ListNode* head;
    ListNode* tail;
};

class Queue : public List
{
public:
    void enqueue(int n) {InsertTail(n);}
    int dequeue() {return removeHead();}
    bool isEmpty() {return List::isEmpty();}
};

class Graph
{
public:
    Graph(int _n) : n(_n) {adj = new List[n];}
    ~Graph() {delete [] adj;}
    Graph& addEdge(int u, int v) {adj[u].InsertTail(v); adj[v].InsertTail(u); return *this;}
    int getN() const {return n;}
    const List& getAdj(int v) const {return adj[v];}

    void PrintShortestPath(int s, int v)
    {
        color = new color_t[n];
        d = new int[n];
        pred = new int[n];

        BFS(s);
        cout << "Il cammino minimo tra " << s << " e " << v << " è lungo " << d[v] << " ed è il seguente: ";
        PrintPath(cout, s, v);
        cout << endl;

        delete [] color;
        delete [] d;
        delete [] pred;
    }

private:
    int n;
    List* adj;

    enum color_t {white, gray, black};
    color_t* color;
    int* d;
    int* pred;

    void BFS(int s)
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
        q.enqueue(s);
        while(!q.isEmpty())
        {
            int u = q.dequeue();
            ListNode* p = adj[u].getHead();
            while(p != nullptr)
            {
                int v = p->getData();
                if(color[v] == white)
                {
                    color[v] = gray;
                    d[v] = d[u] + 1;
                    pred[v] = u;
                }
                p = p->getNext();
            }
            color[u] = black;
        }
    }

    void PrintPath(ostream& os, int s, int v)
    {
        if(s == v)
            os << s << " ";
        if(pred[v] = -1)
            os << "Nessun path da " << s << " a " << v;
        else
        {
            PrintPath(os, s, pred[v]);
            os << v << " ";
        }
           
    }
};

template<class T>
class BST;

template<class T>
class BSTNode
{
public:
    BSTNode(T _data) : data(_data), right(nullptr), left(nullptr), parent(nullptr) {}
    T getData() const {return data;}

private:
    T data;
    BSTNode* right;
    BSTNode* left;
    BSTNode* parent;

    friend class BST<T>;
};

template<class T>
class BST
{
public:
    BST() : root(nullptr) {}
    ~BST() {Delete(root);}
    void Delete(BSTNode* p)
    {
        if(p != nullptr)
        {
            Delete(p->left);
            Delete(p->right);
            delete p;
        }
    }

    BST<T>& Insert(T val)
    {
        BSTNode<T>* newNode = new BSTNode(val);
        BSTNode<T>* curr = root;
        BSTNode<T>* prev = nullptr;
        while(curr)
        {
            prev = curr;
            if(val < curr->getData())
                curr = curr->left;
            else
                curr = curr->right;
        }
        newNode->parent = prec;
        if(prev == nullptr)
        {
            root = newNode;
            return *this;
        }
        if(prev->getData() > val)
            prev->left = newNode;
        else
            prev->right = newNode;
        return *this;
    }

    void print(ostream& os, BSTNode<T>* node)
    {
        if(node != nullptr)
        {
            print(os, node->left);
            os << node->getData();
            print(os, node->right);
        }
        return os;
    }

    BSTNode<T>* Search(T key, BSTNode<T>* node)
    {
        if(node == nullptr || node->getData() == key)
            return node;
        else if(val < node->val)
            Search(key, node->left);
        else
            Search(key, node->right);
    }

    BSTNode<T>* Search(T key)
    {
        return Search(key, root);
    }

    BSTNode<T>* Min(BSTNode<T>* p)
    {
        if(p == nullptr)
            p = root;
        if(p == nullptr)
            return nullptr;
        while(p->left)
            p = p->left;
        return p;
    }

    BSTNode<T>* Next(BSTNode<T>* p)
    {
        if(p->right)
            return Min(p->right);
        else
        {
            BSTNode<T>* parent = p->parent;
            while(parent && p != parent->left)
            {
                p = parent;
                parent = p->parent;
            }
            return parent;
        }
    }

    BSTNode<T>* Trapianta(BSTNode<T>* dest, BSTNode<T>* src)
    {
        if(dest->parent == nullptr)
            root = src;
        else if(dest == dest->parent->right)
            dest->parent->right = src;
        else
            dest->parent->left = src;
        if(src != nullptr)
            src->parent = dest->parent;
        return dest;
    }

    void Remove(BSTNode<T>* p)
    {
        if(p->right == nullptr && p->left == nullptr)
        {
            if(p->parent = nullptr)
                root = nullptr;
            else if(p == p->parent->left)
                p->parent->left = nullptr;
            else
                p->parent->right = nullptr;
        }
        else if(p->right)
            Trapianta(p, p->right);
        else if(p->left)
            Trapianta(p, p->left);
        else
        {
            BSTNode<T>* next = Min(p->right);
            if(next->right)
            {
                Trapianta(next, next->right);
                next->right = p->right;
                p->right->parent = next;
            }
            Trapianta(p, next);
            next->left = p->left;
            p->left->parent = next;
        }
        delete p;
    }


private:
    BSTNode<T>* root;
}