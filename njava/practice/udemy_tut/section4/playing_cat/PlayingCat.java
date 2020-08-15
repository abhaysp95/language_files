public class PlayingCat {
	public static boolean isCatPlaying(boolean summer, int temperature) {
		boolean status = false;
		if (summer) {
			if (25 <= temperature && 45 >= temperature) {
				status = true;
			}
		}
		else {
			if (25 <= temperature && 35 >= temperature) {
				status = true;
			}
		}
		return status;
	}
}
