let thevar = 10;
console.log(thevar);            

let invar = prompt("Enter a number");   // prompt is a function that takes input from user
// let invar = prompt("Enter a number", "0");   // prompt is a function that takes input from user
console.log('u entered', invar);

let invar2 = confirm("Are you sure?");   // confirm is a function that takes input from user
// invar2 is a boolean value

// alert("Hello World");   // alert is a function that shows a message to user
// let invar = prompt("Enter a number", "0");   // prompt is a function that takes input from user

/*
    in devoloper mode in browser,
    document.write("Hello World");   // document.write is a function that writes to the document
    document.head   // gives the head tag
    document.body   // gives the body tag
    document.title   // gives the title tag

*/

let object1 = {  
    key1: "value1",
    key2: "value2",
    key3: "value"
};  // object is a collection of key-value pairs

let object2 = {
    key1: "value1",
    key2: "value2",
    key3: "value3",
};

console.log(object1, object2);       // print the object
console.table({object1, object2});    // print the object in table format

let arr = [1, 2, 3, 4, 5];  // array is a collection of values

// type cast 
let num = 10;
num = String(num);  // type cast to string

let str = "10";
str = Number(str);  // type cast to number
str = parseInt(str);  // type cast to integer
str = parseFloat(str);  // type cast to float


console.log("Hello " + "World");  // concatenation);
console.log('Hello ${str}');  // string interpolation

//array methods
let arr2 = [1, 2, 3, 4, 5];
console.log(arr.length);  // length of array
console.log(arr.concat(arr2));  // concatenation of arrays
console.log(arr.join(" "));  // join the array elements with a separator
console.log(arr.pop());  // remove the last element of array
console.log(arr.push(6));  // add an element to the end of array
console.log(arr.shift());  // remove the first element of array
console.log(arr.unshift(0));  // add an element to the beginning of array
console.log(arr.slice(1, 3));  // slice the array from index 1 to 3
console.log(arr.splice(1, 2));  // remove 2 elements from index 1
console.log(arr.reverse());  // reverse the array
console.log(arr.sort());  // sort the array


//object methods
let object = {
    name: "John",
    age: 33,
    Languages: ["English", "Spanish"],
    address: {
        street: "123 Main St",
        city: "New York"
    }
};
console.log(object.name);  // get the value of key
object.name = "Jane";  // set the value of key

console.log(Object.keys(object));  // get the keys of object
console.log(Object.values(object));  // get the values of object
console.log(Object.entries(object));  // get the key-value pairs of object
console.log(object.hasOwnProperty('key1'));  // check if the object has the key
console.log(object.hasOwnProperty('key4'));  // check if the object has the key
console.log(object.hasOwnProperty('value1'));  // check if the object has the value
console.log(object.hasOwnProperty('value4'));  // check if the object has the value

// foreach loop
arr.forEach(element) => {
    console.log(element);
};

//map
let arr3 = arr.map(element => {             // map function can return elements of array
    return element * 2;
});

for(element of arr) {
    console.log(element);
}


let result = arr.filter(element => {        // filter function can return elements of array based on condition
    return element > 2;
});


// get all odd numbers in array and add 5 to em

let result2 = arr.filter(element => {
    return element % 2 !== 0;
}).map(element =>{
    return element + 5;
});

console.log(result2);


// reduce