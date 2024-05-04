#include <iostream>
#include <vector>
using namespace std;
/************************Subsequences*************************/
class Solution{
public:
  long long int helper(vector<long long int> &nums){
    long long int n = nums.size();
    long long int prev = nums[0];
    long long int prev2 = 0;
    for(long long int ind=1; ind<n; ind++){
      long long int pick = nums[ind];
      if(ind>1) pick += prev2;
      long long int notPick = 0 + prev;
      long long int current = max(pick, notPick);
      prev2 = prev;
      prev = current;
    }
    return prev;
  }

  long long int houseRobber(vector<int> &valueInHouse){
    vector<long long int> temp1;
    vector<long long int> temp2;
    int n = valueInHouse.size();
    if(n==1) return valueInHouse[0];
    for(int i=0; i<n; i++){
      if(i != 0) temp1.push_back(valueInHouse[i]);
      if(i != n-1) temp2.push_back(valueInHouse[i]);
    }
    return max(helper(temp1), helper(temp2));
  }
};

ostream& operator<<(ostream& os, vector<int> arr){
  for(auto it: arr){
    os << it << " ";
  }
  return os;
}

int main(){
  vector<int> arr = { 1, 3, 2, 1 };
  cout << "The given array is: " << arr << endl;
  Solution obj;
  long long int ans = obj.houseRobber(arr);
  cout << "The maximum amount of money Mr. X can rob tonight is: " << ans;
}
