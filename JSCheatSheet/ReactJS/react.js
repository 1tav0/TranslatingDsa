// most of the js needed for react

/*---------------- arrow functions & exports --------------- */
{/* export default function doSomething() {
  console.log("normal function");
}

export const doSomething = () => {
  console.log("arrow function");
}

export const myComponent = () => {
  return <div>Hello</div>
} */}

// anonimous function declaring it inside when theres no name for it 
{/* <button
  onClick={() => {
    console.log("hello world from onClick");
  }}
>
  hello
</button> */}

/*---------------- working with conditionals --------------- */

let age1 = 10;
let name1 = 'bob';

if (age1 > 10) {
  name1 = "bob";
} else {
  name1 = "pedro";
}

console.log(name1);

// terniary operator

let age2 = 16;
let name2 = age2 > 10 ? "joe" : "jay";

{/* const component = () => {
  return age2 > 10 ? <div>JOE</div> :<div>JAY</div>
} */}

/*-------------------------- Objects ----------------------- */
// destructuring objects

const person1 = {
  name: "pedro",
  age: 20,
  isMarried: false
}

const { name, age, isMarried } = person1;
console.log("person1 is: ", person1); 
// { name: 'pedro', age: 20, isMarried: false }

// creating a new object using the spread operator
// very useful when working with arrays


const person2 = { ...person1, name: "jack" };
console.log("person2 is: ", person2);
// { name: 'jack', age: 20, isMarried: false }

const names = ["pedron", "jacki", "jessica"];
const names2 = [...names, "joel"];

console.log("names is: ", names);
// [ 'pedron', 'jacki', 'jessica' ]
console.log("names2 is: ", names2);
// [ 'pedron', 'jacki', 'jessica', 'joel' ]

/*--------------- Iterating through Arrays ----------------- */
// 3 most used functions
// .map(), .filter(), .reduce()

let list = ['joe', 'joey', 'jake'];

// prints the item
list.map((item) => {
  console.log(item);
})

// when we return the item we get a new copied array with transformed data 

let l1 = list.map((item) => {
  return "j";
})
console.log(l1); // [ 'j', 'j', 'j' ]

/* list.map((name) => {
  return <h1>{name}</h1>
}) */

let nums = [1, 2, 3, 4, 5, 6];

let ans = nums.filter((num) => {
  return num % 2 !== 0; 
});
console.log(ans); // [ 1, 3, 5 ]

/*------------------- async, await, fetch ------------------ */

// to fetch data from an api
const fetchData = async () => {
  const data = await fetch("imaginaryapi.com")
  const name = data.person?.name; // ?. aka optional chaining
}

/*------------------- Template Literals ------------------ */
const fetchStuff = async (animalName) => {
  const data = await fetch(`imaginaryapi.com/searchTerms/${animalName}`)
  const name = data.person?.name;
}
