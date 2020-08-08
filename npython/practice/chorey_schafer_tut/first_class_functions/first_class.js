function html_tag(tag) {
	function wrap_text(msg) {
		return '<' + tag + '>' + msg + '</' + tag + '>';
	}
	return wrap_text;
}

print_h1 = html_tag('h1');  // wrap_text isn't executed yet;
console.log(print_h1('Test Headline!'));
console.log(print_h1('Test Another Headline!'));

print_p1 = html_tag('p1');
console.log(print_p1('This is a paragraph.'))















//function logger(msg) {
	//function log_msg() {
		//console.log('Log: ', msg);
	//}
	//return log_msg;
//}

//log_hi = logger("Hello, this the logger function");
//log_hi();















//function square(x) {
	//return x * x;
//}

//function cube(x) {
	//return x * x * x;
//}

//function my_map(func, arg_list) {
	//result = [];
	//for (var i = 0; i < arg_list.length; i++) {
		//result.push(func(arg_list[i]));
	//}
	//return result;
//}

//var cubes = my_map(cube, [1, 2, 3, 4, 5])

//console.log(cubes)





















//function square(x) {
	//return x * x;
//}

// var f = square(5)  // not execute, just set the variable to the function
//var f = square

//console.log(square)
//console.log(f)
//console.log(f(5))

// if function takes another function as argument or returns another function, that's when it's called higher order function
