#include <iostream>
#include <vector>

using namespace std;

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
