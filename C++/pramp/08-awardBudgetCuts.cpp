#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;
/*
The awards committee of your alma mater (i.e. your college/university) asked
for your assistance with a budget allocation problem they’re facing.
Originally, the committee planned to give N research grants this year.
However, due to spending cutbacks, the budget was reduced to newBudget
dollars and now they need to reallocate the grants. The committee made a
decision that they’d like to impact as few grant recipients as possible by
applying a maximum cap on all grants. Every grant initially planned to be
higher than cap will now be exactly cap dollars. Grants less or equal to cap,
obviously, won’t be impacted.

Given an array grantsArray of the original grants and the reduced budget
newBudget, write a function findGrantsCap that finds in the most efficient
manner a cap such that the least number of recipients is impacted and that
the new budget constraint is met (i.e. sum of the N reallocated grants equals
to newBudget).

input:  grantsArray = [2, 100, 50, 120, 1000], newBudget = 190

output: 47 # and given this cap the new grants array would be
           # [2, 47, 47, 47, 47]. Notice that the sum of the
           # new grants is indeed 190
*/
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
    int newBudget = 200;
    double cap = findGrantsCap(grantsArray, newBudget);
    cout << "The cap is: " << cap << endl;
    return 0;
}
