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

let object = {  
    key1: "value1",
    key2: "value2",
    key3: "value"
};  // object is a collection of key-value pairs

let object2 = {
    key1: "value1",
    key2: "value2",
    key3: "value3",
};

console.log(object, object2);       // print the object
console.table({object, object2});    // print the object in table format

let arr = [1, 2, 3, 4, 5];  // array is a collection of values

// type cast 
let num = 10;
num = String(num);  // type cast to string

let str = "10";
str = Number(str);  // type cast to number
str = parseInt(str);  // type cast to integer
str = parseFloat(str);  // type cast to float