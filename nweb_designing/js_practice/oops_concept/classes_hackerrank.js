function Polygon(sides) {
	this.sides = sides;
}

Polygon.prototype.perimeter = function() {
	let sum = 0;
	this.sides.forEach((num) => { sum += num; });
	return sum;
};

let triangle = new Polygon([2, 3, 5]);
console.log(triangle.perimeter());
