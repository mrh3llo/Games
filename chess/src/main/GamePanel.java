package main;

import java.util.ArrayList;

//graphic library
import graph.*;
import java.awt.Color;
import java.awt.Dimension;
import java.awt.Graphics;
import java.awt.Graphics2D;

import javax.swing.JPanel; //organize component including draw, etc. 
 
public class GamePanel extends JPanel implements Runnable {
    public static final int WIDTH = 1200;
    public static final int HEIGHT = 1000;

    public static final int WHITE = 0;
    public static final int BLACK = 1;
    int currentColor = WHITE; //first turn is White

    public static ArrayList<piece> Pieces = new ArrayList<>(); 
    public static ArrayList<piece> simPieces = new ArrayList<>();

    Mouse mouse = new Mouse();

    final int FPS = 60;

    Thread gameThread;

    board chessBoard = new board();

    public GamePanel() {
        setPreferredSize(new Dimension(WIDTH, HEIGHT));
        setBackground(Color.black);

        addMouseMotionListener(mouse);
        addMouseListener(mouse);

        setPieces();
        copyPieces(Pieces, simPieces);
    }

    public void launchGame() {
        gameThread = new Thread(this);
        gameThread.start(); //this start() method basicly call the run() function
    }

    //set each pieces position
    public void setPieces() {
        //WHITE PIECES

        //8 white pawn
        for(int i = 1; i <= 8; i ++)
            Pieces.add(new pawn(i, 7, WHITE));

        //BLACK PIECES

        //8 black pawn
        for(int i = 1; i <= 8; i ++)
            Pieces.add(new pawn(i, 2, BLACK));
    }

    public void copyPieces(ArrayList<piece> source, ArrayList<piece> target) {
        target.clear();

        for(int i = 0; i < source.size(); i++) {
            target.add(source.get(i));
        }
    }

    public void run() {
        double drawInterval = 1000000000 / FPS;
        double delta = 0f;
        long lastTime = System.nanoTime();
        long currentTime;

        //GAME LOOP
        //this is one of the most game loop methods
        while(gameThread != null) {
            currentTime = System.nanoTime();

            delta += (currentTime - lastTime) / drawInterval;
            lastTime = currentTime;

            if(delta >= 1) {
                update();
                repaint();
                delta--;
            }
        }
    }
    
    private void update() {

    }
    
    public void paintComponent(Graphics graph) {
        super.paintComponent(graph);

        Graphics2D graph2D = (Graphics2D)graph;

        //draw BOARD
        chessBoard.draw(graph2D);

        //draw PIECES
        for(piece P : simPieces) {
            P.draw(graph2D); 
        }
    }
}
