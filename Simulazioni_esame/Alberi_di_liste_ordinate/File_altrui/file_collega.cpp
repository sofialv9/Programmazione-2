#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

class Product {
    public:
        Product() : id(""), name(""), category(""), price(0) {}
        Product(std::string id, std::string name, std::string category, size_t price) : 
            id(id), name(name), category(category), price(price) {}
        Product(const Product& other) {
            this->id = other.getId();
            this->name = other.getName();
            this->category = other.getCategory();
            this->price = other.getPrice();
        }

        void setId(std::string newId) { this->id = newId; }
        void setName(std::string newName) { this->name = newName; }
        void setCategory(std::string newCategory) { this->category = newCategory; }
        void setPrice(size_t newPrice) { this->price = newPrice; }

        std::string getId() const { return this->id; }
        std::string getName() const { return this->name; }
        std::string getCategory() const { return this->category; }
        size_t getPrice() const { return this->price; }

        std::string toString() const {
            std::stringstream ss;
            ss << this->id << ": " << this->name << " " << this->category << " " << this->price;
            
            return ss.str();
        }

        bool operator>(const Product& other) { return this->price > other.getPrice(); }
        bool operator>=(const Product& other) { return this->price >= other.getPrice(); }
        bool operator<(const Product& other) { return this->price < other.getPrice(); }
        bool operator<=(const Product& other) { return this->price <= other.getPrice(); }

        friend std::ostream& operator<<(std::ostream& os, const Product& p) {
            os << p.toString();
            return os;
        }

        friend std::istream& operator>>(std::istream& is, Product& p) {
            is >> p.id >> p.name >> p.category >> p.price;
            return is;
        }

    private:
        std::string id;
        std::string name;
        std::string category;
        size_t price;
};

class List;
class BST;

class ListNode {
    public:
        ListNode(Product product) : product(product), next(nullptr) {} 
        
    private:
        ListNode* next;
        Product product;

    friend class List;
};

class List {
    public:     
        List() : root(nullptr), price(0), category("") {}
        ~List() {
            ListNode* curr = this->root;
            while(curr != nullptr) {
                ListNode* temp = curr;
                curr = curr->next;
                delete temp;
            }   
        }
        
        bool isEmpty() const { return this->root == nullptr; }

        void insert(Product p) {
            if(this->isEmpty()) {
                ListNode* newNode = new ListNode(p);
                if(not newNode) throw std::bad_alloc();

                this->root = newNode;
                this->price = p.getPrice();
                this->category = p.getCategory();
            }
            else if(this->category == p.getCategory() and this->price == p.getPrice()) {
                ListNode* newNode = new ListNode(p);
                if(not newNode) throw std::bad_alloc();

                bool inserted = false;
                ListNode* curr = this->root;
                ListNode* prev = nullptr;

                while(curr != nullptr and not inserted) {
                    prev = curr;

                    if(curr->product.getId() > p.getId()) {
                        this->insertAfter(curr, newNode);
                        inserted = true;
                    }

                    curr = curr->next;
                }

                if(not inserted) prev->next = newNode;
            }
        }

        size_t getPrice() const { return this->price; }
        std::string getCategory() const { return this->category; }

        std::string toString() const {
            std::stringstream ss;

            ss << this->category << " " << this->price << ": " << std::endl;
            this->loadSStream(ss);

            return ss.str();
        }

        friend std::ostream& operator<<(std::ostream& os, const List& l) {
            os << l.toString();
            return os;
        }

    private:
        ListNode* root;
        size_t price;
        std::string category;

        /* this method works only if key and new node are not nullptr, so assert it before*/
        void insertAfter(ListNode* key, ListNode* newNode) {
            ListNode* keyNext = key->next;
            key->next = newNode;
            newNode->next = keyNext;
        }

        void loadSStream(std::stringstream& ss) const {
            if(this->isEmpty()) ss << "Empty list";
            else {
                for(ListNode* temp = this->root; temp != nullptr; temp = temp->next) {
                    ss << temp->product << " ";
                }
            }
        }
};

class BSTNode {
    public:
        BSTNode() : products(nullptr), left(nullptr), right(nullptr) {}

        void addProduct(Product& p) {
            if(not this->products) {
                this->products = new List();
                if(not this->products) throw std::bad_alloc();
            }
            
            this->products->insert(p);
        }

        void addList(List* l) { this->products = l; }
        
    private:    
        List* products;
        BSTNode* left;
        BSTNode* right;

    friend class BST;
};

class BST {
    public:
        BST() : root(nullptr) {}

        void insert(Product& p) {
            BSTNode* curr = this->root;
            BSTNode* prev = nullptr;

            bool inserted = false;
            while(curr != nullptr and not inserted) {
                prev = curr;
                if(p.getPrice() == curr->products->getPrice() and p.getCategory() == curr->products->getCategory()) {
                    curr->addProduct(p);
                    inserted = true;
                }
                else if(p.getPrice() > curr->products->getPrice()) curr = curr->right;
                else curr = curr->left;
            }

            
            if(not inserted) {
                // if the tree is empty
                BSTNode* newNode = new BSTNode();
                if(not newNode) throw std::bad_alloc();

                newNode->addProduct(p);

                if(prev == nullptr) {
                    this->root = newNode;
                }
                else if(newNode->products->getPrice() > prev->products->getPrice()) prev->right = newNode;
                else prev->left = newNode;
            }
        }

        std::string inOrderToString() const {
            std::stringstream ss;
            ss << "TREE: " << "\n\n";

            this->inOrderSStreamLoad(ss, this->root);

            return ss.str();
        }

        friend std::ostream& operator<<(std::ostream& os, const BST& b) {
            os << b.inOrderToString();
            return os;
        }

    private:
        BSTNode* root;

        void inOrderSStreamLoad(std::stringstream& ss, BSTNode* node) const {
            if(node) {
                this->inOrderSStreamLoad(ss, node->left);
                ss << "- " << *(node->products) << std::endl;
                this->inOrderSStreamLoad(ss, node->right);
            }
        }

};

void readTreeFromFile(BST& tree, std::string fileName) {
    std::ifstream f(fileName, std::ios::in);
    if(not f.is_open()) throw std::runtime_error("No such file");

    std::string line;
    while(getline(f, line)) {
        std::stringstream lineStream(line);
        Product p;
        
        lineStream >> p;

        tree.insert(p);    
    }
}
    

int main() {
    BST tree;
    readTreeFromFile(tree, "input.txt");

    std::cout << tree.inOrderToString() << std::endl;

    return 0;
}