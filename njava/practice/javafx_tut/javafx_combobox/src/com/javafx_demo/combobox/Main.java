package com.javafx_demo.combobox;

import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.Parent;
import javafx.stage.Stage;
import javafx.fxml.FXMLLoader;

public class Main extends Application {
	@Override
	public void start(Stage primaryStage) throws Exception {
		Parent root = FXMLLoader.load(getClass().getResource("/com/javafx_demo/combobox/javafx_combobox.fxml"));
		Scene scene = new Scene(root, 400, 400);
		primaryStage.setScene(scene);
		primaryStage.show();
	}
	public static void main(String ...args) {
		launch(args);
	}
}