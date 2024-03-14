#include <iostream>
using namespace std;

class Square{
  private:
    int x;
  public:
    Square(int _x) : x(_x){}
    virtual ~Square(){}
    int getX() const { return x; }
    void setX(int _x) { x = _x; }
    virtual void print() const { cout << "Square" << endl; }
};

class Rectangle:public Square{
  private:
    int y;
  public:
    Rectangle(int _x, int _y) : Square(_x) { y = _y; }
    virtual ~Rectangle(){}
    int getY() const { return y; }
    void setY(int _y) { y = _y; }
    void print() const { cout << "Rectangle" << endl; }
};

class foo: public Square{
  public:
    //inheriting the constructor from the base class
    using Square::Square;
    virtual ~foo(){}
    void print() const { cout << "Foo" << endl; }
};

// void printf1(const Square& square){
//     cout << square.getX() << endl;
// }

void printf(const Square& square){
    square.print();
}
int main(){
    Square s(3);
    Rectangle r(2, 3);

    //printf1(s); //prints 3
    //printf1(r); //prints 2 //because of polymorphism a rectangle has a x side too and is a kind of square

    //printf(s); //prints print function from square class
    printf(r); //prints print function from square class too because it is a REDEFINED function and these type of functions are bound at compile time aka set in stone at compile time
    //to fix this we use the VIRTUAL KEYWORD  
    //This changes the STATIC BINDING to DYNAMIC BINDING overriding the function
    //The decision to run the function is now made at RUNTIME based on the object being passed to it only have to place the virtual key word in the base class 
    /**VIRTUAL = DYNAMIC BINDING = OVERRIDING**/
    /**STATIC BINDING = REDEFINING**/
    //to utilize dynamic binding & polymorphism we must use pass by reference or pointers


    //base class pointer to a child of the base class
    //it knows about the defined functions in the base class and any of the redefined/overrided functions in the DERIVED classes
    Square* sptr = &r;
    sptr->print(); 
    //below this wont work because this function inst redefined from the base class
    // cout << sptr->getY() << endl;

    //cannot make a pointer reference to the base class if you're a derived class 
    //this will not work
    // Rectangle *&rptr = &s;

    //we create an ARRAY OF SQUARE ptrs and we can store the memory address of all the derived classes and the base class because of POLYMORPHISM
    // new gets us the memory address
    Square* squares[] = {new Square(3), new Rectangle(1,2), new foo(4)};

    //need to DEREFERENCE HERE SINCE WE ARE POINTING AT THE ADDRESS IN THE ARRAY
    for(Square *it: squares){
      it->print();
    }

    //need to take care of the dynamic memory allocation
    for(Square *it: squares){
      delete it;
    }
}