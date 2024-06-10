#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// class Solution{
// public:
//   int minimumMultiplication(vector<int>& arr, int start, int end){
//     vector<int> dist(100000, 1e9);
//     queue<pair<int,int>> q;
//     dist[start] = 0;
//     q.push({start, 0});
//     int mod = 100000;
//     while(!q.empty()){
//       int node = q.front().first;
//       int steps = q.front().second;
//       q.pop();
//
//       if(node == end) return steps;
//
//       for(auto it: arr){
//         int num = (it*node)%mod;
//         if(steps+1<dist[num]){
//           dist[num] = steps + 1;
//           q.push({num, dist[num]});
//         }
//       }
//     }
//     return -1;
//   }
// };
class Solution {
public:
    int minimumMultiplication(vector<int>& arr, int start, int end) {
        vector<int> dist(100000, 1e9);
        vector<int> parent(100000, -1); // To keep track of the parent of each node
        queue<int> q;
        dist[start] = 0;
        q.push(start);
        int mod = 100000;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            if (node == end) break; // Terminate the loop if we reach the end node

            for (auto it : arr) {
                int num = (it * node) % mod;
                if (dist[num] == 1e9) { // If the distance to this node is not calculated yet
                    dist[num] = dist[node] + 1;
                    parent[num] = node; // Update the parent of this node
                    q.push(num);
                }
            }
        }

        // Print the steps
        int currentNode = end;
        vector<pair<int, int>> steps;
        while (currentNode != start) {
            int parentNode = parent[currentNode];
            int step = (currentNode / parentNode)%mod;
            steps.push_back({parentNode, step});
            currentNode = parentNode;
        }

        // Print the steps in reverse order
        int n = steps.size()
        for (int i = steps.size() - 1; i >= 0; i--) {
            cout << "Step " << steps.size() - i << ": ";
            cout << steps[i].first << "*" << steps[i].second << " = ";
            cout << (steps[i].first * steps[i].second) % mod << " % " << mod << " = ";
            cout << (steps[i].first * steps[i].second) % mod << endl;
        }

        return dist[end];
    }
};

ostream& operator<<(ostream& os, vector<int> arr){
  for(auto val: arr){
    os << val << " ";
  }
  return os;
}

int main(){
  vector<int> arr;
  int size = 0;
  cout << "Enter the size of the array: ";
  cin >> size;
  for(int i=0; i<size; i++){
    int val;
    cout << "Enter the value at arr[" << i << "] for array: ";
    cin >> val;
    arr.push_back(val);
  }

  cout << "The list is: " << arr << endl;
  int start=0;
  cout << "Enter the start node: ";
  cin >> start;
  int end=0;
  cout << "Enter the end node: ";
  cin >> end;
  Solution obj;
  int ans = obj.minimumMultiplication(arr, start, end);
  cout << "The minimun steps to go from " << start << " to " << end << " is " << ans;

  return 0;
}
