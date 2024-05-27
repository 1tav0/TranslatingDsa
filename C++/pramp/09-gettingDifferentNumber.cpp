#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
using namespace std;

int getDifferentNumber( const vector<int>& arr )
{
  // your code goes here
  // 0 1 3
  // 0 -> 1
  // 1 -> 1
  // 3 -> 1
  int n =  arr.size();
  unordered_map<int,int> mpp;
  for(int i=0; i<n; i++){
    mpp[arr[i]]++;
  }
  /*
    i = 0
      map contains 0
    i = 1
       map contains 1
    i = 2
    i = 3

    i = 4
  */
  for(int i=0; i<=n; i++){ // incorrect
    if(!(mpp[i] != 0)){
      return i;
    }
  }
  return -1;
}

int main() {
  const vector<int> arr = {0, 1, 2, 3};
  int ans = getDifferentNumber(arr);
  cout << ans;
  return 0;
}

/*
arr = [0, 1, 2, 3] ans = 4

arr = [1,2,3] ans = 0

arr = [1,3,5] ans = 0

smallest = a[i];

for(0->n)

[0, 1 , 3]  ans = 2

int smallest = arr[0]; = 0
for(int val=0; val<n; val++){
  for(int i=0; i<n; i++){
    if(smallest == val){
    continue;
    }
  }
}

for(int i=0; i<=n; i++){
  xor1 = i ^ arr[i] 0 ^ 0,
}
return xor1

*/
