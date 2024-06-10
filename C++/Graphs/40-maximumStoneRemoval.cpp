class Solution {
  public:
  class DisjointSet{
        public:
            vector<int> parent, size, rank;
            DisjointSet(int n){
                parent.resize(n+1);
                rank.resize(n+1, 0);
                size.resize(n+1, 1);
                for(int i=0; i<n; i++){
                    parent[i] = i;
                }
            }

            int findUParent(int node){
                if(node == parent[node]){
                    return node;
                }

                return parent[node] = findUParent(parent[node]);
            }

            void unionBySize(int u, int v){
                int ulp_u = findUParent(u);
                int ulp_v = findUParent(v);

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
    int maxRemove(vector<vector<int>>& stones, int n) {
        int maxRows = 10000;  // The maximum value from the problem constraint
        int maxCols = 10000;  // The maximum value from the problem constraint
        DisjointSet ds(maxRows + maxCols);

        for (auto it : stones) {
            ds.unionBySize(it[0], maxRows + it[1]);
        }

        unordered_set<int> groups;
        for (auto it : stones) {
            groups.insert(ds.findUParent(it[0]));
            groups.insert(ds.findUParent(maxRows + it[1]));
        }

        return n - groups.size();
    }
};
