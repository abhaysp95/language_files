public class Car {

	// private access modifier class variables(fields of this class) are not accessible to other classes
	private int door;
	private int wheels;
	private String model;
	private String engine;
	private String color;

	// setter
	public void setModel(String model) {
		// testing for validation with setter
		String validModel = model.toLowerCase();
		if (validModel.equals("charger") || validModel.equals("f150")) {
			this.model = model;  // this used to access the fields of the class
		}
		else {
			this.model = "Unknown";
		}
	}

	// getter
	public String getModel() {
		return this.model;
	}

}

// if you give it public you need seperate file for this class(also to access this class from another class file) no concept of package here
//class Bike {

	//private int wheels;
	//public String model;
	//private String engine;
	//private String color;
//}
