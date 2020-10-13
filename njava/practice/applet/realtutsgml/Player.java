import java.awt.Graphics;
import java.awt.*;
import java.awt.event.*;
import java.net.URL;

public class Player implements KeyListener {
	private int x = 200;
	private int y = 200;
	private int radius = 20;
	private int velX = 0;
	private int velY = 0;
	private URL url;
	private Image ball;

	Player(MainClass mc) {
		this.url = mc.getDocumentBase();  // check this out(alternative)
		this.ball = mc.getImage(this.url, "lego_small.png");
	}

	public void update(MainClass mc) {
		this.x += velX;
		this.y += velY;
		//this.x += 5;
		mc.addKeyListener(this);
	}

	public void paint(Graphics g, MainClass mc) {
		//g.setColor(Color.BLUE);
		//g.fillOval(this.x, this.y, radius*2, radius*2);
		g.drawImage(this.ball, x, y, mc);
	}

	@Override
	public void keyPressed(KeyEvent e) {
		switch(e.getKeyCode()) {
			case KeyEvent.VK_RIGHT:
				velX = 5;
				break;
			case KeyEvent.VK_LEFT:
				velX = -5;
				break;
			case KeyEvent.VK_UP:
				velY = -5;
				break;
			case KeyEvent.VK_DOWN:
				velY = +5;
				break;
		}
	}
	@Override
	public void keyReleased(KeyEvent e) {
		switch(e.getKeyCode()) {
			case KeyEvent.VK_RIGHT:
				velX = 0;
				break;
			case KeyEvent.VK_LEFT:
				velX = 0;
				break;
			case KeyEvent.VK_UP:
				velY = 0;
				break;
			case KeyEvent.VK_DOWN:
				velY = 0;
				break;
		}
	}
	@Override
	public void keyTyped(KeyEvent e) {}
}
