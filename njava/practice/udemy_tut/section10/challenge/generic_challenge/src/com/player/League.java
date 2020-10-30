package com.player;

import java.util.List;
import java.util.ArrayList;
import java.util.Collections;

public class League<T extends Team> {
	public String name;
	private List<T> league = new ArrayList<T>();

	public League(String name) { this.name = name; }

	public boolean add(T team) {
		if (league.contains(team)) {
			return false;
		}
		league.add(team);
		return true;
	}

	public void showLeagueTable() {
		// our compareTo from Team.java will be used
		Collections.sort(league);
		for(T t: league) {
			System.out.println(t.getName() + ": " + t.ranking());
		}
	}
}
