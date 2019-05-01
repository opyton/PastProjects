//------------------
//		Sprite Variables - same for both here - need better modulariza
//------------------

let STAGE_WIDTH 	= 400,
	STAGE_HEIGHT 	= 400;

let	TIME_PER_FRAME  = 100;						//this equates to 30 fps

// -------------- create a message while images to load
let TEXT_PRELOADING 	= "Loading ...", 			//alert message waiting for sprites to load
	TEXT_PRELOADING_X = 100, 
	TEXT_PRELOADING_Y = 50 ;	
let	STAGE_FONT 		= "bold 20px sans-serif";  // font of message

let	CHAR_SRC0		= "img/mhearts0.png";
let	CHAR_SRC1		= "img/mhearts1.png";
let	CHAR_SRC2		= "img/mhearts2.png";
let	CHAR_SRC3		= "img/mhearts3.png";
	 
let CHAR_WIDTH = 32,
	CHAR_HEIGHT = 32;

let	CHAR_START_X = 100,
	CHAR_START_Y = 20,
	
	IMAGE_START_X = 0,
	IMAGE_START_Y = 0,

	SPRITE_WIDTH = 8*32;
	

let stage = document.getElementById("heartCanvas");
stage.width = STAGE_WIDTH;
stage.height = STAGE_HEIGHT;

let ctx = stage.getContext("2d");
ctx.fillStyle = "white";
ctx.font = STAGE_FONT;

CHAR_START_Y = stage.height-40,
heartCanvas.style.border = '5px solid #F77'; // adjust as needed

//---------------
//Preloading ...
//---------------
//Preload Art Assets
// - Sprite Sheet: Image API:
// http://www.html5canvastutorials.com/tutorials/html5-canvas-images/
var charImage = new Image();
charImage.ready = false;
charImage.onload = setAssetReady;
charImage.src = CHAR_SRC0;  // source image location set in constants.js

function setAssetReady()
{
	this.ready = true;
}

//Display Preloading
ctx.fillRect(0,0,stage.width,stage.height);
ctx.fillStyle = "#000";
ctx.fillText(TEXT_PRELOADING, TEXT_PRELOADING_X, TEXT_PRELOADING_Y);
var preloader = setInterval(preloading, TIME_PER_FRAME);
var currX, currY;

currX = IMAGE_START_X;
currY = IMAGE_START_Y;


function preloading()
{	
	if (charImage.ready)
	{
		clearInterval(preloader);		
		setInterval(update, TIME_PER_FRAME);	
	}
}


function update()
{	
	var speed = 10;	
	//Clear Canvas
	ctx.fillStyle = "lightgrey";
	ctx.fillRect(0, 0, stage.width, stage.height);	
	document.addEventListener("keydown", function(event){
		if(event.keyCode == '38' || event.keyCode == '39'){
			console.log("Speed up");
			console.log(speed);
			speed =speed + 1  ;
		}
		if(event.keyCode == '37' || event.keyCode == '40'){
			speed -= 5;
			console.log(speed);
			console.log("Slowing");
		}
	});


	// floor movement	
	if(CHAR_START_X < (STAGE_WIDTH-40)&&CHAR_START_Y==360){ 
		CHAR_START_X+=speed;
		charImage.src = CHAR_SRC0;
		ctx.drawImage(charImage,
			currX,currY,            		// sprite upper left positino	
			CHAR_WIDTH,CHAR_HEIGHT, 		// size of a sprite 72 x 96
			CHAR_START_X,CHAR_START_Y,  	// canvas position
			1*CHAR_WIDTH,1*CHAR_HEIGHT      // sprite size scale
		);
		currX += CHAR_WIDTH;
		if (currX >= SPRITE_WIDTH)
			currX = 0;
	} 	
	if(CHAR_START_X == 360 && CHAR_START_Y < 400 && CHAR_START_Y > 0){ 
		CHAR_START_Y-=speed;
		charImage.src = CHAR_SRC1;
		ctx.drawImage(charImage,
			currX,currY,            		// sprite upper left positino	
			CHAR_WIDTH,CHAR_HEIGHT, 		// size of a sprite 72 x 96
			CHAR_START_X,CHAR_START_Y,  	// canvas position
			1*CHAR_WIDTH,1*CHAR_HEIGHT      // sprite size scale
		);
		currX += CHAR_WIDTH;
		if (currX >= SPRITE_WIDTH)
			currX = 0;	
	} 
	if(CHAR_START_Y == 0 && CHAR_START_X < 400 && CHAR_START_X > 0){ 
		CHAR_START_X-=speed;
		charImage.src = CHAR_SRC2;
		ctx.drawImage(charImage,
			currX,currY,            		// sprite upper left positino	
			CHAR_WIDTH,CHAR_HEIGHT, 		// size of a sprite 72 x 96
			CHAR_START_X,CHAR_START_Y,  	// canvas position
			1*CHAR_WIDTH,1*CHAR_HEIGHT      // sprite size scale
		);
	currX += CHAR_WIDTH;
		if (currX >= SPRITE_WIDTH)
			currX = 0;
	} 
	if(CHAR_START_Y >= 0 && CHAR_START_Y <= 400 && CHAR_START_X == 0){ 
		CHAR_START_Y+=speed;
		charImage.src = CHAR_SRC3;
		ctx.drawImage(charImage,
			currX,currY,            		// sprite upper left positino	
			CHAR_WIDTH,CHAR_HEIGHT, 		// size of a sprite 72 x 96
			CHAR_START_X,CHAR_START_Y,  	// canvas position
			1*CHAR_WIDTH,1*CHAR_HEIGHT      // sprite size scale
		);
		currX += CHAR_WIDTH;
		if (currX >= SPRITE_WIDTH)
			currX = 0;
	} 
	
	//Draw Image
	// sprite sheet building site:
	// 	http://charas-project.net/charas2/index.php
	// ctx.drawImage(charImage,
	// 	currX,currY,            		// sprite upper left positino	
	// 	CHAR_WIDTH,CHAR_HEIGHT, 		// size of a sprite 72 x 96
	// 	CHAR_START_X,CHAR_START_Y,  	// canvas position
	// 	1*CHAR_WIDTH,1*CHAR_HEIGHT      // sprite size scale
	// );
	// currX += CHAR_WIDTH;
	// if (currX >= SPRITE_WIDTH)
	// 	currX = 0;
}





	
	