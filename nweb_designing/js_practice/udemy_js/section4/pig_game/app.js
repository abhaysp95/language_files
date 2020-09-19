// Rule:
/* Each player gets to roll the dice as many time as he wants, each result is
 * added to ROUND score. But if player gets 1 all his score goes back to 0 and
 * it's now chance of second player. Player can also hold their chance which
 * means that their score gets added to global score. First player to reach 100
 * global points win
There are three rules above*/

// Additonal Rules:
/*
4. A player looses his ENTIRE score when he rolls two 6 in a row. After that, it's the next player's turn  [ done ]
5. Add an input field to the innerHTML where players can set winning score, so that they can change the predefined score of 100.  [ done ]
6. Add another dice to the game, so that there are two dices now. The player looses his current score when one of them is a 1.
Update: rule 6: if there's 2 dice, then the also if both the dices got 6 then player will lose his entire score and it will be next player turn. So, kinda functionality for rule 4 will be broken, so no backtracking for previous score */


/* There's also the idea of to let player choose whether they want to play with one dice or two but currently I'm sticking with 2 dice */

var max, min, scores, roundScore, activePlayer, isGameActive, topScore, started;
// previousRoundScore

// dice
max = 6;
min = 1;

// let's change query of css element
var dice1DOM = document.querySelector(".dice1");
var dice2DOM = document.querySelector(".dice2");

// for help modal
const openModalButton = document.querySelector("[data-modal-target]");
const closeModalButton = document.querySelector("[data-close-button]");
const overlay = document.getElementById("overlay");

openModalButton.addEventListener("click", function() {
	const modal = document.querySelector(openModalButton.dataset.modalTarget);
	openModal(modal);
})

closeModalButton.addEventListener("click", function() {
	const modal = closeModalButton.closest('.modal');  // closest parent modal class
	closeModal(modal);
})

function openModal(modal) {
	if (modal == null) {
		return;
	}
	modal.classList.add('active');
	overlay.classList.add('active');
}

function closeModal(modal) {
	if (modal == null) {
		return;
	}
	modal.classList.remove('active');
	overlay.classList.remove('active');
}

overlay.addEventListener("click", function() {
	const modals = document.querySelectorAll(".modal.active");
	modals.forEach(function(modal) {
		closeModal(modal);
	})
})

init();

// a barebone trial
//chance = 0
//function throwDice() {
	//let currentScore = 0;
	//while (chance < 30) {
		//currentScore = Math.floor((Math.random() * max) + min);
		//console.log(currentScore);
		//if (currentScore == 1) {
			//if (activePlayer == 0) {
				//console.log("now score of first player: " + scores[0]);
				//activePlayer = 1;
			//}
			//else {
				//console.log("now score of second player: " + scores[1]);
				//activePlayer = 0;
			//}
			//scores[activePlayer] = 0;
		//}
		//else {
			//scores[activePlayer] += currentScore;
		//}
		//++chance;
	//}
//}

//throwDice();
//console.log("Score of first player: " + scores[0]);
//console.log("Score of second player: " + scores[1]);


// DOM manipulation
//var value = document.querySelector("#score-0").textContent;
//console.log(value);
//document.querySelector("#score-0").textContent = dice;

// document.querySelector("#current-" + activePlayer).textContent = dice;
/* there's another method if we want to put html element(then don't use textContent, it'll put literal text) */
//document.querySelector('#current-' + activePlayer).innerHTML = "<em>" + dice + "</em>";


/* All the events of browsers are put in 'Message-queue', this will work only when execution stack is empty */

//function btn() {
	// do something here
//}

// btn function below is callback function(function which is passed as argument to another function)
// another thing is we can write anonymous function
document.querySelector(".btn-roll").addEventListener('click', function() {
	// if game is going on
	if (isGameActive) {
		started = true;
		// 1. need random number
		dice1 = Math.floor(Math.random() * max) + min;
		dice2 = Math.floor(Math.random() * max) + min;
		//dice = Math.round(Math.random() * (max - min) + min);
		console.log("dice1: " + dice1);
		console.log("dice2: " + dice2);
		//console.log("previousRoundScore: " + previousRoundScore + "\t roundScore: " + roundScore);
		console.log("roundScore: " + roundScore);

		// 2. display result
		dice1DOM.style.display = "block";
		dice1DOM.src = "img/dice-" + dice1 + ".png";

		dice2DOM.style.display = "block";
		dice2DOM.src = "img/dice-" + dice2 + ".png";

		// 3. update round score if current is not 1
		if ((dice1 !== 1 || dice2 !== 1) && dice1 + dice2 != 12) {
			//previousRoundScore = dice;
			roundScore += (dice1 + dice2);
			document.getElementById('current-' + activePlayer).textContent = roundScore;
		}
		//else if (previousRoundScore + dice == 12) {
		else if (dice1 + dice2 == 12) {
			console.log("in elif");
			document.getElementById('score-' + activePlayer).textContent = 0;
			dice1DOM.style.display = "none";
			dice2DOM.style.display = "none";
			scores[activePlayer] = 0;
			nextPlayer();
		}
		else {
			// change to next player and settings to that stuff
			nextPlayer();
			dice1DOM.style.display = "none";
			dice2DOM.style.display = "none";
		}
	}
});


