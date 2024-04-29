#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution{
public:
  vector<int> sortedArray(vector<int> a, vector<int> b){
    // first approach get a set
    set<int> st;
    for(int i=0; i<a.size(); i++){
      st.insert(a[i]);
    }
    for(int j=0; j<b.size(); j++){
      st.insert(b[j]);
    }
    vector<int> ans;
    for(auto it: st){
      ans.push_back(it);
    }
    return ans;
  }

  vector<int> sortedArray1(vector<int> a, vector<int> b){
    vector<int> temp;
    int i = 0;
    int j = 0;
    while(i < a.size() && j < b.size()){
      if(a[i] < b[j]){
        if(temp.size() == 0 || temp.back() != a[i]){
          temp.push_back(a[i]);
        }
        i++;
      }else{
        if(temp.size() == 0 || temp.back() != b[j]){
          temp.push_back(b[j]);
        }
        j++;
      }
    }
    while(i<a.size()){
      if(temp.size()==0 || temp.back() != a[i]){
        temp.push_back(a[i]);
      }
      i++;
    }

    while(j<b.size()){
      if(temp.size() == 0 || temp.back() != b[j]){
        temp.push_back(b[j]);
      }
      j++;
    }
    return temp;
  }
};

ostream& operator<<(ostream& os, vector<int> arr){
  for(auto it: arr){
    os << it << " ";
  }
  return os;
}

int main(){
  vector<int> a = { 1, 2, 3, 4, 6 };
  vector<int> b = { 2, 3, 5 };
  Solution obj;
  cout << "Array a is: " << a << endl;
  cout << "Array b is: " << b << endl;
  vector<int> ans = obj.sortedArray(a, b);
  cout << "The merged array is: " << ans << endl;
}
