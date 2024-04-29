#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution{
public:
  int getLongestSubarray(vector<int> &arr, int k){
    map<int,int> mpp;
    int n = arr.size();
    int sum = 0;
    int maxLength = 0;
    for(int i=0; i<n; i++){
      sum += arr[i];
      if(sum == k){
        maxLength = max(maxLength, i+1);
      }
      int rem = k - sum;
      if(mpp.find(rem) != mpp.end()){
        int len = i - mpp[rem];
        maxLength = max(maxLength, len);
      }
      if(mpp.find(sum) == mpp.end()){
        mpp[sum] = i;
      }
    }
    return maxLength;
  }
};

ostream& operator<<(ostream& os, vector<int> &arr){
  for(auto it: arr){
    os << it << " ";
  }
  return os;
}

int main(){
  int k = 4;
  vector<int> arr = {  1, 2, 1, 0, 1 };
  cout << "The array is: " << arr << endl;
  Solution obj;
  int ans = obj.getLongestSubarray(arr, k);
  cout << "The length of the longest subarray with sum " << k << " is: " << ans;
}
