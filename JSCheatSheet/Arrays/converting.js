let list = [
  { text: 'bacon', cost: 12, need: true },
  { text: 'eggs', cost: 10, need: true },
  { text: 'butter', cost: 5, need: false },
  { text: 'milk', cost: 4, need: false },
  { text: 'bread', cost: 3, need: true },
];
console.log(list);
/* -----------------------.slice()---------------------- */
// will create a copy doesnt modify existing one at all
let copy = list.slice();
console.log(copy);

console.log(copy === list); // these are not the same
// we end up with a copy to the same references essentially poiting to the same reference it isnt its own copy reference but rather pointing towards the one from list 
console.log(copy[0] === list[0]) // true bc it is a shallow copy not a new deep copy

let copy2 = list.slice(0, 3); // [, )
console.log(copy2);


/* -----------------------.toString()---------------------- */
let list2 = [
  'bacon',
  'eggs',
  'butter',
  'milk',
  'bread'
]
// let html = list2.join('<br />');
// document.getElementById('list').innerHTML = html;

/* -----------------------.map()---------------------- */
// creates a new array with transformed added/deleted data
let listElements = list.map(function ({ text, cost, need }) {
  if (need) {
    return `<li>${text} $${cost}</li>`
  } else {
    return '';
  }
})

// document.getElementById('list').innerHTML = listElements.join('');

/* -----------------------.filter()---------------------- */
// normally map is used with data u do need if we want to accomplish the same on a different case we use filter
// doesnt modify the existing data, it creates a new array with the filtered data to it
// here we filter only the items that are needed so when we map them we are workin with the items we do need
let listElems =
  list
    .filter(item => item.need && item.cost < 12)
    .map(({ text, cost }) => `<li>${text} $${cost}</li>`);
    
document.getElementById('list').innerHTML = listElements.join('');


