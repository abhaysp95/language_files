package practice.udemy_tut.section9.inner_class.challenge.music_playlist;

public class Main {
	public static void main(String[] args) {
		Album loveTheShow = new Album("Love The Show - Akcent");
		loveTheShow.addSongToAlbum("Boca Linda", 3.37);
		loveTheShow.addSongToAlbum("Feelings", 5.21);
		loveTheShow.addSongToAlbum("Serai", 3.18);
		loveTheShow.addSongToAlbum("Sofia", 3.15);

		Album bahubali2 = new Album("Bahubali 2");
		bahubali2.addSongToAlbum("Jay-Jaykara", 3.31);
		bahubali2.addSongToAlbum("Shivam", 2.56);

		Album deshBhakti = new Album("Desh Bhakti");
		deshBhakti.addSongToAlbum("Azaadi", 4.49);
		deshBhakti.addSongToAlbum("Jalwa Tera Jalwa", 5.51);
		deshBhakti.addSongToAlbum("Maa Tujhe Salaam", 6.14);
		deshBhakti.addSongToAlbum("Sandese Aate Hain", 10.25);
		deshBhakti.addSongToAlbum("Ab Tumhare Hawale Watan Saathiyoon", 6.08);

		Album ff7 = new Album("Fast & Furious 7");
		ff7.addSongToAlbum("Ay Vamos", 4.55);
		ff7.addSongToAlbum("Meneo", 3.41);
		ff7.addSongToAlbum("My Angel", 3.10);
		ff7.addSongToAlbum("Turn Down For What", 3.50);
		ff7.addSongToAlbum("Whip Bonus Track", 3.02);

		Album ff8 = new Album("Fast & Furious 8");
		ff8.addSongToAlbum("Good Life", 3.45);
		ff8.addSongToAlbum("Gang Up", 3.51);
		ff8.addSongToAlbum("Hey Ma", 3.15);
		ff8.addSongToAlbum("La Habana", 2.44);
		ff8.addSongToAlbum("Murder (Remix)", 3.20);
		ff8.addSongToAlbum("Speakerbox", 2.30);
		ff8.addSongToAlbum("Sieze The Block", 3.59);

		Playlist mix = new Playlist("Mix");
		mix.addSongToPlaylist(loveTheShow, "Boca Linda");
		mix.addSongToPlaylist(loveTheShow, "Serai");
		mix.addFullAblum(bahubali2);
		mix.addSongToPlaylist(deshBhakti, "Azaadi");
		mix.addSongToPlaylist(deshBhakti, "Desh Bhakti");  // provided ill arg
		mix.addSongToPlaylist(deshBhakti, "Maa Tujhe Salaam");

		Playlist workout = new Playlist("Workout");
		workout.addFullAblum(ff8);
		workout.addSongToPlaylist(ff7, "Meneo");
		workout.addSongToPlaylist(ff7, "Turn Down For What");

		mix.printSongsInPlaylist();
		System.out.println("-------------------------");
		workout.printSongsInPlaylist();

		MusicPlayer blackPlayer = new MusicPlayer("Black Player");
		blackPlayer.addPlaylistToPlayer("Mix");
		blackPlayer.addPlaylistToPlayer("Workout");
		blackPlayer.addSongToGivenPlaylist(workout, ff7, "My Angel");
		blackPlayer.startPlaying(workout);
	}
}
