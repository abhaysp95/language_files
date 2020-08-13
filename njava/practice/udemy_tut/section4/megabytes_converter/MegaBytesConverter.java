public class MegaBytesConverter {
	public static void printMegaBytesAndKiloBytes(int kilobytes) {
		if (kilobytes < 0) {
			System.out.println("Invalid Value");
		}
		else {
			System.out.print(kilobytes + " KB =");
			System.out.print(" " + kilobytes / 1024 + " MB and");
			System.out.println(" " + kilobytes % 1024 + " KB");
		}
	}
}
