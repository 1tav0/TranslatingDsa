#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
#include <vector>
#include <functional>
using namespace std::chrono_literals;

int main(){
  //declare variables and correspoding mutexes
  int count1 = 0;
  std::mutex count1Mutex;
  int count2 = 0;
  std::mutex count2Mutex;
  int total = 0;
  bool done = false;
  std::mutex doneMutex;

  //lamnda function to imcremet
  auto increment = [](int &counter, std::mutex &m, const char *desc)
  {
    for (int i = 0; i < 10; ++i)
    {
      //lock the mutex to ensure exclusive access to counter
      std::unique_lock<std::mutex> lock(m);
      ++counter;
      std::cout << desc << ": " << counter << '\n';
      lock.unlock();
      std::this_thread::sleep_for(10000ms);
    }
  };

  /*2 threads created*/
  //create two threads that will use the increment function for two counts
  std::thread t1(increment, std::ref(count1), std::ref(count1Mutex), "count1");
  std::thread t2(increment, std::ref(count2), std::ref(count2Mutex), "count2");


  /*1 thread created*/
  //thread to update total
  std::thread updateTotal([&]()
  {
    //lock the doneMutex and enter a loop while done is false
    while(!done){
      doneMutex.lock(); 

      //try to lock both count1Mutex & count2Mutex simultanously
      int result = std::try_lock(count1Mutex, count2Mutex);
      if(result == -1){
        //update total count and reset the counts
        total += count1 + count2;
        count1 = 0;
        count2 = 0;
        std::cout << "Total: " << total << std::endl;
        count1Mutex.unlock();
        count2Mutex.unlock();
      }
      std::this_thread::sleep_for(2000ms);
      doneMutex.unlock(); //unlock the doneMutex
    } 
  });

  //wait for 2 threads to join
  t1.join();
  t2.join();

  // lock the done mutex to change the flag value since we are finished and wait for the last thread to join
  doneMutex.lock();
  done = true;
  doneMutex.unlock();

  //now we wait for the last thread to join
  updateTotal.join();

  std::cout << "Done Processing\n"
            << "count1: " << count1 << '\n'
            << "count2: " << count2 << '\n';
}