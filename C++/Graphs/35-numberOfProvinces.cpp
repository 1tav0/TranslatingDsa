class Solution {
    class DisjointSet{
        vector<int> parent,size,rank;
        public:
        DisjointSet(int n){
            parent.resize(n+1);
            size.resize(n+1);
            rank.resize(n+1);

            for(int i=0; i<n; i++){
                parent[i] = i;
                rank[i] = 0;
                size[i]=1;
            }
        }

        int getUParent(int node){
            if(node == parent[node]){
                return node;
            }

            return parent[node] = getUParent(parent[node]);
        }
        void unionByRank(int v, int u){
            int ulp_u = getUParent(u);
            int ulp_v = getUParent(v);

            if(ulp_u == ulp_v){
                return;
            }

            if(rank[ulp_u]<rank[ulp_v]){
                parent[ulp_u] = ulp_v;
            }else if(rank[ulp_v]<rank[ulp_u]){
                parent[ulp_v] = ulp_u;
            }else{
                parent[ulp_u] = ulp_v;
                rank[ulp_v]++;
            }
        }
        void unionBySize(int u, int v){
            int ulp_u = getUParent(u);
            int ulp_v = getUParent(v);

            if(ulp_u==ulp_v) return;

            if(size[ulp_u]<size[ulp_v]){
                parent[ulp_u] = ulp_v;
                size[ulp_v] += size[ulp_u];
            }else{
                parent[ulp_v] = ulp_u;
                size[ulp_u] += size[ulp_v];
            }
        }
    };
  public:
    int numProvinces(vector<vector<int>> adj, int V) {
       DisjointSet ds(V);
       for(int i=0; i<V; i++){
           for(int j=0; j<V; j++){
               if(adj[i][j]==1){
                   ds.unionBySize(i,j);
               }
           }
       }
       
       int cnt=0;
       for(int i=0; i<V; i++){
           if(ds.getUParent(i)==i){
               cnt++;
           }
       }
       return cnt;
    }
};
