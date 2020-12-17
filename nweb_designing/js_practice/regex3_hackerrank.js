function main() {
	let arr = [102, 194923423, 1.3, 2.5];
	regexVar(arr);
}

function regexVar(arr) {
	let re = new RegExp(/^(\d+)\.?(\d)*/, "gm");
	for (const num of arr) {
		const r = num.match(re)
		console.log(r);
	}
}

main()
