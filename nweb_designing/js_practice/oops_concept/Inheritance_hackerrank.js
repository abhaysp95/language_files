class Rectangle {
	constructor(w, h) {
		this.w = w;
		this.h = h;
	}
};

Rectangle.prototype.area = function() {
	return this.h * this.w;
}

class Square extends Rectangle {
	constructor(arm) {
		super(arm, arm);
	}
}

const rec = new Rectangle(4, 3);
const sqr = new Square(3);

console.log(rec.area());
console.log(sqr.area());

/* figure out how to do it with prototype */
//function Square(arm) {
	//Rectangle.create(this, arm, arm);
//}

//Square.prototype = Object.create(Rectangle.prototype);

//const rec = new Rectangle(3, 4);
//const sqr = new Square(3);
//console.log(rec.area());
//console.log(sqr.area());

//if (JSON.stringify(Object.getOwnPropertyNames(Square.prototype)) === JSON.stringify(['constructor'])) {
	//const rec = new Rectangle(3, 4);
	//const sqr = new Sqr(3);

	//console.log(rec.area());;
	//console.log(sqr.area());;
//}
//else {
	//console.log(-1);
	//console.log(-1);
//}
