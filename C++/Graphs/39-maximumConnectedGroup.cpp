class Solution {
    class DisjointSet{
        public:
        vector<int> rank, size, parent;

        DisjointSet(int n){
                rank.resize(n+1,0);
                size.resize(n+1,1);
                parent.resize(n+1);
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

            void unionByRank(int u, int v){
                int up = findUParent(u);
                int vp = findUParent(v);

                if(up == vp){
                    return;
                }
                if(rank[up] < rank[vp]){
                    parent[up] = vp;
                }else if(rank[vp] < rank[up]){
                    parent[vp] = up;
                }else{
                    parent[vp] = up;
                    rank[up]++;
                }
            }

            void unionBySize(int u, int v){
                int up = findUParent(u);
                int vp = findUParent(v);

                if(up == vp) return;

                if(size[up] < size[vp]){
                    parent[up] = vp;
                    size[vp] += size[up];
                }else{
                    parent[vp] = up;
                    size[up] += size[vp];
                }
            }
    };
  public:
    int MaxConnection(vector<vector<int>>& grid) {
        int n = grid.size();
        // int m = grid[0].size();
        DisjointSet ds(n*n);
        // unite all the components in the given graph so we have different components we can easily connect
        // with a one and count its new size
        // tc - O(N*N)
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 0) continue;

                int delrow[] = { -1, 0,1,0 };
                int delcol[] = { 0, -1, 0, 1};

                for(int ind=0; ind<4; ind++){
                    int newr = delrow[ind] + i;
                    int newc = delcol[ind] + j;

                    if(newr>=0 && newr<n && newc>=0 && newc<n && grid[newr][newc]==1){
                        int node = i * n + j;
                        int adjNode = newr * n + newc;

                        ds.unionBySize(node,adjNode);
                    }
                }
            }
        }
        // store ulitimate parent for every adjNode in a set to avoid repeating ultimate parents
        // and get maxi size
        // tc - O(N*N)
          int mx = 0;
         for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 1) continue;

                int delrow[] = { -1, 0,1,0 };
                int delcol[] = { 0, -1, 0, 1};
                set<int> st;

                for(int ind=0; ind<4; ind++){
                    int newr = delrow[ind] + i;
                    int newc = delcol[ind] + j;

                    if(newr>=0 && newr<n && newc>=0 && newc<n && grid[newr][newc]==1){
                        int adjNode = newr * n + newc;
                        st.insert(ds.findUParent(adjNode));
                    }
                }

                int cnt = 0;
                for(auto it: st){
                    cnt += ds.size[it];
                }

                mx = max(mx, cnt+1);
            }
         }
         // in case the whole matrix is one whole component
            for(int cell=0; cell<n*n; cell++){
                mx = max(mx, ds.size[ds.findUParent(cell)]);
            }

        return mx;
    }
};
