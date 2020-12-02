package com.javafx_demo;

import javafx.application.Application;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.fxml.FXMLLoader;
import javafx.scene.Scene;
import javafx.scene.Parent;
import javafx.scene.control.Button;
import javafx.scene.layout.StackPane;
import javafx.scene.layout.VBox;
import javafx.stage.Stage;

public class Helloworld extends Application {

	@Override
	public void start(Stage primaryStage) throws Exception {
		Parent root = FXMLLoader.load(getClass().getResource("/opt/SceneBuilder/app/javafx_helloworld.fxml"));
		Scene scene = new Scene(root);



		// create a button
		/*Button print = new Button("Click To Print");
		Button exit = new Button("Click To Exit");
		// create a layout(other 2 are HBox and VBox(probably))
		print.setOnAction(new EventHandler<ActionEvent>() {

			@Override
			public void handle(ActionEvent event) {
				System.out.println("Hello World");
			}
		});
		// you can use lambda expression here, because handle() is single
		// abstract method inside thie anonymous class of EventHandler
		exit.setOnAction(e -> {
			System.out.println("Exiting Now!!!");
			System.exit(0);
		});
		//StackPane stackPane = new StackPane();
		//stackPane.getChildren().add(btn);
		VBox vb = new VBox();
		//vb.getChildren().add(print);
		// addAll allows us to call multiple widgets
		vb.getChildren().addAll(print, exit);
		Scene scene = new Scene(vb, 500, 300);*/
		primaryStage.setTitle("HelloWorld");
		primaryStage.setScene(scene);
		primaryStage.show();
	}

	public static void main(String[] args) {
		launch(args);
	}
}