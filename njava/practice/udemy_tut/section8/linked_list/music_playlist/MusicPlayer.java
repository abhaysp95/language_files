// Playing Music Player

package practice.udemy_tut.section8.linked_list.music_playlist;

import java.util.LinkedList;
import java.util.ListIterator;
import java.io.BufferedReader;
import java.io.InputStreamReader;

public class MusicPlayer {
	private String playerName;
	private LinkedList<Playlist> playlistList = new LinkedList<Playlist>();

	public MusicPlayer(String title) {
		this.playerName = title;
		System.out.println("Music Player started");
	}

	public String getPlayerName() {
		return this.playerName;
	}

	public boolean addPlaylistToPlayer(String playlistName) {
		Playlist ifPlaylist = findPlaylist(playlistName);
		if (ifPlaylist == null) {
			playlistList.add(new Playlist(playlistName));
			return true;
		}
		else {
			System.out.println("Playlist with this name \"" + playlistName + "\" already exist");
			return false;
		}
	}

	public void addSongToGivenPlaylist(Playlist playlist, Album album, String songName) {
		playlist.addSongToPlaylist(album, songName);
		System.out.println("Added song: '" + songName +
				"' from album: '" + album.getAlbumTitle() +
				"' to playlist '" + playlist.getPlaylistName() + "'.");
		//System.out.println("Given playlist \"" + playlistName + "\" doesn't exist");
	}

	public void startPlaying(Playlist playlist) {
		LinkedList<Song> listOfPlayingSong = playlist.getSongsinPlaylist();
		ListIterator<Song> soIterator = listOfPlayingSong.listIterator();
		System.out.println("I'm here");
		boolean quit = false;
		boolean moveForward = true;

		if (listOfPlayingSong.isEmpty()) {
			System.out.println("No song in playlist");
		}
		else {
			System.out.println("Started playing song: " + soIterator.next().getSongTitle());
			showPlayerOptions();
		}

		while (!quit) {
			BufferedReader bufr = new BufferedReader(new InputStreamReader(System.in));
			System.out.println("Enter your choice:\r");
			try {
				int choice = Integer.parseInt(bufr.readLine());
				switch (choice) {
					case 0:
						System.out.println("Exiting music player");
						quit = true;
						break;
					case 1:
						if (!moveForward) {
							if (soIterator.hasNext()) {
								soIterator.next();
							}
							moveForward = true;
						}
						if (soIterator.hasNext()) {
							System.out.println("Now Playing Song(Next): " + soIterator.next().getSongTitle());
						}
						else {
							System.out.println("Reached to end of playlist");
							moveForward = false;
						}
						break;
					case 2:
						if (moveForward) {
							if (soIterator.hasPrevious()) {
								soIterator.previous();
							}
							moveForward = false;
						}
						if (soIterator.hasPrevious()) {
							System.out.println("Now Playing Song(Previous): " + soIterator.previous().getSongTitle());
						}
						else {
							System.out.println("At the very begining of playlist");
							moveForward = true;
						}
						break;
					case 3:
						System.out.println("Song " + soIterator.previous().getSongTitle() + " paused");
						break;
					case 4:
						System.out.println("Song " + soIterator.next().getSongTitle() + " started");
						break;
					case 5:
						System.out.println("Restarted song: " + soIterator.previous().getSongTitle());
						soIterator.next();
						break;
					case 6:
						String removeSong = bufr.readLine();
						System.out.println("Removing current song from playlist: " + playlist.getPlaylistName());
						boolean status = removeSong(soIterator, removeSong);
						if (status) {
							System.out.println("Removed Song: " + removeSong);
						}
						else {
							System.out.println("Probably entered wrong song name");
						}
						break;
					case 7:
						//playlist.printSongsInPlaylist();
						songsInCurrentPlayingList(soIterator);
						break;
					case 8:
						showPlayerOptions();
						break;
					default:
						System.out.println("Please, provide correct choice");
				}
			}
			catch (Exception e) {
				System.out.println("Exception: " + e);
			}
		}
	}

	public void printSongsFromPlaylist(Playlist playlist) {
		playlist.printSongsInPlaylist();
	}

	private boolean removeSong(ListIterator<Song> songs, String songName) {
		while (songs.hasNext()) {
			String currentSong = (String) songs.next().getSongTitle();
			if (currentSong.equals(songName)) {
				songs.remove();
				if (songs.hasNext()) {
					System.out.println("Now playing: " + songs.next().getSongTitle());
				}
				else {
					System.out.println("Now playing: " + songs.next().getSongTitle());
				}
				return true;
			}
		}
		return false;
	}

	private Playlist findPlaylist(String playlistName) {
		for (Playlist playlist: playlistList) {
			if (playlist.getPlaylistName().compareTo(playlistName) == 0) {
				return playlist;
			}
		}
		return null;
	}

	private void songsInCurrentPlayingList(ListIterator<Song> songs) {
		int count = 0;
		while (songs.hasNext()) {
			System.out.println(++count + ": " + songs.next().getSongTitle());
		}
	}

	private void showPlayerOptions() {
		System.out.println("0. Exit Player");
		System.out.println("1. Next Song");
		System.out.println("2. Previous Song");
		System.out.println("3. Pause Song");
		System.out.println("4. Play Song");
		System.out.println("5. Restart Song");
		System.out.println("6. Remove current song from playlist");
		System.out.println("7. Show song from playlist");
		System.out.println("8. Show this option menu");
	}
}
