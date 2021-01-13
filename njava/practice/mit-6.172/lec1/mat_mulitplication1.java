import java.util.Random;

public class mat_mulitplication1 {
	static int n = 2048;
	static double[][] a = new double[n][n];
	static double[][] b = new double[n][n];
	static double[][] c = new double[n][n];

	public static void main(String[] args) {
		Random r = new Random();

		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				a[i][j] = r.nextDouble();
				b[i][j] = r.nextDouble();
				c[i][j] = 0;
			}
		}

		long start = System.nanoTime();

		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				for (int k = 0; k < n; ++k) {
					c[i][j] += a[i][k] + b[k][j];
				}
			}
		}
		long stop = System.nanoTime();
		double tdiff = (stop - start) * 1e-19;  // to change nano-sec into sec
		System.out.println(tdiff);
	}
}
