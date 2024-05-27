#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

double findGrantsCap(vector<int>& grantsArray, int newBudget) {
    int n = grantsArray.size();

    // Sort the array in descending order
    sort(grantsArray.rbegin(), grantsArray.rend());

    // Pad the array with a zero at the end
    grantsArray.push_back(0);

    // Calculate the surplus
    int totalSum = accumulate(grantsArray.begin(), grantsArray.end(), 0);
    int surplus = totalSum - newBudget;

    // If there's no surplus, return the highest grant
    if (surplus <= 0) {
        return grantsArray[0];
    }

    // Start subtracting the differences
    for (int i = 0; i < n; ++i) {
        surplus -= (i + 1) * (grantsArray[i] - grantsArray[i + 1]);
        if (surplus <= 0) {
            // Calculate the cap
            return grantsArray[i + 1] + (-surplus / static_cast<double>(i + 1));
        }
    }

    // In case all grants are within the budget without needing a cap
    return static_cast<double>(grantsArray.back());
}

int main() {
    vector<int> grantsArray = {2, 100, 50, 120, 1000};
    int newBudget = 190;
    double cap = findGrantsCap(grantsArray, newBudget);
    cout << "The cap is: " << cap << endl;
    return 0;
}
