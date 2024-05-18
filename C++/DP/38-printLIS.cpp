#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution{
public:
  vector<int> printLIS(vector<int> arr, int n){
    vector<int> dp(n+1, 1);
    vector<int> hash(n);
    int maxi = 0;
    int lastIndex = 0;
    for(int ind=0; ind<n; ind++){
      hash[ind] = ind;
      for(int prev=0; prev<ind; prev++){
        if(arr[prev] < arr[ind] && 1 + dp[prev] > dp[ind]){
          dp[ind] = 1 + dp[prev];
          hash[ind] = prev;
        }
      }
      if(dp[ind] > maxi){
        maxi = dp[ind];
        lastIndex = ind;
      }
    }
    vector<int> temp;
    temp.push_back(arr[lastIndex]);
    while(lastIndex != hash[lastIndex]){
      lastIndex = hash[lastIndex];
      temp.push_back(arr[lastIndex]);
    }
    reverse(temp.begin(), temp.end());
    return temp;
  }
};

ostream& operator<<(ostream& os, vector<int> arr){
  for(auto it: arr){
    os << it << " ";
  }
  return os;
}

int main(){
  vector<int> arr = {5, 4, 11, 1, 16, 8};
  int n = arr.size();
  cout << "The array is " << arr << endl;
  Solution obj;
  vector<int> ans = obj.printLIS(arr, n);
  cout << "The LIS is " << ans << endl;
  return 0;
}
