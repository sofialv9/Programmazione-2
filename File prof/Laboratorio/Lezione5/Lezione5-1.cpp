#include <iostream>
#include "LList.h"

using namespace std;

template<class T> void print(LList<T>* list)
{
	LNode<T>* it= list->getTail();
	while (it != nullptr)
	{
		cout << it->getKey() << endl;
		it = it->getNext();
	}
}

int main()
{
	LNode<int>* n = new LNode<int>(3);	
	cout << n->getKey() << endl;
	n->setNext(new LNode<int>(9));
	cout << n->getNext()->getKey() << endl;
	n->removeNext();
	cout << ((n->getNext() == nullptr) ? "No next" : to_string(n->getNext()->getKey())) << endl;	
	cout << "Check List" << endl;
	LList<int>* list = new LList<int>();
	list->insertTail(new LNode<int>(3));
	list->insertHead(new LNode<int>(5));	
	list->insertHead(new LNode<int>(9));
	list->insertTail(new LNode<int>(1));
	cout << "Head: " << list->getHead()->getKey() << endl;
	cout << "Tail: " << list->getTail()->getKey() << endl;
	list->insertAfter(5, new LNode<int>(7));
	list->insertAfter(9, new LNode<int>(11));
	list->insertBefore(7, new LNode<int>(6));
	list->insertBefore(1, new LNode<int>(0));
	list->insertInOrder(new LNode<int>(-1));
	list->insertInOrder(new LNode<int>(12));
	list->insertInOrder(new LNode<int>(4));
	print(list);
	cout << "Pop: " << to_string(list->removeHead()->getKey()) << endl;
	cout << "Pop: " << to_string(list->removeHead()->getKey()) << endl;
	cout << "Pop tail: " << to_string(list->removeTail()->getKey()) << endl;
	cout << "Pop tail: " << to_string(list->removeTail()->getKey()) << endl;
	cout << "All elements" << endl;
	print(list);
	cout << "Head: " << ((list->getHead() == nullptr) ? "Null Head" : to_string(list->getHead()->getKey())) << endl;
	cout << "Tail: " << ((list->getTail() == nullptr) ? "Null Tail" : to_string(list->getTail()->getKey())) << endl;
	cout << "Pop: " << to_string(list->removeTail()->getKey()) << endl;
	cout << "Head: " << ((list->getHead() == nullptr) ? "Null Head" : to_string(list->getHead()->getKey())) << endl;
	cout << "Tail: " << ((list->getTail() == nullptr) ? "Null Tail" : to_string(list->getTail()->getKey())) << endl; 
	print(list);
	cout<<"Remove: " << list->remove(9)->getKey() << endl;
	cout << "Remove: " << list->remove(3)->getKey() << endl;
	cout << "Remove: " << list->remove(6)->getKey() << endl;
	cout << "Remove: " << list->remove(5)->getKey() << endl;
	cout << "Remove: " << list->remove(7)->getKey() << endl;
	cout << "Remove: " << list->remove(4)->getKey() << endl;
	cout << "Remove: 10" << endl;
	list->remove(10);
	cout << "Head: " << ((list->getHead() == nullptr) ? "Null Head" : to_string(list->getHead()->getKey())) << endl;
	cout << "Tail: " << ((list->getTail() == nullptr) ? "Null Tail" : to_string(list->getTail()->getKey())) << endl;
	print(list);
	return 0;
	
}