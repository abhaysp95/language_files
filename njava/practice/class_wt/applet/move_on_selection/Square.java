import java.awt.*;
import java.awt.event.*;

public class Square {
	//implements KeyListener {
	private int x = 50;
	private int y = 50;
	private int posX = 200;
	private int posY = 100;
	private int velX = 5;
	private int velY = 5;

	public void update(MainClass mc) {
		//mc.addKeyListener(this);
		this.posX += velX;
		this.posY += velY;
		System.out.println("Current postion: " + this.posX + ", " + this.posY);
	}

	public void setVelX(int x) {
		this.velX = x;
	}

	public void setVely(int y) {
		this.velY = y;
	}

	public void bigger(MainClass mc) {
		this.x += 30;
		this.y += 30;
	}

	public void reset(MainClass mc) {
		this.x -= 20;
		this.y -= 20;
	}

	public void paint(Graphics g) {
		g.setColor(Color.YELLOW);
		g.drawRect(200, 100, this.x, this.y);
	}

	//public void keyPressed(KeyEvent e) {
		//System.out.println("key pressed");
		//switch (e.getKeyCode()) {
			//case KeyEvent.VK_LEFT:
				//velX = -5;
				//break;
			//case KeyEvent.VK_RIGHT:
				//velX = 5;
				//break;
			//case KeyEvent.VK_UP:
				//velY = -5;
				//break;
			//case KeyEvent.VK_DOWN:
				//velY = 5;
				//break;
		//}
	//}

	//public void keyReleased(KeyEvent e) {
		//System.out.println("key released");
		//switch (e.getKeyCode()) {
			//case KeyEvent.VK_LEFT:
				//velX = 0;
				//break;
			//case KeyEvent.VK_RIGHT:
				//velX = 0;
				//break;
			//case KeyEvent.VK_UP:
				//velY = 0;
				//break;
			//case KeyEvent.VK_DOWN:
				//velY = 0;
				//break;
		//}
	//}

	//public void keyTyped(KeyEvent e) {}
}
