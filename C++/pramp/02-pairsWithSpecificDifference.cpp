#include <iostream>
#include <vector>

using namespace std;
/*
Given an array arr of distinct integers and a nonnegative integer k,
write a function findPairsWithGivenDifference that returns an array of
all pairs [x,y] in arr, such that x - y = k. If no such pairs exist,
return an empty array.

Note: the order of the pairs in the output array should maintain the order
of the y element in the original array.

input:  arr = [0, -1, -2, 2, 1], k = 1
output: [[1, 0], [0, -1], [-1, -2], [2, 1]]

input:  arr = [1, 7, 5, 3, 32, 17, 12], k = 17
output: []

*/
vector<vector<int>> findPairsWithGivenDifference( const vector<int>& arr, int k)
{
  int n = arr.size();
  vector<vector<int>> ans;
  for(int i=0; i<n; i++){
    int y = arr[i];
    for(int j=0; j<n; j++){
      //if(arr[i] - arr[j] == k){
        //temp.push_back(arr[i]);
        //temp.push_back(arr[j]);
      //}
      if(arr[j] == k + y){
        int x = arr[j];
        //temp.push_back(x);
        //temp.push_back(y);
        ans.push_back({x,y});
      }

    }
    //ans.push_back(temp);
    //temp.pop_back();
    //temp.pop_back();
  }
  return ans;
}

int main() {
  const vector<int> arr = {0, -1, -2, 2, 1};
  int k = 1;

  vector<vector<int>> ans = findPairsWithGivenDifference(arr, k);
  int n = ans.size();
  for(int i=0; i<n; i++){
    for(int j=0; j<ans[i].size(); j++){
      cout << ans[i][j] << " ";
    }
  }
  return 0;
}

/*
let y = arr[i], i being the primary idx
x - arr[i] = k => x = k + arr[i]
*/
//[0, -1, -2, 2, 1] k=1                 ans[]
// i    j
// arr[0] - arr[1] == k
// arr[1] - arr[0] == k
// 0 - -1 == 1
// 0 - 0 == -1
