let numbers = [1, 2, 3, 4, 5];
let doubled = numbers.map(x => x * x);
console.log(doubled);

let cubic = num_arr => num_arr.map(x => Math.pow(x, 3));
console.log(cubic(numbers))


// square of only even numbers
let newSquare = numbers.filter(num => num % 2 == 0).map(x => x * x);
console.log(newSquare);


// cube of only odd numbers
let newCubic = num_arr => {
	return num_arr.filter(num => num % 2 == 1).map(num => Math.pow(num, 3));
}
console.log(newCubic(numbers));


// get id
let officers = [
  { id: 20, name: 'Captain Piett' },
  { id: 24, name: 'General Veers' },
  { id: 56, name: 'Admiral Ozzel' },
  { id: 88, name: 'Commander Jerjerrod' }
];
console.log(officers[1].id)
let onlyID = officers.map(get_id => get_id.id)
console.log(onlyID);


// total years of experience
var pilots = [
	{
		id: 10,
		name: "Poe Dameron",
		years: 14,
	},
	{
		id: 2,
		name: "Temmin 'Snap' Wexley",
		years: 30,
	},
	{
		id: 41,
		name: "Tallissan Lintra",
		years: 16,
	},
	{
		id: 99,
		name: "Ello Asty",
		years: 22,
	}
];
let totalExprerience = pilots.reduce((acc, pilots) => acc + pilots.years, 0);
console.log(totalExprerience);

let totExp = all_pilots => {
	return all_pilots.reduce((acc, all_pilots) => acc + all_pilots.years, 0);
}
console.log(totExp(pilots));

// most experienced pilot
let mostExperienced = pilots.reduce(
	(oldest, pilot) => (oldest.years || 0) > oldest.years ? oldest : pilot, {}
)
console.log(mostExperienced);

const COMPANIES = [
	{name: "Company One", category: "Finance", start: 1981, end: 2003},
	{name: "Company Two", category: "Retail", start: 1992, end: 2008},
	{name: "Company Three", category: "Auto", start: 1999, end: 2007},
	{name: "Company Four", category: "Retail", start: 1989, end: 2010},
	{name: "Company Five", category: "Technology", start: 2009, end: 2014},
	{name: "Company Six", category: "Finance", start: 1987, end: 2010},
	{name: "Company Seven", category: "Auto", start: 1986, end: 1996},
	{name: "Company Eight", category: "Technology", start: 2011, end: 2016},
	{name: "Company Nine", category: "Retail", start: 1981, end: 1989}
];
const AGES = [33, 12, 20, 16, 5, 54, 21, 44, 61, 13, 15, 45, 25, 64, 32];
const AGES2 = [33, 12, 20, 16, 5, 54, 21, 44, 61, 13, 15, 45, 25, 64, 32];

const FRUITS = ['Banana', 'Orange', 'Apple', 'Mango', 'Pear']
const fruits = ['banana', 'orange', 'apple', 'mango', 'guava']

// forEach
/*COMPANIES.forEach(function(company) {
	console.log(company);
});*/
COMPANIES.forEach(company => { console.log(company.name) });

// filter ages 21 and over
// filter will only return those value which will return true to condition
console.log(AGES.filter(age => age >= 21));

// get only retail company
/*const retailCompanies = COMPANIES.filter(company => {
	if (company.category === "Retail") {
		return true;
	}
});*/
const retailCompanies = COMPANIES.filter(
	company => company.category === "Retail");
console.log(retailCompanies);

// this method is handy if you want to pass more than one argument
const retailCompanies2 = companies => {
	return companies.filter(
	company => company.category === "Auto");
}
console.log(retailCompanies2(COMPANIES));


// get 80s companies
const eightiesCompanies = COMPANIES.filter(
	company => company.start >= 1980 && company.start <= 1989);
console.log(eightiesCompanies);

// companies lasted atleast 10 years
const last10Years = COMPANIES.filter(
	company => company.end - company.start >= 10);
console.log(last10Years);


// map function
// array of company names
const companyNames = COMPANIES.map(
	company => company.name);
console.log(companyNames);

// get name, start and end date
const companyData = COMPANIES.map(
	// es6 template string, syntax for variable
	company => `${company.name} [${company.start} - ${company.end}]`
);
console.log(companyData);

// get square of ages
const agesSquare = AGES.map(
	ages => Math.pow(ages, 2)
);
console.log(agesSquare);

// get squareroot of ages
const agesSquareRoot = AGES.map(
	ages => Math.sqrt(ages)
);
console.log(agesSquareRoot);

// squareroot and the twice
const ageMap = AGES.map(ages => Math.sqrt(ages)).map(ages => ages * 2);
console.log(ageMap);


