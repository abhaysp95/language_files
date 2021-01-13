module com.javafx_demo.combobox {
	requires javafx.fxml;
	requires javafx.controls;

	opens com.javafx_demo.combobox to javafx.fxml, javafx.graphics;
}
