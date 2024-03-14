class Solution{
  nearestCell(grid){
    let n = grid.length;
    let m = grid[0].length;
    const vis = Array.from({length: n}, () => Array(m).fill(0));
    const ans = Array.from({length: n}, () => Array(m).fill(0));
    const q = []
    for (let row = 0; row < grid.length; row++) {
      for (let col = 0; col < grid[row].length; col++) {
        if (grid[row][col] === 1) {
            q.push([row, col, 0]);
            vis[row][col] = 1;
        }
      }
    }
    const delrow = [-1, 0, 1, 0];
    const delcol = [0, -1, 0, 1];
    while(q.length){
      const front = q.shift();
      let row = front[0];
      let col = front[1];
      let steps = front[2];

      ans[row][col] = steps;
      for(let i=0; i<4; i++){
        let newr = delrow[i] + row;
        let newc = delcol[i] + col;
        if(newr>=0 && newr<n && newc>=0 && newc<m && !vis[newr][newc]){
          vis[newr][newc] = 1;
          q.push([newr, newc, steps+1]);
        }
      }
    }
    return ans;
  }

  printGraph(grid){
    for(const row of grid){
      let r = "";
      for(const val of row){
        r += val + " "
      }
      console.log(r);
    }
  }
}

const grid = [
  [1, 0, 1],
  [1, 1, 0],
  [1 ,0, 0]
]
console.log("old grid: ");
const obj = new Solution();
obj.printGraph(grid);
console.log("new grid; ");
const ans = obj.nearestCell(grid);
obj.printGraph(ans);
