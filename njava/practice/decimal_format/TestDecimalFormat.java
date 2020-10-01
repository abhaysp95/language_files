import java.text.DecimalFormat;

public class TestDecimalFormat {
	public static void main(String[] args) {
		String pattern1 = "#####, ####.##";
		String pattern2 = "'$'###,##0.00";
		double number = 2903234.3692034;
		double another_number = 239402342.3234;
		DecimalFormat df = new DecimalFormat(pattern1);
		DecimalFormat df2 = new DecimalFormat(pattern2);
		System.out.println(number);
		System.out.println(another_number);
		System.out.println(df.format(number));
		System.out.println(df.format(another_number));
		System.out.println(df2.format(number));
		System.out.println(df2.format(another_number));
	}
}
