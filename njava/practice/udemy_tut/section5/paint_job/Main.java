public class Main {
	public static void main(String args[]) {
		System.out.println("1 count(-3.4, 2.1, 1.5, 2): " + PaintJob.getBucketCount(-3.4, 2.1, 1.5, 2));
		System.out.println("2 count(3.4, 2.1, 1.5, 2): " + PaintJob.getBucketCount(3.4, 2.1, 1.5, 2));
		System.out.println("3 count(2.75, 3.25, 2.5, 1): " + PaintJob.getBucketCount(2.75, 3.25, 2.5, 1));

		System.out.println("----------------------------------");

		System.out.println("4 count(-3.4, 2.1, 1.5): " + PaintJob.getBucketCount(-3.4, 2.1, 1.5));
		System.out.println("5 count(3.4, 2.1, 1.5): " + PaintJob.getBucketCount(3.4, 2.1, 1.5));
		System.out.println("6 count(7.25, 4.3, 2.35): " + PaintJob.getBucketCount(7.25, 4.3, 2.35));

		System.out.println("----------------------------------");

		System.out.println("7 count(3.4, 1.5): " + PaintJob.getBucketCount(3.4, 1.5));
		System.out.println("8 count(6.26, 2.2): " + PaintJob.getBucketCount(6.26, 2.2));
		System.out.println("9 count(3.26, 0.75): " + PaintJob.getBucketCount(3.26, 0.75));
	}
}
