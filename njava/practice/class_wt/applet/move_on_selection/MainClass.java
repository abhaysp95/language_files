import java.awt.*;
import java.applet.Applet;
import java.awt.event.*;

public class MainClass extends Applet implements Runnable, KeyListener {
	private Thread thr;
	private boolean running = true;
	private Image img;
	private Graphics gp;
	private Square s;
	private Circle c;
	private Triangle t;
	private int selected = 0;

	public void init() {
		thr = new Thread(this);
		setSize(1000, 500);
		setBackground(Color.BLUE);

		this.s = new Square();
		this.c = new Circle();
		this.t = new Triangle();

		addKeyListener(this);
	}

	public void start() { this.thr.start(); }
	public void stop() { this.running = false; }
	public void destroy() { this.running = false; }

	public void run() {
		while (running) {
			repaint();
			//this.s.update(this);
			try {
				Thread.sleep(20);
			}
			catch (InterruptedException ie) {
				System.out.println("Some interrupted exception happened");
			}
		}
	}

	public void update(Graphics g) {
		this.img = createImage(getWidth() , getHeight());
		this.gp = this.img.getGraphics();
		paint(this.gp);
		g.drawImage(this.img, 0, 0, this);
	}

	public void paint(Graphics g) {
		this.s.paint(g);
		this.c.paint(g);
		this.t.paint(g);
	}

	public void keyPressed(KeyEvent e) {
		switch(e.getKeyCode()) {
			case KeyEvent.VK_1:
				this.s.bigger(this);
				// how to pass outer class method/fields to inner anonymous class
				this.addKeyListener(new KeyAdapter() {
					@Override
					public void keyPressed(KeyEvent e) {
						System.out.println("key pressed");
						switch (e.getKeyCode()) {
							case KeyEvent.VK_LEFT:
								this.s.setVelX(-5);
								break;
							case KeyEvent.VK_RIGHT:
								this.s.setVelX(5);
								break;
							case KeyEvent.VK_UP:
								this.s.setVelY(-5);
								break;
							case KeyEvent.VK_DOWN:
								this.s.setVelY(5);
								break;
						}
					}
					@Override
					public void keyReleased(KeyEvent e) {
						System.out.println("key released");
						switch (e.getKeyCode()) {
							case KeyEvent.VK_LEFT:
								this.s.setVelX(0);
								break;
							case KeyEvent.VK_RIGHT:
								this.s.setVelX(0);
								break;
							case KeyEvent.VK_UP:
								this.s.setVelY(0);
								break;
							case KeyEvent.VK_DOWN:
								this.s.setVelY(0);
								break;
						}
					}
				});
				break;
			case KeyEvent.VK_2:
				this.c.bigger(this);
				break;
			case KeyEvent.VK_3:
				this.t.bigger(this);
				break;
		}
	}

	public void keyReleased(KeyEvent e) {
		switch(e.getKeyCode()) {
			case KeyEvent.VK_1:
				this.s.reset(this);
				break;
			case KeyEvent.VK_2:
				this.c.reset(this);
				break;
			case KeyEvent.VK_3:
				this.t.reset(this);
				break;
		}
	}

	public void keyTyped(KeyEvent e) {}
}
