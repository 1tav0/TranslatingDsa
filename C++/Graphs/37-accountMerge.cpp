class Solution{
  public:
   class DisjointSet{
	    vector<int> parent, rank, size;
	    public:
	       DisjointSet(int n){
	           parent.resize(n+1);
	           rank.resize(n+1, 0);
	           size.resize(n+1, 1);
	           for(int i=0; i<n; i++){
	               parent[i] = i;
	           }
	       }

	       int findUParent(int node){
	           if(parent[node]==node){
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
	           }else if(rank[ulp_v] < rank[ulp_u]){
	               parent[ulp_v] = ulp_u;
	           }else{
	               parent[ulp_v] = parent[ulp_u];
	               rank[ulp_u]++;
	           }
	       }

	       void unionBySize(int u, int v){
	           int ulp_u = findUParent(u);
	           int ulp_v = findUParent(v);
	           if(ulp_u == ulp_v) return;

	           if(size[ulp_u] < size[ulp_v]){
	               parent[ulp_u] = ulp_v;
	               size[ulp_v] += size[ulp_u];
	           }else{
	               parent[ulp_v] = ulp_u;
	               size[ulp_u] += size[ulp_v];
	           }
	       }
	};
  /* Approach:
    - map the mail and how many times it appears in the accounts
    - if already in the map unionBySize the index im in with the index of the mail in the map
    - iterating the map create an adj list using the mail and the ultimate parent for the node
    - iterating through the adj list sort the adj list note the first row in the adj list can be empty
    - use a temp vector to push from the adj list the list of emails and them push that vector to answer vector


  */
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts) {
        int n = accounts.size();
        DisjointSet ds(n);
        unordered_map<string,int> mailToNodes;
        for(int i=0; i<n; i++){
            for(int j=1; j<accounts[i].size(); j++){
                string mail = accounts[i][j];
                if(mailToNodes.find(mail)==mailToNodes.end()){
                    mailToNodes[mail] = i;
                }else{
                    ds.unionBySize(i,mailToNodes[mail]);
                }
            }
        }
        vector<string> adjMailList[n];
        for(auto it: mailToNodes){
            string mail = it.first;
            int node = ds.findUParent(it.second);
            adjMailList[node].push_back(mail);
        }
        vector<vector<string>> ans;
        for(int i=0; i<n; i++){
            if(adjMailList[i].size() == 0) continue;
            sort(adjMailList[i].begin(), adjMailList[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for(auto it: adjMailList[i]){
                temp.push_back(it);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
