import java.util.Scanner;

class OtpGeneration {
	static Scanner scan = new Scanner(System.in);
	String input;

	String returnOtp() {
		this.input = scan.nextLine();
		if ((this.input.length() < 8)) {
			System.out.println("string length is not upto the specified constraint");
			return null;
		}
		else {
			String otp = "";
			String tempNum = "";
			int count = 0;
			for (int i = 0; i < input.length(); ++i) {
				if (i % 2 != 0) {
					tempNum += input.charAt(i);
					count++;
				}
				if (count > 4) {
					break;
				}
			}
			// make it work in one loop
			for (int i = 0; i < tempNum.length(); ++i) {
				//otp += Double.toString(Math.pow((Integer.parseInt(Character.toString(tempNum.charAt(i)))), 2));
				otp += Integer.toString((int) Math.pow((Integer.parseInt(Character.toString(tempNum.charAt(i)))), 2));
				//System.out.println("otp: " + otp);
			}
			if (otp.length() > 4) {
				String newOtp = "";
				for (int i = 0; i < 4; ++i) {
					newOtp += otp.charAt(i);
				}
				otp = newOtp;
			}
			//System.out.println("Got temp: " + otp);
			return otp;
		}
	}
}

class solution {
	public static void main(String[] args) {
		OtpGeneration ob = new OtpGeneration();
		String gotNum = ob.returnOtp();
		//System.out.println("Got: " + gotNum);
		if (gotNum != null) {
			System.out.println(gotNum);
		}
	}
}
