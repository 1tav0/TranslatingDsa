#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution{
public:
  //brute
  //tc - O(nlogn)
  //sc  O(n)
  void sortArray1(vector<int> &arr, int n){
    sort(arr.begin(), arr.end());
  }
  //better
  //tc - O(2(n))
  //sc  O(1)
  void sortArray2(vector<int> &arr, int n){
    int cnt0=0, cnt1=0, cnt2=0;
    for(int i=0; i<n; i++){
      if(arr[i] == 0){
        cnt0++;
      }else if(arr[i] == 1){
        cnt1++;
      }else{
        cnt2++;
      }
    }
    for(int i=0; i<cnt0; i++){
      arr[i] = 0;
    }
    for(int i=cnt0; i<cnt0+cnt1; i++){
      arr[i] = 1;
    }
    for(int i=cnt0+cnt1; i<n; i++){
      arr[i] = 2;
    }
  }
  // Dutch flag
  //better
  //tc - O(n)
  //sc  O(1)
  void sortArray3(vector<int> &arr, int n){
    int low = 0, mid = 0, high = n-1;
    while(mid <= high){
      if(arr[mid] == 0){
        swap(arr[low], arr[mid]);
        low++, mid++;
      }else if(arr[mid] == 1){
        mid++;
      }else{
        swap(arr[mid], arr[high]);
        high--;
      }
    }
  }
};

ostream& operator<<(ostream& os, vector<int> arr){
  for(auto it: arr){
    os << it << " ";
  }
  return os;
}

int main(){
  vector<int> arr = { 2, 2, 2, 2, 0, 0, 1, 0 };
  int n = 8;
  cout << "The array is: " << arr << endl;
  Solution obj;
  obj.sortArray2(arr, n);
  cout << "The sorted array is: " << arr << endl;
}
