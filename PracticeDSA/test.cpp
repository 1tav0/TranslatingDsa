//  Input = "abc"
// output = [], [a], [a,b], [a,b,c], [a,c], [b,c],[c]

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution{
public:
  void problem(int ind, string str, string& ans){
    if(ind == str.length()){
      cout << ans << " ";
      return;
    }

    ans = ans + str[ind];
    problem(ind + 1, str, ans);
    ans.pop_back(); // backtracking
    problem(ind + 1, str, ans);
  }

  vector<int> problem2(vector<int> arr, int target, int ind){
    vector<int> ds;
    if(target == 0){
      return ds;
    }

    if(arr[ind] == target){
      ds.push_back(ind);
      return ds;
    }

    if(arr[ind]>=target){
      ds.push_back(ind);
      problem2(arr, target - arr[ind], ind+1);
    }
    return {};
  }
};

ostream& operator<<(ostream& os, vector<int> ds){
  for(auto it: ds){
    os << it << " ";
  }
  return os;
}

int main(){
  // string str = "abc";
  // string ans = "";
  // Solution obj;
  // cout << "All possible subsequences: ";
  // obj.problem(0, str, ans);
  vector<int> arr = {1, 2, 3, 4, 5};
  int target = 3;
  Solution obj;
  vector<int> ans = obj.problem2(arr, target, 0);
  cout << "The Array is: " << arr << endl;
  cout << "The target: " << target << " is at indeces: " << ans;
}

// [1,2,3,4,5] target=6 output= 
//  [1,3]

                                   

                            