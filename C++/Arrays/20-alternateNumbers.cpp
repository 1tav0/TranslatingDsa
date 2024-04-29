#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution{
public:
  //brute force
  //tc - O(n) + O(n)
  //sc - O(n)
  vector<int> alternateNumbers1(vector<int> &arr){
    int n = arr.size();
    vector<int> pos;
    vector<int> neg;
    for(int i=0; i<n; i++){
      if(arr[i] >= 0){
        pos.push_back(arr[i]);
      }else{
        neg.push_back(arr[i]);
      }
    }
    for(int i = 0; i<n/2; i++){
      arr[2*i] = pos[i];
      arr[2*i+1] = neg[i];
    }
    return arr;
  }
  //optimal
  //tc - O(n)
  //sc - O(n)
  vector<int> alternateNumbers2(vector<int> &arr){
    int n = arr.size();
    int pos = 0;
    int neg = 1;
    vector<int> ans(n, 0);
    for(int i=0; i<n; i++){
      if(arr[i] > 0){
        ans[pos] = arr[i];
        pos+=2;
      }else{
        ans[neg] = arr[i];
        neg+=2;
      }
    }
    return ans;
  }
};

ostream& operator<<(ostream& os, vector<int> arr){
  for(auto it: arr){
    os << it << " ";
  }
  return os;
}

int main(){
  vector<int> arr = { 1, 2, -4, -5 };
  int n = arr.size();
  cout << "The array is: " << arr << endl;
  Solution obj;
  vector<int> ans = obj.alternateNumbers2(arr);
  cout << "The alteranating array is: " << ans << endl;
}
