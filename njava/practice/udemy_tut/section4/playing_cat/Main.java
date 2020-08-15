public class Main {
	public static void main(String args[]) {
		boolean res1 = PlayingCat.isCatPlaying(true, 10);
		boolean res2 = PlayingCat.isCatPlaying(false, 36);
		boolean res3 = PlayingCat.isCatPlaying(false, 35);
		System.out.println(res1);
		System.out.println(res2);
		System.out.println(res3);
	}
}
