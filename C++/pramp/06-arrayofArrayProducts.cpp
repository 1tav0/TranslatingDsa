#include <iostream>
#include <vector>

using namespace std;

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
