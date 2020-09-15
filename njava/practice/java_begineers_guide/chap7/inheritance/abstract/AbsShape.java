// Usage of abstract method and class

/* Abstract modifier can be used only with instance methods */

abstract class TwoDShape {  // <-- abstract class
	private double height;
	private double width;
	private String name;

	TwoDShape() { height = width = 0.0; name = "none"; }
	TwoDShape(double x, String name) {
		this.height = x;
		this.width = x;
		this.name = name;
	}
	TwoDShape(double height, double width, String name) {
		this.height = height;
		this.width = width;
		this.name = name;
	}
	TwoDShape(TwoDShape ob) {
		this.height = ob.getHeight();
		this.width = ob.getWidth();
		this.name = ob.getName();
	}

	double getHeight() { return this.height; }
	double getWidth() { return this.width; }
	String getName() { return this.name; }

	void setHeight(double height) { this.height = height; }
	void setWidth(double width) { this.width = width; }

	abstract double area();  // <-- abstract method
}

class Triangle extends TwoDShape {
	private String style;

	Triangle() { super(); this.style = "none"; }
	Triangle(double x) {
		super(x, "Triangle");
		this.style = "Filled";
	}
	Triangle(double height, double width, String style) {
		super(height, width, "Triangle");
		this.style = style;
	}
	Triangle(Triangle ob) {
		super(ob);  // this is the child of the superClass, superClass can have this method
		this.style = ob.getStyle();
	}

	String getStyle() { return this.getStyle(); }
	void showStyle() { System.out.println("Style is: " + this.style); }
	double area() { return (this.getHeight() * this.getWidth()) / 2; }
}

class Rectangle extends TwoDShape {
	Rectangle() {
		super();
	}
	Rectangle(double x) {
		super(x, "Square");
	}
	Rectangle(double height, double width) {
		super(height, width, "Rectangle");
	}
	Rectangle(Rectangle ob) {
		super(ob);
	}

	boolean isSquare() {
		// this will check if getWidth() is in subClass, if not then look in super
		if (this.getWidth() == this.getHeight()) {
			return true;
		}
		return false;
	}

	double area() {
		return this.getHeight() * this.getWidth();
	}
}

class AbsShape {
	public static void main(String[] args) {
		TwoDShape[] shapes = new TwoDShape[4];

		shapes[0] = new Triangle(9.0, 12.0, "Outlined");
		shapes[1] = new Rectangle(9.0);
		shapes[2] = new Rectangle(10.0, 4.0);
		shapes[3] = new Triangle(7.0);

		for (int i = 0; i < shapes.length; ++i) {
			System.out.println("Names: " + shapes[i].getName());
			System.out.println("Area: " + shapes[i].area());
			System.out.println();
		}
	}
}
