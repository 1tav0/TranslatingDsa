#include <iostream>
using namespace std;
#include <memory>

//RAII for deleting memory hassle 
// Resource Acquistion In Inisialization
class Wrapper{
  private:
    int *mem;
  public:
    Wrapper(int* _mem){
      cout << "ctor\n";
      mem = _mem;
    }
    ~Wrapper(){
      cout << "dtor\n";
      //need to free bc its stored in the memory head 
      delete mem;
    }
};

/*Types of smart pointers*/
// 1. Shared ptr
// 2. unique ptr
// 3. auto ptr deprecated
// 4. weak ptr -special case of shared ptr

// 2. when to use it ? when a particular resource is owned exclusively by a particular object
// exclusivity - unique ptr
// 1. when to use it ? when one particular resource is shared between multiple objects
template <class T>
class UniquePtr{
  private:
    T *res; // resource

  public:
    UniquePtr(T *_res = NULL){
      res = _res;
      cout << "ctor\n";
    }
    UniquePtr(const UniquePtr<T> &ptr) = delete;
    UniquePtr& operator =(const UniquePtr<T> &ptr) = delete; //for compilation error when someone tries to use it again
    //move copy constructor
    UniquePtr(UniquePtr<T> &&ptr){
      res = ptr.res;
      ptr.res = NULL;
    }

    UniquePtr& operator =(UniquePtr<T>&& ptr){
      if(this != &ptr){ //if passing the same resource ptr aka pointing to same thing
        if(res){ //to reset the resource with something new
          delete res;
        }
        res = ptr.res;
        ptr.res = NULL;
      }

      return *this;
    }
    //returns a pointer of the data type we provide
    T* operator->(){
      return res;
    }
    //we return the reference of the value
    T& operator*(){
      return *res;
    }

    T* get(){
      return res;
    }

    void reset(T* newRes = NULL){
      if(res){
        delete res;
      }
      res = newRes;
    }

    ~UniquePtr(){
      cout << "dtor\n";
      if(res){
        delete res;
        res = NULL;
      }
    }
};

int main(){
    //both constructor and destructor will be called at moment of builiding object 
    //Wrapper obj(new int(10));

    //user define type for unique ptr
    UniquePtr<int> ptr1(new int(2));
    //UniquePtr<int> ptr2(ptr1); //compilation error copy constructor

    //UniquePtr<int> ptr3 = ptr1; //compilation error
    UniquePtr<int> ptr4(new int(500));
    //ptr4 = ptr3; //compilation error copy assignment operator
    
    //to transfer ownership
    //UniquePtr<int> ptr3 = std::move(ptr1);
    //ptr4 = std::move(ptr1);

    //to make use of -> and dereference * 
    //operator overloading
    //ptr1->fun();
    cout << *ptr1;
    ptr1.get();
    ptr1.reset(new int(30));
    //destructor



    return 0;
}