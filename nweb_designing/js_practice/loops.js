const arr = ['badger', 'beaver', 'baboon']

// traditional for loop
console.log('tradition')
for (let i = 0; i < arr.length; i++) {
	console.log(arr[i]);
}

// for of loop
console.log('for of loop')
for (const e of arr) {
	console.log(e)
}

// for of on base level
arr[Symbol.iterator] = (() => {
	let i = 0;
	let arr = this;
	return {
		next: function() {
			if (i >= arr.length) {
				return { done: true };
			}
			else {
				const value = arr[i];
				i++;
				return { value, done: false };
			}
		}
	};
})();

// ForEach array
console.log(arr);

arr.forEach(console.log);


// let's check performance
const mil = 10000000;
const Arr = Array(mil);

//console.time('time');
// Arr.forEach(f => null)  // 121ms
//Arr.map(v => v).forEach(v => null);  // 376ms
//console.timeEnd('time');


// loop over an object
const equine = { horse: 'h', zebra: 'z', unicorn: 'u'};
// objects are not iterable by default

// for in loop, loop over the keys
for (const key in equine) {
	console.log(key);
	console.log(equine[key]);
}

console.log(Object.values(equine));
for (const v of Object.values(equine)) {
	console.log(v);
}