// sort
const sortedComapnies = COMPANIES.sort(function(c1, c2) {
	if(c1.start > c2.start) {
		return 1;
	}
	else {
		return -1;
	}
});
console.log(sortedComapnies);

// short form
//const sortedComapnies2 = COMPANIES.sort(
	//(comp1, comp2) => (comp1.start > comp2.start ? 1 : -1))
const sortedComapnies2 = COMPANIES.sort(
	(comp1, comp2) => (comp1 - comp2)
)
console.log(sortedComapnies2);

// sort ages

// if sort passed without any argument it'll only compare first number
const sortAges = AGES.sort((a1, b1) => (a1 > b1 ? 1 : -1))
console.log(sortAges);
const sortAges2 = AGES.sort((a, b) => a - b)
console.log(sortAges2);

// sort fruits
const sortFruits = FRUITS.sort();
console.log(sortFruits);

const sortFruits2 = (cap, small) => {
	return small.concat(cap).sort();
}
const sortFruits3 = (cap, small) => small.concat(cap).sort().reverse();
console.log(sortFruits2(FRUITS, fruits));
console.log(sortFruits3(FRUITS, fruits));


// sum of ages
//let ageSum = 0;
//for (let i = 0; i < AGES.length; i++) {
	//ageSum += AGES[i];
//}

//const ageSum = AGES.reduce(function(total, age) {
	//return total + age;
//}, 0);

const ageSum = AGES.reduce((total, age) => total + age, 0);
console.log(ageSum);

// get total years for companies
const totalYears = COMPANIES.reduce(
	(total, duration) => total + (duration.end - duration.start), 0);
console.log(totalYears);


// combine methods
const combine = AGES2
	.map(age => age * 2)
	.filter(age => age >= 40)
	.sort((age1, age2) => age2 - age1)  // descending order
	.reduce((total, age) => total + age, 0);
console.log(combine);


// working of sort
let rivers = ['Nile', 'Amazon', 'Congo', 'Mississippi', 'Rio-Grande'];
//sortedRivers = rivers.sort();
//let sortedRivers = rivers.sort((a, b) => {
	//console.log(a, b);
	//return a.length - b.length;
//})
//console.log(sortedRivers);

// optization, Schwartzian transform
// temporary array
let lengths = rivers.map((a, b) => ({index: b, value: a.length}))
// sorting the length array containing lengths
//lengths.sort((a, b) => a.value - b.value)
// is same as
lengths.sort((a, b) => +(a.value > b.value) || +(a.value === b.value) - 1);
let sortedRivers = lengths.map((a) => rivers[a.index]);
console.log(lengths);
console.log(sortedRivers);


// numbers
let numbers2 = ["10", "10", "10"]
numbers2 = numbers2.map(parseInt);
console.log(numbers2);


var pilots = [
	{
		id: 2,
		name: "Wedge Antilles",
		faction: "Rebels",
	},
	{
		id: 8,
		name: "Ciena Ree",
		faction: "Empire",
	},
	{
		id: 40,
		name: "Iden Versio",
		faction: "Empire",
	},
	{
		id: 66,
		name: "Thane Kyrell",
		faction: "Rebels",
	}
];
let rebelPilot = pilots.filter(pilot => pilot.faction === 'Rebels')
let empirePilot = pilots.filter(pilot => pilot.faction === 'Empire')
console.log(rebelPilot);
console.log(empirePilot);

var personnel = [
	{
		id: 5,
		name: "Luke Skywalker",
		pilotingScore: 98,
		shootingScore: 56,
		isForceUser: true,
	},
	{
		id: 82,
		name: "Sabine Wren",
		pilotingScore: 73,
		shootingScore: 99,
		isForceUser: false,
	},
	{
		id: 22,
		name: "Zeb Orellios",
		pilotingScore: 20,
		shootingScore: 59,
		isForceUser: false,
	},
	{
		id: 15,
		name: "Ezra Bridger",
		pilotingScore: 43,
		shootingScore: 67,
		isForceUser: true,
	},
	{
		id: 11,
		name: "Caleb Dume",
		pilotingScore: 71,
		shootingScore: 85,
		isForceUser: true,
	},
];
// total score of force user only
//let totalScore = personnel
	//.filter(person => person.isForceUser === true)
	//.reduce((total, person) => total + person.shootingScore + person.pilotingScore, 0);
//console.log(totalScore);

// another way is
let totalJediScore = personnel
	.filter(person => person.isForceUser === true)
	.map(jedi => jedi.pilotingScore + jedi.shootingScore)
	.reduce((total, score) => total + score, 0);
console.log(totalJediScore);
