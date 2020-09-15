import javax.xml.transform.Source;

// swap() that exchanges the contents of the objects referred by two Test object references

class Test {
	int a;
	Test (int i) {
		this.a = i;
	}
}

class Ques4 {
	public static void main(String[] args) {
		Test t1 = new Test(4);
		Test t2 = new Test(6);

		System.out.println("Previously: t1 -> " + t1.a + ", t2 -> " + t2.a);
		swap(t1, t2);
		System.out.println("After: t1 -> " + t1.a + ", t2 -> " + t2.a);
	}

	public static void swap(Test t1, Test t2) {
		t1.a += t2.a;
		t2.a = t1.a - t2.a;
		t1.a -= t2.a;
	}
}
