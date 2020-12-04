module com.javafx_event {
	requires javafx.fxml;
	requires javafx.controls;

	opens com.javafx_event to javafx.graphics, javafx.fxml;
}
