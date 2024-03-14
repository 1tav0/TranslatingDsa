/**
*@param {character[][]} board
*@return {void}
*/

class Solution{
  dfs(row, col, vis, board, delrow, delcol){
    vis[row][col] = 1;
    const n = board.length;
    const m = board.length;
    for(let i=0; i<4; i++){
      let newr = delrow[i] + row;
      let newc = delcol[i] + col;
      if(newr>=0 && newr<n && newc>=0 && newc<m && board[newr][newc]=='O' && !vis[newr][newc]){
        this.dfs(newr, newc, vis, board, delrow, delcol);
      }
    }
  }
  solve(board){
    const n = board.length;
    const m = board[0].length;
    const vis = Array.from({length: n},() => Array(m).fill(0));
    const delrow = [-1, 0, 1, 0];
    const delcol = [0, -1, 0, 1];
    for(let i=0; i<n; i++){
      //left col
      if(board[i][0]=='O' && !vis[i][0]){
        this.dfs(i, 0, vis, board, delrow, delcol);
      }
      //right col
      if(board[i][m-1]=='O' && !vis[i][m-1]){
        this.dfs(i, m-1, vis, board, delrow, delcol);
      }
    }
    for(let j=0; j<m; j++){
      //top row
      if(board[0][j]=='O' && !vis[0][j]){
        this.dfs(0, j, vis, board, delrow, delcol);
      }
      //bottom row
      if(board[n-1][j]=='O' && !vis[n-1][j]){
        this.dfs(n-1, j, vis, board, delrow, delcol);
      }
    }

    for(let i=0; i<n; i++){
      for(let j=0; j<m; j++){
        if(board[i][j]=='O' && !vis[i][j]){
          board[i][j] = 'X';
        }
      }
    }
    return board;
  }

  printGraph(board){
    for(const row of board){
      let r = "";
      for(const val of row){
        r += val + " ";
      }
      console.log(r);
    }
  }

}

const board = [
  ["X","X","X","X"],
  ["X","O","O","X"],
  ["X","X","O","X"],
  ["X","O","X","X"]
]
console.log("old grid: ");

const obj = new Solution();
obj.printGraph(board);
console.log("new grid: ");
const ans = obj.solve(board);
obj.printGraph(ans);
