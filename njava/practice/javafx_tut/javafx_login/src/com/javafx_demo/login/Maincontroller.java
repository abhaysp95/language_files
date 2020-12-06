package com.javafx_demo.login;

import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.scene.control.Label;
import javafx.scene.control.Button;
import javafx.scene.control.TextField;
import javafx.event.ActionEvent;
import javafx.scene.Scene;
import javafx.scene.Parent;
import javafx.stage.Stage;

import java.io.IOException;

public class Maincontroller {
	@FXML private Label loginStatus;
	@FXML private TextField userName;
	@FXML private TextField password;

	private Credentials credentials = new Credentials();

	public void Login(ActionEvent event) throws IOException {
		if ((userName.getText().equals(credentials.getUserName())) &&
				(password.getText().equals(credentials.getPassword()))) {
			System.out.println("Login Successful");
			loginStatus.setText("Login Successful");
			((Stage)(((Button)event.getSource()).getScene().getWindow())).close();

			Parent root = FXMLLoader.load(getClass().getResource("/com/javafx_demo/login/javafx_main.fxml"));
			Stage mainStage = new Stage();
			Scene scene = new Scene(root, 400, 400);
			mainStage.setScene(scene);
			mainStage.show();
		}
		else {
			System.out.println("Login Failed, Try Again");
			loginStatus.setText("Login Failed, Try Again");
		}
	}
}