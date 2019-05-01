package cs1302.arcade;

import javafx.event.Event;
import javafx.event.EventHandler;
import javafx.geometry.Insets;
import javafx.geometry.Pos;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.MenuBar;
import javafx.scene.image.Image;
import javafx.scene.image.ImageView;
import javafx.scene.input.MouseButton;
import javafx.scene.input.MouseEvent;
import javafx.scene.layout.BorderPane;
import javafx.scene.layout.GridPane;
import javafx.scene.layout.StackPane;
import javafx.scene.layout.VBox;
import javafx.scene.text.Font;
import javafx.scene.text.Text;

/**
 *Constructs a Minesweeper class
 */
public class Minesweeper{
	final int mineSize = 30;//defined size of images, change to change all mines
	int clickRow=0, clickCol=0;
	boolean notDone;
	ImageView[][] m;
	MinesweeperGame msGame;
	static ImageView smilePic = new ImageView(new Image("msSmiley.png", 25, 25, true, true));
	private static Button reset = new Button("",smilePic);
	int totalRow, totalCol;
	
	/**
	 * 
	 * @return reset Button
	 */
	public static Button getReset(){
		return reset;
	} 
	/**
	 * non-static class that creates a layout for the minesweeper game.
	 * 
	 * @param menuBar (MenuBar)
	 * @param rows (int) 
	 * @param cols (int)
	 * 
	 * @return Scene a scene of minesweeper
	 */
	Scene msLayout(MenuBar menuBar, int rows, int cols){
		msGame = new MinesweeperGame(rows,cols);//instantiate game
		totalRow = rows;
		totalCol = cols;
		notDone = true;
//		msGame.printSol();//testing purpose prints solution to command line
//		System.out.println(msGame.getNumMines());
		
		BorderPane msLayout = new BorderPane();
		VBox topPart = new VBox();
		StackPane scoreBoard = new StackPane();
		
		//smiley
		StackPane.setAlignment(reset, Pos.CENTER);
			
		//mines remaining
		String mineLeftStr = "Mines: "+ msGame.flagCounter;
		Text mineLeft = new Text(mineLeftStr);
		mineLeft.setFont(Font.font(12));
		StackPane.setMargin(mineLeft, new Insets(8,8,8,8));
		StackPane.setAlignment(mineLeft, Pos.CENTER_LEFT);

		//score
		String scoreStr = "High Score: " + msGame.getScore();
		Text score = new Text(scoreStr);
		score.setFont(Font.font(12));
		StackPane.setMargin(score, new Insets(8,8,8,8));
		StackPane.setAlignment(score, Pos.CENTER_RIGHT);

		scoreBoard.getChildren().addAll(reset,mineLeft,score);

		topPart.getChildren().addAll(menuBar,scoreBoard);
		
		//mineGrid
		GridPane mineGrid = new GridPane();
		GridPane.setColumnSpan(mineGrid, cols);
		GridPane.setRowSpan(mineGrid, rows);
		m = new ImageView[rows][cols];
		for(int y = 0; y < rows; y++){
			for(int x = 0; x < cols; x++){
				m[y][x] = new ImageView(new Image("m.png",mineSize,mineSize,true,true));
				GridPane.setConstraints(m[y][x], y, x);
				mineGrid.getChildren().add(m[y][x]);
			}
		}
		mineGrid.addEventHandler(MouseEvent.MOUSE_CLICKED, e->{
			if (notDone){
				clickRow = (int)(e.getY()/mineSize);
				clickCol = (int)(e.getX()/mineSize);
				if(e.getButton()==MouseButton.PRIMARY){
					if(!msGame.winCondition())
						msPlay(clickRow,clickCol);
				}
				else if ((e.getButton()==MouseButton.SECONDARY)){
					if(!msGame.winCondition()){
						if(msGame.array[clickRow][clickCol]=='f'){
							msGame.unflag(clickRow,clickCol);
							flagAdjust(mineLeft);
							scoreAdjust(score);
							m[clickCol][clickRow].setImage(new Image("m.png",mineSize,mineSize,true,true));
						}
						else{	
							if(msGame.flagCounter>0){
								msGame.flag(clickRow, clickCol);
								flagAdjust(mineLeft);
								scoreAdjust(score);
								m[clickCol][clickRow].setImage(new Image("mflag.png",mineSize,mineSize,true,true));
							}
						}
						
					}
				}
				else if ((e.getButton()==MouseButton.MIDDLE)){
					if(!msGame.winCondition()){
						msGame.flag(clickRow, clickCol);
						m[clickCol][clickRow].setImage(new Image("mquestion.jpg",mineSize,mineSize,true,true));
					}
				}
			}
		});
		
		msLayout.setTop(topPart);
		msLayout.setCenter(mineGrid);
		Scene msScene = new Scene(msLayout,300,358);
		return msScene;
	}
	
	/**
	 * Returns score
	 * @param text 
	 */
	void scoreAdjust(Text text){
		if(msGame.winCondition()) text.setText("HighScore: " + msGame.getScore());
	}
	
	/**
	 * returns flag count
	 * @param text 
	 */
	void flagAdjust(Text text){
		text.setText("Mines: "+ msGame.flagCounter);
	}
	
	/**
	 * Plays game
	 * @param row
	 * @param col 
	 */
	void msPlay(int row, int col){
		if(msGame.revealArray[row][col]) return;
		msGame.revealArray[row][col] = true;
		
		if(msGame.run(row,col) !=0 || msGame.array[row][col]=='b'||msGame.array[row][col]=='f'){
			msGame.run(row,col);
			switch(msGame.array[row][col]){
				case '1': m[col][row].setImage(new Image("m1.png",mineSize,mineSize,true,true));break;
				case '2': m[col][row].setImage(new Image("m2.png",mineSize,mineSize,true,true));break;
				case '3': m[col][row].setImage(new Image("m3.png",mineSize,mineSize,true,true));break;
				case '4': m[col][row].setImage(new Image("m4.png",mineSize,mineSize,true,true));break;
				case '5': m[col][row].setImage(new Image("m5.png",mineSize,mineSize,true,true));break;
				case '6': m[col][row].setImage(new Image("m6.png",mineSize,mineSize,true,true));break;
				case '7': m[col][row].setImage(new Image("m7.png",mineSize,mineSize,true,true));break;
				case '8': m[col][row].setImage(new Image("m8.png",mineSize,mineSize,true,true));break;
				case 'f': m[col][row].setImage(new Image("mflag.png",mineSize,mineSize,true,true));break;
				case 'b': m[col][row].setImage(new Image("mmine.jpg",mineSize,mineSize,true,true)); 
					notDone = false;
					msGame.gameOver();break;
				
				default: m[col][row].setImage(new Image("m0.png",mineSize,mineSize,true,true));
			}
		}
	
		else{
			m[col][row].setImage(new Image("m0.png",mineSize,mineSize,true,true));
			if(row+1 < totalRow && col+1 < totalCol)msPlay(row + 1, col +1);
			if(row+1 < totalRow)msPlay(row + 1, col);
			if(col+1 < totalCol)msPlay(row, col +1);
			if(row-1 >= 0 && col-1 >= 0)msPlay(row - 1, col -1);
			if(row+1 < totalRow && col-1 >= 0)msPlay(row + 1, col-1);
			if(col-1 >=0)msPlay(row, col-1);
			if(row -1 >= 0) msPlay(row - 1, col);
			if(row-1 >= 0 && col+1 < totalCol) msPlay(row - 1, col+1);
			
		}			
	}
}
