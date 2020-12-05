module com.javafx_demo.calculator {
	requires javafx.fxml;
	requires javafx.controls;

	opens com.javafx_demo.calculator to javafx.fxml, javafx.graphics;
}
