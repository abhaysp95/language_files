let journal = []

function addEntry(events, squirrel) {
	journal.push({events, squirrel});
}

addEntry(["work", "touched tree", "pizza", "running", "television"], false);
addEntry(["work", "ice cream", "cauliflower", "lasagna", "touched tree", "brushed teeth"], false);
addEntry(["weekend", "cycling", "break", "peanuts", "beer"], true);

console.log(journal[2]);


/* Correlation
0 -> variables not related
1 -> two variables are perfectly related
-1 -> also perfectly related but opposite

To measure, co-relation we use 'phi coefficient'

formula: phi = (n11xn00 - n01xn10)/sqrt(n1(dot)xn0(dot)xn(dot)1xn(dot)0)

n11 = both are true
n00 = nothing is true
n01 = first is false, and second is true
n10 = opp. of above

n1(dot) = sum of all measurements where first variable is true
n0(dot) = same as n1(dot) but for second variable
n(dot)1 = sum of all measurements where first variable is false
n(dot)0 = same as n1(dot) but for second variable
*/

function phi(table) {
	return (table[3] * table[0] - table[1] * table[2]) /
		Math.sqrt((table[2] + table[3]) *
		(table[0] + table[1]) *
		(table[1] + table[3]) *
		(table[0] + table[2]));
}

console.log(Math.round(phi([76, 9, 4, 1]) * 10000) / 10000);
