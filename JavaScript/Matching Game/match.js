var n = 3;
var numberOfFaces = n;
var Body = document.getElementsByTagName("body")[0];
var LeftSide = document.getElementById("leftSide");
var RightSide = document.getElementById("rightSide");
Body.onclick = GameOver;
function GenerateFaces(){

	for(var i = 0; i < numberOfFaces; i++){
		//create left smileys
		var smile = document.createElement("img");
		smile.src = "http://home.cse.ust.hk/~rossiter/mooc/matching_game/smile.png";
		smile.style.top = Math.floor(Math.random() * 400) + "px";
		smile.style.left = Math.floor(Math.random() * 400) + "px";
		LeftSide.appendChild(smile);
	}
	//copy left smileys to right side
	var rightImages = LeftSide.cloneNode(true);
	rightImages.removeChild(rightImages.lastChild);
	RightSide.appendChild(rightImages);
	LeftSide.lastChild.onclick = NextLevel;
}
function NextLevel(event){
	event.stopPropagation();
	numberOfFaces += n;
	//clear smileys
	var smiley = LeftSide.firstChild;
	while(smiley){
		var node = smiley.parentNode.firstChild;
		smiley = smiley.nextSibling;
		node.parentNode.removeChild(node);
	}
	smiley = RightSide.firstChild;
	while(smiley){
		var node = smiley.parentNode.firstChild;
		smiley = smiley.nextSibling;
		node.parentNode.removeChild(node);
	}
	GenerateFaces();
}
function GameOver(event){
	if(confirm("Game Over!\nYou clicked the wrong smiley!\n\n" + "Score : " + (numberOfFaces-n) + "\nClick OK to play again."))
		location.reload();
	else{
		Body.onclick = null;
		LeftSide.lastChild.onclick = null;
	}
}
