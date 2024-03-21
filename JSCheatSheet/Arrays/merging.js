let odd = [1, 3, 5, 7, 9];
let even = [2, 4, 6, 8, 10];
let letters = ['a', 'b', 'c', 'd', 'e', 'f'];

/* -----------------------.concat()---------------------- */
let numbers = odd.concat(even);

console.log(odd); // [ 1, 3, 5, 7, 9 ]
console.log(even); // [ 2, 4, 6, 8, 10 ]
console.log(numbers); // [ 1, 3, 5, 7, 9, 2, 4, 6, 8, 10]

let numbers2 = odd.concat(even, letters);
console.log(numbers2); // [1, 3, 5, 7, 9, 2, 4, 6, 8, 10, 'a','b', 'c', 'd', 'e', 'f']

/* -------------... aka spread operator------------------ */
let alphanumeric = [...odd, ...even, ...letters];
console.log(alphanumeric);


