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
