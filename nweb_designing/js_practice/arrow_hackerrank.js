function main() {
	let arr = [1, 2, 3, 4, 5];
	//modifyArray(arr);
	console.log(modifyArray(arr).toString().split(',').join(' '));
}

const modifyArray = nums => {
	console.log(nums);
	nums.forEach((part, index, array) => {
		array[index] = part % 2 ? part * 3 : part * 2; // cause 0 is false
	});
	console.log(nums);
	return nums;
};

main()



const getMaxLessThanK = (n, k) => {
	let res = 0;
	let temp = 0;
	for (let i = 1; i <= n; ++i) {
		for (let j = i + 1; j <= n; ++j) {
			temp = i & j;
			if (temp < k) {
				if (temp > res) {
					res = temp;
				}
			}
		}
	}
	return res;
}
