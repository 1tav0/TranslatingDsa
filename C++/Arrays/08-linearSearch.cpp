#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
  int linearSearch(int n, int num, vector<int>& arr){
    for(int i=0; i<n; i++){
      if(arr[i] == num){
        return 1;
      }
    }
    return 0;
  }
};

ostream& operator<<(ostream& os, vector<int> arr){
  for(auto it: arr){
    os << it << " ";
  }
  return os;
}

int main(){
  vector<int> arr = { 6,7,8,4,1 };
  int n = 5;
  int num = 10;
  Solution obj;
  cout << "The array is: " << arr << "is " << num << " there? " << obj.linearSearch(n, num, arr);
}
