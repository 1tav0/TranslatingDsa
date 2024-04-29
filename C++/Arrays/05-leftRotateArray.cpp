#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
  vector<int> rotateArray(vector<int>& arr, int n){
    int temp = arr[0];
    for(int i=1; i<n; i++){
      arr[i-1] = arr[i];
    }
    arr[n-1] = temp;
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
  vector<int> arr = {1, 2, 3, 4, 5};
  int n = 5;
  cout << "The array is: " << arr << endl;
  Solution obj;
  vector<int> ans = obj.rotateArray(arr, n);
  cout << "The rotated array is: " << ans << endl;
}
