// IIFE => Immediately Invoked Function Expression

function game() {
	var score = Math.random() * 10;
	//console.log((Math.random() * 10) > 5);
	console.log(score > 5);
}
game();

// but if the only purpose of this program is to hide score and provide abstraction for only showing true and false, we can use IIFE syntax

// let's see
/*function () {

}*/

// Now js, will know this is function declaration but since there isn't name, it'll throw error, solution is to wrap around (), so that it would become an expression, like this
/*(function() {

})*/

/* and to invoke the function we have to use another (), so that function can be called, pay attention */
/*(function() {

})();*/
// Now, above is general IIFE syntax, and so now benefit is using this one can no longer access score variable

(function() {
	var score = Math.random() * 10;
	console.log(score > 5);
})();

// We can also pass arguments and use parameters in IIFE, watch this
(function(goodLuck) {
	console.log((Math.random * 10 - goodLuck) > (5 - goodLuck));
})(3);
// Here, goodLuck is parameter and 3 is passed as it's argument

// Goal of IIFE is to not make a reusable peace of code but to make a block(scope) which is hidden from outside scope
// So, helps in data privacy
