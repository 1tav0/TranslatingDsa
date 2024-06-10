class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
  /*---------------------------------Prim's Algorithm----------------------------------------------------------*/
    int spanningTree1(int V, vector<vector<int>> adj[])
    {
        vector<int> vis(V, 0);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0,0});
        int sum = 0;

        while(!pq.empty()){
            int node = pq.top().second;
            int wt = pq.top().first;
            pq.pop();

            if(vis[node] == 1) continue;
            vis[node] = 1;
            sum += wt;
            for(auto it: adj[node]){
                int adjN = it[0];
                int adjW = it[1];
                if(!vis[adjN]){
                    pq.push({adjW, adjN});
                }

            }
        }
        return sum;
    }
};
