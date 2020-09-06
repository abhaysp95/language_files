// elements for the song

package practice.udemy_tut.section8.linked_list.music_playlist;

public class Song {
	private String title;
	private double duration;

	public Song(String title, double duration) {
		this.title = title;
		this.duration = duration;
	}

	public void setSongTitle(String title) {
		this.title = title;
	}
	public void setSongDuration(double duration) {
		this.duration = duration;
	}

	public String getSongTitle() {
		return this.title;
	}
	public double getSongDuration() {
		return this.duration;
	}
}
