
import java.awt.event.*;
import javax.swing.*;

public class Ders2 {
    public static void main(String[] args) {
        JFrame f = new JFrame("Button Example");
        final JTextField tf = new JTextField();
        tf.setBounds(45, 75, 220, 20);
        JButton b = new JButton("Click Here");
        b.setBounds(100, 100, 100, 50);
        b.addActionListener((ActionEvent e) -> {
            tf.setText("You have just clicked the button!");
        });
        f.add(b); f.add(tf);
        f.setSize(300, 300);
        f.setLayout(null);
        f.setVisible(true);
    }
}
