#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution{
public:
  //Brute force
  //tc - O(N^2)
  //sc - O(N)
  vector<int> superiorElements1(vector<int> &arr){
    int n = arr.size();
    vector<int> ans;
    for(int i=0; i<n; i++){
      bool flag = true;
      for(int j=i+1; j<n; j++){
        if(arr[i] <= arr[j]){
          flag = false;
          break;
        }
      }
      if(flag == true){
        ans.push_back(arr[i]);
      }
    }
    reverse(ans.begin(), ans.end());
    return ans;
  }
  // optimal
  //tc - O(N)
  //sc - O(N)
  vector<int> superiorElements2(vector<int> &arr){
    int n = arr.size();
    vector<int> ans;
    int maxi = -1e9;
    for(int i=n-1; i>=0; i--){
      if(arr[i] > maxi){
        ans.push_back(arr[i]);
      }
      maxi = max(maxi, arr[i]);
    }
    return ans;
  }
  // optimal
  //tc - O(N)
  //sc - O(N)
  vector<int> superiorElements3(vector<int> &arr){
    vector<int> ans;
    int n = arr.size();
    int maxi = -1e9;
    for(int i=n-1; i>=0; i--){
        if(arr[i] > maxi){
            maxi = arr[i];
            ans.push_back(arr[i]);
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
  vector<int> arr = { 1, 2, 2, 1 };
  int n = arr.size();
  cout << "The array is: " << arr << endl;
  Solution obj;
  vector<int> ans = obj.superiorElements2(arr);
  cout << "The superior elements in the array in ascending order are: " << ans << endl;
}
