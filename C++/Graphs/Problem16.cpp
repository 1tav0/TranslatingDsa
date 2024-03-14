#include <iostream>
#include <vector>
#include <queue>
using namespace std;
// Prerequisite Tasks I

class Solution{
  public:
  bool isPossible(int N, int P, vector<pair<int,int>>& prerequisite){
    vector<int> adj[N];
    for(auto it: prerequisite){
      int u = it.first;
      int v = it.second;
      adj[u].push_back(v);
    }
    vector<int> inDegrees(N);
    for(int i=0; i<N; i++){
      for(auto it: adj[i]){
        inDegrees[it]++;
      }
    }
    queue<int> q;
    for(int i=0; i<N; i++){
      if(inDegrees[i]==0){
        q.push(i);
      }
    }
    int cnt = 0;
    while(!q.empty()){
      int node = q.front();
      q.pop();

      cnt++;
      for(auto it: adj[node]){
        inDegrees[it]--;
        if(inDegrees[it]==0){
          q.push(it);
        }
      }
    }
    if(cnt != N) return false;

    return true;
  }
};

int main(){
  vector<pair<int,int>> prerequisite = {{1,0},{0,1}};
  int N = 4;
  int P = 3;
  Solution obj;
  bool ans = obj.isPossible(N, P, prerequisite);
  cout << "Is it possible to finish all tasks? " << ans;
  return 0;
}
