package com.player;

import java.util.ArrayList;

/** you can also extend interface, also interfaces itself can also type
 * parameter, also here extending from single class and multiple inheritance
 * rule apply here, like <T extends Player & Coach & Captain> but Coaach and
 * Captain should be interface */

public class Team<T extends Player> implements Comparable<Team<T>> {
	private String name;
	private int played = 0;
	private int won = 0;
	private int lost = 0;
	private int tied = 0;
	private ArrayList<T> members = new ArrayList<T>();

	public Team(String name) { this.name = name; }

	public String getName() { return this.name; }

	public boolean addPlayer(T player) {
		if (members.contains(player)) {
			System.out.println(player.getName() + " already in team");
			return false;
		}
		else {
			members.add(player);
			System.out.println(player.getName() + " added to team " + this.name);
			return true;
		}
	}

	public int numPlayers() { return this.members.size(); }

	public void matchResult(Team<T> opponent, int ourScore, int theirScore) {
		String message;
		if (ourScore > theirScore) {
			this.won++;
			message = " beat ";
		}
		else if (ourScore < theirScore) {
			this.lost++;
			message = " lost to ";
		}
		else {
			this.tied++;
			message = " tied with ";
		}
		this.played++;
		if (opponent != null) {
			System.out.println(this.getName() + message + opponent.getName());
			opponent.matchResult(null, theirScore, ourScore);
		}
	}

	public int ranking() {
		return this.won * 2 + tied;
	}

	@Override
	public int compareTo(Team<T> team) {
		if (this.ranking() > team.ranking()) {
			return 1;
		}
		else if (this.ranking() < team.ranking()) {
			return -1;
		}
		else { return 0; }
	}
}
