import javax.swing.JFrame;
import javax.swing.JTextArea;

public class TextArea1 {
    TextArea1(){
        JFrame f = new JFrame();
        JTextArea area = new JTextArea("This is a textArea");
        area.setBounds(20, 40, 300, 300);
        f.add(area);
        f.setSize(400, 400);
        f.setLayout(null);
        f.setVisible(true);
    }

    public static void main(String[] args) {
        new TextArea1();
    }
}
