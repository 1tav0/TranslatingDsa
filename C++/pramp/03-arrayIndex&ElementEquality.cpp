#include <iostream>
#include <vector>

using namespace std;
/*
Given a sorted array arr of distinct integers, write a function
indexEqualsValueSearch that returns the lowest index i for which arr[i] == i.
Return -1 if there is no such index. Analyze the time and space complexities
of your solution and explain its correctness.

input: arr = [-8,0,2,5]
output: 2 # since arr[2] == 2

input: arr = [-1,0,3,6]
output: -1 # since no index in arr satisfies arr[i] == i.
*/
int indexEqualsValueSearch(const vector<int>& arr) {
    int left = 0;
    int right = arr.size() - 1;
    int result = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == mid) {
            result = mid;  // Found a potential index where arr[i] == i
            right = mid - 1;  // Search for a potentially earlier match
        } else if (arr[mid] < mid) {
            left = mid + 1;  // Look for a match in the right half
        } else {
            right = mid - 1;  // Look for a match in the left half
        }
    }

    return result;
}

int main() {
    // Example usage:
    vector<int> arr1 = {-1, 0, 2, 3, 6, 7, 9};  // Expected output: 2
    vector<int> arr2 = {-1, 0, 1, 3, 6, 7, 9};  // Expected output: -1

    cout << "First array: " << indexEqualsValueSearch(arr1) << endl;
    cout << "Second array: " << indexEqualsValueSearch(arr2) << endl;

    return 0;
}
