package graph;

import java.awt.Graphics2D;

import java.awt.image.BufferedImage;
import java.io.IOException;

import javax.imageio.ImageIO;

public class piece {
    public BufferedImage img;
    public int x, y;
    public int row, col, preRow, preCol;
    public int color;

    public piece(int row, int col, int color) {
        this.row = row;
        this.col = col;
        this.color = color;

        x = getX(col);
        y = getY(row);

        preCol = col;
        preRow = row;
    }

    public BufferedImage getImg(String imgPath) {
        BufferedImage img = null;

        try {
            img = ImageIO.read(getClass().getResourceAsStream
            (imgPath + ".png"));
        }
        catch(IOException Ex) {
            Ex.printStackTrace();
        }

        return img;
    }

    public int getX(int col) {
        return col * board.SQUARE_SIZE;
    }

    public int getY(int row) {
        return row * board.SQUARE_SIZE;
    }

    public void draw(Graphics2D graph2D) {
        graph2D.drawImage(img, x, y, board.SQUARE_SIZE, board.SQUARE_SIZE, null);
    }
}
