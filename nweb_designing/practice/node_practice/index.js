//const bar = () => console.log("bar");

//const baz = () => console.log("baz");

//const foo = () => {
	//console.log("foo")
	//bar()
	//setTimeout(bar, 1000)
	//baz()
	//setTimeout(baz, 200)
//}

//foo()

// in event loop, any function that is making a delay will be executed at the end of application

// callback is a function that is passed into another function as an argument to be executed later

// let's set a need for callback first

//function getMessage() {
	//console.log("This is getMessage function");
//}

//function displayMessage() {
	//console.log("This is displayMessage function");
//}

//getMessage()
//displayMessage()

// this time callstack have getMessage called first and displayMessage second, now if we change getMessage a little(to make it do delay)

//function getMessage() {
	//setTimeout(() => {
		//console.log("This is getMessage function");
	//}, 1000)
//}

//getMessage()
//displayMessage()

// Now displayMessage is called first(as expected), but if we want to getMessage to displayed first, then we can use callback
// let's write it again

//function getMessage(msg, callback) {
	//setTimeout(() => {
		//console.log(msg);
		//callback();  // this here is a function called(passed as callback function)
	//}, 1000);
//}

//getMessage("This is getMessage function", displayMessage);
// displayMessage here is passed as a callback function

//getMessage("getMessage", () => console.log("displayMessage"))


// Promises

// way to execute the result of a async funciton asap rather than been put at the end of callstack
// promise is a class, so we have to create instance of it

//let promise = new Promise((resolve, reject) => {
	//setTimeout(() => resolve("Run before"), 1000)
	//setTimeout(() => reject(new Error("Wrrooooong"), 1000))
//})
// this will execute the promise after 1 sec

// promise class has a function as constructor with 2 argument,
// resolve => returns the successful result
// reject => returns the error msg(result)

// resolve above is ran as a function to return the result

// now result of both type is return to the then method

//promise.then(
	//result => console.log("from result: ", result),
	//result => {
		//console.log("from result: ", result);
		//afterPromise()
	//},
	//error => console.log("from error: ", error)
//);

// then method have 2 arguments, result and error
// using result arg, you can get the resolve message(result data)
// with error, you'll get error data

// now benefit is, you can give the function which you want to execute after promise inside Promise::then() method

//let afterPromise = () => console.log("this is after promise");


// Async and await are built on promises

//function clown() {
	//return new Promise(resolve => {
		//setTimeout(() => {
			//resolve("resolved clown")
		//}, 2000)
	//})
//}

//function msg() {
	//const msg = clown()  // now this is showing pending
	//console.log("msg: ", msg);
//}

//async function msg(callback) {
	//const msg = await clown()
	//console.log("msg: ", msg);
	//callback()
//}

// function with async will wait for the promises to return something,
// await is new operator, used to wait for a promise to resolve or reject
// await can only be used inside async function
// await informes async about promise

//msg(getResult) // callback is not needed in async(it's just an example I showed)

//function getResult() {
	//console.log("This is getResult function");
//}


// HTTP Server

const http = require('http')

//const hostname = '127.0.0.1'
//const port = 3000

//const server = http.createServer((req, res) => {
	//res.statusCode = 200;
	//res.setHeader("Content-Type": "text/plain");
	//res.end("Welcome to HTTP Server")
//})

//server.listen(port, hostname, () => {  // making the above created server run
	//console.log("Welcome to HTTP Server(127.0.0.1)");
//})

// this below is also a valid way

//http.createServer((req, res) => {
	//res.writeHead(200, {"Content-Type": "text/plain"})
	//res.write("Welcome to HTTP Server")
	//res.end()
//}).listen(
	//port, hostname, () => console.log("Welcome to HTTP Server(127.0.0.1)"
	//));

// Making HTTP Request

http.get("http://api.open-notify.org/astros.json", resp => {
	// on method is taking event as 1st arg and callback fn as 2nd argument
	// the 'data' event collects the data from the request
	// on getting data from this url 'on' method will automatically trigger
	let data = "";
	resp.on('data', chunk => {
		data += chunk
	});
	// when all the data is recieved from the request using 'data' event, 'end' event is automatically fired
	//resp.on('end', () => console.log(data));
	resp.on('end', () => {
		let jsondata = JSON.parse(data);
		console.log(jsondata);
	})
})
