#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
/*-----------------------------------------------Parameterised---------------------------------------------------*/
  int helper1(int ind, int n, int sum){
    if(ind > n){
      return sum;
    }
    return helper1(ind+1, n, sum+ind);
  }
  int sumOfn1(int n){
    return helper1(0, n, 0);
  }

  int helper2(int ind, int sum){
    if(ind < 0){
      return sum;
    }
    return helper2(ind-1, sum+ind);
  }
  int sumOfn2(int n){
    return helper2(n, 0);
  }
/*-----------------------------------------------------Functional------------------------------------------------*/
// n = 3 :-->: 3 + f(2) -> 2 + f(1) -> 1 + f(0)=0 then return

int helper3(int ind){
  if(ind == 0){
    return 0;
  }
  return ind + helper3(ind-1);
}
int sumOfn3(int n){
  return helper3(n);
}
/*-----------------------------------------------------Functional------------------------------------------------*/

int helper4(int ind){
  if(ind == 1) return 1;

  return ind * helper4(ind-1);
}

int factorialOfN(int n){
  return helper4(n);
}
};

int main(){
  int n = 4;
  Solution obj;
  int sum = obj.sumOfn3(n);
  int factorial = obj.factorialOfN(n);
  cout << "The sum from 0-"<< n <<" is: " << sum << endl;
  cout << "The factorial of " << n << " is: " << factorial << endl;
}
