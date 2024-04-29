#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
  int missingNumber(vector<int> &a, int N){
    for(int i=1; i<=N; i++){
      bool flag = false;
      for(int j=0; j<N; j++){
        if(a[j]==i){
          flag = true;
          break;
        }
      }

      if(flag == false){
        return i;
      }
    }
  }

  int missingNumber1(vector<int> &a, int N){
    vector<int> hash(N+1, 0);
    for(int i=0; i<N-1; i++){
      hash[a[i]]++;
    }
    for(int i=1; i<=N; i++){
      if(hash[i]==0){
        return i;
      }
    }
    return -1;
  }

  int missingNumber2(vector<int> &a, int N){
    int totalSum = (N*(N+1))/2;
    int sum = 0;
    for(int i=0; i<N-1; i++){
      sum += a[i];
    }
    return totalSum - sum;
  }

  int missingNumber3(vector<int> &a, int N){
    int xor1 = 0, xor2 = 0;
    for(int i=0; i<N-1; i++){
      xor2 = xor2 ^ a[i];
      xor1 = xor1 ^ (i + 1);
    }
    xor1 = xor1 ^ N;
    return xor1 ^ xor2;
  }
};

ostream& operator<<(ostream& os, vector<int> arr){
  for(auto it: arr){
    os << it << " ";
  }
  return os;
}

int main(){
  vector<int> arr = { 1, 2, 3, 4, 6, 7, 8 };
  int n = 7;
  cout << "The array is: " << arr << endl;
  Solution obj;
  int ans = obj.missingNumber3(arr, n);
  cout << "The missing number in the array is: " << ans << endl;
}
