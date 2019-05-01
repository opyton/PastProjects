
package cs1302.arcade;

import java.util.Random;
import javafx.animation.RotateTransition;


import javafx.event.*;
import javafx.application.Application;
import javafx.application.Platform;
import javafx.geometry.Insets;
import javafx.geometry.Pos;
import javafx.scene.layout.StackPane;
import javafx.scene.control.MenuBar;
import javafx.scene.control.Menu;
import javafx.scene.control.MenuItem;
import javafx.scene.Scene;
import javafx.scene.image.Image;
import javafx.scene.image.ImageView;
import javafx.stage.Stage;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.layout.BackgroundImage;
import javafx.scene.layout.Background;
import javafx.scene.layout.BackgroundFill;
import javafx.scene.layout.BackgroundRepeat;
import javafx.scene.layout.BackgroundPosition;
import javafx.scene.layout.BackgroundSize;
import javafx.scene.layout.CornerRadii;
import javafx.scene.layout.Pane;
import javafx.scene.paint.Color;
import javafx.stage.Modality;
import javafx.util.Duration;

public class ArcadeApp extends Application {

    Random rng = new Random();

    public enum Difficulty {
	EASY,
	MEDIUM,
	HARD;
    }

    public Difficulty difficulty;
    @Override
    public void start(Stage stage) {
	difficulty = Difficulty.EASY;
	StackPane mainLayout = new StackPane();
	BackgroundImage backgroundImage = new BackgroundImage(new Image("download.jpg",50,50,true,true), BackgroundRepeat.REPEAT, BackgroundRepeat.REPEAT, BackgroundPosition.CENTER, BackgroundSize.DEFAULT);
	Background background = new Background(backgroundImage);
	mainLayout.setBackground(background);
	
	MenuBar menuBar = new MenuBar();
	Menu fileMenu = new Menu("File");
	MenuItem home = new MenuItem("Home");
	MenuItem exit = new MenuItem("Exit");
	EventHandler<ActionEvent> exitEvent = e -> {
		Platform.exit();
		System.exit(0);
	    };
	exit.setOnAction(exitEvent);
	fileMenu.getItems().addAll(home,exit);
	
	Menu helpMenu = new Menu("Help");
	MenuItem msHelp = new MenuItem("About Minesweeper");
	Stage msHelpStage = new Stage();
	msHelpStage.initModality(Modality.APPLICATION_MODAL);
	Scene msHelpScene = new Scene(new StackPane(new Label("Instructions: \n"
		+ "Left click to reveal a square.\n"
		+ "Right click to flag a square as a mine.\n"
		+ "Flag all mines to win!\n"
		+ "Careful though. Left click a mine and you lose!")),400,200);
	msHelpStage.setScene(msHelpScene);
	msHelp.setOnAction(e -> msHelpStage.show());
	MenuItem breakoutHelp = new MenuItem("About Breakout");
	Stage breakoutHelpStage = new Stage();
	breakoutHelpStage.initModality(Modality.APPLICATION_MODAL);
	Scene breakoutHelpScene = new Scene(new StackPane(new Label("Instructions: \n"
		+ "Use left arrow key to move left.\n"
		+ "Use right arrow key to ove right\n"
		+ "If you let the ball fall you have 3 tries total before you lose."
		+ "Break all the colored blocks to win!")),400,200);
	breakoutHelpStage.setScene(breakoutHelpScene);
	breakoutHelp.setOnAction(e -> breakoutHelpStage.show());
	helpMenu.getItems().addAll(msHelp,breakoutHelp);
	
	menuBar.getMenus().addAll(fileMenu, helpMenu);
	
	mainLayout.getChildren().add(menuBar);
	
	StackPane.setAlignment(menuBar, Pos.TOP_CENTER);
	ImageView breakoutPic = new ImageView(new Image("breakout.jpg", 320, 180, true, true));
	ImageView minesweeperPic = new ImageView(new Image("minesweeper.jpg", 320, 180, true, true));
	Button breakoutBtn = new Button("", breakoutPic);
	Button minesweeperBtn = new Button("", minesweeperPic);
	
	mainLayout.getChildren().addAll(breakoutBtn, minesweeperBtn);
	StackPane.setAlignment(breakoutBtn, Pos.CENTER_LEFT);
	StackPane.setAlignment(minesweeperBtn, Pos.CENTER_RIGHT);
	
	
        Scene scene = new Scene(mainLayout, 640, 480);
        stage.setTitle("cs1302-arcade!");
	
	Label animationLabel = new Label("cs1302-arcade\n404:CREATIVITY_NOT_FOUND\nLucas Connell\nNathaniel Lee");
	RotateTransition rt = new RotateTransition(Duration.seconds(3), animationLabel);
       	rt.setByAngle(360);
	rt.setCycleCount(1);
	rt.setOnFinished(e -> {
		stage.setScene(scene);
		stage.sizeToScene();
		stage.show();
	    });
	Pane animationGroup = new Pane(animationLabel);
	animationGroup.setPrefSize(640,480);
	animationLabel.setTranslateX(220);
	animationLabel.setTranslateY(200);
	animationGroup.setBackground(new Background(new BackgroundFill(Color.RED, CornerRadii.EMPTY, Insets.EMPTY)));
	Scene introAnimation = new Scene(animationGroup);
	stage.setScene(introAnimation);
	stage.sizeToScene();
       	stage.setResizable(false);
	stage.show();
	rt.play();

	

  
	
	home.setOnAction((event) -> {
		if (stage.getScene() != scene) {
		    mainLayout.getChildren().add(menuBar);
		    StackPane.setAlignment(menuBar, Pos.TOP_CENTER);
		}
		stage.setScene(scene);
		stage.sizeToScene();
	});
	
	
	minesweeperBtn.setOnAction(e -> {
		Minesweeper minesweeper = new Minesweeper();
		Scene msScene = minesweeper.msLayout(menuBar,10,10); 
		stage.setScene(msScene);
		stage.sizeToScene();
	});
	Button msReset = Minesweeper.getReset();
	msReset.setOnAction(e -> minesweeperBtn.fire());
	
	breakoutBtn.setOnAction(e -> {
		Breakout breakout = new Breakout(breakoutBtn, difficulty); //creates new breakout game
		stage.setScene(breakout.boLayout(this, menuBar)); //takes the scene from breakout and sets it to our stage
		stage.sizeToScene();
		breakout.getGameDisplay().requestFocus(); //makes sure that the breakout main game scene can take keyboard input
	    });

    } // start

    public static void main(String[] args) {
	try {
	    Application.launch(args);
	} catch (UnsupportedOperationException e) {
	    System.out.println(e);
	    System.err.println("If this is a DISPLAY problem, then your X server connection");
	    System.err.println("has likely timed out. This can generally be fixed by logging");
	    System.err.println("out and logging back in.");
	    System.exit(1);
	} // try
    } // main

} // ArcadeApp
