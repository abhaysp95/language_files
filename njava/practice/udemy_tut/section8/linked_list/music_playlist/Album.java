// add songs to album

package practice.udemy_tut.section8.linked_list.music_playlist;

import java.util.ArrayList;

public class Album {
	private String title;
	private ArrayList<Song> songArrayList = new ArrayList<Song>();

	public Album(String title) {
		this.title = title;
	}

	public String getAlbumTitle() {
		return this.title;
	}

	public ArrayList<Song> getSongListAlbum() {
		return this.songArrayList;
	}

	// add song to album only if song doesn't exist
	public boolean addSongToAlbum(String title, double duration) {
		Song ifSong = findSong(title);
		if (ifSong == null) {
			songArrayList.add(new Song(title, duration));
			return true;
		}
		else {
			System.out.println("Song already exist in the album");
			return false;
		}
	}

	public void printSongsInAlbum() {
		int count = 0;
		for (Song thisSong: songArrayList) {
			System.out.println(++count + ": " + thisSong.getSongTitle());
		}
	}

	// check if song exist in album
	public Song findSong(String title) {
		for (Song thisSong: songArrayList) {
			if (thisSong.getSongTitle() == title) {
				return thisSong;
			}
		}
		return null;
	}
}
