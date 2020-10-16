import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.HashMap;
import java.util.Map;
import java.util.ArrayList;

public class Solution {
	private static HashMap<Character, String> codes = new HashMap<Character, String>();
	public static void main(String[] args) {
		codes.put('a', ".-"  );
		codes.put('b', "-...");
		codes.put('c', "-.-.");
		codes.put('d', "-.." );
		codes.put('e', "."   );
		codes.put('f', "..-.");
		codes.put('g', "--." );
		codes.put('h', "....");
		codes.put('i', ".."  );
		codes.put('j', ".---");
		codes.put('k', "-.-" );
		codes.put('l', ".-..");
		codes.put('m', "--"  );
		codes.put('n', "-."  );
		codes.put('o', "---" );
		codes.put('p', ".--.");
		codes.put('q', "--.-");
		codes.put('r', ".-." );
		codes.put('s', "..." );
		codes.put('t', "-"   );
		codes.put('u', "..-" );
		codes.put('v', "...-");
		codes.put('w', ".--" );
		codes.put('x', "-..-");
		codes.put('y', "-.--");
		codes.put('z', "--..");

		BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
		try {
			int takeInput = Integer.parseInt(bf.readLine());
			String[] inputs = new String[takeInput];
			ArrayList<String> inputCodes = new ArrayList<String>();

			while (takeInput > 0) {
				inputs[--takeInput] = bf.readLine();
			}

			String wordCode = null;
			for (String input: inputs) {
				wordCode = "";
				for (char alpha: input.toCharArray()) {
					for (Map.Entry<Character, String> code: codes.entrySet()) {
						if (alpha == code.getKey()) {
							//System.out.println(code.getKey() + ", " + code.getValue());
							wordCode += code.getValue();
						}
					}
				}
				if (inputCodes.size() == 0) {
					inputCodes.add(wordCode);
				}
				boolean found = false;
				for (int i = 0; i < inputCodes.size(); ++i) {
					if (wordCode.equals(inputCodes.get(i))) {
						found = true;
					}
				}
				if (!found) {
					inputCodes.add(wordCode);
				}
			}
			System.out.println("Total distinct codes: " + inputCodes.size());
		}
		catch (IOException ie) {
			System.out.println("Some IOException, exiting!");
		}
		catch (ArrayIndexOutOfBoundsException aie) {
			System.out.println("Some error in array indexing: " + aie);
		}
	}
}
