#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

//gives us a mutex error
// void driveCar(string driverName){
//   cout << endl << driverName << " is driving" << endl;
//   this_thread::sleep_for(chrono::seconds(2));
//   cout << endl << driverName << " is done driving" << endl;
// }

// unique_lock needs to be unlocked manually 
// we can defer/delay locking in our application
// we can use the carLock object of unique_lock to lock or unlock our code multiple times during the lifetime of the object.
//  mutex carMutex;
//  void driveCar(string driverName){
//    unique_lock<mutex> carLock(carMutex);
//    cout << driverName << " is driving" << endl;
//    this_thread::sleep_for(chrono::seconds(2));
//    cout << driverName << " is done driving" << endl;
//    carLock.unlock();
//  }

//shorter way to lock
//locks the critical section at the same line where u create it & will unlock the code automatically when the object (carLock) goes out of scope at the end of block or the end of the function
//1st cannot be unlocked manually since it is automatic
//2nd benefit: since it is unlocking automatically it always makes sure to release the mutex and your code is available for the next thread 
mutex carMutex;
void driveCar(string driverName){
  lock_guard<mutex> carLock(carMutex);
  cout << driverName << " is driving" << endl;
  this_thread::sleep_for(chrono::seconds(2));
  cout << driverName << " is done driving" << endl;
}

int main(){
  thread t1(driveCar, "tavo");
  thread t2(driveCar, "joe");

  //make sure the threads end before closing the program
  t1.join();
  t2.join();

  return 0;
}