function doSum(num1, num2) {
	let sum = new Array();
	let carry = 0;
	num1 = parseInt(num1);
	num2 = parseInt(num2);
	while (num1 > 0 || num2 > 0) {
		sum.push(parseInt(((num1 % 10) + (num2 % 10) + carry) % 2));
		carry = parseInt(((num1 % 10) + (num2 % 10) + carry) / 2);
		num1 = parseInt(num1 / 10);
		num2 = parseInt(num2 / 10);
	}
	if (carry) {
		sum.push(carry);
	}
	return sum.reverse().join('');
}

function makeSameBit(num1, num2) {
	let ifBigNumIsNum1 = false;
	let bigNumber;
	if (num1.length > num2.length) {
		bigNumber = num1;
		ifBigNumIsNum1 = true;
	}
	else {
		bigNumber = num2;
	}
	let editNum = ifBigNumIsNum1 ? num2.split('') : num1.split('');
	while (editNum.length != bigNumber.length) {
		editNum.unshift("0");
	}
	return ifBigNumIsNum1 ? [num1, editNum.join('')] : [editNum.join(''), num2];
}

function doTwosCompliment(number) {
	let temp = number;
	let invertNum = new Array();
	let count = number.length;
	while (count--) {
		if (number > 0) {
			let remainder = number % 10;
			number = parseInt(number / 10);
			invertNum.push(remainder ? "0" : "1");
		}
		else {
			invertNum.push("1");
		}
	}
	let twosCompliment = doSum(invertNum.reverse().join(''), 1);
	let recievedNumbers = makeSameBit(temp, twosCompliment);
	return recievedNumbers[1];
}

function doSubtract(num1, num2) {
	let numbers = makeSameBit(num1, num2);
	let subtractFrom = numbers[0];
	let subtractNum = doTwosCompliment(numbers[1]);
	let subtractionResult;
	let gotAdditionResult = doSum(subtractFrom, subtractNum);
	if (gotAdditionResult.length < subtractNum.length) {
		let count = subtractNum.length - gotAdditionResult.length;
		let temp = gotAdditionResult.split('');
		while (count--) {
			temp.unshift("0");
		}
		gotAdditionResult = temp.join('');
	}
	if ((gotAdditionResult.length > subtractFrom.length)
		|| (gotAdditionResult.length > subtractNum.length)) {
		gotAdditionResult = gotAdditionResult.split('');
		gotAdditionResult.shift();
		subtractionResult = gotAdditionResult.join('');
	}
	else {
		let result = () => {
			let tempResult = doTwosCompliment(gotAdditionResult).split('');
			tempResult.unshift("-");
			return tempResult.join("");
		}
		subtractionResult = result();
	}
	return subtractionResult;
}

function doMultiplication(num1, num2) {
	num2 = parseInt(num2);
	let count = 0;
	let allNumbers = new Array();
	while (num2 > 0) {
		let remainder = num2 % 10;
		num2 = parseInt(num2 / 10);
		if (remainder == 1) {
			allNumbers.push(num1 + "0".repeat(count));
		}
		count++;
	}
	let sum = allNumbers[0];
	allNumbers.forEach((part, index) => {
		if (index > 0) {
			sum = doSum(sum, part);
		}
	});
	return sum;
}

function doDivision(num1, num2) {
	let arrNum1 = num1.split('');
	let quotient = new Array();
	let lastRemainder;
	if (parseInt(num1) < parseInt(num2)) {
		return "0";
	}
	else {
		quotient.push("1");
	}
	let getDividend = (parseInt(num2) > parseInt(arrNum1.slice(0, num2.length).join('')))
		? arrNum1.slice(0, num2.length + 1).join('')
		: arrNum1.slice(0, num2.length).join('');
	for (let i = getDividend.length; i <=arrNum1.length; ++i) {
		if (i == arrNum1.length) {
			lastRemainder = doSubtract(getDividend, num2);
			break;
		}
		let remainder = doSubtract(getDividend, num2);
		getDividend = remainder + arrNum1[i];
		if (parseInt(num2) > parseInt(getDividend)) {
			getDividend += arrNum1[++i];
			quotient.push("01");
		}
		else {
			quotient.push("1");
		}
	}
	console.log("remainder: " + lastRemainder);
	return quotient.join("");
}


function toCallFunctions() {
	console.log(doSum("10011", "1011"));
	console.log("---------------------");
	console.log(doTwosCompliment("110101"));
	console.log("---------------------");
	console.log(doSubtract("10110", "110101"));
	console.log(doSubtract("101101", "11010"));
	console.log(doSubtract("10110", "111101"));
	console.log(doSubtract("1101", "1010"));
	console.log("---------------------");
	console.log(doMultiplication("10111", "11"));
	console.log(doMultiplication("10111", "1011"));
	console.log("---------------------");
	console.log(doDivision("100111", "101"));
	console.log(doDivision("11001", "101"));
	console.log(doDivision("101010101", "11001100"));
}

toCallFunctions();

