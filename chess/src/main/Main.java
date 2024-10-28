package main;

import javax.swing.JFrame;

public class Main {
    public static void main(String[] args)
    {
        //1. Create a new window by JFrame with the name 'window'
        //2. Let the window open until press the 'close' button
        //3. To unable to resize the window
        //4. Set the window open in the centre of the screen
        //5. To see the window in the screen if the value is 'true'

        JFrame window = new JFrame("_koocs chess");
        window.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        window.setResizable(false);

        GamePanel gamePanel = new GamePanel();
        window.add(gamePanel);
        window.pack();

        window.setLocationRelativeTo(null);
        window.setVisible(true);

        gamePanel.launchGame();
    }
}
