#include <iostream>
#include <vector>
using namespace std;

/*--------------------------------------LIS------------------------------------------------------*/
//  A Bitonic Sequence is a sequence of numbers that is first strictly increasing and then strictly decreasing.
// A strictly ascending order sequence is also considered bitonic,
// with the decreasing part as empty, and same for a strictly descending order sequence.
// For example, the sequences [1, 3, 5, 3, 2], [1, 2, 3, 4] are bitonic,
// whereas the sequences [5, 4, 1, 4, 5] and [1, 2, 2, 3] are not.
// You are given an array 'arr' consisting of 'n' positive integers.
// Find the length of the longest bitonic subsequence of 'arr'.
class Solution{
public:
  int longestBitonicSubsequence(vector<int>& arr, int n){
  	vector<int> dp1(n, 1);
  	for(int ind=0; ind<n; ind++){
  		for(int prev=0; prev<ind; prev++){
  			if(arr[prev]<arr[ind] && 1 + dp1[prev] > dp1[ind]){
  				dp1[ind] = 1 + dp1[prev];
  			}
  		}
  	}
  	vector<int> dp2(n, 1);
  	for(int ind=n-1; ind>=0; ind--){
  		for(int prev=n-1; prev>ind; prev--){
  			if(arr[prev]<arr[ind] && 1 + dp2[prev] > dp2[ind]){
  				dp2[ind] = 1 + dp2[prev];
  			}
  		}
  	}
  	int maxi = 0;
  	for(int i=0; i<n; i++){
  		maxi = max(maxi, dp1[i]+dp2[i]-1);
  	}
  	return maxi;
  }
};
