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
    document.URL   // gives the URL of the page
    document.domain   // gives the domain of the page
    document.getElementById("id")   // gives the element with the id
    document.getElementsByClassName("class")   // gives the elements with the class

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
console.table({ object1, object2 });    // print the object in table format

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

for (element of arr) {
    console.log(element);
}


let result = arr.filter(element => {        // filter function can return elements of array based on condition
    return element > 2;
});


// get all odd numbers in array and add 5 to em

let result2 = arr.filter(element => {
    return element % 2 !== 0;
}).map(element => {
    return element + 5;
});

console.log(result2);


// reduce
let sum = arr.reduce((acc, element) => {    // reduce function can return a single value
    return acc + element;
}, 0);


// find
let found = arr.find(element => {           // find function can return the first element that satisfies the condition
    return element > 2;
});

// some
let some = arr.some(element => {            // some function can return true if any of the elements satisfy the condition
    return element > 2;
});


// find min in an array
const numbers = [10, 5, 8, 3, 9];  // Array of numbers
const min = Math.min(...numbers);   // Expands array and finds the min value
console.log(min); // Output: 3


// thiss is better forr large arrays
const numbers = [10, 5, 8, 3, 9];
const min = numbers.reduce((a, b) => Math.min(a, b));
console.log(min); // Output: 3

// find max in an array
const numbers = [10, 5, 8, 3, 9];  // Array of numbers
const max = Math.max(...numbers);   // Expands array and finds the max value
console.log(max); // Output: 10

// thiss is better forr large arrays
const numbers = [10, 5, 8, 3, 9];
const max = numbers.reduce((a, b) => Math.max(a, b));
console.log(max); // Output: 10

//math functions
let num1 = 10;
let num2 = 20;
console.log(Math.max(num1, num2));  // max of two numbers
console.log(Math.min(num1, num2));  // min of two numbers
console.log(Math.abs(num1));  // absolute value of a number
console.log(Math.sqrt(num1));  // square root of a number
console.log(Math.pow(num1, 2));  // power of a number
console.log(Math.round(num1));  // round a number
console.log(Math.floor(num1));  // floor of a number
console.log(Math.ceil(num1));  // ceil of a number
console.log(Math.random());  // random number between 0 and 1
console.log(Math.random() * 10);  // random number between 0 and 10
console.log((Math.random() * (maxval - minval)) + minval);  // random number between minval and maxval


//date and time
let date = new Date();  // current date and time
console.log(date);  // current date and time
console.log(date.getDate());  // current date
console.log(date.getMonth());  // current month
console.log(date.getFullYear());  // current year
console.log(date.getHours());  // current hour
let date2 = new Date("2023-10-01");  // date object with specific date
console.log(date2);  // date object with specific date


//labels in loop
outerloop:
for (let i = 0; i < 5; i++) {
    for (let j = 0; j < 5; j++) {
        if (i === 2 && j === 2) {
            break outerloop;  // break the outer loop
        }
        console.log(i, j);
    }
}

//functions
<html>
    <head>
        <script type="text/javascript">
            function sayHello() {
                document.writeln("Hello there!");
            }
        </script>
    </head>
    <body>
        <p>Click the following button to call the function</p>
        <form>
            <input type="button" onclick="sayHello()" value="Say Hello"></input>
        </form>
        <p>Use different text in write method and then try...</p>
    </body>
</html>

// Events 
// Events are actions that occur in the browser, such as a user clicking a button, submitting a form, or moving the mouse. JavaScript can respond to these events using event listeners.
// Event listeners are functions that are called when an event occurs. They can be added to HTML elements using the `addEventListener` method, which takes two arguments: the event type and the function to be called when the event occurs. For example, to add a click event listener to a button, you can use the following code:
// ```javascript
// const button = document.getElementById("myButton");
// button.addEventListener("click", function() {
//     alert("Button clicked!");
// });


