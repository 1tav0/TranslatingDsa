let list = [
  { text: 'milk', cost: 4, need: false },
  { text: 'eggs', cost: 10, need: true },
  { text: 'butter', cost: 5, need: false },
  { text: 'bread', cost: 3, need: true },
  { text: 'bacon', cost: 12, need: false },
];

let html = '';
let total = 0;

for (let i = 0; i < list.length; i++){
  if (list[i].need) {
    html += `<li>${list[i].text}</li>`
    total += list[i].cost
  }
}

document.getElementById('list').innerHTML = html;
document.getElementById('cost').innerHTML = `$${total}`;