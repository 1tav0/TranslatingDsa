#include <iostream>
#include <vector>

using namespace std;
/*
Given two sorted arrays arr1 and arr2 of passport numbers, implement a
function findDuplicates that returns an array of all passport numbers
that are both in arr1 and arr2. Note that the output array should be
sorted in an ascending order.

Let N and M be the lengths of arr1 and arr2, respectively. Solve for two
cases and analyze the time & space complexities of your
solutions: M ≈ N - the array lengths are approximately the same M ≫ N - arr2
is much bigger than arr1.

input:  arr1 = [1, 2, 3, 5, 6, 7], arr2 = [3, 6, 7, 8, 20]

output: [3, 6, 7] # since only these three values are both in arr1 and arr2
*/
int helper(int target, vector<int> arr2){
  int low = 0;
  int m = arr2.size();
  int high = m-1;
  vector<int> ans;
  while(low <= high){
    int mid = low+(high-low)/2;
    if(arr2[mid] == target){
      return mid;
    }else if(arr2[mid] < target){
      low = mid+1;
    }else{
      high = mid-1;
    }
  }
  return -1;
}

vector<int> findDuplicates( const vector<int>& arr1, const vector<int>& arr2)
{
  int n = arr1.size();
  int m = arr2.size();

  int target = 0;
  vector<int> ans;
  for(int i=0; i<n; i++){
    target = arr1[i];
    int mid = helper(target, arr2);
    if(mid != -1){
      ans.push_back(target);
    }
  }
  return ans;
}

int main() {
  const vector<int> arr1 = {1, 2, 3, 5, 6, 7};
  const vector<int> arr2 = {3, 6, 7, 8, 20};
  vector<int> ans = findDuplicates(arr1, arr2);

  for(auto it: ans){
    cout << it << " ";
  }
  return 0;
}

/*
1, 2, 3, 5, 6, 7,.........., 555,....666,.....,777

3, 6, 7, 8, 20, 777

3, 6, 7


*/

 /*
  int i = 0;
  int j = 0;
  vector<int> ans;
  while(i<n && j<n){
    if(arr1[i] < arr2[j]){
      i++;
    }else if(arr1[i] > arr2[j]){
      j++;
    }else{
      ans.push_back(arr1[i]);
      i++, j++;
    }
  }
  return ans;
  */
