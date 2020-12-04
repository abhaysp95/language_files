package com.javafx_event;

import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.Parent;
import javafx.stage.Stage;
import javafx.scene.layout.BorderPane;
import javafx.fxml.FXMLLoader;

import java.net.URL;
import java.nio.file.Paths;

public class Main extends Application {
	@Override
	public void start(Stage primaryStage) throws Exception {
		//BorderPane root = new BorderPane();
		//URL fxmlURL = Paths.get("/opt/SceneBuilder/app/javafx_event.fxml").toUri().toURL();
		//FXMLLoader loader = new FXMLLoader();
		//Parent root = loader.load(fxmlURL);
		Parent root = FXMLLoader.load(getClass().getResource("javafx_event.fxml"));
		Scene scene = new Scene(root, 400, 300);

		/* use this method(just below) to load the file when it's in you classpath, when you are in bin folder
		   it is treated as your classpath, so everything .java from src is compiled to .class as you do and all
		   other data from src/ should be put to bin respecting the hierarchy of structure */
		scene.getStylesheets().add(getClass().getResource("application.css").toExternalForm());
		/* or you can use below one which is relative to classpath */
		//scene.getStylesheets().add(Paths.get("../src/com/javafx_event/application.css").toUri().toURL().toExternalForm());
		/* you can do samething(above two) to load fxml file(I'm not doing yet
		 * cause I need it on that path so that Scenebuilder can use it) */
		primaryStage.setScene(scene);
		primaryStage.show();
	}

	public static void main(String ...args) {
		launch(args);
	}
}