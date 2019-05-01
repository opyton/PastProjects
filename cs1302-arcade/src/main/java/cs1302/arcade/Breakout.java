package cs1302.arcade;

import javafx.scene.control.Menu;
import javafx.scene.control.MenuBar;
import javafx.scene.control.MenuItem;
import javafx.scene.input.KeyCode;
import javafx.event.*;
import javafx.scene.shape.Rectangle;
import javafx.scene.shape.Circle;
import javafx.scene.layout.StackPane;
import javafx.scene.layout.BorderPane;
import javafx.scene.control.Label;
import javafx.scene.Group;
import javafx.geometry.Pos;
import javafx.scene.Scene;
import javafx.scene.control.MenuBar;
import javafx.scene.layout.VBox;
import javafx.geometry.Insets;
import javafx.scene.layout.Pane;
import javafx.scene.input.KeyEvent;
import javafx.scene.paint.Color;
import javafx.scene.layout.CornerRadii;
import javafx.scene.layout.BackgroundFill;
import javafx.scene.layout.Background;
import javafx.scene.text.Font;
import javafx.animation.KeyFrame;
import javafx.animation.Timeline;
import javafx.util.Duration;
import javafx.scene.control.Button;

public class Breakout {

    public enum Velocity {
	UPRIGHT,
	UPLEFT,
	DOWNRIGHT,
	DOWNLEFT;
    }

    
    private int score, lives;
    private boolean started;
    private Rectangle paddle;
    private StackPane scoreBoard;
    private Label scoreLabel, livesLabel, outOfBoundsMessage;
    private Rectangle[][] enemies;
    private boolean[][] alive;
    private Circle ball;
    private Velocity currentTrajectory;
    private boolean ballOutOfBounds, gameDone;
    private Button reinstantiationButton;
    
    Timeline timeline;
    
    Pane gameDisplay;

    /**
     * Creates the scene to pass back to the ArcadeApp game. Requires ArcadeApp to pass itself to the method so that we may access ArcadeApp's
     * difficulty variable. Besides just setting up the scene, this method also implements the logic for taking keyboard input. It does not
     * request focus for the keyboard input though, that is done in the ArcadeApp.
     *
     * @return Scene
     */
    Scene boLayout(ArcadeApp a, MenuBar menuBar) {
	BorderPane boLayout = new BorderPane();

	Label currentDifficulty = new Label();
	switch (a.difficulty) {
	case EASY: currentDifficulty.setText("Currently on easy"); break;
	case MEDIUM: currentDifficulty.setText("Currently on medium");break;
	case HARD: currentDifficulty.setText("Currently on hard");break;
	}

	scoreBoard.getChildren().add(currentDifficulty);
	StackPane.setMargin(currentDifficulty, new Insets(8,8,8,8));
	StackPane.setAlignment(currentDifficulty, Pos.CENTER);
	
	MenuItem eButton = new MenuItem("Easy");
	eButton.setOnAction(e -> {
		a.difficulty = ArcadeApp.Difficulty.EASY; //sets difficulty to easy
		reinstantiationButton.fire(); //creates new BO game
	    });
	MenuItem mButton = new MenuItem("Medium");
	mButton.setOnAction(e -> {
		a.difficulty = ArcadeApp.Difficulty.MEDIUM; //sets difficulty to medium
		reinstantiationButton.fire(); //creates new BO game
	    });
	MenuItem hButton = new MenuItem("Hard");
	hButton.setOnAction(e -> {
		a.difficulty = ArcadeApp.Difficulty.HARD; //sets difficulty to hard
		reinstantiationButton.fire(); //creates new BO game
	    });
	Menu difficultyToggle = new Menu("Toggle Difficulty");
	difficultyToggle.getItems().addAll(eButton, mButton, hButton); //buttons to change difficulty
	MenuBar difficultyBar = new MenuBar(difficultyToggle);
	
	VBox topPart = new VBox(menuBar, difficultyBar , scoreBoard);
	
	gameDisplay = new Pane(paddle);

	gameDisplay.setBackground(new Background(new BackgroundFill(Color.BLACK, CornerRadii.EMPTY, Insets.EMPTY)));
	
	for (int i = 0; i < 6; i++) {
	    for (int j = 0; j < 6; j++) {
		gameDisplay.getChildren().add(enemies[i][j]); //adds the "enemy" blocks to the game
	    }
	}
	paddle.setX(175);
	paddle.setY(385); //starting paddle spot
	gameDisplay.setPrefSize(450,400);
	boLayout.setTop(topPart);
	boLayout.setCenter(gameDisplay);

	Label startPrompt = new Label("Press SPACE to begin!!");
	startPrompt.setTextFill(Color.WHITE);
	startPrompt.setFont(new Font(20));
	startPrompt.setLayoutX(130);
	startPrompt.setLayoutY(230);
	gameDisplay.getChildren().add(startPrompt);
	
       	gameDisplay.addEventHandler(KeyEvent.KEY_PRESSED, event -> { //this watches for keyboard input
		if (event.getCode() == KeyCode.LEFT && paddle.getX() > 0 && started)  paddle.setX(paddle.getX() - 20.0); //move left
		if (event.getCode() == KeyCode.RIGHT && paddle.getX() < 335 && started) paddle.setX(paddle.getX() + 20.0); //move right
		if (event.getCode() == KeyCode.SPACE && !started) { //start game
		    started = true;
		    gameDisplay.getChildren().remove(startPrompt);
		    gameDisplay.getChildren().add(ball);
		    timeline.play();
		}
		if (event.getCode() == KeyCode.TAB && ballOutOfBounds) { //continue game
		    ballReset();
		    ballOutOfBounds = false;
		    paddleReset();
		    lives--;
		    updateLives();
		    currentTrajectory = Velocity.UPLEFT;
		    gameDisplay.getChildren().remove(outOfBoundsMessage);
		    timeline.play();
		}
		if (event.getCode() == KeyCode.ENTER && gameDone) { //start over
		    reinstantiationButton.fire();
		}
	    });
	
	return new Scene(boLayout);
    }
    /**
     * Allows user to access game display from another class-- for example, if they want to let the gameDisplay pane request focus...
     *
     * @return Pane
     */
    public Pane getGameDisplay() {
	return gameDisplay;
    }

