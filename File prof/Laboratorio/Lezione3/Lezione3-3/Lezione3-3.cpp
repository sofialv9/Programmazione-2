#include <iostream>

using namespace std;

class MyClass
{
private:
    static int counter;
public:
    MyClass() 
    {
        counter++; // increases the value of counter when a new object is created
    }

    static void setCounter(int c)
    {
      counter=c;
    }

    static int getCounter() 
    {
        return counter;
    }

    void doSomething()
    {
        cout << "Nice thing to do" << endl;
    }
};

int MyClass::counter = 0;

int main()
{    
    MyClass ob1, ob2, ob3; //three objects are created
    cout << "Number of objects: " << MyClass::getCounter()<<endl;
    MyClass::setCounter(0);
    cout << "Number of objects: " << MyClass::getCounter() << endl;
    ob1.doSomething();
}