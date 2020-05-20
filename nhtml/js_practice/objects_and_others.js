var ourDog = {
	// objects are similar to arrays, use property instead of index
	// "property": "value"
	"name": "Camper",
	"legs": 4,
	"tails": 1,
	"friends": ["everythin!", "everyone!"]
};

var testObj = {
	"hat": "ballcap",
	"shirt": "jersey",
	"shoes": "cleats"
};
var hatValue = testObj.hat;
var shirtValue = testObj.shirt;
console.log(hatValue);
console.log(shirtValue);

var testObj = {
	"an entree": "hamburger",
	"my side": "veggies",
	"the drink": "water"
};
var vegi = "my side";
console.log(testObj["an entree"]);
console.log(testObj['the drink']);
console.log(testObj[vegi]);
console.log(testObj);

// updating object properties
ourDog.name = "happy camper";
ourDog.bark = "bow wow";
console.log(ourDog.name);
console.log(ourDog);
delete ourDog.tails;
console.log(ourDog);

// we can use object(dictionary type) in place of switch to lookup values
// compare this example to switch case
function phoneticLookup(val) {
	var result = "";

	var lookup = {
		"alpha": "Adams",
		"bravo": "Boston",
		"charlie": "Chicago",
		"delta": "Denver",
		"echo": "Easy",
		"foxtrot": "Frank"
	};
	result = lookup[val];
	return result;
};
console.log(phoneticLookup('charlie'));


// check for property
var myObj = {
	// properties[keys] are not declared like this in python
	gift: "pony",
	pet: "kitten",
	bed: 'sleigh'
};
console.log(myObj.bed);

// complex manipulation
var myMusic = [
	{
		"artist": "Billy Joel",
		"title": 'Piano Man',
		"formats": [
			"CD", "8T", "LP"
		],
		"gold": true
	},
	{
		"artist": "Beau Carnes",
		"title": "Cereal Man",
		"releas_year": 2003,
		"formats": [
			"mp3", "m4a", "aac"
		]
	},
	{
		"artist name": {
			"first singer": "Arjun",
			"second singer": {
				"first": "Neha",
				"second": "Kakkar"
			}
		},
		song: "La La La",
		plateforms: [
			"youtube", 'gaana', 'spotify'
		]
	}
]
console.log(myMusic[0].formats)
console.log(myMusic[1].formats[2])
console.log(myMusic[2]['artist name']["second singer"].second);


// record collection
var collection = {
	"2548": {
		"album": "Slippery When Wet",
		"artist": "Bon Jovi",
		"tracks": [
			"Let It Rock",
			"You Give Love a Bad Name"
		]
	},
	"2468": {
		"album": "1998",
		"artist": "Prince",
		"tracks": [
			"1999",
			"Little Red Corvette"
		]
	},
	"1245": {
		"artist": "Robert Palmer",
		"tracks": [ ]
	},
	"5439": {
		"album": "ABBA Gold"
	}
}
// keep a copy of collection
var collectionCopy = JSON.parse(JSON.stringify(collection));

function updateCollection(id, prop, value) {
	if (value === "") {
		// delete collection.id.prop;  this isn't working
		delete collection[id][prop];
	}
	else if (prop === "tracks") {
		collection[id][prop] = collection[id][prop] || [];
		collection[id][prop].push(value);
	}
	else {
		collection[id][prop] = value;
	}
	return collection;
}
console.log(updateCollection(5439, "artist", "ABBA"));
console.log(updateCollection(1245, "tracks", "test"))
console.log(collectionCopy);


// loops
var myArray = [];
var i = 0;
while (i < 5) {
	myArray.push(i + 1);
	i++;
}
console.log(myArray)

myArray = [];
for (var i = 1; i < 10; i += 2) {
	myArray.push(i);
}
console.log(myArray)

ourTotal = 0;
for (var i = 0; i < myArray.length; i++) {
	ourTotal += myArray[i]
}
console.log(ourTotal);


// nested loop
function multiplyAll(arr) {
	console.log(arr.length);
	var product = 1;
	var i = 0, j = 0;
	while (i < arr.length) {
		if (arr[i].length > 1) {
			j = 0;
			while (j < arr[i].length) {
				product *= arr[i][j];
				j++;
			}
		}
		else {
			product *= arr[i];
		}
		i++;
	}
	return product;
}
var product = multiplyAll([[1, 2], [10], [3, 4], [5, 6, 7]]);
console.log(product);


// do-while loop
var myArray = [];
var i = 10;
do {
	myArray.push(i);
	i++;
} while (i < 5);
console.log(i, myArray);


// profile lookup
var contacts = [
	{
		"firstname": "Akira",
		"lastname": "Laine",
		"number": "5242242153871",
		"likes": ["Pizza", "Coding", "Brownie Points"]
	},
	{
		"firstname": "Harry",
		"lastname": "Potter",
		"number": "0252185227434",
		"likes": ["Hogwarts", "Magic", "Hermoine"]
	},
	{
		"firstname": "Sherlock",
		"lastname": "Holmes",
		"number": "12254201453272",
		"likes": ["Intriguing Cases", "Violen", "John Watson"]
	},
	{
		"firstname": "Kristian",
		"lastname": "Vos",
		"number": "unknown",
		"likes": ["JavaScript", "Gaming", "Foxes"]
	},
]

function lookUpProfile(name, prop) {
	for (var i = 0; i < contacts.length; i++) {
		if (contacts[i].firstname === name) {
			return contacts[i][prop] || "No Such Property";
		}
	}
	return "No Such Contacts";
}

function lookUpProfile2(name, prop) {
	var i = 0;
	while (i < contacts.length) {
		if (name === contacts[i].firstname) {
			if (contacts[i][prop] !== undefined) {
				if (prop === "likes") {
					return JSON.stringify(contacts[i][prop]);
				}
				else {
					return contacts[i][prop];
				}
			}
			else {
				return "No Such Property";
			}
		}
		i++;
	}
	return "No Such Contact";
}
var data = lookUpProfile2("Akira", "dots");
console.log(data);


// generate random number(decimal)
function randomFraction() {
	// randome between 0 and 1
	return Math.random();
}
console.log(randomFraction());


// random whole number
function randomWholeNum() {
	// random whole num bt. 0 and 9
	return Math.floor(Math.random() * 10);
}
console.log(randomWholeNum());


// random whole number between range
function ourRandomRange(ourMin, ourMax) {
	// including max number
	return Math.floor(Math.random() * (ourMax - ourMin +1)) + ourMin;
}
console.log(ourRandomRange(5, 10));


// using parseInt function
function convertToInterger(str) {
	console.log(typeof str)
	console.log(typeof parseInt(str));
	return parseInt(str);
}
console.log(convertToInterger("56"));


// parseInt with Radix
// Radix specifies the base of the number in string
function convertToInterger2(str) {
	// converts the binary to decimal int
	console.log(typeof parseInt(str, 2));
	return parseInt(str, 2);
}
console.log(convertToInterger2("100011"));


// ternary operator
function checkEqual(num1, num2) {
	// below line is same to return num1 === num2,
	// which will return true or false
	return num1 === num2 ? true : false
}
console.log(checkEqual(5, 4));

function checkSign(num) {
	return (num < 0) ? "Negative" : (num === 0) ? "Zero" : "Positive";
}
console.log(checkSign(10));
