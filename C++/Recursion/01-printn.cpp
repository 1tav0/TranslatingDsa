#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
  /*------------------------------------------------------------------------------------------------------------*/
  vector<int> helper1(int ind, int n, vector<int>& list){
    if(ind > n) return list;

    list.push_back(ind);
    return helper1(ind+1, n, list);
  }

  vector<int> printnInOrder(int n){
    vector<int> list;
    return helper1(1, n, list);
  }
  /*------------------------------------------------------------------------------------------------------------*/
  void helperr1(int ind, vector<int>& list){
    if(ind <= 0) return;

    helperr1(ind-1, list);
    list.push_back(ind);
  }

  vector<int> printnInOrderWithBacktracking(int n){
    vector<int> list;
    helperr1(n, list);
    return list;
  }
/*------------------------------------------------------------------------------------------------------------*/
  // vector<int> helper2(int ind, int n, vector<int> &list){
  //   if(ind > n) return list;
  //
  //   helper2(ind+1, n, list);
  //   list.push_back(ind);
  //   return list;
  // }
  // vector<int> printnInReverse(int n){
  //   vector<int> list;
  //   return helper2(1, n, list);
  // }
/*------------------------------------------------------------------------------------------------------------*/
  vector<int> helper2(int ind, vector<int> &list){
    if(ind <= 0) return list;

    list.push_back(ind);
    helper2(ind-1, list);
    return list;
  }
  vector<int> printnInReverse(int n){
    vector<int> list;
    return helper2(n, list);
  }
  /*------------------------------------------------------------------------------------------------------------*/
    void helperr2(int ind, int n, vector<int> &list){
      if(ind > n) return;

      helperr2(ind+1, n, list);
      list.push_back(ind);
    }
    vector<int> printnInReverseWithBacktracking(int n){
      vector<int> list;
      helperr2(1, n, list);
      return list;
    }
/*------------------------------------------------------------------------------------------------------------*/
  // void helper3(int ind, vector<string> &ans, string name, int n){
  //   if(ind == n) return;
  //
  //   ans.push_back(name);
  //   helper3(ind+1, ans, name, n);
  // }
  //
  // vector<string> printNamenTimes(string name, int n){
  //   vector<string> ans;
  //   helper3(0, ans, name, n);
  //   return ans;
  // }
/*------------------------------------------------------------------------------------------------------------*/
  vector<string> helper3(int ind, vector<string> &ans, string name, int n){
    if(ind == n) return ans;

    ans.push_back(name);
    return helper3(ind+1, ans, name, n);
  }

  vector<string> printNamenTimes(string name, int n){
    vector<string> ans;
    return helper3(0, ans, name, n);
  }
  /*------------------------------------------------------------------------------------------------------------*/

};

ostream& operator<<(ostream& os, vector<int> arr){
  for(auto it: arr){
    os << it << " ";
  }
  return os;
}


int main(){
  int n = 10;
  Solution obj;
  vector<int> inOrder = obj.printnInOrder(n);
  vector<int> inOrderWithBacktracking = obj.printnInOrderWithBacktracking(n);
  vector<int> inReverse = obj.printnInReverse(n);
  vector<int> inReverseWithBacktracking = obj.printnInReverseWithBacktracking(n);
  vector<string> names = obj.printNamenTimes("tavo", n);
  cout << "inOrder: " << inOrder << endl << endl;
  cout << "inOrder with backtracking: " << inOrderWithBacktracking << endl << endl;
  cout << "inReverse: " << inReverse << endl << endl;
  cout << "inReverse with backtracking: " << inReverseWithBacktracking << endl << endl;
  for(auto it: names){
    cout << it << " ";
  }
  cout << endl;
  return 0;
}
