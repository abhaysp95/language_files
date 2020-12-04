package com.javafx_event;

import javafx.event.ActionEvent;
import javafx.scene.control.Label;
import javafx.fxml.FXML;

import java.util.Random;

public class Controller {

	// annotation that tags a class or member accessible to markup
	@FXML
	private Label myRandomNum;
	public void generateRandom(ActionEvent event) {
		Random rand = new Random();
		int rand_num = rand.nextInt(50) + 1;
		myRandomNum.setText(Integer.toString(rand_num));
		System.out.println(Integer.toString(rand_num));
	}
}
