class Solution{
  dfs(initColor, vis, delrow, delcol, image, sr, sc, newColor){
    vis[sr][sc] = newColor;
    let n = image.length;
    let m = image.length;
    for(let i=0; i<4; i++){
      let newr = delrow[i] + sr;
      let newc = delcol[i] + sc;
      if(newr>=0 && newr<n && newc>=0 && newc<m && image[newr][newc]==initColor && vis[newr][newc] != newColor){
        vis[newr][newc] = 1;
        this.dfs(initColor, vis, delrow, delcol, image, newr, newc, newColor);
      }
    }
  }

  floodFill(image, sr, sc, newColor){
    const initColor = image[sr][sc];

    // Create a deep copy of the image
    // const vis = new Array(n);
    // for (let i = 0; i < n; i++) {
    //   vis[i] = new Array(m);
    //   for (let j = 0; j < m; j++) {
    //     vis[i][j] = image[i][j];
    //   }
    // }
    //or
    // for (let i = 0; i < image.length; i++) {
    //   vis[i] = image[i].slice();
    // }
    const vis = image.map(row => row.slice());
    const delrow = [-1, 0, 1, 0];
    const delcol = [0, -1, 0, 1];
    this.dfs(initColor, vis, delrow, delcol, image, sr, sc, newColor);
    return vis;
  }
};

const image = [
  [1,1,1],
  [1,1,0],
  [1,0,1]
]

const sr = 1;
const sc = 1;
const newColor = 2;

const obj = new Solution();
const ans = obj.floodFill(image, sr, sc, newColor);

console.log("old image: ");
for(let i=0; i<image.length; i++){
  let row = "";
  for(let j=0; j<image[i].length; j++){
    row += image[i][j] + ' ';
  }
  console.log(row);
}

console.log("-------------------");

console.log("new image: ");
for(let i=0; i<ans.length; i++){
  let row = "";
  for(let j=0; j<ans[i].length; j++){
    row += ans[i][j] + ' ';
  }
  console.log(row);
}
