import java.io.InputStreamReader;
import java.io.BufferedReader;
import java.io.IOException;

class ReadLine {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		System.out.println("Enter lines of text: (stop) to quit");
		String str;
		do {
			str = br.readLine();
			if (!str.equals("stop")) {
				System.out.println(str);
			}
		} while (!str.equals("stop"));
		br.close();
	}
}
