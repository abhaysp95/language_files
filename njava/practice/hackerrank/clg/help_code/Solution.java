import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.Map;

enum Code {

}

public class Solution {
	private static HashMap<String, String> codes = new HashMap<String, String>();

	public static void main(String[] args) {
		BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));

		codes.put(".-"  , "a");
		codes.put("-...", "b");
		codes.put("-.-.", "c");
		codes.put("-.." , "d");
		codes.put("."   , "e");
		codes.put("..-.", "f");
		codes.put("--." , "g");
		codes.put("....", "h");
		codes.put(".."  , "i");
		codes.put(".---", "j");
		codes.put("-.-" , "k");
		codes.put(".-..", "l");
		codes.put("--"  , "m");
		codes.put("-."  , "n");
		codes.put("---" , "o");
		codes.put(".--.", "p");
		codes.put("--.-", "q");
		codes.put(".-." , "r");
		codes.put("..." , "s");
		codes.put("-"   , "t");
		codes.put("..-" , "u");
		codes.put("...-", "v");
		codes.put(".--" , "w");
		codes.put("-..-", "x");
		codes.put("-.--", "y");
		codes.put("--..", "z");

		try {
			String[] input = bf.readLine().split("\\s");
			for (String str: input) {
				for(Map.Entry<String, String> code: codes.entrySet()) {
					if (str.equals(code.getKey())) {
						System.out.println("Code matched: " + code.getKey() + ", value: " + code.getValue());
					}
				}
			}
		}
		catch (Exception ie) {
			System.out.println("Some Exception happened");
		}
	}
}
