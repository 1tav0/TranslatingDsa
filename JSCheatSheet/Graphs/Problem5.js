class Solution{
  dfs(node, parent, vis, adj){
    vis[node] = 1;
    for(let v of adj[node]){
      if(!vis[v]){
        if(dfs(v, node, vis, adj)==true) return true;
      }else if(v != parent){
        return true;
      }
    }
    return false;
  }

  isCycle(V, adj){
    vis = Array(V).fill(0);
    for(let i=0; i<V; i++){
      if(!vis[i]){
        if(dfs(i, -1, vis, adj)==true) return true;
      }
    }
    return false;
  }

  printGraph(adj,V){
    for(let i=0; i<V; i++){
      let output = "Adjancency list of vertex: " + i + ": ";
      for(let j=0; j<V; j++){
        output += adj[i][j] + " ";
      }
      conosole.log(output);
    }
  }

}

const adj = [
  [1],
  [0,2,4],
  [1,3],
  [2,4],
  [1,3]
]

const V = adj.size();
const obj = new Solution();
obj.printGraph(adj, V);
console.log("Is there a cycle in the graph: " + obj.isCycle(V, adj));
