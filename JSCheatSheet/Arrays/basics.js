let list = [
  'milk',
  'eggs',
  'butter',
  'bread',
  'bacon'
];

let html = '';
for (let i = 0; i < list.length; i++){
  html += `<li>${list[i]}</li>`
}

document.getElementById('list').innerHTML = html;