    /**
     * The one and only constructor for a game. It takes in a button which will be used for restarting purposes. It further
     * takes a difficulty, to decide how to set speed.
     */
    public Breakout(Button b, ArcadeApp.Difficulty difficulty) {
	reinstantiationButton = b;
	started = false;
	gameDone = false;

	int speed = 25; //default speed
	switch (difficulty) {
	case EASY: speed = 25; break;
	case MEDIUM: speed = 17; break;
	case HARD: speed = 12; break;
	}
	
	score = 0;
	lives = 3;
	scoreLabel = new Label(Integer.toString(score));
	livesLabel = new Label(Integer.toString(lives));

	ball = new Circle(232.5, 370, 10, Color.YELLOW);
	currentTrajectory = Velocity.UPLEFT; //default velocity

	KeyFrame keyFrame = new KeyFrame(Duration.millis(speed), e -> {
		checkCollision(); //checks to see if it should change direction
		switch (currentTrajectory) { //decides which direction to move
		case UPRIGHT: upRight(); break;
		case UPLEFT: upLeft(); break;
		case DOWNRIGHT: downRight(); break;
		case DOWNLEFT: downLeft(); break;
        }
	    });
	timeline = new Timeline();
	timeline.getKeyFrames().add(keyFrame);
	timeline.setCycleCount(Timeline.INDEFINITE);
	
	enemies = new Rectangle[6][6]; //instantiates the "enemy" rectangles
	alive = new boolean[6][6];
	for (int i = 0; i< 6; i++) {
	    for (int j = 0; j < 6; j++) {
		enemies[i][j] = new Rectangle(75,20);
		int choice = (int)(Math.random() * 4); //random gen colors for the "enemy" rectangles
		switch (choice) {
		case 0: enemies[i][j].setFill(Color.RED);break;
		case 1: enemies[i][j].setFill(Color.WHITE);break;
		case 2: enemies[i][j].setFill(Color.BLUE);break;
		case 3: enemies[i][j].setFill(Color.GREEN);break;
		}
		enemies[i][j].setStroke(Color.BLACK);
		enemies[i][j].setStrokeWidth(2.5);
		enemies[i][j].setX(j * 75);
		enemies[i][j].setY(i * 20);
		alive[i][j] = true;
	    }
	}
	
	scoreBoard = new StackPane(scoreLabel, livesLabel);

	StackPane.setMargin(scoreLabel, new Insets(8,8,8,8));
	StackPane.setMargin(livesLabel, new Insets(8,8,8,8));
	
	StackPane.setAlignment(scoreLabel, Pos.CENTER_RIGHT);
	StackPane.setAlignment(livesLabel, Pos.CENTER_LEFT);
	
	paddle = new Rectangle(115, 15);
	paddle.setFill(Color.GRAY);
    }

