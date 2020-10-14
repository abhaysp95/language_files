import java.awt.*;
import java.applet.Applet;
import java.awt.event.*;

public class Example extends Applet implements MouseListener {
	private String str = "Not Set";
	private int clickCounts = 0;

	public void init() {
		setBackground(Color.BLUE);
		addMouseListener(this);
	}

	public void mouseClicked(MouseEvent e) {
		this.str = "Mouse Clicked, position: " + e.getX() + ", " + e.getY();
		repaint();
	}

	public void mouseEntered(MouseEvent e) {
		this.str = "Mouse entered from postion " + e.getX() + ", " + e.getY();
		repaint();
	}

	public void mousePressed(MouseEvent e) {
		this.clickCounts += e.getClickCount();
		this.str = "Mouse pressed: " + this.clickCounts;
		repaint();
	}
	public void mouseReleased(MouseEvent e) {
		this.str = "Mouse released: " + this.clickCounts;
		repaint();
	}
	public void mouseExited(MouseEvent e) {
		this.str = "Mouse exited";
		repaint();
	}

	public void paint(Graphics g) {
		g.drawString(this.str, 50, 50);
		g.setColor(Color.CYAN);
	}
}
