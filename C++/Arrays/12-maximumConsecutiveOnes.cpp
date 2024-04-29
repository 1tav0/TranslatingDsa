#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
  int consecutiveOnes(vector<int> &arr){
    int n = arr.size();
    int cnt = 0;
    int maxi = -1e9;
    for(int i=0; i<n; i++){
      if(arr[i] == 1){
        cnt++;
        maxi = max(maxi, cnt);
      }else{
        cnt = 0;
      }
    }
    return maxi;
  }
};

ostream& operator<<(ostream& os, vector<int> &arr){
  for(auto it: arr){
    os << it << " ";
  }
  return os;
}

int main(){
  vector<int> arr = { 0, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1 };
  cout << "The array is: " << arr << endl;
  Solution obj;
  int ans = obj.consecutiveOnes(arr);
  cout << "The number of consecutive ones in the array is: " << ans;
}
