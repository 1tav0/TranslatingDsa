//  Input = "abc"
// output = [], [a], [a,b], [a,b,c], [a,c], [b,c],[c]

// const possibleCombinations = (str)=> {
//     let ar = [];
//     for(let i = 0; i<str.length; i++){
//         for(j=i+1; j<str.length; j++){
//             ar.push(str.slice(i,j))
//         }
//     }
//    return ar
// }
// console.log(possibleCombinations("abc"));

// class Solution {
//   problem(ind, str, ans) {
//     // base case
//     if (ind === str.length) {
//       console.log(ans + " ");
//       return;
//     }

//     ans += str.charAt(ind);
//     this.problem(ind + 1, str, ans);
//     ans = ans.slice(0, -1); // backtracking
//     this.problem(ind + 1, str, ans);
//   }
// }

// const obj = new Solution();
// const str = "abc";
// let ans = "";
// console.log("All possible subsequences: ");
// obj.problem(0, str, ans);

//  2. Return indexes that add up to target

const returningIndexes = (nums, target) => {
    let myobj = {}
    for(let i = 0; i<nums.length; i++){
      let difference = target - nums[i];
      if(myobj[nums[i]] != null){
        return [myobj[nums[i]], i];
      } else { myobj[difference] = i}
    }
  }
  console.log(returningIndexes([1,2,3,4],6))