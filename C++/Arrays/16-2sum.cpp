#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

class Solution{
public:
  //brute
  //tc ~ O(n^2)
  string read(int n, vector<int> book, int target){
    for(int i=0; i<n; i++){
      for(int j=0; j<n; j++){
        int sum = book[i] + book[j];
        if(sum == target){
          return "Yes";
        }
      }
    }
    return "No";
  }
  //better
  //tc ~ O(nlogn)
  //sc - O(n)
  string read1(int n, vector<int> book, int target){
    map<int, int> mpp;
    for(int i=0; i<n; i++){
      int num = book[i];
      int rem = target - num;
      if(mpp.find(rem) != mpp.end()){
        return "Yes"; // return {mpp[rem], i};
      }
      mpp[num] = i;
    }
    return "No";
  }
  //optimal
  //tc ~ O(n)
  //sc - O(n)+O(n) for sorting
  string read2(int n, vector<int> book, int target){
    sort(book.begin(), book.end());
    int left = 0;
    int right = n-1;
    while(left <= right){
      int sum = book[left] + book[right];
      if(sum > target){
        right--;
      }else if(sum < target){
        left++;
      }else{
        return "Yes";
      }
    }
    return "No";
  }

};

ostream& operator<<(ostream& os, vector<int> arr){
  for(auto it: arr){
    os << it << " ";
  }
  return os;
}

int main(){
  int n = 5;
  int target = 5;
  vector<int> book = { 4, 1, 2, 3, 1 };
  cout << "The book pages are: " << book << endl;
  Solution obj;
  string ans = obj.read2(5, book, target);
  cout << "Can sam read " << target << " pages? " << ans;
  return 0;
}
