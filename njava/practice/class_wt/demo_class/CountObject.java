class CountObject {
	static int count = 0;
	CountObject() {
		count++;
	}
}

class CountObjectMain {
	public static void main(String ...args) {
		// useless program, but tells a scenerio of how static variable can be useful
		for (int i = 0; i < 10; i++) {
			new CountObject();
		}
		System.out.println("Count: " + CountObject.count);
	}
}
