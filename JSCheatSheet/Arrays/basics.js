let list = [
  { text: 'milk', cost: 4, need: false },
  { text: 'eggs', cost: 10, need: true },
  { text: 'butter', cost: 5, need: false },
  { text: 'bread', cost: 3, need: true },
  { text: 'bacon', cost: 12, need: true },
];

let html = '';
let total = 0;
/* ------> normal for loop <------- */
// for (let i = 0; i < list.length; i++){
//   if (list[i].need) {
//     html += `<li>${list[i].text}</li>`
//     total += list[i].cost
//   }
// }

/* ------> normal while loop <------- */
// let index = 0;
// while (index < list.length) {
//   let item = list[index];
//   if (item.need) {
//     html += `<li>${item.text}</li>`;
//     total += item.cost;
//   }
//   index++;
// }

/* ------> forEach loop <------- */
// item we are working, index of it, and the array we are working with 
// list.forEach((item, index, array) =>{})
// list.forEach((item) => {
//   if (item.need) {
//     html += `<li>${item.text}</li>`;
//     total += item.cost;
//   }
// })

//or
/* ------> forEach loop <------- */
// list.forEach(({text, cost, need}) => {
//   if (need) {
//     html += `<li>${text}</li>`;
//     total += cost;
//   }
// })

/* ------> for of loop <------- */
// for (let item of list) {
//   if (item.need) {
//     html += `<li>${item.text}</li>`;
//     total += item.cost;
//   }
// }
// or
/* ------> for of loop <------- */
for (let {text,cost,need} of list) {
  if (need) {
    html += `<li>${text}</li>`;
    total += cost;
  }
}

document.getElementById('list').innerHTML = html;
document.getElementById('cost').innerHTML = `$${total}`;