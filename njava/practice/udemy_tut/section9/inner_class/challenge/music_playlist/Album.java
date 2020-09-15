// add songs to album

package practice.udemy_tut.section9.inner_class.challenge.music_playlist;

import java.util.ArrayList;

public class Album {
	private String title;
	//private ArrayList<Song> songArrayList = new ArrayList<Song>();
	private SongInnerClass songs;

	public Album(String title) {
		this.title = title;
		this.songs = new SongInnerClass();
	}

	public String getAlbumTitle() {
		return this.title;
	}

	/*public ArrayList<Song> getSongListAlbum() {
		return this.songArrayList;
	}*/

	public ArrayList<Song> getSongListAlbum() {
		return this.songs.songArrayList;
	}

	// add song to album only if song doesn't exist
	/*public boolean addSongToAlbum(String title, double duration) {
		Song ifSong = findSong(title);
		if (ifSong == null) {
			songArrayList.add(new Song(title, duration));
			return true;
		}
		else {
			System.out.println("Song already exist in the album");
			return false;
		}
	}*/

	public boolean addSongToAlbum(String title, double duration) {
		return this.songs.addSongInnerClass(new Song(title, duration));
	}

	/*public void printSongsInAlbum() {
		int count = 0;
		for (Song thisSong: songArrayList) {
			System.out.println(++count + ": " + thisSong.getSongTitle());
		}
	}*/

	public void printSongsInAlbum() {
		int count = 0;
		for (Song thisSong: this.songs.songArrayList) {
			System.out.println(++count + ": " + thisSong.getSongTitle());
		}
	}

	// check if song exist in album
	/*public Song findSong(String title) {
		for (Song thisSong: songArrayList) {
			if (thisSong.getSongTitle() == title) {
				return thisSong;
			}
		}
		return null;
	}*/

	public Song findSong(String title) {
		return this.songs.findSong(title);
	}

	// method overloading for findSong
	public Song findSong(int index) {
		return this.songs.findSong(index);
	}


	// innerClass(challenge)
	private class SongInnerClass implements ITestInterfaceAlbum {
		private ArrayList<Song> songArrayList;

		private SongInnerClass() {
			this.songArrayList = new ArrayList<Song>();
		}

		@Override
		public boolean addSongInnerClass(Song song) {
			// or you can just pass song object and check
			// if songArrayList.contains(song_obj)
			/*Song ifSong = findSong(title);
			if (ifSong == null) {
				songArrayList.add(new Song(title, duration));
			}*/
			if (this.songArrayList.contains(song)) {
				return false;
			}
			this.songArrayList.add(song);
			return true;
		}

		private Song findSong(String title) {
			for (Song thisSong: this.songArrayList) {
				if (thisSong.getSongTitle().equals(title)) {
					return thisSong;
				}
			}
			return null;
		}

		@Override
		public Song findSong(int trackNumber) {
			int index = trackNumber - 1;
			if (index >= 0 && index < this.songArrayList.size()) {
				return this.songArrayList.get(index);
			}
			return null;
		}
	}
}
