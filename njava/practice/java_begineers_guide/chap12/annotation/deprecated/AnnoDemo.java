// An example to use @Deprecated

// Deprecate a Class

@Deprecated
class MyClass {
	private String msg;

	MyClass(String m) {
		this.msg = m;
	}

	// Deprecate a method within class
	@Deprecated
	String getMsg() {
		return this.msg;
	}
}

public class AnnoDemo {
	public static void main(String[] args) {
		MyClass obj = new MyClass("test");
		System.out.println(obj.getMsg());
	}
}
