import java.applet.*;
import java.awt.*;

public class MainClass extends Applet implements Runnable {
	Thread thr = new Thread(this);
	Player p;
	Enemy e1, e2, e3, e4;
	Image dbImage;
	Graphics dbg;
	private int sizeX = 1000;
	private int sizeY = 600;
	private boolean running = true;
	public void init() {
		setBackground(Color.BLUE);
		setSize(sizeX, sizeY);
		this.p = new Player(this);
		this.e1 = new Enemy(this);
		this.e2 = new Enemy(
				(int)(Math.random() * (sizeX - 1) + 1),
				(int)(Math.random() * (sizeY - 1) + 1), this);
		// e1, e2 are having motions for x and y both, how ?
		//this.e3 = new Enemy(200, 450, this);
		//this.e4 = new Enemy(700, 450, this);
		this.e3 = new Enemy(
				(int)(Math.random() * (sizeX - 1) + 1),
				(int)(Math.random() * (sizeY - 1) + 1), this);
		this.e4 = new Enemy(
				(int)(Math.random() * (sizeX - 1) + 1),
				(int)(Math.random() * (sizeY - 1) + 1), this);
	}
	public void start() { this.thr.start(); }
	public void stop() { this.running = false; }
	public void destroy() { this.running = false; }
	public void run() {
		while (running) {
			repaint();
			this.p.update(this);
			this.e1.update(this, this.p);
			this.e2.update(this, this.p);
			this.e3.update(this, this.p);
			this.e4.update(this, this.p);
			try {
				Thread.sleep(20);
			}
			catch (InterruptedException ie) {
				System.out.println("Some interruption error occured");
			}
		}
	}
	// update() is bydefault run by repaint() and update() by default runs paint()
	@Override
	public void update(Graphics g) {
		this.dbImage = createImage(getWidth(), getHeight());
		this.dbg = this.dbImage.getGraphics();
		paint(dbg);
		g.drawImage(this.dbImage, 0, 0, this);
	}

	@Override
	public void paint(Graphics g) {
		this.p.paint(g, this);
		this.e1.paint(g, this);
		this.e2.paint(g, this);
		this.e3.paint(g, this);
		this.e4.paint(g, this);
	}
}
