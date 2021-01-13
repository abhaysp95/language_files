package com.javafx_demo.events;

import javafx.application.Application;
import javafx.stage.Stage;
import javafx.scene.Scene;
import javafx.scene.Parent;
import javafx.fxml.FXMLLoader;

public class Main extends Application {

	@Override
	public void start(Stage primaryStage) throws Exception {
		Parent root = FXMLLoader.load(getClass().getResource("/com/javafx_demo/events/javafx_events.fxml"));
		primaryStage.setTitle("javafx_events");
		primaryStage.setScene(new Scene(root, 400, 400));
		primaryStage.show();
	}
	public static void main(String ...args) {
		launch(args);
	}
}


/* errors setproj:

   not giving com when src is used as source in update_files.sh

	not providing ext to fxml file in FXMLLoader

	if Controller class is created see a why to provide it in fxml file

	*/