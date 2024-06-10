#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
using namespace std;
/*
Given an array arr of unique nonnegative integers, implement a function
getDifferentNumber that finds the smallest nonnegative integer that is
NOT in the array.

Even if your programming language of choice doesn’t have that restriction
(like Python), assume that the maximum value an integer can have is
MAX_INT = 2^31-1. So, for instance, the operation MAX_INT + 1 would be
undefined in our case.

Your algorithm should be efficient, both from a time and a space complexity
perspectives.

Solve first for the case when you’re NOT allowed to modify the input arr.
If successful and still have time, see if you can come up with an algorithm
with an improved space complexity when modifying arr is allowed. Do so
without trading off the time complexity.

input:  arr = [0, 1, 2, 3]

output: 4 
*/
int getDifferentNumber( const vector<int>& arr )
{
  int n =  arr.size();
  unordered_map<int,int> mpp;
  for(int i=0; i<n; i++){
    mpp[arr[i]]++;
  }
  for(int i=0; i<=n; i++){ // incorrect
    if(!(mpp[i] != 0)){
      return i;
    }
    // if (mpp[i] == 0) {
    //   return i;
    // }
  }
  return -1;
}

int main() {
  const vector<int> arr = {0,5,4,6,3};
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
