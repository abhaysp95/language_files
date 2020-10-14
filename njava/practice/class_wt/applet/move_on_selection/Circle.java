import java.awt.*;

public class Circle {
	private int x = 400;
	private int y = 100;
	private int radius = 25;

	public void update(MainClass mc) {
		this.radius += 10;
	}

	public void bigger(MainClass mc) {
		this.radius += 10;
	}

	public void reset(MainClass mc) {
		this.radius -= 10;
	}

	public void paint(Graphics g) {
		g.setColor(Color.YELLOW);
		g.drawOval(this.x, this.y, this.radius * 2, this.radius * 2);
	}
}
