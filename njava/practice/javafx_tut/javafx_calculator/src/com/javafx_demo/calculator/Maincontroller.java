package com.javafx_demo.calculator;

import javafx.event.ActionEvent;
import javafx.scene.control.Label;
import javafx.scene.control.Button;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;

/**
TODO: pressing ans before getting result through "=" doesn't provides answer,
instead is added to number1 "C" doesn't work yet after getting number1 from
Ans, and same stands for operator which is entered after the number1 obtained
by Ans
*/

public class Maincontroller {

	@FXML private Label query;
	@FXML private Label result;
	String queryString = "";
	private boolean start = true;
	private double number1 = 0;
	private double number2 = 0;
	private String operator = "";
	private boolean useOfOperator = false;
	private boolean usingAns = false;
	private Modelcalculator modelCalc = new Modelcalculator();

	@FXML
	public void processNumbers(ActionEvent event) {
		if (start && (!usingAns)) {
			//result.setText("");
			query.setText("");
			start = false;
		}
		String value = ((Button)event.getSource()).getText();
		//result.setText(result.getText() + value);
		queryString += value;
		if ((!operator.isEmpty()) && (!useOfOperator)) {
			query.setText(query.getText() + " " + value);
			useOfOperator = true;
		}
		else {
			query.setText(query.getText() + value);
		}
	}

	@FXML
	public void processOperator(ActionEvent event) {
		String value = ((Button)event.getSource()).getText();

		if ((!value.equals("=")) && (!value.equals("Ans")) && (!value.equals("Sq."))) {
			if (!operator.isEmpty()) { return; }

			operator = value;
			//number1 = Double.parseDouble(result.getText());
			if (!queryString.isEmpty()) {
				number1 = Double.parseDouble(queryString);
			}
			query.setText(query.getText() + " " + operator);
			System.out.println("number1: " + number1);
			//result.setText("");
			queryString = "";
		}
		else if (value.equals("Ans")) {
			usingAns = true;
			System.out.println("reached here");
			if (!operator.isEmpty()) {
				operator = "";
			}
			number1 = Double.parseDouble(result.getText());
			System.out.println("ans number1: " + number1);
			query.setText(result.getText());
		}
		else if (value.equals("Sq.")) {
			if (!operator.isEmpty()) { return; }
			operator = value;
			if (!queryString.isEmpty()) {
				number1 = Double.parseDouble(queryString);
			}
			query.setText(query.getText());
			System.out.println("number1: " + number1);
			queryString = "";
			double output = modelCalc.calculate(number1, operator);
			System.out.println("output: " + output);
			result.setText(String.valueOf(output));
			operator = "";
			queryString = "";
			useOfOperator = false;
			usingAns = false;
			start = true;
		}
		else {
			if (operator.isEmpty()) {
				return;
			}
			//double number2 = Double.parseDouble(result.getText());
			number2 = Double.parseDouble(queryString);
			System.out.println("number2: " + number2);
			double output = modelCalc.calculate(number1, number2, operator);
			System.out.println("output: " + output);
			result.setText(String.valueOf(output));
			operator = "";
			queryString = "";
			useOfOperator = false;
			usingAns = false;
			start = true;
		}
	}

	@FXML
	public void processDelete(ActionEvent event) {
		String value = ((Button)event.getSource()).getText();
		switch(value) {
			case "CE":
				number1 = 0.0;
				operator = "";
				queryString = "";
				start = true;
				useOfOperator = false;
				usingAns = false;
				if (!result.getText().isEmpty()) {
					result.setText("0");
				}
				if (!query.getText().isEmpty()) {
					query.setText("Query");
				}
				break;
			case "C":
				if (number1 == 0.0) {
					if (!queryString.isEmpty()) {
						queryString = queryString.substring(0, queryString.length() - 1);
						query.setText(queryString);
					}
				}
				else if ((number2 == 0.0) && (!operator.isEmpty())) {
					operator = "";
					useOfOperator = false;
					query.setText(query.getText().substring(0, query.getText().length() - 1));
				}
				else {
					if (!queryString.isEmpty()) {
						queryString = queryString.substring(0, queryString.length() - 1);
						query.setText(number1 + " " + operator + " " + queryString);
					}
				}
		}
	}
}