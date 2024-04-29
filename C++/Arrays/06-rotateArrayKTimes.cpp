#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
  vector<int> rotateArrayKTimes(vector<int> arr, int k){
    vector<int> temp;
    int n = arr.size();
    k = k % n;
    // copy the first part of the array in a temp array
    for(int i=0; i<k; i++){
      temp.push_back(arr[i]);
    }
    // manipulate the original Array
    for(int i=k; i<n; i++){
      arr[i-k] = arr[i];
    }
    // merge the temp and original array
    for(int i=n-k; i<n; i++){
      arr[i] = temp[i-(n-k)];
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
  vector<int> arr = { 5, 6, 7, 8 };
  int k = 3;
  cout << "The array is: " << arr << endl;
  Solution obj;
  vector<int> ans = obj.rotateArrayKTimes(arr, k);
  cout << "The new array rotated " << k << " times is: " << ans << endl;
}
