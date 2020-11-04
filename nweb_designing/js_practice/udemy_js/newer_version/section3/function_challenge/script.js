

const avg = (num1, num2, num3) => (num1 + num2 + num3) / 3;

const checkWinner = function(avgDolphins, avgKoala) {
	if (avgDolphins >= 2 * avgKoala) {
		console.log("avgDolphins wins");
	}
	else if (avgKoala >= 2 * avgDolphins) {
		console.log("avgKoala wins");
	}
	else {
		console.log("Nobody won");
	}
}

checkWinner(avg(44, 23, 71), avg(65,54, 49))
checkWinner(avg(85, 54, 41), avg(23, 34, 27))
