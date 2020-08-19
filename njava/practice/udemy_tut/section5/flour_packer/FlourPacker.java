public class FlourPacker {
	public static void main(String args[]) {
		System.out.println("For 1, 0, 4: " + canPack(1, 0, 4));
		System.out.println("For 1, 0, 5: " + canPack(1, 0, 5));
		System.out.println("For 0, 5, 4: " + canPack(0, 5, 4));
		System.out.println("For 2, 2, 11: " + canPack(2, 2, 11));
		System.out.println("For -3, 2, 12: " + canPack(-3, 2, 12));
		System.out.println("For 4, 18, 19: " + canPack(4, 18, 19));
	}

	public static boolean canPack(int bigCount, int smallCount, int goal) {
		if (bigCount < 0 || smallCount < 0 || goal < 0) {
			return false;
		}
		else if (bigCount > goal) {
			return false;
		}
		else if ((bigCount * 5 + smallCount) < goal) {
			return false;
		}
		else {
			int sumForGoal = 0;
			while (sumForGoal < goal) {
				if (bigCount > 0 && (sumForGoal + 5 <= goal)) {
					sumForGoal += 5;
					// System.out.println("sumForGoal: " + sumForGoal);
					bigCount--;
				}
				else if(smallCount > 0 && (sumForGoal + 1 <= goal)) {
					sumForGoal += 1;
					// System.out.println("sumForGoal: " + sumForGoal);
					smallCount--;
				}
				else {
					break;
				}
			}
			// System.out.println(sumForGoal);
			if (sumForGoal == goal) {
				return true;
			}
		}
		return false;
	}
}
