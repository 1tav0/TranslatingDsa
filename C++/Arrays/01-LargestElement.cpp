#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    int largest(vector<int>& arr, int n){
      int largest = arr[0];
      for(int i=1; i<n; i++){
        if(arr[i] > largest){
          largest = arr[i];
        }
      }
      return largest;
    }
};

ostream& operator<<(ostream& os, vector<int> &arr){
  for(auto it: arr){
    os << it << " ";
  }
  return os;
}

int main(){

  vector<int> arr = {4, 7, 8, 6, 7, 6 };
  cout << "The Original Array: " << arr << endl;
  Solution obj;
  cout << "The largest number in the array is: " << obj.largest(arr, arr.size());
}
