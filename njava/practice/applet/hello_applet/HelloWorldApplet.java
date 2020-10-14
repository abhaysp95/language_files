import java.applet.Applet;
import java.awt.Graphics;

/* A main() is not invoked on an applet, and an applet class will not define main() */

public class HelloWorldApplet extends Applet {
	public void paint(Graphics g) {
		g.drawString("Hello World", 25, 50);  // x, y from top-left
	}
}
