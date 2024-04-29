#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
  int findSecondLargest(int n, vector<int> a){
      int largest = a[0];
      int slargest = -1;
      for(int i=1; i<n; i++){
        if(a[i] > largest){
          slargest = largest;
          largest = a[i];
        }else if(a[i]>slargest && a[i]<largest){
          slargest = a[i];
        }
      }
      return slargest;
  }

  int findSecondSmallest(int n, vector<int> a){
    int smallest = a[0];
    int ssmallest = 1e9;
    for(int i=1; i<n; i++){
      if(a[i] < smallest){
        ssmallest = smallest;
        smallest = a[i];
      }else if(a[i] <= ssmallest && a[i] != ssmallest){
        ssmallest = a[i];
      }
    }
    return ssmallest;
  }

  vector<int> getSecondOrderElements(int n, vector<int> a){
    int slargest = findSecondLargest(n, a);
    int ssmallest = findSecondSmallest(n, a);
    return {slargest, ssmallest};
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
  vector<int> arr = {1, 2, 3, 4, 5};
  cout << "The array is: " << arr << endl;
  Solution obj;
  vector<int> ans = obj.getSecondOrderElements(n, arr);
  cout << "The Second largest and Second smallest numbers in the array are: " << ans;
}
