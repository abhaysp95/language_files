module com.javafx_demo.helloworld {
	requires javafx.fxml;
	requires javafx.controls;

	opens com.javafx_demo.helloworld to javafx.fxml, javafx.graphics;
}
