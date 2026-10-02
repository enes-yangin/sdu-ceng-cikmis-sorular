import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.net.UnknownHostException;

public class IPFinderApp extends JFrame implements ActionListener {
    private final JTextField tf;
    private final JLabel l;
    private final JButton b;

    public IPFinderApp() {
        super("IP Finder");

        tf = new JTextField("Enter a domain (e.g. google.com)", 20);
        tf.setForeground(Color.GRAY);

        l = new JLabel("Result will be displayed here.");

        b = new JButton("Find IP");
        b.addActionListener(this);

        setLayout(new FlowLayout()); // Daha iyi bir düzen kullanıldı
        add(tf);
        add(b);
        add(l);

        setSize(400, 200);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setVisible(true);
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        try {
            String host = tf.getText().trim();
            if (host.isEmpty() || host.equalsIgnoreCase("Enter a domain (e.g. google.com)")) {
                JOptionPane.showMessageDialog(this, "Please enter a valid domain name!", "Error", JOptionPane.ERROR_MESSAGE);
                return;
            }
            String ip = java.net.InetAddress.getByName(host).getHostAddress();
            l.setText("IP of " + host + " is: " + ip);
        } catch (UnknownHostException ex) {
            JOptionPane.showMessageDialog(this, "Invalid domain or no internet connection!", "Error", JOptionPane.ERROR_MESSAGE);
        }
    }

    public static void main(String[] args) {
        new IPFinderApp();
    }
}
