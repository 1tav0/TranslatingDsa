class Solution
{
  class DisjointSet{
        vector<int> rank, parent, size;
    public:
        DisjointSet(int n){
            rank.resize(n+1, 0);
            parent.resize(n+1);
            size.resize(n+1);
            for(int i=0; i<=n; i++){
                parent[i] = i;
                size[i] = 1;
            }
        }

        int findUParent(int node){
            if(node == parent[node])
                return node;
            return parent[node] = findUParent(parent[node]);
        }

        void unionByRank(int u, int v){
            int ulp_u = findUParent(u);
            int ulp_v = findUParent(v);

            if(ulp_u == ulp_v) return;

            if(rank[ulp_u] < rank[ulp_v]){
                parent[ulp_u] = ulp_v;
            }
            else if(rank[ulp_v] < rank[ulp_u]){
                parent[ulp_v] = ulp_u;
            }
            else{
                parent[ulp_u] = ulp_v;
                rank[ulp_v]++;
            }
        }

        void unionBySize( int u, int v ){
            int ulp_u = findUParent(u);
            int ulp_v = findUParent(v);

            if(ulp_u == ulp_v) return;

            if(size[ulp_u] < size[ulp_v]){
                parent[ulp_u] = ulp_v;
                size[ulp_v] += size[ulp_u];
            }
            else{
                parent[ulp_v] = ulp_u;
                size[ulp_u] += size[ulp_v];
            }
        }
    };
	public:
/*------------------------------------------------------------------------------------------------------------*/
int spanningTree(int V, vector<vector<int>> adj[])
{
    //space O(n)
    vector<pair<int,pair<int,int>>> edges;
    //O(n+E) - tc
    for(int i=0; i<V; i++){
        for(auto it: adj[i]){
            int adjN = it[0];
            int wt = it[1];
            int node = i;

            edges.push_back({wt, {node, adjN}});
        }
    }
    //NlogM -tc
    sort(edges.begin(), edges.end());

    DisjointSet ds(V);
    int mstWt = 0;
    //M x 4 x alpha -tc
    for(auto it: edges){
        int wt = it.first;
        int u = it.second.first;
        int v = it.second.second;

        if(ds.findUParent(u) != ds.findUParent(v)){
            mstWt += wt;
            ds.unionBySize(u,v);
        }
    }

    return mstWt;
}
};
