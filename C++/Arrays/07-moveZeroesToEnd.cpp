#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
  vector<int> moveZeros(int n, vector<int> arr){
    vector<int> temp;
    for(int i=0; i<=n; i++){
      if(arr[i] != 0){
        temp.push_back(arr[i]);
      }
    }
    int cnt = 0;
    for(int i=0; i<temp.size(); i++){
      arr[i] = temp[i];
      cnt++;
    }
    for(int i=cnt; i<=n; i++){
      arr[i] = 0;
    }
    return arr;
  }

  vector<int> moveZeros1(int n, vector<int> arr){
    int j = -1;
    for(int i=0; i<=n; i++){
      if(arr[i] == 0){
        j = i;
        break;
      }
    }

    if(j==-1) return arr;

    for(int i=j+1; i<=n; i++){
      if(arr[i] != 0){
        swap(arr[i], arr[j]);
        j++;
      }
    }
    return arr;
  }

};

ostream& operator<<(ostream& os, vector<int> arr){
  for(auto it: arr){
    os << it << " ";
  }
  return os;
}

int main(){
  vector<int> arr = { 1, 2, 0, 0, 2, 3 };
  int n = 5;
  cout << "The array is: " << arr << endl;
  Solution obj;
  vector<int> ans = obj.moveZeros1(n, arr);
  cout << "The new array is: " << ans << endl;
}
