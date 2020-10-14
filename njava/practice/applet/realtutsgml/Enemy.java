import java.awt.*;
import java.net.URL;

public class Enemy {
	private int x = 0;
	private int y = 0;
	private int speedX = 5;
	private int speedY = 5;
	private URL url;
	private Image enemy;
	private int imgSize = 50;

	Enemy(MainClass mc) {
		this(100, 50, mc);
	}

	Enemy(int x, int y, MainClass mc) {
		this.x = x;
		this.y = y;
		System.out.println("Starting at: " + this.x + ", " + this.y);
		this.url = mc.getDocumentBase();
		this.enemy = mc.getImage(this.url, "evil_small.png");
	}

	public void update(MainClass mc, Player p) {
		this.x += speedX;
		this.y += speedY;
		if (this.x < 0) {
			this.speedX += (int)((Math.random() * 3) + 5);
		}
		else if (this.x >= mc.getWidth() - this.imgSize) {
			this.speedX -= (int)((Math.random() * 3) + 5);
		}

		if (this.y < 0) {
			this.speedY += (int)((Math.random() * 3) + 5);
		}
		else if (this.y >= mc.getHeight() - this.imgSize) {
			this.speedY -= (int)((Math.random() * 3) + 5);
		}

		collision(p);
	}

	private void collision(Player p) {
		int pX = p.getX();
		int pY = p.getY();
		if (pX - 50 <= this.x && pX + 50 >= this.x && pY - 50 <= this.y && pY + 50 >= this.y) {
			p.restart();
			System.out.println("Collision detected");
		}
	}

	public void paint(Graphics g, MainClass mc) {
		g.drawImage(this.enemy, x, y, mc);
	}
}
