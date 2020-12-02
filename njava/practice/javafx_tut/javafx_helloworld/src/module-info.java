module com.javafx_demo {
	requires javafx.fxml;
	requires javafx.controls;

	opens com.javafx_demo to javafx.graphics;
}
