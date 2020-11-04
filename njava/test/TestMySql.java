public class TestMySql {
	public static void main(String[] args) {
		try {
			Class.forName("com.mysql.jdbc.Driver").newInstance();
		}
		catch (Exception e) {
			System.out.println("The driver couldn't be loaded");
			return;
		}
		System.out.println("The driver is loaded");
	}
}
