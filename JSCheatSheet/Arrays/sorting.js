let list = [
  'eggs',
  'butter',
  'milk',
  'bread',
  'bacon'
];

let list2 = [
  { text: 'milk', cost: 4, need: false },
  { text: 'eggs', cost: 10, need: true },
  { text: 'butter', cost: 5, need: false },
  { text: 'bread', cost: 3, need: true },
  { text: 'bacon', cost: 12, need: true },
];

let html = '';

// list.sort().reverse(); // in descending order
/* -------------------------------------------------------- */
//but a better approach is to do this
// list.sort((a, b) => {
//   if (a === b) return 0;
//   if (a > b) return -1;
//   return 1;

//   // the sort function works depending on the returned value
//   // 0, a === b, there is no change
//   // -1, a sorted before b
//   // 1, b sorted before a
// })
/* --------------------------------------------------------- */
// list.forEach((item) => {
//   html += `<li>${item}</li>`
// })
/* --------------------------------------------------------- */

// the fact that our sort can take in a callback function is an advantage bc we can sort our data however we want 

list.sort((a, b) => {
  if (a.text === b.text) return 0;
  if (a.text > b.text) return -1;
  return 1;
})

list2.forEach(({text}) => {
  html += `<li>${text}</li>`
})

document.getElementById('list').innerHTML = html;