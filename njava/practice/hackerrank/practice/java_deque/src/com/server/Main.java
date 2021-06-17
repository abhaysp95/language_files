package com.server;

import java.util.Deque;
import java.util.ArrayDeque;
import java.util.HashSet;
import java.util.Scanner;

// you can also use LinkedList with Deque too

public class Main {

	private static Deque<Integer> deque = new ArrayDeque<>();

	private static HashSet<Integer> set = new HashSet<>();

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		int m = in.nextInt();
		int max = Integer.MIN_VALUE;

		for (int i = 0; i < n; ++i) {
			int input = in.nextInt();

			deque.add(input);  // similar to addLast()
			set.add(input);

			if (deque.size() == m) {
				if (set.size() > max) {
					max = set.size();
				}
				int firstRemoved = deque.removeFirst();
				if (!deque.contains(firstRemoved)) {
					// if there's no firstRemoved item left in deque
					// then also remove it from set
					set.remove(firstRemoved);
				}
			}
		}
		System.out.println(max);
	}

	// new main method(final solution)

	// use this main method with rest of the methods
	/*public static void main(String ...args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();  // number of total elements
		int m = in.nextInt();  // number of elements for subarray
		int[] uniqueEveryTime = new int[( n - m ) + 1 ];

		int count = 0;  // count if unique found for every subarray(deque)
		for( int i = 0; i < n; ++i ) {
			int num = in.nextInt();
			if( deque.size() == m ) {
				int uniqueCount = getUniqueEveryTime();
				uniqueEveryTime[count++] = uniqueCount;
				deque.removeFirst();  // delete from front
			}
			deque.addLast( num );  // insertion from rear
		}
		int uniqueCount = getUniqueEveryTime();
		uniqueEveryTime[count++] = uniqueCount;
		int maxIs = getMaxFromUniques(uniqueEveryTime);
		System.out.println("Max is: " + maxIs);
	}*/

	private static int getUniqueEveryTime() {
		set.clear();  // clear the previous inputs residing in it
		// trave the deque
		for (int num: deque) {
			if (!set.contains(num)) {
				set.add(num);
			}
		}
		return set.size();
	}

	/**
	  * This method is not right, because if elements entered are more than of
	  * range 0..9 then you can't find unique with using this technique, and if
	  * I change this technique for using it like this way then it's also not
	  * efficient probably
	*/
	/*private static int getUniqueEveryTime() {
		int[] indexOfDecimalNums = new int[10];
		for( int num: deque ) {
			indexOfDecimalNums[num]++;
		}
		int count = 0;
		for( int num: indexOfDecimalNums ) {
			if( num != 0 ) {
				count++;
			}
		}
		return count;
	}*/

	private static int getMaxFromUniques(int[] arr) {
		int max = Integer.MIN_VALUE;
		for (int num: arr) {
			if (max < num) {
				max = num;
			}
		}
		return max;
	}
}