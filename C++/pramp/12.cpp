#include <vector>
using namespace std;

int findBusiestPeriod(vector<vector<int>> data) {
    int maxVisitors = 0;
    int currentVisitors = 0;
    int busiestTimestamp = 0;

    for (size_t i = 0; i < data.size(); ++i) {
        int timestamp = data[i][0];
        int visitors = data[i][1];
        bool entered = data[i][2] == 1;

        // Update current visitors count
        if (entered) {
            currentVisitors += visitors;
        } else {
            currentVisitors -= visitors;
        }

        // If this is the last data point or the next data point has a different timestamp
        if (i == data.size() - 1 || data[i + 1][0] != timestamp) {
            if (currentVisitors > maxVisitors) {
                maxVisitors = currentVisitors;
                busiestTimestamp = timestamp;
            }
        }
    }

    return busiestTimestamp;
}
