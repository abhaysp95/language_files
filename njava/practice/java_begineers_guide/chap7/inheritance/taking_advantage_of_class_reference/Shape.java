class TwoDShape {
	private double x;
	private double y;

	TwoDShape () { this.x = this.y = 0.0; }

	TwoDShape (double same) { this.x = this.y = same; }

	TwoDShape (double x, double y) {
		this.x = x;
		this.y = y;
	}

	TwoDShape (TwoDShape ob) {  // <-- Construct object from an object
		this.x = ob.getHeight();
		this.y = ob.getWidth();
	}

	double getHeight () { return this.x; }
	double getWidth () { return this.y; }

	void setHeight (double x) { this.x = x; }
	void setWidth (double y) { this.y = y; }

	void showDim() {
		System.out.println("Height and width: " + this.x + " and " + this.y);
	}
}

class Triangle extends TwoDShape {
	private String style;

	Triangle () {
		super();
		this.style = "none";
	}

	Triangle (double same) {
		super(same);
		this.style = "filled";
	}

	Triangle (double height, double width, String style) {
		super(height, width);
		this.style = style;
	}

	Triangle (Triangle ob) {  // <-- pass a triangle reference to TwoDShape constructor
		super(ob);
		this.style = ob.getStyle();
	}

	String getStyle() { return this.style; }
	double getArea() { return (this.getWidth() * this.getHeight()) / 2; }
}

class Shape {
	public static void main(String[] args) {
		Triangle t1 = new Triangle(8.0, 12.0, "outlined");
		Triangle t2 = new Triangle(t1);

		System.out.println("Info for t1:");
		t1.showDim();
		System.out.println("Style: " + t1.getStyle());
		System.out.println("Area: " + t1.getArea());

		System.out.println();

		System.out.println("Info for t2:");
		t2.showDim();
		System.out.println("Style: " + t2.getStyle());
		System.out.println("Area: " + t2.getArea());
	}
}
