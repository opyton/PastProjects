/* MinesweeperGame.java
 * 
 * Copyright © 2018 Michael E. Cotterell and the University of Georgia. This work is licensed under a 
 * Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License to students and 
 * the public.
 */

package cs1302.arcade;

import javafx.geometry.Pos;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.image.Image;
import javafx.scene.image.ImageView;
import javafx.scene.layout.StackPane;
import javafx.stage.Modality;
import javafx.stage.Stage;

/**
 * This class represents a Minesweeper game.
 *
 */ 
public class MinesweeperGame {

    /**
     * Constructs an object instance of the {@link Minesweeper} class using the
     * <code>rows</code> and <code>cols</code> values as the game grid's number
     * of rows and columns respectively. Additionally, the number of positions
     * in the grid that will be set as a mine should equal the ceiling of 
     * <code>1.0 * rows * cols / 3.0</code>, casted to an <code>int</code>. These
     * mine positions should be assigned randomly.
     *
     * @param rows the number of rows in the game grid
     * @param cols the number of cols in the game grid
     */
    public MinesweeperGame(int rows, int cols) {
	arrayReveal = new char[rows][cols];	
	array = new char[rows][cols];
	revealArray = new boolean[rows][cols];
	
	for (int y = 0; y < rows; y++){
		for(int x=0; x < array[0].length; x++){
		array[y][x] = ' ';
		arrayReveal[y][x] = ' ';
		revealArray[y][x] = false;
		}
	}
//	mines = (int)(1.0*rows*cols/3.0);
	mines = 10;

	/*
	 * This for loop will set a 'mine' amount of mines in random locations throughout
	 * the array. 'b' denotes a mine
	 */
	for(int mine = 0; mine<mines; mine++) {
		int y = (int)(Math.random()*rows);
		int x = (int)(Math.random()*cols);
		if (arrayReveal[y][x]=='b') 
			mine--;
		else
			arrayReveal[y][x] = 'b';
	}
	flagCounter = mines;
    } // Minesweeper
   
	public char[][]array=null;
	public char[][]arrayReveal=null;
	public boolean[][] revealArray=null;
	
	private int rounds = 0;
	public int getRoundNum(){
		return rounds;
	}
	private int mines = 0;
	public int getNumMines(){
		return mines;
	}
	
	public int flagCounter;//count mines left 
	
	private int score = 0;
	public int getScore(){
		return score;
	}

	private int guesses = 0;
	public int getGuesses(){
		return guesses;
	}
	private int rows;
	public int getRows(){
		return rows;
	}
	private int cols;
	public int getCols(){
		return cols;
	}

	private int nearbyMine=0;
	public int getNearbyMine(){
		return nearbyMine;
	}

	/**
	 * returns solution to command line
	 */
	public void printSol(){	
		System.out.println();
		System.out.println(" Rounds Completed: " + getRoundNum());
		System.out.println();
		
		for (int y = 0; y < arrayReveal.length; y++){
		System.out.print(" " + y + " |");
			for(int x = 0; x<arrayReveal[y].length;x++){
				if(arrayReveal[y][x]=='b')
					System.out.print("<" + array[y][x] + ">|");
				else
					
					System.out.print(" " + array[y][x] + " |");
			}
		System.out.println();
		}
		System.out.print("    ");
			for(int x = 0; x<array[0].length;x++){
			System.out.print(" " + x + "  ");
			}
	}
	
	/**
	 * This will display a gameover 
	 */
	public void gameOver(){
		Stage lose = new Stage();
		
		Label loseText = new Label("Oh no! You Picked a Mine!");
		ImageView loseImage = new ImageView(new Image("lose.png",100,100,true,true));
		Button returnToGame = new Button("Return to game");
			returnToGame.setOnAction(e -> lose.close());
		
		StackPane loseScene = new StackPane();
		StackPane.setAlignment(loseText, Pos.TOP_CENTER);
		StackPane.setAlignment(loseImage, Pos.CENTER);
		StackPane.setAlignment(returnToGame, Pos.BOTTOM_CENTER);
		loseScene.getChildren().addAll(loseText,loseImage,returnToGame);
		
		Scene scene = new Scene(loseScene,200,200);
		lose.setScene(scene);
		lose.sizeToScene();
		lose.initModality(Modality.APPLICATION_MODAL);
		lose.showAndWait();
	}	

