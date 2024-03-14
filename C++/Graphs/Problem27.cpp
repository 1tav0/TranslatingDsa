#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Solution{
public:
  int minimumEffort(vector<vector<int>>& heights){
    int n = heights.size();
    int m = heights[0].size();
    vector<vector<int>> dist(n, vector<int>(m, 1e9));
    priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
    dist[0][0] = 0;
    pq.push({0, {0, 0}});
    int delrow[] = {-1, 0, 1, 0};
    int delcol[] = {0, -1, 0, 1};
    while(!pq.empty()){
      int diff = pq.top().first;
      int row = pq.top().second.first;
      int col = pq.top().second.second;
      pq.pop();

      if(row==n-1 && col==m-1) return diff;
      for(int i=0; i<4; i++){
        int newr = delrow[i] + row;
        int newc = delcol[i] + col;
        if(newr>=0 && newr<n && newc>=0 && newc<m){
          int newEffort = max(abs(heights[row][col]-heights[newr][newc]), diff);
          if(newEffort < dist[newr][newc]){
            dist[newr][newc] = newEffort;
            pq.push({dist[newr][newc], {newr, newc}});
          }
        }
      }
    }
    return 0;
  }
};

ostream& operator<<(ostream& os, vector<vector<int>> heights){
  for(auto row: heights){
    for(auto val: row){
      os << val << " ";
    }
    os << endl;
  }
  return os;
}

int main(){
  vector<vector<int>> heights;
  int rows=0;
  int cols=0;
  cout << "Enter the number of rows: ";
  cin >> rows;
  cout << "Enter the number of cols: ";
  cin >> cols;

  for(int i=0; i<rows; i++){
    vector<int> newRow;
    for(int j=0; j<cols; j++){
      int val=0;
      cout << "Enter the value at (" << i << "," << j << "): ";
      cin >> val;
      newRow.push_back(val);
    }
    heights.push_back(newRow);
  }

  cout << "Heights is: " << endl << heights << endl;
  Solution obj;
  int maxMinEffort = obj.minimumEffort(heights);
  cout << "The maximum absolute difference is: " << maxMinEffort << endl;

  return 0;
}
