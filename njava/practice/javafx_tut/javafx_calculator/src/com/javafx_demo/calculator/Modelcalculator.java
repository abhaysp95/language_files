package com.javafx_demo.calculator;

public class Modelcalculator {
	public double calculate(double firstNum, double secondNum, String operator) {
		double value = 0.0;
		switch (operator) {
			case "+":
				value = firstNum + secondNum;
				break;
			case "-":
				value = firstNum - secondNum;
				break;
			case "*":
				value = firstNum * secondNum;
				break;
			case "/":
				if (secondNum == 0) {
					value = -0.0;
				}
					value = firstNum / secondNum;
				break;
			case "%":
				value = firstNum % secondNum;
				break;
			default:
				break;
		}
		return value;
	}

	public double calculate(double number, String operator) {
		double value = 0.0;
		switch (operator) {
			case "Sq.":
				value = Math.sqrt(number);
				break;
			default:
				break;
		}
		return value;
	}
}