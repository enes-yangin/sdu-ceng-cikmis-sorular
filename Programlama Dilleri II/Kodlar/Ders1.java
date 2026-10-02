/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
import javax.swing.*;
/**
 *
 * @author ummualtin
 */
public class Ders1 {

    public static void main(String[] args) {
        JFrame fr=new JFrame();     //creating instance of JFrame
        
        JButton but=new JButton("click");   //creating instance of JButton
        but.setBounds(100, 90, 100, 50);    //x axis, y axis, width, height. Click penceresinin boyutları
        
        fr.add(but);    //adding button in JFrame
        
        fr.setSize(300,300);    //300 width and 300 height
        fr.setLayout(null);     // no laylout managers
        fr.setVisible(true);    //making the frame visible
    }
    
}
