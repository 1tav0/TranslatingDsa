#include <iostream>
using namespace std;

//Concept: You cannot create an instance of an abstract base class, but you can create other classes that are derived from it.
//A pure virtual function is a virtual member function that belongs to a base class and needs to be redefined in derived classes
//When a class has a PURE virtual function as a member, it becomes an abstract base class

// base class and abstract - atleast 1 pure virtual function
// since this is an abstract base class then it cannot be instatiated it aka in main cannot make object fromt it
// Foo obj; will give an error
// They only exist to be derived from 
class Foo{
  public:
    virtual void print() const = 0;
};

//anything that "is a" Foo, must override this pure virtual function
class Bar: public Foo{
  public:
    virtual void print() const{
      cout << "I'm in Bar class" << endl;
    }
};

class Spam: public Foo{
  public:
    virtual void print() const{
      cout << "I'm in Spam class" << endl;
    }
};

//abstract base class, it inherits the pure virtual function from Foo
class Eggs: public Foo{
  public:
};

//here the Bacon derived class from Eggs inherits the pure virtual function and must redefine it for it to be used 
class Bacon: public Eggs{
  public:
    virtual void print() const{
      cout << "Im in bacon class" << endl;
    }
};

int main(){

    Bar b;
    b.print();

    Spam s;
    s.print();

    Bacon bn;
    bn.print();

    return 0;
}