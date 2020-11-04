/* A common data structure is 'list'. A list is a nested set of objects, with
	* the first object holding a reference to the second, the second to the
	* third, and so on */

let list = {
	value: 1,
	rest: {
		value: 2,
		rest: {
			value: 3,
			rest: null
		}
	}
}

/* You can have a general gist that it's sort of like linked list, and in the
 * above example every rest knows about it's nested block having a value and
 * rest pointing to another block(except rest with null) */

/* lists can share parts of their structure */

/*let flist = {
	value: 0,
	rest: list
}

let slist = {
	value: -1,
	rest: list
}*/

/* above are both independent lists, but they share the structure that makes
 * up their last three elements. The orignal list is also still a valid
 * three-element list. */

/*console.log(list);
console.log(flist);
console.log(flist.rest.rest.rest.value);
console.log(flist.rest.rest.rest.rest);
console.log(slist);*/

function arrayToList(array) {
	let list = null;
	for (let i = array.length - 1; i >= 0; --i) {
		list = {
			value: array[i],
			rest: list
		}
	}
	return list;
}

function listToArray(list) {
	let arr = [];
	let tempList = list;
	while (tempList.rest !== null) {
		arr.push(tempList.value);
		tempList = tempList.rest;
	}
	arr.push(tempList.value);  // push last element of list to array
	return arr;
}

function prepend(input, list) {
	return {
		value: input,
		rest: list
	}
}

function showList(list) {
	while (list.rest !== null) {
		console.log(list.value);
		list = list.rest;
	}
	console.log((list.value));  // for last element's value it also shows undefined but why
}

function getElementFromlist(number, list) {
	let count = 0;
	while ((count++ !== number) && (list.rest !== null)) {
		list = list.rest;
	}
	if (number >= count) {
		return undefined;
	}
	else {
		return list.value;
	}
}

// above function with recursive method
function getElementFromlist1(number, list) {
	if ((number == 0) || list.rest === null) {
		if (number === 0) {
			return list.value
		}
		else {
			return undefined;
		}
	}
	return getElementFromlist1(number - 1, list.rest);
}

// just to remeber recursion again, no use in this exercise
/*function factorial(number) {
	if (number == 0) {
		return 1;
	}
	return number * factorial(number - 1);
}*/


console.log(arrayToList([1, 2, 3]));
console.log(listToArray(arrayToList([1, 2, 3])));
showList(arrayToList([1, 2, 3]));

console.log("-------------------------");

console.log(prepend(0, arrayToList([1, 2, 3])));
showList(prepend(0, arrayToList([1, 2, 3])));

console.log("-------------------------");

console.log(getElementFromlist(1, arrayToList([1, 2, 3])));
console.log(getElementFromlist(3, arrayToList([1, 2, 3])));

console.log("-------------------------");

console.log(getElementFromlist1(0, arrayToList([1, 2, 3])));
console.log(getElementFromlist1(1, arrayToList([1, 2, 3])));
console.log(getElementFromlist1(2, arrayToList([1, 2, 3])));
console.log(getElementFromlist1(3, arrayToList([1, 2, 3])));
//console.log(factorial(10));
