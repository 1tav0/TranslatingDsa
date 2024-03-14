class Solution{

  dfs(row, col, vis, grid, vec, row1, col1){
    vis[row][col] = 1;
    vec.push([row-row1, col-col1]);
    const n = grid.length;
    const m = grid[0].length;
    const delrow = [-1, 0, 1, 0];
    const delcol = [0, -1, 0, 1];

    for(let i=0; i<n; i++){
      let newr = delrow[i] + row;
      let newc = delcol[i] + col;

      if(newr>=0 && newr<n && newc>=0 && newc<m && grid[newr][newc]==1 && !vis[newr][newc]){
        this.dfs(newr, newc, vis, grid, vec, row1, col1);
      }
    }
  }

  countDistinctIslands(grid){
    const n = grid.length;
    const m = grid[0].length;
    const vis = Array.from({length: m}, () => Array(m).fill(0));
    const st = new Set();

    for(let i=0; i<n; i++){
      for(let j=0; j<m; j++){
        if(grid[i][j]==1 && !vis[i][j]){
          const vec = [];
          this.dfs(i, j, vis, grid, vec, i, j);
          st.add(JSON.stringify(vec));
        }
      }
    }
    return st.size;
  }
}

const grid = [
    [1, 1, 0, 1, 1],
    [1, 0, 0, 0, 0],
    [0, 0, 0, 0, 1],
    [1, 1, 0, 1, 1]
];

console.log("grid: ");
grid.forEach(row => console.log(row.join(" ")));
const obj = new Solution();
const ans = obj.countDistinctIslands(grid);
console.log("The number of distinct islands is: " + ans);
