class Car {
	private boolean engine;
	private int cylinders;
	private int wheels;
	private String name;

	public Car(int cylinders, String name) {
		this(true, cylinders, 4, name);
	}

	public Car(boolean engine, int cylinders, int wheels, String name) {
		this.engine = engine;
		this.cylinders = cylinders;
		this.wheels = wheels;
		this.name = name;
	}

	public int getCylinders() {
		return this.cylinders;
	}

	public String getName() {
		return this.name;
	}

	public String startEngine() {
		return "Engine of Car started";
	}

	public String accelerate() {
		return "Car -> Accelerate";
	}

	public String brake() {
		return "Car -> brake";
	}
}

class Mitshubishi extends Car {
	public Mitshubishi() {
		super(4, "Mitshubishi");
	}

	public Mitshubishi(int cylinders, String name) {
		super(cylinders, name);
	}

	@Override
	public String startEngine() {
		return super.getName() + " -> startEngine()";
	}

	@Override
	public String accelerate() {
		return super.getName() + " -> accelerate()";
	}

	@Override
	public String brake() {
		return super.getName() + " -> brake()";
	}
}

class Dodge extends Car {
	public Dodge() {
		super(4, "Dodge");
	}

	public Dodge(int cylinders, String name) {
		super(cylinders, name);
	}

	@Override
	public String startEngine() {
		return super.getName() + " -> startEngine()";
		// return getClass().getSimpleName() + " -> startEngine";  // from java object class
	}

	@Override
	public String accelerate() {
		return super.getName() + " -> accelerate()";
	}

	@Override
	public String brake() {
		return super.getName() + " -> brake()";
	}
}


public class Main {
	public static void main(String[] args) {
		Car car = new Car(0, "Base Car");
		System.out.println(car.getName());
		System.out.println(car.getCylinders());

		Mitshubishi Lancer = new Mitshubishi(6, "Lancer");
		System.out.println(Lancer.getName());
		System.out.println(Lancer.getCylinders());
		System.out.println(Lancer.startEngine());
		System.out.println(Lancer.accelerate());
		System.out.println(Lancer.brake());

		Dodge charger = new Dodge(8, "Charger 2013");
		System.out.println(charger.getName());
		System.out.println(charger.getCylinders());
		System.out.println(charger.startEngine());
		System.out.println(charger.accelerate());
		System.out.println(charger.brake());
	}
}
