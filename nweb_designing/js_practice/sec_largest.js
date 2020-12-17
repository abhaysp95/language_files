function getSecondLargest(nums) {
	let largestNum = nums[0];
	let secLargestNum = largestNum;

	nums.forEach((num) => {
		console.log("current num: " + num);
		if (num > largestNum) {
			secLargestNum = largestNum;
			largestNum = num;
		}
		else if (num < largestNum) {
			if (num > secLargestNum) {
				secLargestNum = num;
			}
		}
	})
	return secLargestNum;
}

let gotSecLargestNum = getSecondLargest([2, 3, 6, 6, 5]);
console.log(gotSecLargestNum);