	/**
	 * Displays a win screen. Good Job!
	 */
	public void win() {

		rows = array.length;
		cols = array[0].length;
		score = (rows * cols) + (mines - guesses) / rounds;
		
		Stage win = new Stage();
		
		Label winText = new Label("Congrats you win! Your score is " + score);
		ImageView winImage = new ImageView(new Image("win.jpg",100,100,true,true));
		Button returnToGame = new Button("Return to game");
			returnToGame.setOnAction(e -> win.close());
		
		StackPane winScene = new StackPane();
		StackPane.setAlignment(winText, Pos.TOP_CENTER);
		StackPane.setAlignment(winImage, Pos.CENTER);
		StackPane.setAlignment(returnToGame, Pos.BOTTOM_CENTER);
		winScene.getChildren().addAll(winText,winImage,returnToGame);
		
		Scene scene = new Scene(winScene,280,200);
		win.setScene(scene);
		win.sizeToScene();
		win.initModality(Modality.APPLICATION_MODAL);
		win.showAndWait();
		
	}

	/**
	*checks if the user has won after every round
	 * @return if win condition
	 */
	public boolean winCondition() {
		boolean noWin=true;
		int flagCount = 0;
		for(int y = 0; y<arrayReveal.length;y++) {
			for (int x =0; x<arrayReveal[0].length;x++){
				if(arrayReveal[y][x]=='b'&& (array[y][x]=='f'||array[y][x]=='?')){
					flagCount++;
					if(flagCount == getNumMines())
						return (noWin);
				}
				if(arrayReveal[y][x]=='b'&& (array[y][x]!='f'&&array[y][x]!='?'))
					noWin=true;

			}//for x
		}//for y
		return (!noWin);
	}
	
