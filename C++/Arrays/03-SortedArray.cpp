#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
  int isSorted(int n, vector<int> a){
    for(int i=1; i<n; i++){
      if(a[i] >= a[i-1]){
        continue;
      }else{
        return 0;
      }
    }
    return 1;
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
  vector<int> arr = {0, 0, 0, 1};
  cout << "The array is: " << arr << endl;
  Solution obj;
  cout << "Is the array sorted? " << obj.isSorted(n, arr);
}
