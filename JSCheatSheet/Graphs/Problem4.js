class Solution{
  orangesRotting(grid){
    const n = grid.length;
    const m = grid[0].length;

    const vis = Array.from({length: n}, () => Array.from(m).fill(0));
    const q = [];
    let orangesToRot = 0;
    for(let i=0; i<n; i++){
      for(let j=0; j<m; j++){
        if(grid[i][j]==2 && !vis[i][j]){
          q.push([0, i, j]);
          vis[i][j] = 2;
        }
        if(grid[i][j]==1){
          orangesToRot++;
        }
      }
    }

    const delrow = [-1, 0, 1, 0];
    const delcol = [0, -1, 0, 1];
    let orangesRotted = 0;
    let time = 0;
    while(q.length > 0){
      const [t, row, col] = q.shift();

      time = Math.max(time, t);
      for(let i=0; i<4; i++){
        let newr = delrow[i] + row;
        let newc = delcol[i] + col;

        if(newr>=0 && newr<n && newc>=0 && newc<m && grid[newr][newc]==1 && !vis[newr][newc]){
          vis[newr][newc] = 2;
          q.push([t+1, newr, newc]);
          orangesRotted++;
        }
      }
    }
    if(orangesRotted !== orangesToRot) return -1;

    return time;
  }

  newGrid(grid){
    const n = grid.length;
    const m = grid[0].length;

    const vis = [...grid];
    const q = [];
    let orangesToRot = 0;
    for(let i=0; i<n; i++){
      for(let j=0; j<m; j++){
        if(grid[i][j]==2){
          q.push([0, i, j]);
        }
        if(grid[i][j]==1){
          orangesToRot++;
        }
      }
    }

    const delrow = [-1, 0, 1, 0];
    const delcol = [0, -1, 0, 1];
    let orangesRotted = 0;
    let time = 0;
    while(q.length > 0){
      const [t, row, col] = q.shift();

      time = Math.max(time, t);
      for(let i=0; i<4; i++){
        let newr = delrow[i] + row;
        let newc = delcol[i] + col;

        if(newr>=0 && newr<n && newc>=0 && newc<m && grid[newr][newc]==1){
          vis[newr][newc] = 2;
          q.push([t+1, newr, newc]);
          orangesRotted++;
        }
      }
    }
    if(orangesRotted !== orangesToRot) return [[]];

    return vis;
  }
};

const grid = [
    [0,1,2],[0,1,2],[2,1,1]
];

const obj = new Solution();
const ans = obj.orangesRotting(grid);
const newGrid = obj.newGrid(grid);

console.log("old grid: ");
for(const row of grid){
  let r = "";
  for(const val of row){
    r += val + " ";
  }
  console.log(r);
}

console.log("new grid: ");
for(const row of newGrid){
  let r = "";
  for(const val of row){
    r += val + " ";
  }
  console.log(r);
}

console.log(`Total time to rot all oranges: ${ans}`);
