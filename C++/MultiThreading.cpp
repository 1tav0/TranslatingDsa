#include <iostream>
#include <thread>
using namespace std;
// void function1(){
//   for (int i = 0; i < 200; i++){
//     cout << "+";
//   }
// }
void function1(char symbol){
  for (int i = 0; i < 200; i++){
    cout << symbol;
  }
}
void function2(){
  for (int i = 0; i < 200; i++){
    cout << "-";
  }
}

int main(){
  // thread worker1(function1);
  // thread worker2(function2);
  thread worker1(function1, 'o');
  thread worker2(function2);

  // Wait for the threads to finish
  worker1.join();
  worker2.join();
  return 0;
}