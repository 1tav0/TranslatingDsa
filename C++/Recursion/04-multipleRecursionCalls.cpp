#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
  /*-----------------------------------------------Fibonacci----------------------------------------------------*/
  // 1 1 2 3 5 8 13 21 ...

  int helper1(int ind){
    if(ind <= 1){
      return ind;
    }

    return helper1(ind-1) + helper1(ind-2);
  }

  int Fibonacci(int n){
    return helper1(n);
  }

};

int main(){
  int n = 3;
  Solution obj;
  cout << "The fibonacci sum from 0 - " << n << " is: " << obj.Fibonacci(n) << endl;

  return 0;
}
