/** module file for project */

module com.javafx_demo.events {
	requires javafx.fxml;
	requires javafx.controls;

	opens com.javafx_demo.events to javafx.fxml, javafx.graphics;
}
                            