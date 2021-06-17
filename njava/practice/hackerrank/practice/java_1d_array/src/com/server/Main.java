package com.server;

import java.util.Scanner;

public class Main {
	public static void main(String ...args) {
		Scanner scan = new Scanner(System.in);
		int q = scan.nextInt();
		while (q-- > 0) {
			int n = scan.nextInt();
			int leap = scan.nextInt();

			int[] game = new int[n];
			for (int i = 0; i < n; ++i) {
				game[i] = scan.nextInt();
			}
			System.out.println((canWin(leap, game) ? "YES" : "NO"));
		}
		scan.close();
	}
	*/

	/** Now this can be solved with DFS(depth first search) algorithm */
	/* with each iteraration(or recursion) you have to check the conditions for
	 * 'i + 1', 'i - 1' and 'i + leap' if any of the three returns true then
	 * check further else if all fails then go back and check again for the
	 * parents siblings */
	public static boolean returnGameResult(int leap, int[] game, int index) {
		if (index < 0 || game[index] == 1) {
			return false;
		}
		else if (index == game.length - 1 || index + leap >= game.length) {
			return true;
		}
		// if neither true nor false, then mark the node as visited
		game[index] = 1;  // visited
		// call all three recursive calls
		return returnGameResult(leap, game, index + 1)
			|| returnGameResult(leap, game, index - 1)
			|| returnGameResult(leap, game, index + leap);
	}

	// cause hackerrank had caller fixed with two params
	public static boolean canWin(int leap, int[] game) {
		return returnGameResult(leap, game, 0);
	}

	/*public static boolean canwin(int leap, int[] game) {
		int index = 0;
		while (index < game.length && game[index] == 0) {
			if (leap > 0 && index + leap >= game.length) {
				return true;
			}
			else if (leap > 0 && game[index + leap] == 0) {
				index += leap;
			}
			index++;
		}
		return false;
	}*/
}