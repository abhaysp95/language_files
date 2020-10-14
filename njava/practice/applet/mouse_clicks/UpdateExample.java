import java.awt.*;
import java.applet.Applet;
import java.awt.event.*;

/* <applet code="UpdateExample.class" width="600" height="600"></applet> */

public class UpdateExample extends Applet implements MouseListener {
	private int mouseX;
	private int mouseY;
	private boolean mouseClickedField = false;
	public void init() {
		setBackground(Color.BLACK);
		addMouseListener(this);
	}

	public void mouseClicked(MouseEvent e) {
		this.mouseX = e.getX();
		this.mouseY = e.getY();
		this.mouseClickedField = true;
		repaint();
	}

	public void mouseEntered(MouseEvent e) {}
	public void mousePressed(MouseEvent e) {}
	public void mouseReleased(MouseEvent e) {}
	public void mouseExited(MouseEvent e) {}

	public void update(Graphics g) {
		paint(g);
	}

	public void paint(Graphics g) {
		String str;
		g.setColor(Color.YELLOW);
		if (this.mouseClickedField) {
			str = "X = " + this.mouseX + ", Y = " + this.mouseY;
			g.drawString(str, this.mouseX, this.mouseY);
			this.mouseClickedField = false;
		}
	}
}
