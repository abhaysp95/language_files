# SubArray

It is the continuous part of the Array. Like, arr = {1, 2, 0, 7, 0, 2}

A subarray will be: {2, 0, 7, 0}

Number of subarrays of an array with n elements = `nC2 + n = n*(n + 1)/2`

# SubSequence

A subsequence is a sequence that can be derived from an array, by selecting zero
or more elements without changing order of the remaining elements too.

Like, arr = {1, 2, 0, 7, 0, 2}

subsequence = {2, 7, 2} and the remaining is {1, 0, 7, 0}

it's not continuous and order is not changed too

Number of subsequence of an array with n elements = `2 ^ n`


**Note:**

`Every subarray is a subsequence but every subsequence is not a subarray.`
