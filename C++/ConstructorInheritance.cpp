#include <iostream>
using namespace std;

class Base{
  private:
    int x;
    int y;
  public:
    Base() { 
      x = 0; 
      y = 0;
      cout << "Base Constructor\n";
    }
    ~Base(){
      cout << "Base destructor\n";
    }
    //overloaded constructor
    Base(int _x, int _y){
      x = _x;
      y = _y;
    }

    void print(){
      cout << x << ", " << y << endl;
    }
};

// class Derived: public Base{
//   public: 
//     Derived(){
//       cout << "Derived Constructor\n";  
//     }
//     ~Derived(){
//       cout << "Derived Destructor\n";
//     }
// };

//invoking base classes constructor
// class Derived: public Base{
//   private:
//     int s;

//   public:
//     Derived(int q, int r, int _s) : Base(q, r) { s = _s; }
//     int getS() const{
//       return s;
//     }
// };

//another way
class Derived: public Base{
  private:
    using Base::Base; //inheriting the Base constructor

  public:
};
int main(){
    //to trigger the constructor 
    //base constructor then derived constructor
    //Base* ptr = new Derived;
    //derived destructor then base destructor
    //to trigger the destructor 
    //delete ptr;

    //invoking the base constructor from the derived class
    // Derived d(1,2,4);
    // d.print();

    // cout << d.getS() << "\n";

    //invoking inherited constructor from the derived class
    Derived d(1,2);
    d.print();


    return 0;
}