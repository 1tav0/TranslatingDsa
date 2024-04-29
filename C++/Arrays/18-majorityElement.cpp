#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution{
public:
  // brute
  // tc - O(n^2)
  // sc - O(c)
  int majorityElement(vector<int> arr){
    int n = arr.size();
    for(int i=0; i<n; i++){
      int cnt = 0;
      for(int j=0; j<n; j++){
        if(arr[i] == arr[j]){
          cnt++;
        }
      }
      if(cnt > n/2) return arr[i];
    }
    return -1;
  }
  // better
  //tc - O(nlogn)+O(n)
  //sc - O(n) for storing in the map worst case when array has only unique elements
  int majorityElement2(vector<int> arr){
    int n = arr.size();
    map<int,int> mpp;
    //nlogn
    for(int i=0; i<n; i++){
      mpp[arr[i]]++;
    }
    //n
    for(auto it: mpp){
      if(it.second > n/2){
        return it.first;
      }
    }
    return -1;
  }
  //optimal
  //tc - O(n)+ (O(n) if not majority element)
  //sc - O(1)
  int majorityElement3(vector<int> arr){
    int n = arr.size();
    int element;
    int cnt = 0;
    //n
    for(int i=0; i<n; i++){
      if(cnt == 0){
        cnt = 1;
        element = arr[i];
      }else if(arr[i] == element){
        cnt++;
      }else{
        cnt--;
      }
    }
    int val = 0;
    //n
    for(int i=0; i<n; i++){
      if(arr[i] == element){
        val++;
      }
    }
    if(val > n/2) return element;

    return -1;
  }
};

ostream& operator<<(ostream& os, vector<int> arr){
  for(auto it: arr){
    os << it << " ";
  }
  return os;
}

int main(){
  vector<int> arr = { 2, 2, 1, 3, 1, 1, 3, 1, 1 };
  cout << "The array is: " << arr << endl;
  Solution obj;
  int majorityElement = obj.majorityElement3(arr);
  cout << "The majority element in the array is: " << majorityElement << endl;
}
