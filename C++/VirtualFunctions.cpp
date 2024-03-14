#include <iostream>
using namespace std;
//*****VIRTUAL***** says if theres a nother function like me named in another derived class please execute the most derived version else execute me
//An ABSTRACT CLASS is a class that has at least ONE PURE VIRTUAL FUNCTION
// base class
class Instrument{
  public: 
    // virtual void makeSound(){
    //   cout << "Instrument sound...\n";
    // }
    /****PURE VIRTUAL function***/
    virtual void makeSound() = 0; // pure virtual function every class inherited and derived from this one will need to implement its own version of this function
};

//inheritance
//derived class
class Accordion:public Instrument{
  public:
    void makeSound(){
      cout << "Accordion sound...\n";
    }
};
class Trumpet:public Instrument{
  public:
    void makeSound(){
      cout << "Trumpet sound...\n";
    }
};
int main(){
  //most derived version will be accessed 
    Instrument* i1 = new Accordion();
    //i1->makeSound();
    Instrument* i2 = new Trumpet();
    //i2->makeSound();

    Instrument *instruments[2] = {i1, i2};
    for (int i = 0; i < 2; i++){
      instruments[i]->makeSound();
    }

      return 0;
}