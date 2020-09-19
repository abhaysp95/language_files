// Creating Question constructor

// let's put it in IIFE so it doesn't interfere with another persons code

(function() {
	var Question = function(ques, answers, correctAnswer) {
		this.ques = ques;
		this.answers = answers;
		this.correctAnswer = correctAnswer;
	}

	Question.prototype.displayQuestion = function() {
		console.log(this.ques);
		let i = 0;
		for (let option of this.answers) {
			console.log(`${++i}: ${option}`);
		}
	};

	Question.prototype.isAnswerCorrect = function(ans, updateScore) {
		//if (allQuestions[selectedQuestion].answers[ans - 1] === allQuestions[selectedQuestion].correctAnswer) {
		let sc = 0;
		console.log(`Enter option: ${ans}`);
		if (this.answers[ans - 1] === this.correctAnswer) {
			console.log("Correct Answer");
			sc = updateScore(true);
		}
		else {
			console.log("Not Correct Answer");
			sc = updateScore(false);
		}
		this.displayScore(sc);  // this is calling the displayScore method from it's own function constructor where "this" is an object of Question on which this message here was called
		// so you're thinking right that, "this.displayScore(sc)" is different object everytime but score will increase(not increase if ans. wrong) because every instance of Question object is having same keepScore as parameter
	}

	Question.prototype.displayScore = function(sc) {
		console.log(`Your current score is ${sc}`);
		console.log("---------------------------");
	}

	var question1 = new Question(
		"Is JavaScript good?",
		["yes", "no"],
		"yes"
	);

	var question2 = new Question(
		"Who is The Punisher?",
		["Matt Murdock", "Frank Castle", "Clark Kent"],
		"Frank Castle"
	);

	var question3 = new Question(
		"What is the logo for The Punisher?",
		["Red Skull", "Gun", "White Skull"],
		"White Skull"
	);

	var allQuestions = [question1, question2, question3];

	/*function logQuestion(selectedQuestion, allQuestions) {
		console.log(allQuestions[selectedQuestion].ques);
		for (let option of allQuestions[selectedQuestion].answers) {
			console.log(option);
		}
	}
	logQuestion(selectedQuestion, allQuestions);*/


	// passing score to the isAnswerCorrect, is not good way to keep track of player's score, as it's not dependent upon player but upon questions

	// let's solve the score keeping problem with closure
	function score() {
		let sc = 0;
		return function(isCorrect) {
			if (isCorrect) {
				sc++;
			}
			return sc;
		}
	}

	let keepScore = score();
	// now, "sc" is always attached with score() variable

	let quit = false;
	do {
		var selectedQuestion = Math.floor(Math.random() * allQuestions.length);
		allQuestions[selectedQuestion].displayQuestion();

		let ans = prompt("Enter the correct option number(type \"exit\" to exit): ");
		if (ans === "exit") {
			quit = true;
			console.log("Exiting!");
		}
		else {
			allQuestions[selectedQuestion].isAnswerCorrect(parseInt(ans), keepScore);
		}
	} while(!quit);
	// or use recursion


	// give input for answer
	/*function getAnswer() {
		let ans = prompt("Enter the correct option number: ");
		console.log("Entered answer: " + ans);
		if (allQuestions[selectedQuestion].answers[ans - 1] === allQuestions[selectedQuestion].correctAnswer) {
			console.log("Correct Answer");
		}
		else {
			console.log("Not Correct Answer");
		}
	}*/
	//getAnswer();
})();
