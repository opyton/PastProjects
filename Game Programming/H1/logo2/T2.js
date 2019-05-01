var canvas = document.querySelector("canvas");
canvas.width = 225;
canvas.height = 225;

var c = canvas.getContext('2d');//context

//big circle
c.beginPath();
c.arc(112.5, 112.5, 93.5, 0, 2*Math.PI);
c.closePath();
c.strokeStyle = "rgb(254,198,0)";
c.stroke();
c.fillStyle = "rgb(254,198,0)";
c.fill();

//upperRed Triangle
c.beginPath();
c.moveTo(93, 40);
c.lineTo(138, 55);
c.lineTo(101, 55);
c.closePath();
c.strokeStyle = "rgb(255,0,73)";
c.stroke();
c.fillStyle = "rgb(255,0,73)";
c.fill();

//arc
c.beginPath();
c.arc(120, 110, 81, (4*Math.PI/3), (1*Math.PI/3), true);
c.closePath();
c.strokeStyle = "rgb(254,198,0)";
c.stroke();
c.fillStyle = "white";
c.fill();

//large triangle
c.beginPath();
c.moveTo(104, 64);
c.lineTo(195, 155);
c.lineTo(170, 179);
c.closePath();
c.stroke();
c.fillStyle = "white";
c.fill();

//thick line in between
c.beginPath();
c.moveTo(33, 163);
c.bezierCurveTo(100, 108, 140, 200, 200, 155);
c.arc(112.5, 112.5, 93.5, .8, 2.21);
c.closePath();
c.strokeStyle = "rgb(51,126,193)";
c.stroke();
c.fillStyle = "rgb(51,126,193)";
c.fill();

//thick line in between
c.beginPath();
c.moveTo(33, 163);
c.bezierCurveTo(100, 108, 140, 200, 200, 155);
c.lineWidth = 10;
c.strokeStyle = "white";
c.stroke();

