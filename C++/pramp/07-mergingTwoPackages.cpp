#include <iostream>
#include <vector>
#include <map>

using namespace std;

vector<int> getIndicesOfItemWeights( const vector<int>& arr, int limit)
{
  int n = arr.size();
  vector<int> ans = {};
  /*
  for(int i=0; i<n; i++){
    for(int j=i+1; j<n; j++){
      int sum = arr[i] + arr[j];
      if(sum == limit && j < i){
        ans.push_back(i);
        ans.push_back(j);
        return ans;
      }
    }
  }
  return ans;
  */

  map<int, int> mpp;
  for(int i=0; i<n; i++){
    mpp[arr[i]] = i;
  }

  for(int i=0; i<n; i++){
    int num = arr[i];
    int rem = limit - num;
    if(mpp.find(rem) != mpp.end()){
      ans.push_back(mpp[rem]);
      ans.push_back(i);
    }

    // arr[i]
  }
  return ans;
}

int main() {
  const vector<int> arr = {4, 6, 10, 15, 16};
  int limit = 30;
  vector<int> ans = getIndicesOfItemWeights(arr, limit);
  for(auto it: ans){
    cout << it << " ";
  }
  return 0;
}

// https://leetcode.com/problems/two-sum/description/
