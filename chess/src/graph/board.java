package graph;

import java.awt.Color;
import java.awt.Graphics2D;

public class board {
    final int MAX_COL = 8;
    final int MAX_ROW = 8;

    public static int SQUARE_SIZE = 100;
    public static int HALF_SQUARE_SIZE = SQUARE_SIZE / 2;

    public void draw(Graphics2D graph2D) {
        boolean changeColor = false;

        graph2D.setColor(Color.WHITE);
        //boolean changeColor1 = true;

        //first version theme of the board
        for(int row = 1; row < MAX_ROW + 1; row++) {
            if(row % 2 == 0)
                changeColor = false;
            else
                changeColor = true;
            //for loop for col
            for(int col = 1; col < MAX_COL + 1; col++) {
                //this is dark square
                if(changeColor == false) {
                    graph2D.setColor(new Color(176, 196, 222));
                    changeColor = true;

                }
                //this is light square
                else {
                    graph2D.setColor(new Color(255, 250, 240));
                    changeColor = false;
                }

                //fillRect(1, 2, 3, 4)
                /*
                1. is the x pos
                2. is the y pos
                => this x, y is the position of the square in thr board

                3. is width size of the shape
                4. is the height size of the shape
                */       
                
                graph2D.fillRect(col*SQUARE_SIZE, row*SQUARE_SIZE, SQUARE_SIZE, SQUARE_SIZE);  
            }
        }
    }
}