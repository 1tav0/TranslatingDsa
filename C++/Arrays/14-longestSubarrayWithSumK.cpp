#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution{
public:
  //brute force
  //tc ~ O(n^3)
  int longestSubarrayWithSumK(vector<int> a, long long k){
    int n = a.size();
    int len = 0;
    for(int i=0; i<n; i++){
      for(int j=i; j<n; j++){
        long long sum = 0;
        for(int p=i; p<=j; p++){
          sum += a[p];
        }
        if(sum == k){
          len = max(len, j-i+1);
        }
      }
    }
    return len;
  }
  //better
  //tc ~ O(nxlongn) or(nx1) unordered map worst case O(nxn)
  //sc O(n)
  int longestSubarrayWithSumK1(vector<int> a, long long k){
    map<long long, int> mpp;
    long long sum = 0;
    int maxLength = 0;
    int n = a.size();
    for(int i=0; i<n; i++){
      sum += a[i];
      if(sum == k){
        maxLength = max(maxLength, i+1);
      }
      long long rem = sum - k;
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
  //optimal
  //tc ~ O(2n)
  //sc O(1)
  int longestSubarrayWithSumK2(vector<int> a, long long k){
    int left = 0, right = 0;
    long long sum = a[0];
    int maxLength = 0;
    int n = a.size();
    while(right<n){
        while(left <= right && sum > k){
            sum -= a[left];
            left++;
        }
        if(sum == k){
            maxLength = max(maxLength, right-left+1);
        }
        right++;
        if(right<n) sum += a[right];
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
  vector<int> arr = { 1, 2, 3, 1, 1, 1, 1 };
  int target = 4;
  cout << "The array is: " << arr << endl;
  Solution obj;
  int ans = obj.longestSubarrayWithSumK1(arr, target);
  cout << "The longest subarray with sum " << target << " has: " << ans << " elements";
}
