import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;

class SolutionTraditional {
	private ArrayList<String> wordList = new ArrayList<String>();
	private BufferedReader bf;

	SolutionTraditional(BufferedReader bf) {
		this.bf = bf;
	}

	void print() {
		System.out.println("Got substrings: ");
		for (String str: wordList) {
			System.out.print(str + "\t");
		}
		System.out.println();
	}

	void getSubStrings() throws IOException {
		try {
			int wordCount = Integer.parseInt(this.bf.readLine());
			StringBuilder sb = new StringBuilder(this.bf.readLine());
			for (int i = 0; i < wordCount; ++i) {
				for (int j = i; j < sb.length(); j += wordCount) {
					if (j + wordCount <= sb.length()) {
						this.wordList.add(sb.substring(j, j + wordCount).toString());
					}
				}
			}
		}
		catch (NumberFormatException nfe) {
			System.out.println("Enter input in correct form: " + nfe);
			return;
		}
	}

	void getMaxMin() {
		//int lenOfWord = this.wordList.get(0).length();
		// every substring is having same length
		for (int i = 0; i < this.wordList.size() - 1; ++i) {
			for (int j = i + 1; j < this.wordList.size(); ++j) {
				if (this.wordList.get(i).compareTo(this.wordList.get(j)) > 0) {
					String temp1 = this.wordList.get(i);
					this.wordList.add(i, this.wordList.get(j));
					this.wordList.remove(i + 1);
					this.wordList.add(j, temp1);
					this.wordList.remove(j + 1);
				}
			}
		}
		System.out.println("Min: " + this.wordList.get(0));
		System.out.println("Max: " + this.wordList.get(wordList.size() - 1));
	}
}

class SolutionNonTraditional {
	private BufferedReader bf;
	private ArrayList<String> wordList = new ArrayList<String>();

	SolutionNonTraditional(BufferedReader bf) {
		this.bf = bf;
	}

	void print() {
		System.out.println("Got substrings: ");
		for (String str: wordList) {
			System.out.print(str + "\t");
		}
		System.out.println();
	}

	void getSubStrings() throws IOException {
		try {
			int wordCount = Integer.parseInt(this.bf.readLine());
			StringBuilder sb = new StringBuilder(this.bf.readLine());
			for (int i = 0; i < wordCount; ++i) {
				for (int j = i; j < sb.length(); j += wordCount) {
					if (j + wordCount <= sb.length()) {
						this.wordList.add(sb.substring(j, j + wordCount).toString());
					}
				}
			}
		}
		catch (NumberFormatException nfe) {
			System.out.println("Enter input in correct form: " + nfe);
			return;
		}
	}

	void getMaxMin() {
		Collections.sort(this.wordList);
		System.out.println("Min: " + this.wordList.get(0));
		System.out.println("Max: " + this.wordList.get(wordList.size() - 1));
	}
}

class MySolutionToSubmit {
	void getSmallestAndLargest(String s, int k) {
		String smallest = "";
		String largest = "";
		String[] wordArr = new String[50];  // don't know size
		int count = 0;
		for (int i = 0; i < k; ++i) {
			for (int j = i; j < s.length(); j += k) {
				if (j + k <= s.length()) {
					wordArr[count++] = s.substring(j, j + k);
				}
			}
		}

		// every substring is having same length
		for (int i = 0; i < count - 1; ++i) {
			for (int j = i + 1; j < count; ++j) {
				if (wordArr[i].compareTo(wordArr[j]) > 0) {
					String temp = wordArr[i];
					wordArr[i] = wordArr[j];
					wordArr[j] = temp;
				}
			}
		}
		smallest = wordArr[0];
		largest = wordArr[count - 1];
		System.out.println("smallest: " + smallest + ", largest: " + largest);
	}
}

public class Solution {
	static BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));

	public static void main(String[] args) {
		try {
			/*System.out.println("----------  First ------------");
			SolutionTraditional ob1 = new SolutionTraditional(bf);
			ob1.getSubStrings();
			ob1.print();
			ob1.getMaxMin();
			System.out.println("----------  Second ------------");
			SolutionNonTraditional ob2 = new SolutionNonTraditional(bf);
			ob2.getSubStrings();
			ob2.print();
			ob2.getMaxMin();*/
			//System.out.println("----------  Second ------------");
			MySolutionToSubmit ob3 = new MySolutionToSubmit();
			int k = Integer.parseInt(bf.readLine());
			String s = bf.readLine();
			ob3.getSmallestAndLargest(s, k);
			bf.close();
		}
		catch (IOException ie) {
			System.out.println("Some IOException occured: " + ie);
		}
	}
}
