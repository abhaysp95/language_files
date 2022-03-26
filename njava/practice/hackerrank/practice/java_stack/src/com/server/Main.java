package com.server;

import java.util.Scanner;
import java.util.Stack;
import java.util.Iterator;
import java.util.Deque;
import java.util.ArrayDeque;

public class Main {
	public static void main(String ...args) {
		Scanner scan = new Scanner(System.in);
		BetterMethod(scan);
		scan.close();
	}

	public static void BetterMethod( Scanner scan ) {
		while (scan.hasNext()) {
			String input = scan.next();
			boolean status = isBalanced(input);
			System.out.println(status ? "Balanced" : "Not Balanced");
		}
	}

	private static Deque<Character> deque = new ArrayDeque<>();

	private static boolean isBalanced( String input ) {
		deque.clear();
		boolean ifFailed = false;
		int strLength = input.length();
		for( int index = 0; !ifFailed && index < strLength; ++index ) {
			char gotChar = input.charAt( index );
			switch( gotChar ) {
				case '[':
				case '{':
				case '(':
					deque.addFirst( gotChar );  // behave like stack
					break;
				case ']':
					// behave like stack
					ifFailed = deque.isEmpty() || ( deque.removeFirst() != '[' );
					break;
				case '}':
					ifFailed = deque.isEmpty() || ( deque.removeFirst() != '{' );
					break;
				case ')':
					ifFailed = deque.isEmpty() || ( deque.removeFirst() != '(' );
					break;
				default:
					ifFailed = true;
					break;
			}
		}
		if( !ifFailed ) {  // if ifFailed is already true, then no need to check
			ifFailed = !deque.isEmpty();  // ifFailed is true, if deque is not empty
		}
		return !ifFailed;
	}

	public static void firstMethod(Scanner scan) {
		while (scan.hasNext()) {
			String str = scan.next();
			Stack<Character> stack = new Stack<Character>();
			int[] countOfOpenBrackets = pushInStack(stack, str);
			//System.out.println("\nPrinting stack: ");
			//printStackElements(stack);
			//System.out.println("Counts: ");
			//for (int count: countOfOpenTypeBrackets) {
				//System.out.println(count);
			//}
			boolean status = checkIfBalanced(stack, countOfOpenBrackets);
			System.out.println(status ? "Balanced" : "Not Balanced");
		}
	}

	public static int[] pushInStack(Stack<Character> stack, String str) {
		char[] strToChar = str.toCharArray();
		int countBrackets = 0, countBraces = 0, countParentheses = 0;
		int[] countOfOpenBrackets = new int[3];
		for (int i = 0; i < strToChar.length; ++i) {
			switch (strToChar[i]) {
				case '[':
					countBrackets++;
					break;
				case '{':
					countBraces++;
					break;
				case '(':
					countParentheses++;
					break;
			}
			stack.push(strToChar[i]);
		}
		countOfOpenBrackets[0] = countParentheses;
		countOfOpenBrackets[1] = countBraces;
		countOfOpenBrackets[2] = countBrackets;
		return countOfOpenBrackets;
	}

	public static boolean checkIfBalanced(Stack<Character> stack, int[] countOfOpenBrackets) {
		char returnedChar;
		while (!stack.isEmpty()) {
			returnedChar = stack.pop();
			switch( returnedChar ) {
				case ']':
					countOfOpenBrackets[2]--;
					break;
				case '}':
					countOfOpenBrackets[1]--;
					break;
				case ')':
					countOfOpenBrackets[0]--;
					break;
			}
		}
		if( countOfOpenBrackets[0] == 0
				&& countOfOpenBrackets[1] == 0
				&& countOfOpenBrackets[2] == 0 ) {
			return true;
		}
		return false;
	}

	public static void printStackElements(Stack<Character> stack) {
		Iterator<Character> iter = stack.iterator();
		while (iter.hasNext()) {
			System.out.println(iter.next());
		}
	}
}


/**
  as a solution do this:

  if ( !ifFailed ) {  // no need to check if, ifFailed is already true
	ifFailed = !deque.isEmpty()
  }

*/