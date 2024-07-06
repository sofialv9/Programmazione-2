// Nodo con puntatore al nodo alla sua sinitra

template<class T> class LNode
{
 private:
	 LNode* left;
	 T key;
 public:
	LNode<T>() : left{ nullptr } {};
	LNode<T>(T key) : key{ key }, left{ nullptr } { };
	
	LNode<T>* getNext() const { return left; }
	T getKey() const { return key; }

	void setNext(LNode* left) { this->left = left; }	
	void setKey(T& key) { this->key = key; }

	LNode<T>* removeNext()
	{
		delete left;
		left = nullptr;
		return this;
	}

	LNode<T>* clearNext()
	{
		left = nullptr;
		return this;
	}
};