#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
  bool isTrue(vector<int> &arr, int num){
    int n = arr.size();
    for(int i=0; i<n; i++){
      if(arr[i] == num){
        return true;
      }
    }
    return false;
  }
  int longestSuccessiveElements1(vector<int> &arr){
    int n = arr.size();
    int longest = 1;
    int cnt = 0;
    for(int i=0; i<n; i++){
      int num = arr[i];
      cnt = 1;
      while(isTrue(arr, num+1)){
        num += 1;
        cnt++;
      }
      longest = cnt;
    }
    return longest;
  }
};

ostream& operator<<(ostream& os, vector<int> arr){
  for(auto it: arr){
    os << it << " ";
  }
  return os;
}

int main(){
  vector<int> arr = { 5, 8, 3, 2, 1, 4 };
  int n = arr.size();
  cout << "The array is: " << arr << endl;
  Solution obj;
  int ans = obj.longestSuccessiveElements(arr);
  cout << "The longest successive elements in the array are: " << ans;
  return 0;
}
