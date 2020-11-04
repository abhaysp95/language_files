// arrow funciton expression

const calcAge3 = birthYear => 2039 - birthYear;
const age3 = calcAge3(1991);

const yearsUnitRetirement = (birthYear, firstname) => {
	const age = 2037 - birthYear;
	const retirement = 65 - age;
	return `${firstname} retires in ${age}`;
}

console.log(yearsUnitRetirement(1991, 'Jonas'));

// arrow function don't get this keyword
