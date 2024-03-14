#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution{
public:
  int minimumMultiplication(vector<int>& arr,  int start, int end){
    vector<int> dist(100000, 1e9);
    vector<int> parent(100000, -1);
    queue<pair<int,int>> q;
    q.push({start, 0});
    dist[start] = 0;
    int mod = 100000;
    while(!q.empty()){
      int node = q.front().first;
      int steps = q.front().second;
      q.pop();

      if(node == end) break;
      for(auto it: arr){
        int num = (it*node)%mod;
        if(steps+1 < dist[num]){
          dist[num] = steps+1;
          q.push({num, dist[num]});
          parent[num] = node;
        }
      }
    }
    vector<pair<int,int>> temp;
    int currentNode =  end;
    while(currentNode != start){
      int parentNode = parent[currentNode];
      int step = currentNode/parentNode;
      temp.push_back({parentNode, step});
      currentNode = parentNode;
    }

    int n = temp.size();
    for(int i=n-1; i>=0; i--){
      cout << "Step " << n-i << ": ";
      cout << temp[i].first << "*" << temp[i].second << " = ";
      cout << (temp[i].first * temp[i].second)%mod << "%" << mod << " = ";
      cout << (temp[i].first * temp[i].second)%mod << endl;
    }
  }
};

int main(){

  return 0;
}
