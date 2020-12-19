const inputBox = document.getElementById("res");
inputBox.value = "";

// update the resultant with the input query and clear after the result
function changeInputBox(e) {
	let btn = e.target || e.srcElement;
	if (isResultantFound) {
		inputBox.value = "";
		isResultantFound = false;
	}
	inputBox.value += document.getElementById(btn.id).innerText;
}

// to check if we got the result of the input query
var isResultantFound = false;

// process output according to the provided input
function processOutput(inputString) {
	let re = /^(?<operand1>[0-1]+)(?<operator>\+|-|\*|\/)(?<operand2>[0-1]+)$/gm;
	let result = re.exec(inputString)
	let operand1 = result.groups["operand1"];
	let operand2 = result.groups["operand2"];
	let operator = result.groups["operator"];
	let resultant = 0;

	switch(operator) {
		case "+":
			resultant = performAddition(operand1, operand2);
			break;
		case "-":
			resultant = performSubtraction(operand1, operand2);
			break;
		case "*":
			resultant = performMultiplication(operand1, operand2);
			break;
		case "/":
			resultant = performDivision(operand1, operand2);
			break;
	}

	inputBox.value = resultant;
	isResultantFound = true;
}

// logic to perform addition on two numbers(strings)
function performAddition(num1, num2) {
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
	// if carry after the last bit addition is left
	if (carry) {
		sum.push(carry);
	}
	return sum.reverse().join('');  // return back the string
}

// make the numbers same with adding '0' upto to the number of max number's length
// helpful for substraction
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

// provide twos' compliment of provided number
function doTwosCompliment(number) {
	let temp = number;
	let invertNum = new Array();
	let count = number.length;
	// goes upto the length of entered number which we don't want
	// (say if inversion is 001100, 00 of starting will be removed)
	while (count--) {
		if (number > 0) {
			let remainder = number % 10;
			number = parseInt(number / 10);
			invertNum.push(remainder ? "0" : "1");
		}
		else {
			invertNum.push("1");  // invert all 0s from the left side
		}
	}
	let twosCompliment = performAddition(invertNum.reverse().join(''), 1);
	let recievedNumbers = makeSameBit(temp, twosCompliment);  // again make same bit
	return recievedNumbers[1]; // return the twos compliment
}

// logic to perform subtraction(takes two strings of number)
function performSubtraction(num1, num2) {
	let numbers = makeSameBit(num1, num2);  // returns an array
	let subtractFrom = numbers[0];
	let subtractNum = doTwosCompliment(numbers[1]);
	let subtractionResult;
	let gotAdditionResult = performAddition(subtractFrom, subtractNum);
	// if length of result is less than subtracter then add 0s upto the subtracter's length
	// so that we get correct twos compliment
	if (gotAdditionResult.length < subtractNum.length) {
		let count = subtractNum.length - gotAdditionResult.length;
		let temp = gotAdditionResult.split('');
		while (count--) {
			temp.unshift("0");
		}
		gotAdditionResult = temp.join('');
	}
	// check if we need to get twos compliment
	// if left most bit is 1(as carry) then no, if left most is 0(as carry) or no
	// left most bit(it means that results length is not greater than both numbers)
	// then yes
	if ((gotAdditionResult.length > subtractFrom.length)
		|| (gotAdditionResult.length > subtractNum.length)) {
		// remove left most bit('1')
		gotAdditionResult = gotAdditionResult.split('');
		gotAdditionResult.shift();
		subtractionResult = gotAdditionResult.join('');
	}
	else {
		// get twos compliment and add '-' before
		let result = () => {
			let tempResult = doTwosCompliment(gotAdditionResult).split('');
			tempResult.unshift("-");
			return tempResult.join("");
		}
		subtractionResult = result();
	}
	return subtractionResult;
}

// logic to perform multiplication
function performMultiplication(num1, num2) {
	num2 = parseInt(num2);
	let count = 0;
	let allNumbers = new Array();
	// repeation upto the length of second number(just like in real decimal multiplication)
	while (num2 > 0) {
		let remainder = num2 % 10;
		num2 = parseInt(num2 / 10);
		// since binary only have 0 and 1, so perform multiplication only when
		// there is 1 as remainder, and put 0 as per count at right
		if (remainder == 1) {
			allNumbers.push(num1 + "0".repeat(count));
		}
		count++;
	}
	let sum = allNumbers[0];
	// perform addition like ((l1 + l2) + l3)
	allNumbers.forEach((part, index) => {
		if (index > 0) {
			sum = performAddition(sum, part);
		}
	});
	return sum;  // return result as string
}

// logic to perform division
function performDivision(num1, num2) {
	let arrNum1 = num1.split('');
	let quotient = new Array();
	let lastRemainder;
	if (parseInt(num1) < parseInt(num2)) {
		return "0";  // if dividend is small than divisor
	}
	else {
		quotient.push("1");
	}
	// get dividend for the first time
	let getDividend = (parseInt(num2) > parseInt(arrNum1.slice(0, num2.length).join('')))
		? arrNum1.slice(0, num2.length + 1).join('')
		: arrNum1.slice(0, num2.length).join('');
	// go upto the length of original dividend starting after the previously got dividend
	for (let i = getDividend.length; i <= arrNum1.length; ++i) {
		if (i == arrNum1.length) {
			// on extra iteration to find out the final remainder of division
			lastRemainder = performSubtraction(getDividend, num2);
			break;
		}
		let remainder = performSubtraction(getDividend, num2);  // remainder after every iteraiton
		getDividend = remainder + arrNum1[i];
		if (parseInt(num2) > parseInt(getDividend)) {
			getDividend += arrNum1[++i];  // when we have to add 0 to take down one more number from dividend
			quotient.push("01");
		}
		else {
			quotient.push("1");
		}
	}
	console.log("remainder: " + lastRemainder);  // print remainder of division
	return quotient.join("");  // return quotient as string
}



// perform action when buttons are clicked
const buttons = document.getElementById("btns");
buttons.querySelector("#btn0").addEventListener("click", changeInputBox);
buttons.querySelector("#btn1").addEventListener("click", changeInputBox);
buttons.querySelector("#btnSum").addEventListener("click", changeInputBox);
buttons.querySelector("#btnSub").addEventListener("click", changeInputBox);
buttons.querySelector("#btnMul").addEventListener("click", changeInputBox);
buttons.querySelector("#btnDiv").addEventListener("click", changeInputBox);
buttons.querySelector("#btnClr").addEventListener("click", () => { inputBox.value = ""; })
buttons.querySelector("#btnEql").addEventListener("click", () => {
	processOutput(inputBox.value);
});
