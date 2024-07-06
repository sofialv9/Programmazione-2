#include"LNode.h"
using namespace std;

//lista al contrario (coda a sinistra e testa a destra)
template<class T> class LList
{
private:
	LNode<T>* head;
	LNode<T>* tail;
public:
	LList<T>(LNode<T>* head) : head{ head }, tail{ head } {}
	LList<T>() : head{ nullptr }, tail{ nullptr } {}
	LNode<T>* getHead() const { return head; }
	LNode<T>* getTail() const { return tail; }
	size_t getSize() const
	{		
		size_t num = 0;
		LNode<T>* it = getTail();
		while (it != nullptr)
		{
			num++;			
			it = it->getNext();
		}
		return num;
	}
	
	bool isEmpty() const
	{
		return this->getSize() == 0;
	}

	// si inserisce il nodo dopo la testa corrente
	LList* insertHead(LNode<T>* node)
	{
		if (head != nullptr)		
			head->setNext(node);
		else
			tail = node;
		head = node;		
		return this;		
	}

	// si inserisce il nodo prima della coda corrente
	LList* insertTail(LNode<T>* node)
	{
		if (tail != nullptr)
			node->setNext(tail);
		else
		    head = node;
		tail = node;
		return this;
	}

	LList<T>* insertAfter(const T& key, LNode<T>* node)
	{
		// se la lista è vuota
		if (tail == nullptr)
		{
			insertTail(node);
			return this;
		}

		LNode<T>* it = tail;
		while (it != nullptr)
		{
			if (key == it->getKey())
			{				
				node->setNext(it->getNext());
				it->setNext(node);
				if(node->getNext() == nullptr)// more safe then if (it == head)
				   head = node;	
				break;
			}
			it = it->getNext();
		}
		return this;
	}

	LList<T>* insertBefore(const T& key, LNode<T>* node)
	{		
		if (tail == nullptr)
		{			
			insertTail(node);
			return this;
		}
		LNode<T>* prev = nullptr;
		LNode<T>* it = tail;		
		while (it != nullptr)
		{
			if (key == it->getKey())
			{				
				if (prev == nullptr)
				{					
					node->setNext(tail);
					tail = node;
				}
				else
				{					
					prev->setNext(node);
					node->setNext(it);
				}
				break;
			}
			prev = it;
			it = it->getNext();			
		}
		return this;
	}

	LList<T>* insertInOrder(LNode<T>* node)
	{
		if (tail == nullptr)
		{
			insertTail(node);
			return this;
		}
		LNode<T>* prev = nullptr;
		LNode<T>* it = tail;
		while (it != nullptr)
		{
			if (node->getKey() <= it->getKey())
			{
				if (prev == nullptr)
				{
					node->setNext(tail);
					tail = node;
				}
				else
				{
					prev->setNext(node);
					node->setNext(it);
				}
				break;
			}
			prev = it;
			it = it->getNext();
		}
		if (it == nullptr) // il nodo da inserire è più grande di tutti quelli già nella lista
			insertHead(node);
		return this;
	}

	LNode<T>* removeHead()
	{
		LNode<T>* tmp = head;
		if (tmp != nullptr)
		{
			LNode<T>* it = tail;
			LNode<T>* prev = nullptr;
			while (it != nullptr)
			{
				if (it->getNext() == nullptr)
				{
					head = prev;					
					if (prev == nullptr)					
						 tail = nullptr;		
					else
						head->clearNext();
					break;
				}
				prev = it;
				it = it->getNext();
			}
		}
		tmp->clearNext();
		return tmp;
	}

	LNode<T>* removeTail()
	{
		LNode<T>* tmp = tail;
		if (tail != nullptr)
		{
			if (tail->getNext() == nullptr)
			{
				tail = head = nullptr;
			}
			else
				tail = tail->getNext();
			tmp->clearNext();
		}
		return tmp;
	}

	LNode<T>* remove(const T& key)
	{
		if (tail == nullptr)
			return nullptr;	
		LNode<T>* prev = nullptr;
		LNode<T>* it = tail;
		while (it != nullptr)
		{
			if (it->getKey() == key)
			{
				if (prev == nullptr) //tail
				{
					if (it->getNext() != nullptr)
					{
						tail = it->getNext();
					}
					else
					{
						tail = head = nullptr;
					}
				}
				else
				{
					prev->setNext(it->getNext());
					if (it->getNext() == nullptr)
						head = prev;
				}
				break;
			}
			prev = it;
			it = it->getNext();
		}
		if(it != nullptr)
		   it->clearNext();
		return it;		
	}

};