	/**
	 * guess input in game
	 * @param clickRow
	 * @param clickCol 
	 */
	public void guess(int clickRow,int clickCol){
		int y = clickRow;
		int x = clickCol;
		array[y][x]= '?';
		guesses++;
		if (winCondition())
			win();
	}
	/**
	 * unflag input in game
	 * @param clickRow
	 * @param clickCol 
	 */
	public void unflag(int clickRow,int clickCol){
		int row = clickRow;
		int col = clickCol;
		array[row][col] = ' ';
		flagCounter++;
		rounds++;
		if (winCondition())
			win();
	}
	/**
	 * flag input in game
	 * @param clickRow
	 * @param clickCol 
	 */
	public void flag(int clickRow,int clickCol){
		int row = clickRow;
		int col = clickCol;
		array[row][col]= 'f';
		flagCounter--;
		rounds++;
		if (winCondition())
			win();
	}
    /**
     * Starts the game and execute the game loop.
	 * @param clickRow
	 * @param clickCol
	 * @return int
	 * 
     */
    public int run(int clickRow, int clickCol) {
					
		nearbyMine=0;//reset nearbyMine value
		int y = clickRow;
		int x = clickCol;
		
		if(arrayReveal[y][x]=='b'){
			array[y][x] = 'b';
		}
		else {
			if(y!=0 && x!=0 && y!=(array.length-1) && x!=(array[0].length-1)){
				nearbyMine = (arrayReveal[y-1][x]=='b')?(nearbyMine + 1): nearbyMine;
				nearbyMine = (arrayReveal[y-1][x+1]=='b')?(nearbyMine + 1): nearbyMine;
				nearbyMine = (arrayReveal[y][x+1]=='b')?(nearbyMine + 1): nearbyMine;
				nearbyMine = (arrayReveal[y+1][x+1]=='b')?(nearbyMine + 1): nearbyMine;
				nearbyMine = (arrayReveal[y+1][x]=='b')?(nearbyMine + 1): nearbyMine;
				nearbyMine = (arrayReveal[y+1][x-1]=='b')?(nearbyMine + 1): nearbyMine;
				nearbyMine = (arrayReveal[y][x-1]=='b')?(nearbyMine + 1): nearbyMine;
				nearbyMine = (arrayReveal[y-1][x-1]=='b')?(nearbyMine + 1): nearbyMine;
			}//if for non edges
			else if(y==0 && x!=0 && x!=(array[0].length-1)){
				nearbyMine = (arrayReveal[y][x-1]=='b')?(nearbyMine + 1): nearbyMine;
				nearbyMine = (arrayReveal[y][x+1]=='b')?(nearbyMine + 1): nearbyMine;
				nearbyMine = (arrayReveal[y+1][x-1]=='b')?(nearbyMine + 1): nearbyMine;
				nearbyMine = (arrayReveal[y+1][x]=='b')?(nearbyMine + 1): nearbyMine;
				nearbyMine = (arrayReveal[y+1][x+1]=='b')?(nearbyMine + 1): nearbyMine;
			}//top edge no corner
			else if(y==(array.length-1) && x!=0 && x!=(array[0].length-1)){
				nearbyMine = (arrayReveal[y][x-1]=='b')?(nearbyMine + 1): nearbyMine;
				nearbyMine = (arrayReveal[y][x+1]=='b')?(nearbyMine + 1): nearbyMine;
				nearbyMine = (arrayReveal[y-1][x-1]=='b')?(nearbyMine + 1): nearbyMine;
				nearbyMine = (arrayReveal[y-1][x]=='b')?(nearbyMine + 1): nearbyMine;
				nearbyMine = (arrayReveal[y-1][x+1]=='b')?(nearbyMine + 1): nearbyMine;
			}//bot edge no corner
			else if(x==0 && y!=0 && y!=(array.length-1)){
				nearbyMine = (arrayReveal[y-1][x]=='b')?(nearbyMine + 1): nearbyMine;
				nearbyMine = (arrayReveal[y-1][x+1]=='b')?(nearbyMine + 1): nearbyMine;
				nearbyMine = (arrayReveal[y][x+1]=='b')?(nearbyMine + 1): nearbyMine;
				nearbyMine = (arrayReveal[y+1][x]=='b')?(nearbyMine + 1): nearbyMine;
				nearbyMine = (arrayReveal[y+1][x+1]=='b')?(nearbyMine + 1): nearbyMine;
			}//left edge no corner
			else if(x==(array[0].length-1) && y!=0 && y!=(array.length-1)){
				nearbyMine = (arrayReveal[y-1][x]=='b')?(nearbyMine + 1): nearbyMine;
				nearbyMine = (arrayReveal[y-1][x-1]=='b')?(nearbyMine + 1): nearbyMine;
				nearbyMine = (arrayReveal[y][x-1]=='b')?(nearbyMine + 1): nearbyMine;
				nearbyMine = (arrayReveal[y+1][x]=='b')?(nearbyMine + 1): nearbyMine;
				nearbyMine = (arrayReveal[y+1][x-1]=='b')?(nearbyMine + 1): nearbyMine;
			}//right edge no corner
			else if(x==0 && y==0) {
				nearbyMine = (arrayReveal[y+1][x]=='b')?(nearbyMine + 1): nearbyMine;
				nearbyMine = (arrayReveal[y+1][x+1]=='b')?(nearbyMine + 1): nearbyMine;
				nearbyMine = (arrayReveal[y][x+1]=='b')?(nearbyMine + 1): nearbyMine;
			}//top left corner
			else if(x==(array[0].length-1) && y==0) {
				nearbyMine = (arrayReveal[y+1][x]=='b')?(nearbyMine + 1): nearbyMine;
				nearbyMine = (arrayReveal[y+1][x-1]=='b')?(nearbyMine + 1): nearbyMine;
				nearbyMine = (arrayReveal[y][x-1]=='b')?(nearbyMine + 1): nearbyMine;
			}//top right corner
			else if(x==0 && y==(array.length-1)) {
				nearbyMine = (arrayReveal[y-1][x]=='b')?(nearbyMine + 1): nearbyMine;
				nearbyMine = (arrayReveal[y-1][x+1]=='b')?(nearbyMine + 1): nearbyMine;
				nearbyMine = (arrayReveal[y][x+1]=='b')?(nearbyMine + 1): nearbyMine;
			}//bot left corner
			else if(x==(array[0].length-1) && y==(array.length-1)) {
				nearbyMine = (arrayReveal[y-1][x]=='b')?(nearbyMine + 1): nearbyMine;
				nearbyMine = (arrayReveal[y-1][x-1]=='b')?(nearbyMine + 1): nearbyMine;
				nearbyMine = (arrayReveal[y][x-1]=='b')?(nearbyMine + 1): nearbyMine;
			}//bot right corner
			
			if(!(array[y][x]=='f'))array[y][x]=(char)(nearbyMine + 48);
				
			}//else
			if (winCondition())
				win();
			
		rounds++;
		return nearbyMine;
	} // run
} // Minesweeper
