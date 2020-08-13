import java.awt.EventQueue;

import javax.swing.JFrame;

public class Game extends JFrame {

Game() {
    add(new Board());
    setResizable(false);
    pack();

    setTitle("Snake");
    setLocationRelativeTo(null);
    setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
}

public static void main(String[] args) {

    // Creates a new thread so our GUI can process itself
    EventQueue.invokeLater(new Runnable() {
        @Override
        public void run() {
            JFrame frame = new Game();
            frame.setVisible(true);
        }
    });
}
}
