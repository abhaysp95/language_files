

function repeat(n, action) {
	for (let i = 0; i < n; ++i) {
		action(i);
	}
}

// We don't necessarily have to pass the predifined function as action, it could be created spot on

let labels = [];
repeat(5, i => {
	labels.push(`Unit ${i + 1}`);
})

let newLabels = [];
repeat(10, function(i) {
	newLabels.push(`Unit: ${i + 1}`)
})

console.log(labels);
console.log(newLabels);

//export { repeat };

// exporting a module

module.exports = { repeat, labels };


// Another way to exports function is to define functions inside module.exports object

module.exports = {
	add: (x, y) => {
		return x + y;
	},
	subtract: (x, y) => {
		return x - y;
	}
}

// you can also define each function independently as method of module.exports
module.exports.multiply = (x, y) => {
	return x * y;
}
module.exports.divide = (x, y) => {
	return x / y;
}
