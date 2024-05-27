#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using namespace std;

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
