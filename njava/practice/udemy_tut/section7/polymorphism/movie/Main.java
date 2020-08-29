class Movie {
	private String name;

	public Movie(String name) {
		this.name = name;
	}

	public String getName() {
		return this.name;
	}

	public String plot() {
		return "No plot";
	}
}

class Jaws extends Movie {
	public Jaws() {
		super("Jaws");
	}

	public String plot() {
		return "A shark eats a lot of people";
	}
}

class IndependanceDay extends Movie {
	public IndependanceDay() {
		super("IndependanceDay");
	}

	public String plot() {
		return "Aliens attempt to take over Earth";
	}
}

class MazeRunner extends Movie {
	public MazeRunner() {
		super("MazeRunner");
	}

	public String plot() {
		return "Kids try and escape a Maze";
	}
}

class StarWars extends Movie {
	public StarWars() {
		super("StarWars");
	}

	public String plot() {
		return "Imperial Forces try to take over the universe";
	}
}

class Forgetable extends Movie {
	public Forgetable() {
		super("Forgetable");
	}
	// No plot method
}

public class Main {
	public static void main(String[] args) {
		for (int i = 1; i < 11; ++i) {
			Movie movie = returnMovie();
			System.out.println("Movie #" + i +
					": " + movie.getName() + "\n" +
					"Plot: " + movie.plot() + "\n");
		}
	}

	public static Movie returnMovie() {
		// generate a random number between 1 to 5 inclusive
		int randomNum = (int)((Math.random() * 5) + 1);
		System.out.println("Random number generated: " + randomNum);
		// Using inheritance factor, that Jaws is a Movie, IndependanceDay is a Movie ....
		switch(randomNum) {
			case 1:
				return new Jaws();
			case 2:
				return new IndependanceDay();
			case 3:
				return new MazeRunner();
			case 4:
				return new StarWars();
			case 5:
				return new Forgetable();
			// either use default or give null outside of switch statement
			default:
				return null;
		}
	}
}
