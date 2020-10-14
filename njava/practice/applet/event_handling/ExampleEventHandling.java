import java.awt.event.MouseListener;
import java.awt.event.MouseEvent;
import java.applet.Applet;
import java.awt.Graphics;
import java.awt.Color;

public class ExampleEventHandling extends Applet implements MouseListener {
	StringBuffer strBuffer;

	public void init() {
		addMouseListener(this);
		strBuffer = new StringBuffer();
		addItem("initializing the applet");
		setBackground(Color.BLACK);
	}

	public void start() {
		addItem("starting the applet");
	}

	public void stop() {
		addItem("stopping the applet");
	}

	public void destroy() {
		addItem("unloading the applet");
	}

	private void addItem(String word) {
		System.out.println(word);
		strBuffer.append(word);
		repaint();
	}

	public void paint(Graphics g) {
		// draw a rectangle around the applet's display area
		g.drawRect(0, 0, getWidth() - 1, getHeight() - 1);

		// display the string inside the rectangle
		g.drawString(strBuffer.toString(), 10, 20);
		g.setColor(Color.YELLOW);
	}

	public void mouseEntered(MouseEvent event) {}
	public void mouseExited(MouseEvent event) {}
	public void mousePressed(MouseEvent event) {}
	public void mouseReleased(MouseEvent event) {}
	public void mouseClicked(MouseEvent event) {
		addItem("mouse clicked!");
	}
}
