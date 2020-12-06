module com.javafx_demo.login {
	requires javafx.fxml;
	requires javafx.controls;

	opens com.javafx_demo.login to javafx.fxml, javafx.graphics;
}
