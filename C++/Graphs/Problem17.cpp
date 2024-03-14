#include <iostream>
#include <vector>
#include <queue>
using namespace std;
// Course Schedule II
class Solution{
public:
  vector<int> findOrder(int n, int m, vector<vector<int>> prerequisite){
    vector<int> adj[n];
    for(auto it: prerequisite){
      int u = it[0];
      int v = it[1];
      adj[v].push_back(u);
    }
    vector<int> inDegrees(n);
    for(int i=0; i<n; i++){
      for(auto it: adj[i]){
        inDegrees[it]++;
      }
    }
    queue<int> q;
    for(int i=0; i<n; i++){
      if(inDegrees[i]==0){
        q.push(i);
      }
    }
    vector<int> ans;
    while(!q.empty()){
      int node = q.front();
      q.pop();

      ans.push_back(node);
      for(auto it: adj[node]){
        inDegrees[it]--;
        if(inDegrees[it]==0){
          q.push(it);
        }
      }
    }
    if(ans.size()!=n) return {};

    return ans;
  }
};

ostream& operator<<(ostream& os, vector<int> ans){
  for(auto& it: ans){
    os << it << " ";
  }
  return os;
}

int main(){
  vector<vector<int>> prerequisite = {
    {1, 0},
    {2, 0},
    {3, 1},
    {3, 2}
  };

  int n = 4;
  int m = 4;

  Solution obj;
  vector<int> ans = obj.findOrder(n, m, prerequisite);
  cout << "Ordering of tasks you should pick to finish all tasks: " << ans;
  return 0;
}
