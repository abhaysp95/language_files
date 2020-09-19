// make a tip calculator

var bills = new Array();
bills.push(124);
bills.push(48);
bills.push(268);
// or just do var bills = [..., ...];

console.log(bills);

function tipCalculator(bill) {
	if (bill > 200) {
		return bill + (bill * 10) / 100;
	}
	else if (bill > 50 && bill < 200) {
		return bill + (bill * 15) / 100;
	}
	else if (bill < 50) {
		return bill + (bill * 20) / 100;
	}
}

var tips = new Array();
for (var i = 0; i < bills.length; ++i) {
	tips.push(tipCalculator(bills[i]));
}
console.log(tips);

var total = new Array();
for (var i = 0; i < bills.length; ++i) {
	total.push(tips[i] + bills[i]);
}
console.log("Total: " + total);
