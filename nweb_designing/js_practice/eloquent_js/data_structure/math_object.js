/* Math object is used as a container to group bunch of related functionality.
 * There is only one Math object, and it is almost never useful as a value.
 * Rather, it provides a namespace so that all these functions and values do
 * not have to be global bindings

 * Basically it means that, unlike some other language, even though Math object
 * has "max" function, js will not prevent you to have another "max"(unless it's
 * let or const)
 */

function randomPointOnCircle(radius) {
	let angle = Math.random() * 2 * Math.PI;
	return {x: radius * Math.cos(angle),
			y: radius * Math.sin(angle)};
}

console.log(randomPointOnCircle(2));
