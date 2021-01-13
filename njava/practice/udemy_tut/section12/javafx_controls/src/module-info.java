module com.javafx_demo.controlsdemo {
	requires javafx.fxml;
	requires javafx.controls;

	opens com.javafx_demo.controlsdemo to javafx.fxml, javafx.graphics;
}
