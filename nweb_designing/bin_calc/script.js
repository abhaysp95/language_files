const inputBox = document.getElementById("res");
inputBox.value = "";

function changeInputBox(e) {
	let btn = e.target || e.srcElement;
	if (isResultantFound) {
		inputBox.value = "";
		isResultantFound = false;
	}
	inputBox.value += document.getElementById(btn.id).innerText;
}

var isResultantFound = false;

function processOutput(inputString) {
	let re = /^(?<operand1>[0-1]+)(?<operator>\+|-|\*|\/)(?<operand2>[0-1]+)$/gm;
	let result = re.exec(inputString)
	let operand1 = parseInt(result.groups["operand1"]);
	let operand2 = parseInt(result.groups["operand2"]);
	let operator = result.groups["operator"];
	let resultant = 0;

	switch(operator) {
		case "+":
			resultant = doAdd(operand1, operand2);
			break;
		case "-":
			resultant = doSubtract(operand1, operand2);
			break;
		case "*":
			resultant = doMultiply(operand1, operand2);
			break;
		case "/":
			resultant = doDivide(operand1, operand2);
			break;
	}

	inputBox.value = resultant;
	isResultantFound = true;
}

let doAdd = (num1, num2) => {
	let sum = new Array()
	let carry = 0;
	let i = 0;
	while (num1 > 0 || num2 > 0) {
		//console.log("num1: " + num1);
		//console.log("num2: " + num2);
		sum[i] = parseInt(((num1 % 10) + (num2 % 10) + carry) % 2);
		carry = parseInt(((num1 % 10) + (num2 % 10) + carry) / 2);
		//console.log("sum[i]: " + sum[i]);
		//console.log("carry: " + carry);
		num1 = parseInt(num1 / 10);
		num2 = parseInt(num2 / 10);
		i++;
	}
	if (carry) {
		sum[i] = carry;
	}
	return sum.reverse().join('');
};

let invertNum = (num) => {
	let invertedNum = new Array();
	let i = 0;
	while (num > 0) {
		invertedNum[i++] = (num % 10) ? 0 : 1;
		num = parseInt(num / 10);
	}
	return invertedNum.join('');
}

let makeItEqual = (num1, num2) => {
	let strNum1 = num1 + "";
	let strNum2 = num2 + "";
	let firstNumIsBigInLength = strNum1.length > strNum2.length;
	let newNum;
	if (firstNumIsBigInLength) {
		newNum = strNum2.split('');
		while (newNum.unshift("0") != strNum1.length) {} // nothing ;
		return [num1, parseInt(newNum.join(''))];
	}
	else {
		newNum = strNum1.split('');
		while (newNum.unshift("0") != strNum2.length) {} // nothing
		return [parseInt(newNum.join('')), num2];
	}
}

let doSubtract = (num1, num2) => {
	console.log("num1: " + num1);
	console.log("num2: " + num2);
	console.log("inverted num: " + invertNum(num2));
	let gotInvertedNumWithAdd1 = doAdd(num1, invertNum(num2));
	console.log("gotInvertedNumWithAdd1: " + gotInvertedNumWithAdd1);
	let nums = makeItEqual(num1, gotInvertedNumWithAdd1);
	num1 = nums[0];
	num2 = nums[1];
	console.log("num1: " + num1);
	console.log("num2: " + num2);
}
let doMultiply = (num1, num2) => num1 * num2;
let doDivide = (num1, num2) => num1 / num2;

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
