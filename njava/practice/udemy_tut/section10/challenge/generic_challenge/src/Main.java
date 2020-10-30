import com.player.*;

public class Main {
	public static void main(String[] args) {
		FootballPlayer joe = new FootballPlayer("Joe");
		BaseballPlayer pat = new BaseballPlayer("Pat");
		CricketPlayer dhoni = new CricketPlayer("Dhoni");

		Team<FootballPlayer> footballTeam1 = new Team<FootballPlayer>("Football Team 1");
		footballTeam1.addPlayer(joe);

		Team<BaseballPlayer> baseballTeam1 = new Team<BaseballPlayer>("Baseball Team 1");
		baseballTeam1.addPlayer(pat);

		Team<CricketPlayer> cricketTeam1 = new Team<CricketPlayer>("Cricket Team 1");
		cricketTeam1.addPlayer(dhoni);

		Team<FootballPlayer> footballTeam2 = new Team<FootballPlayer>("Football Team 2");
		FootballPlayer jake = new FootballPlayer("Jake");
		footballTeam2.addPlayer(jake);

		Team<BaseballPlayer> beseballTeam2 = new Team<BaseballPlayer>("Baseball Team 2");
		BaseballPlayer peet = new BaseballPlayer("Peet");
		beseballTeam2.addPlayer(peet);

		Team<CricketPlayer> cricketTeam2 = new Team<CricketPlayer>("Cricket Team 2");
		CricketPlayer virat = new CricketPlayer("Virat");
		cricketTeam2.addPlayer(virat);

		footballTeam1.matchResult(footballTeam2, 3, 4);
		cricketTeam2.matchResult(cricketTeam1, 5, 3);
		//beseballTeam2.matchResult(footballTeam1, 10, 14);  // Incompatible type

		System.out.println(footballTeam1.numPlayers());

		System.out.println("Rankings: ");
		System.out.println(footballTeam1.getName() + ": " + footballTeam1.ranking());
		System.out.println(footballTeam2.getName() + ": " + footballTeam2.ranking());
		System.out.println(baseballTeam1.getName() + ": " + baseballTeam1.ranking());
		System.out.println(beseballTeam2.getName() + ": " + beseballTeam2.ranking());
		System.out.println(cricketTeam1.getName() + ": " + cricketTeam1.ranking());
		System.out.println(cricketTeam2.getName() + ": " + cricketTeam2.ranking());

		System.out.println(footballTeam1.compareTo(footballTeam2));
		System.out.println(cricketTeam2.compareTo(cricketTeam1));

		League<Team<CricketPlayer>> ipl = new League<>("IPL");
		Team<CricketPlayer> rcb = new Team<CricketPlayer>("Royal Challengers Banglore");
		Team<CricketPlayer> csk = new Team<CricketPlayer>("Chennai Super Kings");
		Team<CricketPlayer> mi = new Team<CricketPlayer>("Mumbai Indian");
		CricketPlayer abd = new CricketPlayer("A B devillers");
		CricketPlayer jadeja = new CricketPlayer("Jadeja");
		CricketPlayer rohit = new CricketPlayer("Rohit");
		rcb.addPlayer(virat);
		rcb.addPlayer(abd);
		csk.addPlayer(dhoni);
		csk.addPlayer(jadeja);
		mi.addPlayer(rohit);
		ipl.add(rcb);
		ipl.add(csk);
		ipl.add(mi);

		rcb.matchResult(csk, 7, 4);
		csk.matchResult(mi, 7, 5);
		mi.matchResult(rcb, 3, 4);

		ipl.showLeagueTable();
	}
}