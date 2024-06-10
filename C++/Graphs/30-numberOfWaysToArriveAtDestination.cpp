class Solution {
  public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<int,int>> adj[n];
        for(auto it: roads){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }

        vector<int> dist(n,1e9), ways(n,0);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        dist[0] = 0;
        ways[0] = 1;
        pq.push({0,0});
        int mod = (int)(1e9 + 7);
        while(!pq.empty()){
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for(auto it: adj[node]){
                int adjNode = it.first;
                int adjw = it.second;

                if(dis + adjw < dist[adjNode]){
                    dist[adjNode] = dis + adjw;
                    pq.push({dis+adjw, adjNode});
                    ways[adjNode] = ways[node];
                }else if(dis + adjw == dist[adjNode]){
                    ways[adjNode] = (ways[adjNode] + ways[node])%mod;
                }
            }
        }

        return ways[n-1]%mod;
    }
//correct
    int countPaths2(int n, vector<vector<int>>& roads) {
        vector<pair<int,int>>adj[n];
        for(auto it: roads) {
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }

        priority_queue<pair<long long,int>,vector<pair<long long,int>>, greater<pair<long long,int>>>q;
        vector<long long>dist(n,1e18);
        vector<int>ways(n,0);
        dist[0] = 0;
        ways[0] = 1;
        int mod = (int)(1e9+7);
        q.push({0,0});
        while(!q.empty()) {
            long long dis = q.top().first;
            int node = q.top().second;
            q.pop();
            for(auto it: adj[node]) {
                long long edw = it.second;
                int adjnode = it.first;
                if(dis+edw < dist[adjnode]) {
                    dist[adjnode] =dis+edw;
                    q.push({dis+edw,adjnode});
                    ways[adjnode] = ways[node] % mod;
                }
                else if(dis+edw == dist[adjnode]){
                    ways[adjnode] = (ways[adjnode] + ways[node])%mod;
                }
            }
        }
        return ways[n-1]%mod;
    }
};
