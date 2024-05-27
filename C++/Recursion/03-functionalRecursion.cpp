#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution{
public:
/*----------------------------------------------With 2 Pointers-------------------------------------------------*/
  void helper1(int left, vector<int>& arr, int right){
    if(left >= right) return;

    swap(arr[left], arr[right]);
    helper1(left+1, arr, right-1);
  }

  vector<int>& reverseTheArray1(vector<int>& arr){
    int n = arr.size();
    helper1(0, arr, n-1);
    return arr;
  }

/*---------------------------------------------With One Pointer--------------------------------------------------*/
  void helper2(vector<int>& arr, int ind){
    int n = arr.size();
    if(ind > n/2) return;

    swap(arr[ind], arr[n-ind-1]);
    helper2(arr, ind+1);
  }

  vector<int>& reverseTheArray2(vector<int>& arr){
    int n = arr.size();
    helper2(arr, 0);
    return arr;
  }

  /*---------------------------------------------With two Pointer--------------------------------------------------*/
  bool helperr1(int i, string s, int j){
    if(i==j) return true;

    if(s[i] == s[j]){
      return helperr1(i+1, s, j-1);
    }

    return false;
  }

  bool isStringAPalindrome1(string s){
    int n = s.size();
    return helperr1(0, s, n-1);
  }

  /*---------------------------------------------With one Pointer--------------------------------------------------*/
  bool helperr2(int i, string s){
    int n = s.size();
    if(i>=n/2) return true;

    if(s[i] != s[n-i-1]){
      return false;
    }

    return helperr2(i+1, s);
  }

  bool isStringAPalindrome2(string s){
    return helperr2(0, s);
  }
};

ostream& operator<<(ostream& os, vector<int> arr){
  for(auto it: arr){
    os << it << " ";
  }
  return os;
}

int main(){
  vector<int> arr = {1,2,3,4,2};
  cout << "The array is: " << arr << endl;
  Solution obj;
  vector<int> reversedArray = obj.reverseTheArray2(arr);
  cout << "The reversed array is: " << reversedArray << endl;

  string s = "madam";
  bool flag = obj.isStringAPalindrome2(s);
  cout << "Is the string " << s << " a palindrome: " << flag << endl;
}
