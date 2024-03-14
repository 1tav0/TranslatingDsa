#include <iostream>
#include <vector>
#include <queue>
using namespace std;
// Alien Dictionary
const int N = 5;
class Solution{
public:
  vector<int> topoSort(int V, vector<int> adj[]){
    vector<int> inDegrees(V);
    for(int i=0; i<V; i++){
      for(auto it: adj[i]){
        inDegrees[it]++;
      }
    }
    queue<int> q;
    for(int i=0; i<V; i++){
      if(inDegrees[i]==0){
        q.push(i);
      }
    }
    vector<int> topo;
    while(!q.empty()){
      int node = q.front();
      q.pop();

      topo.push_back(node);
      for(auto it: adj[node]){
        inDegrees[it]--;
        if(inDegrees[it]==0){
          q.push(it);
        }
      }
    }
    return topo;
  }

  string alienDictionary(string dict[], int N, int K){
    vector<int> adj[K];
    for(int i=0; i<N-1; i++){
      string s1 = dict[i];
      string s2 = dict[i+1];
      int len = min(s1.length(), s2.length());
      for(int j=0; j<len; j++){
        if(s1[j] != s2[j]){
          adj[s1[j]-'a'].push_back(s2[j]-'a');
          break;
        }
      }
    }
    vector<int> topo = topoSort(K, adj);
    string ans = "";
    for(auto it: topo){
      ans = ans + char(it+'a');
    }
    return ans;
  }
};

ostream& operator<<(ostream& os, string dict[N]){
  for(int i=0; i<N; i++){
    os << dict[i] << " ";
  }
  return os;
}

int main(){
  // int N = 5;
  int K = 4;
  string dict[] = {"baa","abcd","abca","cab","cad"};
  cout << "dictionary: " << dict << endl;
  Solution obj;
  string ans = obj.alienDictionary(dict, N, K);
  cout << "The alien dictionary is: " << ans;
  return 0;
}


// string order;
// // It iterates through the characters of a and b,
// // finding their positions in the order string.
// bool f(string a, string b) {
//     int p1 = 0;
//     int p2 = 0;
//     for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
//         p1 = order.find(a[i]);
//         p2 = order.find(b[i]);
//         //	cout<<p1<<" "<<p2<<endl;
//     }
// // If a and b differ in length but have matched characters so far,
// // it returns true if a should precede b based on length.
//     if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();
// // returns true if the position of a's character in order is less than that of b
//     return p1 < p2;
// }
//
// // std::vector<int> source = {1, 2, 3, 4, 5};
// // std::vector<int> destination(source.size()); // Make sure destination has enough space
// // Copy elements from source to destination
// // std::copy(source.begin(), source.end(), destination.begin());
//
// // Driver program to test above functions
// int main() {
//     int t;
//     cin >> t;
//     while (t--) {
//         int N, K;
//         cin >> N >> K;
//         string dict[N];
//         for (int i = 0; i < N; i++) cin >> dict[i];
//
//         Solution obj;
//         string ans = obj.findOrder(dict, N, K);
//         order = "";
//         for (int i = 0; i < ans.size(); i++) order += ans[i];
//
//         // copy a dict to temp and sort this temp based on comparator
//         string temp[N];
//         std::copy(dict, dict + N, temp);
//         sort(temp, temp + N, f);
//         //
//         bool f = true;
//         for (int i = 0; i < N; i++)
//             if (dict[i] != temp[i]) f = false;
//
//         if(f)cout << 1;
//         else cout << 0;
//         cout << endl;
//     }
//     return 0;
// }
