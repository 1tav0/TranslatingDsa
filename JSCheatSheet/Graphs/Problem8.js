// @params {number[][]} grid
// @returns {number}

class Solution{
  numberOfEnclaves(grid){
    const n = grid.length;
    const m = grid[0].length;
    const vis = Array.from({length: n}, () => Array(m).fill(0));
    const q = [];
    for(let i=0; i<n; i++){
      for(let j=0; j<m; j++){
        if(i==0 || j==0 || i==n-1 || j==m-1){
          if(grid[i][j]==1){
            q.push([i,j]);
            vis[i][j] = 1;
          }
        }
      }
    }
    const delrow = [-1, 0, 1, 0];
    const delcol = [0, -1, 0, 1];
    while(q.length>0){
      const front = q.shift();
      let row = front[0];
      let col = front[1];
      for(let i=0; i<4; i++){
        let newr = delrow[i] + row;
        let newc = delcol[i] + col;
        if(newr>=0 && newr<n && newc>=0 && newc<m && grid[newr][newc]==1 && !vis[newr][newc]){
          vis[newr][newc] = 1;
          q.push([newr, newc]);
        }
      }
    }
    let cnt = 0;
    for(let i=0; i<n; i++){
      for(let j=0; j<m; j++){
        if(grid[i][j]==1 && !vis[i][j]){
          cnt++;
        }
      }
    }
    return cnt;
  }

  newGrid(grid){
    const n = grid.length;
    const m = grid[0].length;
    const vis = Array.from({length: n}, () => Array(m).fill(0));
    const ans = grid.map(row => row.slice());
    const q = [];
    for(let i=0; i<n; i++){
      for(let j=0; j<m; j++){
        if(i==0 || j==0 || i==n-1 || j==m-1){
          if(grid[i][j]==1){
            q.push([i,j]);
            vis[i][j] = 1;
            ans[i][j] = 0;
          }
        }
      }
    }
    const delrow = [-1, 0, 1, 0];
    const delcol = [0, -1, 0, 1];
    while(q.length>0){
      const front = q.shift();
      let row = front[0];
      let col = front[1];
      for(let i=0; i<4; i++){
        let newr = delrow[i] + row;
        let newc = delcol[i] + col;
        if(newr>=0 && newr<n && newc>=0 && newc<m && grid[newr][newc]==1 && !vis[newr][newc]){
          vis[newr][newc] = 1;
          q.push([newr, newc]);
          ans[newr][newc] = 0;
        }
      }
    }

    return ans;
  }

  printGraph(grid){
    for(const row of grid){
      let r = "";
      for(const val of row){
        r += val + " ";
      }
      console.log(r);
    }
  }
};

const grid = [
  [0, 0, 0, 1],
  [0, 1, 1, 0],
  [0, 1, 1, 0],
  [0, 0, 0, 1],
  [0, 1, 1, 0]
]

console.log("old grid: ");
const obj = new Solution();
obj.printGraph(grid);
const ans = obj.newGrid(grid);
console.log("new grid: ");
obj.printGraph(ans);
const cnt = obj.numberOfEnclaves(grid);
console.log("Number of enclaves in the new grid: ", cnt);