/*
Cookies
Cookies are small pieces of data stored on the user's computer by the web browser while browsing a website. They are used to remember information about the user, such as login credentials, preferences, and shopping cart contents.
Cookies are sent to the server with every HTTP request, allowing the server to identify the user and provide a personalized experience.
Cookies can have an expiration date, after which they are deleted from the user's computer. They can also be set to be secure, meaning they will only be sent over HTTPS connections.
Cookies can be accessed and modified using JavaScript, allowing developers to create dynamic and personalized web applications.
Cookies can be set using the `document.cookie` property, and can be deleted by setting the expiration date to a past date.


Redirections
// Redirections are used to send users from one URL to another. This can be done using HTTP status codes, HTML meta tags, or JavaScript.
// Redirections can be used to redirect users to a different page, or to a different domain altogether. They can also be used to redirect users based on their location, device, or other criteria.
// Redirections can be temporary (HTTP status code 302) or permanent (HTTP status code 301). Permanent redirections are cached by the browser, while temporary redirections are not.
// Redirections can also be done using the `window.location` property in JavaScript, which allows developers to change the current URL of the page.
// This can be done using `window.location.href`, `window.location.replace()`, or `window.location.assign()` methods.
// The `window.location.href` method changes the current URL and adds it to the browser's history, allowing users to navigate back to the previous page.
// The `window.location.replace()` method changes the current URL without adding it to the browser's history, effectively replacing the current page. This is useful for redirecting users without allowing them to go back to the previous page.
// The `window.location.assign()` method changes the current URL and adds it to the browser's history, allowing users to navigate back to the previous page. This is similar to `window.location.href`, but allows for more control over the redirection process.
// The `window.location.reload()` method reloads the current page, allowing developers to refresh the page without changing the URL. This can be useful for updating the content of the page without losing the user's place in the document.
// Redirections can also be done using HTML meta tags, which allow developers to specify a URL to redirect to after a certain amount of time. This can be useful for redirecting users to a different page after a certain amount of time has passed, or for redirecting users based on their location or device.
// Redirections can also be done using HTTP status codes, which are sent by the server to indicate the status of the request. For example, a 301 status code indicates that the page has been permanently moved to a new URL, while a 302 status code indicates that the page has been temporarily moved to a new URL. These status codes can be used to redirect users to a different page or domain altogether.
// Redirections can also be done using the `window.location` property in JavaScript, which allows developers to change the current URL of the page. This can be done using `window.location.href`, `window.location.replace()`, or `window.location.assign()` methods.
// The `window.location.href` method changes the current URL and adds it to the browser's history, allowing users to navigate back to the previous page.
// The `window.location.replace()` method changes the current URL without adding it to the browser's history, effectively replacing the current page. This is useful for redirecting users without allowing them to go back to the previous page.
// The `window.location.assign()` metation.href` method changes the current URL and adds it to the browser's history, allowing users to navigate back to the previous page.
// The `window.location.replace()` method changes the current URL without adding it to the browser's history, effectively replacing the current page. This is useful for redirecting users without allowing them to go back to the previous page.
// The `window.location.assign()` method changes the current URL and adds it to the browser's history, allowing users to navigate back to the previous page. This is similar to `window.location.href`, but allows for more control over the redirection process.
hod changes the current URL and adds it to the browser's history, allowing users to navigate back to the previous page. This is similar to `window.location.href`, but allows for more control over the redirection process.
// The `window.location.reload()` method reloads the current page, allowing developers to refresh the page without changing the URL. This can be useful for updating the content of the page without losing the user's place in the document.
// Redirections can also be done using HTML meta tags, which allow developers to specify a URL to redirect to after a certain amount of time. This can be useful for redirecting users to a different page after a certain amount of time has passed, or for redirecting users based on their location or device.
// Redirections can also be done using HTTP status codes, which are sent by the server to indicate the status of the request. For example, a 301 status code indicates that the page has been permanently moved to a new URL, while a 302 status code indicates that the page has been temporarily moved to a new URL. These status codes can be used to redirect users to a different page or domain altogether.
// Redirections can also be done using the `window.location` property in JavaScript, which allows developers to change the current URL of the page. This can be done using `window.location.href`, `window.location.replace()`, or `window.location.assign()` methods.


Dialog boxes
// Dialog boxes are used to display messages to the user and to get input from the user. There are three types of dialog boxes in JavaScript: alert, confirm, and prompt.
// Alert boxes are used to display a message to the user and require the user to click "OK" to close the box. Confirm boxes are used to display a message to the user and require the user to click "OK" or "Cancel" to close the box. Prompt boxes are used to display a message to the user and require the user to enter a value before closing the box.
// Dialog boxes can be used to display messages to the user, get input from the user, and confirm actions. They can also be used to display error messages, warnings, and other types of information to the user. Dialog boxes can be customized using CSS and JavaScript to create a more user-friendly experience. They can also be used to create modal dialogs, which are dialog boxes that require the user to interact with them before they can return to the main page. Modal dialogs can be used to display important information, get input from the user, or confirm actions. They can also be used to create pop-up windows, which are dialog boxes that appear on top of the main page and require the user to interact with them before they can return to the main page.



*/

//defining method for an object
let object3 = {
    key1: "value1",
    key2: "value2",
    key3: "value3",
    method1: function() {
        console.log("Hello World");
    },
    method2: function() {
        console.log("Hello World 2");
    }
};
object3.method1();  // calling the method of the object
object3.method2();  // calling the method of the object


function book(title, author) {
    this.title = title;
    this.author = author;
    this.addPrice = addPrice; // Assign that method as property.
    }
function addPrice(price) {
    this.price = price;
    console.log("Price added: " + price);
    }

    var myBook = new book("Perl", "Mohtashim");


// with keyword
// with keyword is used to access the properties of an object without using the object name
function addPrice(amount) {
    with(this) {
        price = amount;
    }
}



//form validation 

<html>
    <head>
        <script type="text/javascript">
            function validation() {
                var email = document.getElementById("email").value;
                var password = document.getElementById("password").value;
                if (email == "" || password == "") {
                    alert("Email and password are required");
                    document.getElementById("email").style.border = "1px solid red";
                    return false;
                }
                if (email.indexOf("@") == -1) {
                    alert("Email is invalid");
                    document.getElementById("email").style.border = "1px solid red";
                    return false;
                }
                return true;
            }
        </script>
    </head>
    <body>
        <form action="abc.php" method="post" name="myform" onsubmit="return(validation())"> 
            <lable for="email">Email:</label>
            <input type="text" id="email" placeholder="Enter your email" />
            <input type="text" id="password" placeholder="Enter your password" />
            <input type="submit" value="Submit" />
        </form>
    </body>
</html>