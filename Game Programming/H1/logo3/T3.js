var canvas = document.querySelector("canvas");
canvas.width = 250;
canvas.height = 250;

var c = canvas.getContext('2d');//context
var grd = c.createLinearGradient(0, 0, 0, 300);
grd.addColorStop(0, "rgb(11,25,52)");
grd.addColorStop(1, "rgb(20,130,179)");

//big circle
c.beginPath();
c.arc(125, 125, 125, 0, 2*Math.PI);
c.closePath();
c.strokeStyle = "rgb(22,130,179)";
c.stroke();
c.fillStyle = grd;
c.fill();

//upper right ring 
c.beginPath();
c.arc(167, 91, 50, 0, 2*Math.PI);
c.closePath();
c.strokeStyle = "white";
c.stroke();
c.fillStyle = "white";
c.fill();

//upper inner ring
c.beginPath();
c.arc(167, 91, 28, 0, 2*Math.PI);
c.closePath();
c.strokeStyle = "rgb(9,28,71)";
c.lineWidth = 7;
c.stroke();

//connector
c.beginPath();
c.moveTo(119, 94);
c.lineTo(164, 141);
c.lineTo(122, 172);
c.lineTo(90, 140);
c.closePath();
c.lineWidth = 1;
c.strokeStyle = "white";
c.stroke();
c.fillStyle = "white";
c.fill();

//lower left ring 
c.beginPath();
c.arc(90, 170, 32, 0, 2*Math.PI);
c.closePath();
c.strokeStyle = "white";
c.stroke();
c.fillStyle = "white";
c.fill();

//lower inner ring
c.beginPath();
c.arc(90, 170, 20, 0, 2*Math.PI);
c.closePath();
c.strokeStyle = "rgb(9,28,71)";
c.lineWidth = 7;
c.stroke();

//outpiece
c.beginPath();
c.moveTo(0, 114);
c.lineTo(0, 150);
c.lineTo(82, 184);
c.lineTo(95, 155);
c.closePath();
c.lineWidth = 1;
c.strokeStyle = "white";
c.stroke();
c.fillStyle = "white";
c.fill();