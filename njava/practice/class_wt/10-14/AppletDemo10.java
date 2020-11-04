import java.applet.Applet;
import java.awt.*;
import java.awt.event.*;

public class AppletDemo10 extends Applet implements ActionListener {
	Button b1;
	Button b2;
	TextField t1;
	String s;

	public void init() {
		this.b1 = new Button("ok");
		this.b2 = new Button("cancel");
		this.t1 = new TextField(30);
		add(b1);
		add(b2);
		add(t1);
		b1.addActionListener(this);
		b2.addActionListener(this);
	}

	public void start() {}

	public void actionPerformed(ActionEvent e) {
		//this.s = "button clicked";
		if (e.getSource() == b1) {
			this.s = "b1 clicked";
			this.t1.setText(this.s);
		}
		else {
			this.s = "b2 clicked";
			this.t1.setText(this.s);
		}
		repaint();
	}

	public void paint(Graphics g) {
		g.drawString(this.s, 30, 30);
	}
}
