#include <iostream>
#include <vector>

using namespace std;

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
