#include <iostream>
#include <vector>
using namespace std;
/************************Subsequences*************************/
class Solution{
public:
  /* ------------------------------------------------------------------- */
  //Recursion

  /* ------------------------------------------------------------------- */
  //Memoization


  /* ------------------------------------------------------------------- */
  //Tabulation


  /* ------------------------------------------------------------------- */
  //Space optimization
  bool helper(int n, int k, vector<int> &arr){
    vector<int> prev(k+1, false);
    vector<int> current(k+1, false);
    prev[0] = 0;
    current[0] = 0;
    if(arr[0] <= k) prev[arr[0]] = true;
    for(int ind=1; ind<n; ind++){
      for(int target=1; target<=k; target++){
        int notPick = prev[target];
        int pick = false;
        if(arr[ind] <= target){
          pick = prev[target-arr[ind]];
        }
        current[target] = notPick | pick;
      }
      prev = current;
    }
    return prev[k];
  }

  bool canPartition(vector<int> &arr, int n){
    int total = 0;
    for(int i=0; i<n; i++){
      total += arr[i];
    }
    if(total % 2) return false;
    int target = total/2;
    return helper(n, target, arr);
  }

};

ostream& operator<<(ostream& os, vector<int> arr){
  for(auto it: arr){
    os << it << " ";
  }
  return os;
}

int main(){
  vector<int> arr = {2, 3, 3, 3, 4, 5};
  cout << "The given array is: " << arr << endl;
  int n = arr.size();
  int k = 8;
  Solution obj;
  bool ans = obj.subsetSumToK4(n, k, arr);
  cout << "Does there exist a subset with sum equal to " << k << " in the array ? " << ans;
}
