package com.javafx_demo.events;

import javafx.event.ActionEvent;
import javafx.scene.control.TextField;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.CheckBox;
import javafx.application.Platform;
import javafx.fxml.FXML;

public class Controller {

	@FXML private TextField nameField;
	@FXML private Button hellobtn;
	@FXML private Button byebtn;
	@FXML private CheckBox clrCheckBox;
	@FXML private Label ourLabel;

	// runs when our application is initialized
	@FXML
	public void initialize() {
		hellobtn.setDisable(true);
		byebtn.setDisable(true);
	}

	// function is event-handler associated with fxml
	@FXML
	public void onButtonClicked(ActionEvent event) {
		if (event.getSource().equals(hellobtn)) {
			System.out.println("Hello " + nameField.getText());
		}
		else if (event.getSource().equals(byebtn)) {
			System.out.println("Bye " + nameField.getText());
		}

		Runnable task = new Runnable() {

			@Override
			public void run() {
				try {
					String s = Platform.isFxApplicationThread() ? "UI Thread" : "Background Thread";
					System.out.println("I'm going to sleep on " + s);
					Thread.sleep(10000);
					// update the code on UI thread(as Scene graph is not thread safe)
					Platform.runLater(new Runnable() {
						@Override
						public void run() {
							String s = Platform.isFxApplicationThread() ? "UI Thread" : "Background Thread";
							System.out.println("I'm going to sleep on " + s);
							ourLabel.setText("We did something");
						}
					});
				}
				catch (InterruptedException ie) {
				//we don't care about this
				}
			}
		};

		new Thread(task).start();

		if (clrCheckBox.isSelected()) {
			nameField.clear();
			hellobtn.setDisable(true);
			byebtn.setDisable(true);
		}
	}

	@FXML
	public void handleKeyReleased() {
		String text = nameField.getText();
		boolean disableBtn = text.isEmpty() || text.trim().isEmpty();
		hellobtn.setDisable(disableBtn);
		byebtn.setDisable(disableBtn);
	}

	@FXML
	public void handleChange() {
		System.out.println("The checkbox is " + (clrCheckBox.isSelected() ? "checked" : "not checked"));
	}
}