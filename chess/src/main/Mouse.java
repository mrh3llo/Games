package main;

import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;

public class Mouse extends MouseAdapter {
    public int x, y;
    public boolean pressed;

    public void mousePressed(MouseEvent mouse) {
        pressed = true;
    }

    public void mouseReleased(MouseEvent mouse) {
        pressed = false;
    }

    public void mouseDragged(MouseEvent mouse) {
        x = mouse.getX();
        y = mouse.getY();
    }

    public void mouseMoved(MouseEvent mouse) {
        x = mouse.getX();
        y = mouse.getY();
    }
}
