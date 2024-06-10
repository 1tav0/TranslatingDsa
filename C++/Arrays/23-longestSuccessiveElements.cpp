#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
  // tc- O(N2)
  // sc - O(1)
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
      longest = max(longest, cnt);
    }
    return longest;
  }

// O(NlogN) + O(N) O(NlogN) for sorting the array. To find the longest sequence, we are using a loop that results in O(N).
// O(1), as we are not using any extra space to solve this problem.
  int longestSuccessiveElements2(vector<int> &arr){
    int n = arr.size();
    int lastSmaller = -1e9;
    int cnt = 0;
    int maxi = 0;
    sort(arr.begin(), arr.end());
    for(int i=0; i<n; i++){
      if(arr[i]-1 == lastSmaller){
        cnt++;
        lastSmaller = arr[i];
      }else if(arr[i] != lastSmaller){
        cnt = 1;
        lastSmaller = arr[i];
      }
      maxi = max(maxi, cnt);
    }
    return maxi;
  }

// tc - O(N) + O(2*N) ~ O(3*N)
// O(N) for inserting into the set
// for every starting element, we are finding the consecutive elements.
// Though we are using nested loops,
// the set will be traversed at most twice in the worst case.
// sc - O(N) for the set
// the logic here is to insert into a set to avoid duplicates then iterate throught the unordered_set
// we are trying to find the start of every number in the unordered_set
// if there is no prev element for the number we get from the unordered_set
// it is most likely a begining in which we can start cnt for consecutive one increasing by 1

  int longestSuccessiveElements2(vector<int> &arr){
    int n = arr.size();
    int maxi = 0;
    int cnt = 0;
    unordered_set<int> st;
    for(auto it: arr){
      st.insert(it);
    }
    for(auto it: st){
      if(st.find(it-1) == st.end()){ // if no previos of the element most likely a starting element
        cnt = 1;
        int num = it;
        while(st.find(num+1) != st.end()){ // to iterate and increment cnt
          cnt++;
          num++;
        }
        maxi = max(maxi, cnt);
      }
    }
    return maxi;
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
