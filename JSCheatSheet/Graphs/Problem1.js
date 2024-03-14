class Problem1{
  static dfs(node, vis, adjL){
    vis[node] = 1;

    for(let v of adjL[node]){
      if(vis[v] == 0){
        Problem1.dfs(v, vis, adjL);
      }
    }
  }

  static numProvinces(adj, V){
    const adjL = Array.from({ length: V}, () => []);

    for(let i=0; i<V; i++){
      for(let j=0; j<V; j++){
        if(adj[i][j]==1 && i!=j){
          adjL[i].push(j);
          adjL[j].push(i);
        }
      }
    }

    const vis = Array(V).fill(0);
    let cnt = 0;
    for(let i=0; i<V; i++){
      if(vis[i] == 0){
        cnt += 1;
        Problem1.dfs(i, vis, adjL);
      }
    }
    return cnt;
  }
}

const matrix = [
  [1, 0, 1],
  [0, 1, 0],
  [1, 0, 1]
];
const result = Problem1.numProvinces(matrix, 3);
console.log("Number of provinces: ", result);
