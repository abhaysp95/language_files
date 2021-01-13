package com.javafx_example;

import javafx.application.Application;
import javafx.application.Platform;
import javafx.event.ActionEvent;
import javafx.geometry.Insets;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.layout.HBox;
import javafx.stage.Stage;

public class Helloworld extends Application {
	@Override
	public void start(final Stage stage) {
		initUI(stage);
	}
	private void initUI(Stage stage) {
		Button btn = new Button();
		btn.setText("Quit");
		btn.setOnAction((ActionEvent event) -> {
			Platform.exit();
		});

		var root = new HBox();
		root.setPadding(new Insets(25));
		root.getChildren().add(btn);

		var scene = new Scene(root, 280, 200);

		stage.setTitle("Quit Button");
		stage.setScene(scene);
		stage.show();
	}

	public static void main(String[] args) {
		launch(args);
	}
}