    /**
     * A getter method for the score variable
     *
     * @return int
     */
    public int getScore() {
	return score;
    }
    /**
     * A getter method for the lives variable
     *
     * @return int
     */
    public int getLives() {
	return lives;
    }
    /**
     * A getter method for the paddle variable.
     *
     * @return Rectangle
     */
    public Rectangle getPaddle() {
	return paddle;
    }
    /**
     * Moves the ball upleft at a 45 degree angle
     *
     * @return void
     */
    private void upLeft() {
	ball.setCenterX(ball.getCenterX() - 4);
	ball.setCenterY(ball.getCenterY() - 4);
    }
    
    /**
     * Moves the ball upright at a 45 degree angle
     *
     * @return void
     */
    private void upRight() {
	ball.setCenterX(ball.getCenterX() + 4);
	ball.setCenterY(ball.getCenterY() - 4);
    }

     /**
     * Moves the ball downleftt at a 45 degree angle
     *
     * @return void
     */
    private void downLeft() {
	ball.setCenterX(ball.getCenterX() - 4);
	ball.setCenterY(ball.getCenterY() + 4);
    }

     /**
     * Moves the ball downright at a 45 degree angle
     *
     * @return void
     */
    private void downRight() {
	ball.setCenterX(ball.getCenterX() + 4);
	ball.setCenterY(ball.getCenterY() + 4);
    }

     /**
     * To be called ONLY when the ball hits one of the "enemy" rectangles. Changes the currentTrajectory variable
     *
     * @return void
     */
    private void changeVelocity(Rectangle r) {
	switch (currentTrajectory) {
	case UPRIGHT: currentTrajectory = Velocity.DOWNRIGHT;break;
	case UPLEFT: currentTrajectory = Velocity.DOWNLEFT;break;
	case DOWNRIGHT: currentTrajectory = Velocity.DOWNLEFT;break;
	case DOWNLEFT: currentTrajectory = Velocity.DOWNRIGHT;break;
	}
    }

     /**
     * To be called ONLY when the ball hits the paddle. Changes the currentTrajectory variable
     *
     * @return void
     */
    private void hitPaddle() {
	switch (currentTrajectory) {
	case DOWNRIGHT: currentTrajectory = Velocity.UPRIGHT;break;
	case DOWNLEFT: currentTrajectory = Velocity.UPLEFT;break;
	}
    }

     /**
     * To be called ONLY when the ball hits either of the walls. Changes the currentTrajectory variable
     *
     * @return void
     */
    private void hitWall() {
	switch (currentTrajectory) {
	case UPRIGHT: currentTrajectory = Velocity.UPLEFT;break;
	case UPLEFT: currentTrajectory = Velocity.UPRIGHT;break;
	case DOWNRIGHT: currentTrajectory = Velocity.DOWNLEFT;break;
	case DOWNLEFT: currentTrajectory = Velocity.DOWNRIGHT;break;
	}
    }

     /**
     * To be called ONLY when the ball hits the ceiling. Changes the currentTrajectory variable
     *
     * @return void
     */
    private void hitCeiling() {
	switch (currentTrajectory) {
	case UPRIGHT: currentTrajectory = Velocity.DOWNRIGHT;break;
	case UPLEFT: currentTrajectory = Velocity.DOWNLEFT;break;
	}
    }

