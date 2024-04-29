#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution{
public:
  // brute
  vector<int> nextGreaterPermutation1(vector<int> &arr){
    next_permutation(arr.begin(), arr.end());
    return arr;
  }
  // optimal
  vector<int> nextGreaterPermutation2(vector<int> &arr){
    int ind = -1;
    int n = arr.size();
    for(int i=n-2; i>=0; i--){
      if(arr[i] < arr[i+1]){
        ind = i;
        break;
      }
    }
    if(ind == -1){
      reverse(arr.begin(), arr.end());
      return arr;
    }
    for(int i=n-1; i>=ind; i--){
      if(arr[i] > arr[ind]){
        swap(arr[i], arr[ind]);
        break;
      }
    }
    reverse(arr.begin()+ind+1, arr.end());
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
  vector<int> arr = { 2, 1, 3 };
  int n = arr.size();
  cout << "The array is: " << arr << endl;
  Solution obj;
  vector<int> ans = obj.nextGreaterPermutation2(arr);
  cout << "The next greater permutation in the array is: " << ans << endl;
}
