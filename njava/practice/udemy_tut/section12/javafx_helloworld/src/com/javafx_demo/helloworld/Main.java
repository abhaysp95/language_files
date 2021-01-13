package com.javafx_demo.helloworld;

import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.Parent;
import javafx.scene.layout.GridPane;
import javafx.fxml.FXMLLoader;
import javafx.stage.Stage;
import javafx.geometry.Pos;
import javafx.scene.control.Label;
import javafx.scene.paint.Color;
import javafx.scene.text.Font;
import javafx.scene.text.FontWeight;

public class Main extends Application {

	@Override
	public void start(Stage primaryStage) throws Exception {
		Parent root = FXMLLoader.load(getClass().getResource("/com/javafx_demo/helloworld/javafx_helloworld.fxml"));

		/*GridPane root = new GridPane();
		root.setAlignment(Pos.CENTER);
		root.setVgap(10);
		root.setHgap(10);
		Label greetings = new Label("Welcome to JavaFX");
		greetings.setTextFill(Color.GREEN);
		greetings.setFont(Font.font("Ubuntu Nerd Font", FontWeight.BOLD, 70));
		root.getChildren().add(greetings);*/

		primaryStage.setTitle("Hello JavaFx");
		primaryStage.setScene(new Scene(root, 700, 300));
		primaryStage.show();
	}

	public static void main(String ...args) {
		launch(args);
	}
}