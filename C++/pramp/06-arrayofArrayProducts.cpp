#include <iostream>
#include <vector>

using namespace std;
/*
Given an array of integers arr, you’re asked to calculate for each index i
the product of all integers except the integer at that index
(i.e. except arr[i]). Implement a function arrayOfArrayProducts that takes
an array of integers and returns an array of the products.

input:  arr = [8, 10, 2]
output: [20, 16, 80] # by calculating: [10*2, 8*2, 8*10]

input:  arr = [2, 7, 3, 4]
output: [84, 24, 56, 42] # by calculating: [7*3*4, 2*3*4, 2*7*4, 2*7*3]
*/
vector<long> arrayOfArrayProducts1(const vector<int>& arr)
{
  int n = arr.size();
  vector<long> res = {};

  if(arr.size() == 0 || arr.size() == 1){
    return res;
  }

  int product = 1;
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      if(i != j){
        product *= arr[j];
      }
    }
    res.push_back(product);
    product = 1;
  }

  return res;
}

vector<long> arrayOfArrayProducts2(const vector<int>& arr) {
    int n = arr.size();
    if (n == 0 || n == 1) {
        return {};
    }

    vector<long> prefix_products(n, 1);
    vector<long> suffix_products(n, 1);
    vector<long> res(n);

    // Fill prefix_products
    for (int i = 1; i < n; ++i) {
        prefix_products[i] = prefix_products[i - 1] * arr[i - 1];
    }

    // Fill suffix_products
    for (int i = n - 2; i >= 0; --i) {
        suffix_products[i] = suffix_products[i + 1] * arr[i + 1];
    }

    // Calculate result by multiplying prefix_products and suffix_products
    for (int i = 0; i < n; ++i) {
        res[i] = prefix_products[i] * suffix_products[i];
    }

    return res;
}


// vector<long> arrayOfArrayProducts(const vector<int>& arr)
// {
//   int n = arr.size();
//   vector<long> res = {};
//   vector<long> temp1 = {};
//   vector<long> temp2 = {};
//
//   int product = 1;
//   int left=-1, mid=0; right=0;
//   while(mid < n){
//     product *= arr[mid+1];
//     mid++;
//     left++;
//     right
//   }
//
// }


ostream& operator<<(ostream& os, vector<long> arr){
  for(auto it: arr){
    os << it << " ";
  }
  return os;
}

int main() {
  const vector<int> arr = {8, 10, 2};
  vector<long> ans = arrayOfArrayProducts1(arr);
  cout << ans;
  return 0;
}
