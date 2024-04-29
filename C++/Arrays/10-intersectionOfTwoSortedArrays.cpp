
#include <iostream>
#include <vector>
using namespace std;

class Solution{
	public:
		vector<int> findArrayIntersection(vector<int> &arr1, int n, vector<int> &arr2, int m){
			int i = 0;
			int j = 0;
			vector<int> temp;
			while(i < n && j < m){
				if(arr1[i] < arr2[j]){
					i++;
				}else if(arr2[j] < arr1[i]){
					j++;
				}else{
					temp.push_back(arr1[i]);
					i++, j++;
				}
			}
			return temp;
		}

		vector<int> findArrayIntersection1(vector<int> &arr1, int n, vector<int> &arr2, int m){
			vector<int> vis(m, 0);
			vector<int> temp;
			for(int i=0; i<n; i++){
				for(int j=0; j<m; j++){
					if(arr1[i] == arr2[j] && !vis[j]){
						temp.push_back(arr1[i]);
						vis[j] = 1;
						break;
					}
					if(arr1[i] < arr2[j]) break;
				}
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
	vector<int> arr1 = { 1, 2, 2, 2, 3, 4};
	int n = 6, m = 4;
	vector<int> arr2 = { 2, 2, 3, 3};
	Solution obj;
	cout << "Array 1: " << arr1 << endl;
	cout << "Array 2: " << arr2 << endl;
	vector<int> ans = obj.findArrayIntersection1(arr1, n, arr2, m);
	cout << "The intersection of the two sorted arrays: " << ans << endl;
}
