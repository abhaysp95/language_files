// Add songs from album to playlist

package practice.udemy_tut.section8.linked_list.music_playlist;

import java.util.LinkedList;
import java.util.ListIterator;
import java.util.ArrayList;

public class Playlist {
	private String name;
	//private LinkedList<Album> albumList = new LinkedList<Album>();
	private LinkedList<Song> songsInPlaylist = new LinkedList<Song>();

	public Playlist(String name) {
		this.name = name;
	}

	public String getPlaylistName() {
		return this.name;
	}

	public LinkedList<Song> getSongsinPlaylist() {
		return this.songsInPlaylist;
	}

	// Enter the album name and song name which exist in that album
	public boolean addSongToPlaylist(Album album, String songName) {
		Song ifSong = album.findSong(songName);
		if (ifSong != null) {
			songsInPlaylist.add(ifSong);
			return true;
		}
		else {
			System.out.println("Song doesn't exist in provided album: " + album.getAlbumTitle());
			return false;
		}
	}

	public boolean addFullAblum(Album album) {
		ArrayList<Song> songsInAlbum = album.getSongListAlbum();
		if (songsInAlbum.isEmpty()) {
			System.out.println("No song in album: " + album.getAlbumTitle());
			return false;
		}
		else {
			for (Song song: songsInAlbum) {
				songsInPlaylist.add(song);
			}
			return true;
		}
	}

	public void printSongsInPlaylist() {
		int count = 0;
		System.out.println("Printing songs from playlist: " + this.name);
		ListIterator<Song> iterSongs = songsInPlaylist.listIterator();
		while (iterSongs.hasNext()) {
			System.out.println(++count + ": " + iterSongs.next().getSongTitle());
		}
	}
}
