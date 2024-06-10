#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
/*
Given an array of integers arr, write a function absSort(arr), that sorts
the array according to the absolute values of the numbers in arr. If two
numbers have the same absolute value, sort them according to sign, where
the negative numbers come before the positive numbers.

input:  arr = [2, -7, -2, -2, 0]
output: [0, -2, -2, 2, -7]
*/
vector<int> absSort( const vector<int>& arr) {
  vector<int> list = arr;
    int n = list.size();
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (abs(list[j]) < abs(list[i])) {
                swap(list[j], list[i]);
            } else if (abs(list[j]) == abs(list[i]) && list[j] < list[i]) {
                swap(list[j], list[i]);
            }
        }
    }
    return list;
}

int main() {
    vector<int> arr = {1, 2, -5, -7, 4, 9};
    vector<int> sortedArr = absSort(arr);

    for (int num : sortedArr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
