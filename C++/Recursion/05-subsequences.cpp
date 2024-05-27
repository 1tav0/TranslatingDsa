#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
/*----------------------------------------Subsequences----------------------------------------------------------*/
// a contigous/non-contigous sequence which maintains the order it is in the array
// [3,1,2] ---->  [3],[1],[2],[3,1],[1,2],[3,2],[3,1,2],[]
  void helper1(int ind, vector<int> arr, vector<vector<int>> &ds, int n, vector<int> &temp){
    if(ind == n){
      ds.push_back(temp);
      return;
    }
    // pick
    temp.push_back(arr[ind]);
    helper1(ind+1, arr, ds, n, temp);
    temp.pop_back();
    // notPick
    helper1(ind+1, arr, ds, n, temp);

  }

  vector<vector<int>> Subsequences(vector<int> arr){
    int n = arr.size();
    vector<vector<int>> ds;
    vector<int> temp = {};
    helper1(0, arr, ds, n, temp);
    return ds;
  }
};

ostream& operator<<(ostream& os, vector<vector<int>> arr){
  int n = arr.size();
  for(int i=0; i<n; i++){
    for(int j=0; j<arr[i].size(); j++){
      os << arr[i][j] << " ";
    }
    os << endl;
  }
  return os;
}

int main(){
  vector<int> arr = {3, 1, 2};
  Solution obj;
  vector<vector<int>> subquences = obj.Subsequences(arr);
  cout << "The Subsequences are: " << endl <<  subquences << endl;
  return 0;
}
