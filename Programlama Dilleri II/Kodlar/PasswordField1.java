import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPasswordField;

public class PasswordField1 {
    public static void main(String[] args) {
        JFrame f = new JFrame("Password Field Example");
        JPasswordField passf = new JPasswordField();
        JLabel l1 = new JLabel("Password: ");
        l1.setBounds(20,100, 80, 30);
        passf.setBounds(100, 100, 100, 30);
        f.add(passf); f.add(l1);
        f.setSize(300, 300);
        f.setLayout(null);
        f.setVisible(true);
    }
}
