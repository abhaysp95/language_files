package com.javafx_demo.combobox;

import java.net.URL;
import java.util.ResourceBundle;

import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.Label;
import javafx.scene.control.Button;
import javafx.scene.control.ComboBox;
import javafx.collections.ObservableList;
import javafx.collections.FXCollections;
import javafx.fxml.Initializable;

public class Maincontroller implements Initializable {
	@FXML private Label selection;
	@FXML private ComboBox<String> comboBox;
	ObservableList list = FXCollections.observableArrayList("one", "two", "three", "four");

	@Override
	public void initialize(URL location, ResourceBundle resources) {
		//comboBox.setItems(list);

		// or you don't need to use initialize() when using with fxml file
	}

	public void changeLabel(ActionEvent event) {
		selection.setText(comboBox.getValue());
	}

	public void duplicate(ActionEvent event) {
		comboBox.getItems().addAll("one", "two", "three");
	}
}