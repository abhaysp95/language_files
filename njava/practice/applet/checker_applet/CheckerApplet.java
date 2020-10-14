import java.applet.Applet;
import java.awt.*;

public class CheckerApplet extends Applet {
	int squareSize = 50;
	public void init() {
		String squareSizeParam = getParameter("squareSize");
		parseSquareSize(squareSizeParam);

		String colorParam = getParameter("color");
		Color fg = parseColor(colorParam);

		setBackground(Color.BLACK);
		setForeground(fg);
	}

	private void parseSquareSize(String param) {
		if (param == null) {
			return;
		}
		try {
			this.squareSize = Integer.parseInt(param);
		}
		catch (Exception e) {
			System.out.println("Something happened: " + e);
		}
	}

	private Color parseColor(String param) {return null;}
	/* parseColor() does a series of string comparisions to match the parameter
	 * value to the name of a predefined color */
	public void paint(Graphics g) {
		g.drawString("Hello, this is from paint", 30, 20);
	}
}
