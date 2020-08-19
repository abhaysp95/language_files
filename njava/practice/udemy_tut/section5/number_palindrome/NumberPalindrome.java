public class NumberPalindrome {
	public static void main(String args[]) {
		System.out.println("Palindrome of number -1221 is: " + isPalindrome(-1221));
		System.out.println("Palindrome of number 707 is: " + isPalindrome(707));
		System.out.println("Palindrome of number 11212 is: " + isPalindrome(11212));
	}

	public static boolean isPalindrome(long number) {
		number = number < 0 ? -number : number;  // or you can use Math.abs()
		long numberBak = number;
		long anotherNumber = 0;
		long remainder = 0;
		while (number > 0) {
			remainder = number % 10;
			number /= 10;
			anotherNumber = anotherNumber*10 + remainder;
		}
		if (anotherNumber == numberBak) {
			return true;
		}
		return false;
	}
}
