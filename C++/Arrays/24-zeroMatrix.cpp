#include <bits/stdc++.h>
using namespace std;


// Brute force
// tc - O((N*M)*(N + M)) + O(N*M), where N = no. of rows in the matrix
// and M = no. of columns in the matrix.
// Reason: Firstly, we are traversing the matrix to find the cells
//with the value 0. It takes O(N*M). Now, whenever we find any such
// cell we mark that row and column with -1. This process takes O(N+M).
// So, combining this the whole process, finding and marking,
//takes O((N*M)*(N + M)).
//Another O(N*M) is taken to mark all the cells with -1 as 0 finally.
// sc - O(1)

vector<vector<int>> zeroMatrix(vector<vector<int>> &matrix, int n, int m) {
}

int main()
{
    vector<vector<int>> matrix = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> ans = zeroMatrix(matrix, n, m);

    cout << "The Final matrix is: n";
    for (auto it : ans) {
        for (auto ele : it) {
            cout << ele << " ";
        }
        cout << "n";
    }
    return 0;
}
