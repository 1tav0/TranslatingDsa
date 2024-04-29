#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution{
public:
  //brute
//tc - O(n^2)
//sc - O(1)
  int getSingleElement(vector<int> &arr){
    int n = arr.size();
    for(int i=0; i<n; i++){
      int num = arr[i];
      int cnt = 0;
      for(int j=0; j<n; j++){
        if(arr[j] == num){
          cnt++;
        }
      }
      if(cnt == 1) return num;
    }
    return -1;
  }
  //better
  //tc - O(nlogm)+O(n/2+1) m=n/2+1
  //sc - O(n/2+1)
  int getSingleElement1(vector<int> &arr){
    int n = arr.size();
    map<int,int> mpp;
    //hash the given array
    for(int i=0; i<n; i++){
      mpp[arr[i]]++;
    }
    //find the single element and return answer
    for(auto it: mpp){
      if(it.second == 1){
        return it.first;
      }
    }
    return -1;
  }
  //optimal
  //tc - O(n)
  //sc - O(1)
  int getSingleElement2(vector<int> &arr){
    int n = arr.size();
    int xor1 = 0;
    for(int i=0; i<n; i++){
      xor1 = xor1 ^ arr[i];
    }
    return xor1;
  }
};

ostream& operator<<(ostream& os, vector<int> &arr){
  for(auto it: arr){
    os << it << " ";
  }
  return os;
}

int main(){
  vector<int> arr = { 1, 1, 2, 3, 3, 4, 4 };
  cout << "The array is: " << arr << endl;
  Solution obj;
  int ans = obj.getSingleElement2(arr);
  cout << "The single element in the array is: " << ans;
}
