package com.javafx_demo.calculator;

import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.Parent;
import javafx.stage.Stage;
import javafx.fxml.FXMLLoader;

public class Main extends Application {

	@Override
	public void start(Stage primaryStage) throws Exception {
		Parent root = FXMLLoader.load(getClass().getResource("javafx_calculator.fxml"));
		Scene scene = new Scene(root, 364, 357);
		primaryStage.setScene(scene);
		primaryStage.show();
	}
	public static void main(String ...args) {
		launch(args);
	}
}