import java.awt.*;
import java.net.URL;

public class Enemy {
	private int x = 0;
	private int y = 0;
	private int speedX = 5;
	private int speedY = 5;
	private URL url;
	private Image enemy;

	Enemy(MainClass mc) {
		this(100, 50, mc);
	}

	Enemy(int x, int y, MainClass mc) {
		this.x = x;
		this.y = y;
		this.url = mc.getDocumentBase();
		this.enemy = mc.getImage(this.url, "evil_small.png");
	}

	public void update(MainClass mc, String motion) {
		switch (motion) {
			case "horizontal":
				this.x += this.speedX;
				System.out.println("Inside horizontal case " + this.getClass().getName());
				if (this.x < 0) {
					this.speedX += 5;
				}
				else if (this.x > mc.getWidth() - 30) {
					this.speedX -= 5;
				}
			case "vertical":
				this.y += speedY;
				System.out.println("Inside horizontal case " + this.getClass().getName());
				if (this.y < 0) {
					this.speedY += 5;
				}
				else if (this.y > mc.getHeight() - 30) {
					this.speedY -= 5;
				}
		}
	}

	public void paint(Graphics g, MainClass mc) {
		g.drawImage(this.enemy, x, y, mc);
	}
}
