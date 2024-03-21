let list = [
  'bacon',
  'eggs',
  'butter',
  'milk',
  'bread',
  'bacon',
  {text: 'bread', cost: 3}
];
/* -------------------------------------------------------- */
// -1, index
console.log(list.indexOf('milk'));
console.log(list.indexOf('bacon', 1));
console.log(list.lastIndexOf('bacon')); //starts searchin from the back

/* -------------------------------------------------------- */
// findIndex is useful for references or objects
console.log(list.findIndex((item) => {
  return item.text === 'bread';
}))

/* -------------------------------------------------------- */
let list2 = [
  { text: 'bacon', cost: 12, need: true },
  { text: 'eggs', cost: 10, need: true },
  { text: 'butter', cost: 5, need: false },
  { text: 'milk', cost: 4, need: false },
  { text: 'bread', cost: 3, need: true },
];

let numbers = [5, 9, 23, 54, 97, 1];

let item = list2.find((element) => {
  return element.text === 'sausage';
})
console.log(item); //undefined

let item2 = list2.find((element) => element.cost < 5);
console.log(item2); // { text: 'milk', cost: 4, need: false }

let notprime = numbers.find(num => num % 2 === 0)
console.log(notprime) // 54

/* -------------------------------------------------------- */

console.log(numbers.includes(23)); // true
console.log(list2.some(item => item.need)) // if atleast one item in the list is true it some returns true
console.log(numbers.every(item => item%2!==0)) // returns true if every element in the array meets the callback function code

