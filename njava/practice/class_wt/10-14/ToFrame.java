import java.awt.*;
import java.awt.event.*;

public class ToFrame extends Frame implements ActionListener {
	Button b1;
	Button b2;
	TextField t1, t2;
	//Label l1;

	ToFrame() {
		setLayout(new FlowLayout());
		this.b1 = new Button("swap");
		this.b2 = new Button("equal");
		this.t1 = new TextField(30);
		this.t2 = new TextField(30);
		add(b1);
		add(b2);
		add(t1);
		add(t2);
		b1.addActionListener(this);
		b2.addActionListener(this);
	}

	//public void start() {}

	public void actionPerformed(ActionEvent e) {
		//this.s = "button clicked";
		if (e.getSource() == b1) {
			//this.s = "b1 clicked";
			//this.t1.setText(this.s);
			//this.t1.setText("b1 clicked");
			String s = this.t1.getText();
			this.t1.setText(this.t2.getText());
			this.t2.setText(s);
		}
		else {
			//this.s = "b2 clicked";
			//this.t1.setText(this.s);
			//this.t1.setText("b2 clicked");
			if (this.t1.getText().equals(this.t2.getText())) {
				//this.l1 = new Label("True");
				System.out.println("True");
			}
			else {
				//this.l1 = new Label("False");
				System.out.println("False");
			}
		}
		//repaint();
	}

	//public void paint(Graphics g) {
		//g.drawString(this.s, 30, 30);
	//}

	public static void main(String[] args) {
		ToFrame obj1 = new ToFrame();
		obj1.setSize(300, 300);
		obj1.setVisible(true);
	}
}
