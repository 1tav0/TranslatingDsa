#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
  int removeDuplicates(vector<int> &arr, int n){
    int prev = 0;
    for(int i=1; i<n; i++){
      if(arr[i] != arr[prev]){
        arr[prev+1] = arr[i];
        prev++;
      }
    }
    return prev+1;
  }
  vector<int> removeDuplicatesArray(vector<int> &arr, int n){
    int prev = 0;
    for(int i=1; i<n; i++){
      if(arr[i] != arr[prev]){
        arr[prev+1] = arr[i];
        prev++;
      }
    }
    return arr;
  }
};

ostream& operator<<(ostream& os, vector<int> arr){
  for(auto it: arr){
    os << it << " ";
  }
  return os;
}

int main(){
  int n = 5;
  vector<int> arr = {1, 2, 2, 2, 3};
  cout << "The array is: " << arr << endl;
  Solution obj;
  vector<int> newArray = obj.removeDuplicatesArray(arr, n);
  cout << "The new array is: " << newArray << endl;
  int ans = obj.removeDuplicates(arr, n);
  cout << "The new Array without duplicates is of size: " << ans;
}
