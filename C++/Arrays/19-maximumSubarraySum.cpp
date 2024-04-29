#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution{
public:
  //brute force add all possible subarrays
  //tc - O(n^3)
  long long maxSubarraySum1(vector<int> arr, int n){
    long long maxi = -1e9;
    for(int i=0; i<n; i++){
      for(int j=0; j<n; j++){
        long long sum = 0;
        for(int k=i; k<=j; k++){
          sum += arr[k];
        }
        maxi = max(maxi, sum);
      }
    }
    return maxi;
  }
  //better
  //tc - O(n^2)
  //sc-O(1)
  long long maxSubarraySum2(vector<int> arr, int n){
    long long maxi = -1e9;
    for(int i=0; i<n; i++){
      long long sum = 0;
      for(int j=i; j<n; j++){
        sum += arr[j];
        maxi = max(maxi, sum);
      }
    }
    return maxi;
  }
  //optimal ***************Kadane's Algorithm********************
  //tc - O(n)
  //sc-O(1)
  long long maxSubarraySum3(vector<int> arr, int n){
    long long maxi = 0;
    long long sum = 0;
    for(int i=0; i<n; i++){
      sum += arr[i];
      if(maxi < sum){
        maxi = sum;
      }
      if(sum < 0){
        sum = 0;
      }
    }
    if(maxi < 0) maxi = 0;

    return maxi;
  }


};

ostream& operator<<(ostream& os, vector<int> arr){
  for(auto it: arr){
    os << it << " ";
  }
  return os;
}

int main(){
  vector<int> arr = { 1, 2, 7, -4, 3, 2, -10, 9, 1 };
  int n = arr.size();
  cout << "The array is: " << arr << endl;
  Solution obj;
  long long maxSubarraySum = obj.maxSubarraySum3(arr, n);
  cout << "The maximum subarray sum is: " << maxSubarraySum << endl;
}
