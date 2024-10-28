package graph;

import main.GamePanel;

public class pawn extends piece {

    public pawn(int col, int row, int color) {
        super(col, row, color);
        
        if(color == GamePanel.WHITE) {
            //it's White turn
            img = getImg("img/lighter_pawn_rmbg");
        }
        else {
            //it's Black turn
            img = getImg("img/darker_pawn_rmbg");
        }
    }
    
}
