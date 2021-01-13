package com.javafx_demo.controlsdemo;

import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.Parent;
import javafx.stage.Stage;
import javafx.fxml.FXMLLoader;

public class Main extends Application {

	@Override
	public void start(Stage primaryStage) throws Exception {
		Parent root = FXMLLoader.load(getClass().getResource("javafx_controlsdemo.fxml"));
		primaryStage.setTitle("JavaFx Controls");
		primaryStage.setScene(new Scene(root, 800, 500));
		primaryStage.show();
	}

	public static void main(String ...args) {
		launch(args);
	}
}