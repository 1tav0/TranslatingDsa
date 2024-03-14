#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
// Find Eventual safe Nodes using Khans Algorithm
class Solution{
public:
  vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        vector<int> adjRev[V];
        vector<int> inDegrees(V);
        for(int i=0; i<V; i++){
            for(auto it: adj[i]){
                adjRev[it].push_back(i);
                inDegrees[i]++;
            }
        }
        queue<int> q;
        for(int i=0; i<V; i++){
            if(inDegrees[i]==0){
                q.push(i);
            }
        }
        vector<int> ans;
        while(!q.empty()){
            int node = q.front();
            q.pop();

            ans.push_back(node);
            for(auto it: adjRev[node]){
                inDegrees[it]--;
                if(inDegrees[it]==0){
                    q.push(it);
                }
            }
        }

        sort(ans.begin(), ans.end());
        return ans;
    }
};

ostream& operator<<(ostream& os, const vector<int>& adj){
  for(auto &val: adj){
    os << val << " ";
  }
  return os;
}

int main(){
  int V = 7;
  vector<int> adj[V];
  adj[0].push_back(1);
  adj[0].push_back(2);
  adj[1].push_back(3);
  adj[1].push_back(2);
  adj[2].push_back(5);
  adj[3].push_back(0);
  adj[4].push_back(5);

  Solution obj;
  vector<int> ans = obj.eventualSafeNodes(V, adj);
  cout << "The eventual Safe Nodes are " << ans;
  return 0;
}
