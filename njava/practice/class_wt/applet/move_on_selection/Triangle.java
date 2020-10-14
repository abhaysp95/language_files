import java.awt.*;

public class Triangle {
	private int[] x = {600, 650, 700};
	private int[] y = {150, 100, 150};

	public void update(MainClass mc) {
		this.x[1] = 680;
		this.x[2] = 760;
		this.y[0] = 170;
		this.y[1] = 80;
		this.y[2] = 170;
	}

	public void bigger(MainClass mc) {
		this.x[1] = 680;
		this.x[2] = 760;
		this.y[0] = 170;
		this.y[1] = 80;
		this.y[2] = 170;
	}

	public void reset(MainClass mc) {
		this.x[1] = 650;
		this.x[2] = 700;
		this.y[0] = 150;
		this.y[1] = 100;
		this.y[2] = 150;
	}

	public void paint(Graphics g) {
		g.setColor(Color.YELLOW);
		g.drawPolygon(x, y, 3);
	}
}
