class Problem2{

  bfs(i, j, vis, grid){
    vis[i][j] = 1;
    const n = grid.length;
    const m = grid[0].length;

    // const queue = []
    // const enqueue = (item) => {
    //   queue.push(item);
    // }
    // const dequeue = () => {
    //   queue.shift();
    // }
    // enqueue([i,j]);
    const queue = [[i,j]];

    while(queue.length>0){
      const [r,c] = queue.shift();
      for(let dr=-1; dr<=1; dr++){
        for(let dc=-1; dc<=1; dc++){
          const newr = dr + r;
          const newc = dc + c;
          if(0<=newr && newr<n && 0 <= newc && newc<m && grid[newr][newc] == "1" && !vis[newr][newc]){
            queue.push([newr, newc]);
            vis[newr][newc] = 1;
          }
        }
      }
    }
  }

  numIslands(grid){
    const n = grid.length;
    const m = grid[0].length;
    const vis = Array.from({length: n}, () => Array(m).fill(0));
    let cnt = 0;

    for(let i=0; i<n; i++){
      for(let j=0; j<m; j++){
        if(grid[i][j]=="1" && vis[i][j]==0){
          cnt += 1;
          this.bfs(i,j,vis,grid);
        }
      }
    }
    return cnt;
  }
}


const grid = [
    [0, 1, 1, 1, 0, 0, 0],
    [0, 0, 1, 1, 0, 1, 0]
];

const obj = new Problem2();
const result = obj.numIslands(grid);
console.log("number of islands:", result);
