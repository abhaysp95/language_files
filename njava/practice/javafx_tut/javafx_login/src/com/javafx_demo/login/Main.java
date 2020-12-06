package com.javafx_demo.login;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.Parent;
import javafx.stage.Stage;
import javafx.fxml.FXMLLoader;

class Credentials {
	private String userName;
	private String password;


	Credentials() {
		this("nothing@none", "noPassword");
	}

	Credentials(String userName, String password) {
		this.userName = userName;
		this.password = password;
	}

	public String getUserName() { return this.userName; }
	public String getPassword() { return this.password; }

	public void getCredentials() {
		try (BufferedReader bf = new BufferedReader(new InputStreamReader(System.in))) {
			System.out.print("Input username: ");
			this.userName = bf.readLine();
			System.out.println("Input password: ");
			this.password = bf.readLine();
		}
		catch (IOException ie) {
			System.out.println("Some error in input: " + ie);
		}
	}
}


public class Main extends Application {

	@Override
	public void start(Stage primaryStage) throws Exception {
		// you can have file name w.r.t package or just the name itself
		Parent root = FXMLLoader.load(getClass().getResource("/com/javafx_demo/login/javafx_login.fxml"));
		Scene scene = new Scene(root, 400, 400);
		primaryStage.setScene(scene);
		primaryStage.show();
	}

	public static void main(String ...args) {
		launch(args);
	}
}