// eventlistener for hold button
document.querySelector(".btn-hold").addEventListener('click', function() {
	if (isGameActive) {
		// add current score of activePlayer to global score
		scores[activePlayer] += roundScore;
		// update text
		// now below are some code which are repeated(against DRY(don't repeat yourself principle))
		document.querySelector("#score-" + activePlayer).textContent = scores[activePlayer];
		// if any player won
		if (scores[activePlayer] >= topScore) {
			document.querySelector("#name-" + activePlayer).textContent = "Winner";
			document.querySelector(".player-" + activePlayer + "-panel").classList.remove('active');
			document.querySelector(".player-" + activePlayer + "-panel").classList.add('winner');
			document.querySelector("#current-" + activePlayer).textContent = 0;
			dice1DOM.style.display = "none";
			dice2DOM.style.display = "none";
			scores[0] = 0;
			scores[1] = 0;
			roundScore = 0;
			isGameActive = false;
		}
		else {
			nextPlayer();
		}
	}
});

/* Using prompt doesn't matches the theme(style) of game, will change this in future
For now, bear with it */
document.querySelector(".top-score").addEventListener("click", function() {
	if (isGameActive) {
		topScoreElement = document.querySelector(".top-score");
		var enteredScore = prompt("Enter the top score to play for: ");
		if (enteredScore !== null) {
			// only if the game is truly started(anyone of the player have pressed roll dice)
			if (started) {
				// reset the game with the top score
				console.log("activePlayer from enteredScore: " + activePlayer);
				var ifReset = prompt("Reset or Continue?(yes/no)");
				if (ifReset == "yes") {
					init(); // should I reset the game
				}
				else if (ifReset == "no"){
					if (enteredScore <= scores[activePlayer]) {
						console.log("I'm here");
						document.querySelector("#name-" + activePlayer).textContent = "Winner";
						document.querySelector(".player-" + activePlayer + "-panel").classList.remove('active');
						document.querySelector(".player-" + activePlayer + "-panel").classList.add('winner');
						document.querySelector("#current-" + activePlayer).textContent = 0;
						dice1DOM.style.display = "none";
						dice2DOM.style.display = "none";
						scores[0] = 0;
						scores[1] = 0;
						roundScore = 0;
						isGameActive = false;
					}
				}
			}
		topScoreElement = document.querySelector(".top-score");
			topScoreElement.innerHTML = "<i class=\"ion-ios-checkmark-outline\"></i>Top Score: " + enteredScore;
	//<i class="ion-ios-checkmark-outline"></i>T
			topScore = enteredScore;
		}
		//console.log(topScore.textContent);
		//topScore.textContent = "Top Score: 150";
	}
})

function nextPlayer() {
	// set zero the current score for the activePlayer(one which got 1 in dice in last chance)
	document.getElementById('current-' + activePlayer).textContent = 0;
	document.querySelector(".player-" + activePlayer + "-panel").classList.remove("active");
	roundScore = 0;
	//previousRoundScore = roundScore;
	activePlayer = (activePlayer === 0) ? 1 : 0;
	// or you can write above ternary operation like this
	// activePlayer === 0 ? activePlayer = 1 : activePlayer = 0;
	// change the active player
	document.querySelector(".player-" + activePlayer + "-panel").classList.add("active");
	dice1DOM.style.display = "none";
	dice2DOM.style.display = "none";
	console.log("activePlayer: " + activePlayer);
	// there's also toggle() function to toggle class, example
	//document.querySelector(".player-0-panel").classList.toggle("active");
	//document.querySelector(".player-1-panel").classList.toggle("active");
}

document.querySelector(".btn-new").addEventListener("click", init);


function init() {
	scores = [0, 0];
	roundScore = 0;
	previousRoundScore = 0;
	topScore = 200;
	isGameActive = true;

	dice1DOM.style.display = 'none';
	dice2DOM.style.display = 'none';

	// bit faster than using querySelector
	document.getElementById("score-0").textContent = 0;
	document.getElementById("score-1").textContent = 0;

	document.getElementById("current-0").textContent = 0;
	document.getElementById("current-1").textContent = 0;
	document.getElementById("name-0").textContent = "Player 1";
	document.getElementById("name-1").textContent = "Player 2";
	// doesn't matter if .winner is in classList or not, it'll not give error
	document.querySelector(".player-0-panel").classList.remove('winner');
	document.querySelector(".player-1-panel").classList.remove('winner');
	document.querySelector(".player-0-panel").classList.remove('active');
	document.querySelector(".player-1-panel").classList.remove('active');

	topScoreElement = document.querySelector(".top-score");
	topScoreElement.innerHTML = "<i class=\"ion-ios-checkmark-outline\"></i>Top Score: " + topScore;

	// randomly select active player(try this)
	activePlayer = 0;  // 0 is first player and 1 is second player
	// make player 1 active
	document.querySelector(".player-0-panel").classList.add('active');
}
/* if we have bunch of css style manipulation, it's better to create extra class and toggle, add/remove them */