     /**
     * To be called ONLY when the ball misses the paddle and hits the bottom of the pane. Stops ball.
     *
     * @return void
     */
    private void outOfBounds() {
	timeline.pause();
	ballOutOfBounds = true;
	if (lives == 0) {
	    gameOver();
	    return;
	}
	outOfBoundsMessage = new Label("You've lost a life :(\nPress TAB to continue");
	outOfBoundsMessage.setTextFill(Color.WHITE);
	outOfBoundsMessage.setFont(new Font(20));
	outOfBoundsMessage.setLayoutX(100);
	outOfBoundsMessage.setLayoutY(230);
	gameDisplay.getChildren().add(outOfBoundsMessage);
    }

     /**
     * Checks if the ball's boundary is intersecting any other boundaries. If it is, determines which method to call to change the
     * velocity. 
     *
     * @return void
     */
    private void checkCollision() {
	for (int i = enemies.length - 1; i >= 0; i--) {
	    for (int j = enemies[0].length - 1; j >= 0; j--) {
		if (!alive[i][j]) continue; // we needn't check if we're intersecting enemies who aren't even there!
		if (ball.getBoundsInParent().intersects(enemies[i][j].getBoundsInParent())) {
		    changeVelocity(enemies[i][j]);
		    destroyEnemy(i,j); //remove the enemy from the scene
		    return;
		}
	    }
	}
	if (ball.getBoundsInParent().intersects(0,0,1,400) || ball.getBoundsInParent().intersects(449,0,1,400)) {
	    hitWall();
	    return;
	}
	else if (ball.getBoundsInParent().intersects(0,399,450,1)) {
	    outOfBounds();
	    return;
	}
	else if (ball.getBoundsInParent().intersects(paddle.getBoundsInParent())) {
	    hitPaddle();
	    return;
	}
	else if (ball.getBoundsInParent().intersects(0,0,450,5)) {
	    hitCeiling();
	    return;
	}
    }

     /**
     * Removes a given "enemy" rectangle from the scene.
     *
     * @return void
     */
    private void destroyEnemy(int row, int col) {
	gameDisplay.getChildren().remove(enemies[row][col]);
	alive[row][col] = false;
	score++;
	updateScore();
	if (score == 36) {
	    win();
	}
    }

     /**
     * Updates the score label which is displayed in the scoreboard
     *
     * @return void
     */
    private void updateScore() {
	scoreLabel.setText(Integer.toString(score));
    }

     /**
     * To be called when a user wins the game (defeats all enemies). Stops the ball, and prompts the user to instantiate a new game
     * by pressing ENTER
     *
     * @return void
     */
    private void win() {
	timeline.pause();
	Label winMessage = new Label("Congrats!!\nPress ENTER to play again.");
	winMessage.setTextFill(Color.WHITE);
	winMessage.setFont(new Font(20));
	winMessage.setLayoutX(100);
	winMessage.setLayoutY(230);
	gameDisplay.getChildren().add(winMessage);
	gameDone = true;
    }

     /**
     * Resets the ball to original poisition
     *
     * @return void
     */
    private void ballReset() {
	ball.setCenterX(232.5);
	ball.setCenterY(370);
    }

     /**
     * Resets the paddle to original poisition
     *
     * @return void
     */
    private void paddleReset() {
	paddle.setX(175);
	paddle.setY(385);
    }

     /**
     * Updates the lives label which is displayed in the scoreboard
     *
     * @return void
     */
    private void updateLives() {
	livesLabel.setText(Integer.toString(lives));
    }

     /**
     * To be called when the player runs out of lives. Prompts the user to instantiate new game by pressing ENTER
     *
     * @return void
     */
    private void gameOver() {
	Label loseMessage = new Label("LOSER! Press ENTER to play again.");
	loseMessage.setTextFill(Color.WHITE);
	loseMessage.setFont(new Font(20));
	loseMessage.setLayoutX(100);
	loseMessage.setLayoutY(230);
	gameDisplay.getChildren().add(loseMessage);
	gameDone = true;
    }
}
