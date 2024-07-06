#include "manuscript.h"

// Classe Template
template <class T> class Shelf
{
private:
    T* objects; // array contenente gli oggetti
    int size; // numero di oggetti contenuti
    int capacity; // capacità massima
public:
    Shelf<T>(const int& capacity)
    { 
      this->capacity = capacity;
      this->size = 0;
      objects = new T[capacity];      
    }

    Shelf<T>() { objects = NULL; size = 0; }

    bool add(const T *element)
    {
        if (size <= capacity) // se il numero di oggetti non ha superato la capacità max
        {
            objects[size] = *element; // all'interno dell'array si inserisce un puntatore all'oggetto (cioè il suo indirizzo)
            size++;
            return true;
        }
        return false;
    }

    int getSize() const
    {
        return this->size;
    }

    int getCapacity() const
    {
        return this->capacity;
    }

    T* getElement(const int& pos)
    {
        if (pos <= capacity)
            return &(this->objects[pos]);
        return NULL;
    }

    // funzione definita nel main
    void print();
};


template<class T> void Shelf<T> :: print()
{
  for(int i=0; i<this->getCapacity(); i++)
      cout<< *(this->getElement(i)) << endl;
}