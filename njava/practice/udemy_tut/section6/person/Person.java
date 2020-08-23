public class Person {
	private String firstName;
	private String lastName;
	private int age = 0;

	public void setFirstName(String fname) {
		this.firstName = fname;
	}

	public void setLastName(String lname) {
		this.lastName = lname;
	}

	public void setAge(int age) {
		if (age < 0 || age > 100) {
			this.age = 0;
		}
		else {
			this.age = age;
		}
	}

	public String getFirstName() {
		return this.firstName;
	}

	public String getLastName() {
		return this.lastName;
	}

	public int getAge() {
		return this.age;
	}

	public boolean isTeen() {
		if (this.age > 12 && this.age < 20) {
			return true;
		}
			return false;
	}

	public String getFullName() {
		if (firstName.isEmpty() && lastName.isEmpty()) {
			return "";
		}
		if (firstName.isEmpty()) {
			return this.lastName;
		}
		if (lastName.isEmpty()) {
			return this.firstName;
		}
		return this.firstName + " " + this.lastName;
	}
}
