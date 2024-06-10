class Solution {
    class DisjointSet{
        vector<int> rank, size, parent;
    public:
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
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        vector<vector<int>> vis(n, vector<int> (m, 0));
        DisjointSet ds(n*m);
        int cnt = 0;
        vector<int> ans;
        for(auto it: operators){
            int row = it[0];
            int col = it[1];

            if(vis[row][col] == 1){
                ans.push_back(cnt);
                continue;
            }

            vis[row][col] = 1;
            cnt++;

            int delrow[] = {-1,0,1,0};
            int delcol[] = {0,1,0,-1};

            for(int i=0; i<4; i++){
                int newr = delrow[i] + row;
                int newc = delcol[i] + col;

                if(newr>=0 && newr<n && newc>=0 && newc<m && vis[newr][newc]==1){
                    int node = row * m + col;
                    int adjNode = newr * m + newc;

                    if(ds.findUParent(node) != ds.findUParent(adjNode)){
                        cnt--;
                        ds.unionBySize(node,adjNode);
                    }
                }
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};
