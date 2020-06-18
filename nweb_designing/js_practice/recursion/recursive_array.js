function recursive_array(given_arr) {
	let result = []
	given_arr.forEach(function(element) {
		if (!Array.isArray(element)) {
			result.push(element)
		}
		else {
			result = result.concat(recursive_array(element))
		}
	})
	return result;
}
