class Solution {
    class DisjointSet{
      vector<int> rank, size, parent;
    public:
        DisjointSet( int n){
            rank.resize(n+1, 0);
            parent.resize(n+1);
            size.resize(n+1);
            for(int i=0; i<n; i++){
                parent[i] = i;
                size[i] = 1;
            }
        }

    int findUParent(int node){
        if(node == parent[node]){
            return node;
        }

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

    void unionBySize(int u, int v){
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
    /*
      Approach:
      - use the DisjointSet to find the number of connected components to count the extra edges
      - if u and v are in a connected component it means there can be an extra edge
      - otherwise connect them using the DisjointSet
      - then count how many components are given in the graph originally
      - using the number of componets we know that the edges connections is always one less say a graph of three
      - connected nodes there is only two edges minimum required to connect them
      - now using the minimum connections if extra edges is greater than the minConnections we return those minConnections
    */
    int Solve(int n, vector<vector<int>>& edge) {
        DisjointSet ds(n);
        int extraEdge = 0;

        //count the extra edges or unite them
        for(auto it: edge){
            int u = it[0];
            int v = it[1];
            //if they have the same parent that means they are already connected so another connection is extra
            if(ds.findUParent(u)==ds.findUParent(v)){
                extraEdge++;
            }else{ //else they are not connected and we connect them
                ds.unionBySize(u,v);
            }
        }

        int cnt = 0;
        //we find the number of components
        for(int i=0; i<n; i++){
            if(ds.findUParent(i) ==  i) cnt++;
        }

        //min number to connect the components will be 1 less always
        int ans = cnt-1;
        if(extraEdge >= ans) return ans;

        return -1;
    }
};
