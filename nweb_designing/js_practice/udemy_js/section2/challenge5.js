// again with tipping

var john = {
	bills: [124, 48, 268, 180, 42],
	tips: new Array(),
	totals: new Array(),
	getTip: function(bill, per) {
		return (bill * per) / 100;
	},
	tipCalc: function() {
		let i = 0;
		while (i < this.bills.length) {
			if (this.bills[i] > 200) {
				this.tips.push(this.getTip(this.bills[i], 10));
				this.totals.push(this.tips[i] + this.bills[i]);
			}
			else if (this.bills[i] > 50 && this.bills[i] <= 200) {
				this.tips.push(this.getTip(this.bills[i], 15));
			}
			else if (this.bills[i] <= 50) {
				this.tips.push(this.getTip(this.bills[i], 20));
				this.totals.push(this.tips[i] + this.bills[i]);
			}
			++i;
		}
	}
}

var mark = {
	bills: [77, 375, 110, 45],
	tips: new Array(),
	totals: new Array(),
	putTips: function(tip, total) {
		this.tips.push(tip);
		this.totals.push(total);
	},
	getTip: function(bill, per) {
		return (bill * per) / 100;
	},
	tipCalc: function() {
		let i = 0;
		let tip = 0;
		let total = 0;
		while (i < this.bills.length) {
			if (this.bills[i] > 300) {
				tip = this.getTip(this.bills[i], 30);
				total = this.bills[i] + tip;
				this.putTips(tip, total);
			}
			else if (this.bills[i] > 100 && this.bills[i] <= 300) {
				tip = this.getTip(this.bills[i], 10);
				total = this.bills[i] + tip;
				this.putTips(tip, total);
			}
			else if (this.bills[i] <= 100) {
				tip = this.getTip(this.bills[i], 20);
				total = this.bills[i] + tip;
				this.putTips(tip, total);
			}
			++i;
		}
	}
}

john.tipCalc();
mark.tipCalc();
console.log(john);
console.log(mark);

var averageTip = function(tipArray) {
	let sum = 0;
	for (let i = 0; i < tipArray.length; ++i) {
		sum += tipArray[i];
	}
	return Math.round(sum * 100 / tipArray.length) / 100;
}

console.log("Tip Average for John: " + averageTip(john.tips) + "$.");
console.log("Tip Average for Mark: " + averageTip(mark.tips) + "$.");
