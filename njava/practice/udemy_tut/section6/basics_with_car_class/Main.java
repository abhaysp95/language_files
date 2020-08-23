public class Main {
	public static void main(String args[]) {

		// let's create car objects
		// initialization with new keyword(basically this provides the memory to dodge)
		Car dodge = new Car();
		Car ford = new Car();

		// dodge = null;  this will take its memory back, so no initialization only declaration is happened then

		// dodge.model = "Charger 1962";

		// System.out.println("model of dodge: " + dodge.model);

		System.out.println("Model of Dodge is: " + dodge.getModel());
		// returns null, because default return for class and for String(which is also a class) is null
		dodge.setModel("charger");  // valid model acccording to setter of Car
		System.out.println("Model of Dodge is: " + dodge.getModel());
		dodge.setModel("challenger");  // invalid model acccording to setter of Car
		System.out.println("Model of Dodge is: " + dodge.getModel());
	}
}
