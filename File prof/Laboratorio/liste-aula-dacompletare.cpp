#include<iostream>
using namespace std;

template<class T> class Node 
{
private:
	T key;
	Node<T>* next;
public: 
	Node<T>() :  next { nullptr } {}
	Node<T>(T key) : key{ key }, next{ nullptr } {}
	~Node<T>() {}

	T getKey() const { return key; }
	Node<T>* getNext() const { return next; }
	void setKey(T key) { this->key = key;  }
	void setNext(Node<T>* next) { this->next = next; }

	friend ostream& operator<<(ostream& os, const Node<T>& node)
	{
		os << node.getKey();
		return os;
	}
};


template<class T> class LinkedList 
{
  private:
	  Node<T>* head;
	  Node<T>* tail;
	  size_t size;

  protected:
	  void setHead(Node<T>* node)
	  {
		  if (isEmpty())
		  {
			  head = node;
			  tail = node;
		  }
		  else
		  {
			  node->setNext(head);
			  head = node;
		  }
	  }

	  void setTail(Node<T>* node)
	  {
		  if (isEmpty())
		  {
			  head = node;
			  tail = node;
		  }
		  else
		  {
			  getTail()->setNext(node);
			  tail = node;
		  }
	  }

  public:
	  LinkedList<T>() : head{ nullptr }, tail{ nullptr }, size{ 0 } {};
	  LinkedList<T>(Node<T>* node) : head { node }, tail{ node }, size{ 1 }{};
	  LinkedList<T>(T key) : head { new Node<T>(key) }, tail{ head }, size{ 1 }{}

	  Node<T>* getHead() const { return head; }
	  Node<T>* getTail() const { return tail; }
	  size_t getSize() const { return size; }

	  bool isEmpty() const
	  {
		  return head == nullptr; //size == 0
	  }

	  LinkedList<T>* insertHead(Node<T>* node)
	  {
		  setHead(node);
		  return this;
	  }

	  LinkedList<T>* insertHead(T key)
	  {
		  return insertHead(new Node<T>(key));
	  }

	  LinkedList<T>* insertTail(Node<T>* node)
	  {
		  setTail(node);
		  return this;
	  }

	  LinkedList<T>* insertTail(T key)
	  {
		  return insertTail(new Node<T>(key));
	  }


	  Node<T>* deleteHead()  //LinkedList<T>* deleteHead(Node<T>** oldHead)
	  {
		  if (isEmpty())
			  return nullptr;
		  Node<T>* temp = head;
		  head = head->getNext();
		  if (head == nullptr)
			  tail = nullptr;

		  temp->setNext(nullptr);
		  return temp;
	  }

	  Node<T>* deleteTail()
	  {
		  if (isEmpty())
			  return nullptr;

		  Node<T>* it = head;
		  if (it->getNext() == nullptr)
		  {
			  head = tail = nullptr;
			  return it;
		  }
		  while (it->getNext() != getTail())
		  {             
			 it = it->getNext();
		  }

		  tail = it;
		  it = it->getNext();
		  tail->setNext(nullptr);
		  return it;
	  }

	  Node<T>* searchKey(T key)  //bool || Node<T>* 
	  {
		  Node<T>* it = head;
		  while (it != nullptr)
		  {
			  if (key == it->getKey())
				  break;
			  it = it->getNext();
		  }
		  return it;
	  }

	  friend ostream& operator<<(ostream& os, LinkedList<T>& list)
	  {
		  Node<T>* it = list.getHead();
		  while (it != nullptr)
		  {
			  os << *it << " ";
			  it = it->getNext();
		  }
		  return os;
	  }
};


template<class T> class Stack : protected LinkedList<T>
{
	using LinkedList<T>::LinkedList;

    public:
		Node<T>* pop()
		{
			return LinkedList<T>::deleteHead();
		}

		/*
		   insertHead restituisce un puntatore a LinkedList (classe base).
		   Noi vogliamo un riferimento alla classe derivata. Come possiamo fare?

		   --- Così non compila! ---
		*/
		Stack* push(Node<T>* node)
		{
		  return static_cast<Stack*>(this->insertHead(node));
		}

		
};


int main()
{
	Node<int>* node = new Node<int>(7);
	cout << *node << endl; //node->getKey()
	LinkedList<int>* list = new LinkedList<int>(node);

	list->insertHead(8)->insertTail(10)->insertTail(0)->insertHead(1);
	cout << "Head: " << *list->getHead() << endl;
	cout << "Tail: " << *list->getTail() << endl;
	cout <<"Lista 1: "<< *list << endl;

	Node<int>* searchKey = list->searchKey(909);
	cout <<  ((searchKey==nullptr) ? "Chiave non presente" : to_string(searchKey->getKey())  ) << endl;

	cout << *list->deleteTail() << endl; //potenzialmente unsafe
	cout << *list->deleteTail() << endl;
	cout << *list->deleteTail() << endl;
	cout << *list->deleteTail() << endl;
	cout << *list->deleteTail() << endl;
	Node<int>* temp = list->deleteTail();
	/*if (temp == nullptr)
		cout << "Lista vuota" << endl;
	else
		cout << *temp << endl;*/

	cout << ((temp == nullptr) ? "Lista vuota" : " *temp") << endl;

	//list->insertHead(new Node<int>(5));
	LinkedList<int>* listKey = new LinkedList<int>(10);
	Node<int>* searchList = listKey->searchKey(9);
	if (searchList == nullptr)
		cout << "Assunzione (cerchiamo un elemento in una lista con un solo elemento) errata " << endl;
	else
		cout << "Assunzione corretta" << endl;


	Stack<int>* stack = new Stack<int>();
	stack->push(new Node<int>(17));
	cout << stack->pop()->getKey() << endl;

	return 0;
}