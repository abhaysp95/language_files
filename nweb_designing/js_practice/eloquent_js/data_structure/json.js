/* JSON -> JavaScript Object Notation */

/* JSON looks similar to javascript's way of writing arrays and objects with
 * few constraints, all property names have to be surrounded by double
 * quotes, and only simple data expressions are allowed - no function calls,
 * bindings, or anything that involves actual computation. Comments are not
 * allowed
 */

/* A journal entry might look like this in JSON */
/*{
	"squirrel": false,
	"events": ["work", "touced tree"]
}*/

// js have JSON.stringify and JSON.parse

let string = JSON.stringify({squirrel: false,
	events: ["weekend", "touching tree"]});
console.log(string);
console.log(JSON.parse(string).events);
