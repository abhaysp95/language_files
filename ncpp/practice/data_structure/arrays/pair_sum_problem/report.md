# Report of Performance

To know whether _O(n.logn) + O(n)_ time-complexity is actually better than _O(n^2)_ in practice too.

**Scenerio**:

Upon visiting a problem of 'pair-sum-problem', where you have to find if the sum you entered can
be obtained by any pair(two numbers) present in the array(you entered)

I got 2 ways of solving this problem:

* _brute force way_
* _better way_

## brute force way

In this way, I'm having nested-loop(1 outer, 1 inner). And I'm comparing the user_sum with the sum of reference of the indexes pointed by these loop's indexes. Time complexity: _O(n^2)_

## better way

In this way, you have to have the array sorted. Then have to index pointers, head(pointing to 1st index of array) and tail(pointing last). Now adding reference of head and tail, compare it with user_sum and if user_sum is greater than increment head, if user_sum is less than decrement tail.
Time complexity of this algo is: _O(n)_

Now, the question here was to sort the array, for this I have to choose a sorting algorithm with minimum time-complexity. Got _quick-sort_ and _merge-sort_, both having time-complexity of _O(n.logn)_(with quick-sort having O(n^2) in worst case). I choose quick-sort(because of more overhead and space consuming of merge-sort).

Now, if for small number of array_size, overhead from quick-sort also seems big(overhead, recursive calls) when comparing it with other sorting algorithm of _O(n^2)_. So, for array size < 10, I chose to implement _selection-sort_.

## Reason for this test

Theoretically, with brute force(and neglecting the array taking input thing), this problem with brute-force should take _O(n^2)_ time, and with better way, it should take _O(n^2)_ + _O(n)_/_O(n.logn)_ + _O(n)_. And I wanted to compare if `brute-force(O(n^2))` is going to be that bad when compare with other two(two better ways) mentioned.

Now, the actual thing is to implement insertion sort only when array size is less than 10(kind of like what js sort() does), but I focused on providing array size to `100001` numbers.

Also, for better way, I checked this array size of 100001 with both _insertion sort_ and _quick sort_ just to compare the performane(time taken) with brute force way and between themselves.

## Test Runs

In the first 3 runs, inputs are taken from a file "input_data.txt"

### First run(Brute Force way)
```
sum entered: 2038402934
array size: 100001
result: sum not found
performance: 36.28s user 0.00s system 83% cpu 43.675 total
```

### Second run(Better way, insertion sort)
```
sum entered: 2038402934
array size: 100001
result: sum not found
./pair_sum_problem  1.76s user 0.03s system 48% cpu 3.699 total
```

### Third run(Better way, quick sort)
```
sum entered: 2038402934
array size: 100001
result: sum not found
./pair_sum_problem  0.10s user 0.01s system 1% cpu 7.421 total
```


Below 3 runs are based on random int inputs to array

### Forth run(brute force way)
```
sum entered: 2038402934
array size: 100001
result: sum not found
./pair_sum_problem  36.23s user 0.03s system 85% cpu 42.588 total
```

### Fifth run(better way, insertion sort)
```
sum entered: 2038402934
array size: 100001
result: sum not found
./pair_sum_problem  33.55s user 0.01s system 51% cpu 1:05.06 total
-- extra runs
./pair_sum_problem  32.48s user 0.01s system 77% cpu 41.838 total
./pair_sum_problem  32.50s user 0.00s system 81% cpu 39.948 total
```

### Sixth run(better way, quick sort)
```
sum entered: 2038402934
array size: 100001
result: sum not found
./pair_sum_problem  0.05s user 0.01s system 0% cpu 7.344 total
-- extra runs
./pair_sum_problem  0.06s user 0.00s system 1% cpu 2.966 total
./pair_sum_problem  0.05s user 0.00s system 1% cpu 2.923 total
```

I have also included the screenshots of the result(which contain more time-consuming details) in `sshots` folder

## Things I noticed

I had cleared cache everytime before running the test
```sh
$ sync; echo 1 > /proc/sys/vm/drop_caches  # requires root privilege
```

Brute Force performed bad in both the type of input for array elements. It performed bad even when comparing to `insertion sort + better way`. `Better way + quick sort` was the fastest way to do the thing.

When inserting random elements to array, I also got `segmentation fault` with quicksort. Maximum random element which could be entered is `1000000000`. So, when I was in `sixth run`, I got those seg-faults and I had to run the program again and again to get output. This kinda defeated the purpose of clearing cache. So, I included 3 runs from `quicksort` way. And due to this reason, I also added more runs(without clearing cache) again for `insertion-sort` way in _fifth run_.

For quicksort, I decided to take pivot element by taking `median` of the _first, mid & last_ element of array(sub-array). So, that the possibility of going to worst case of quick-sort gets very minimal.

## Result

`Better way` is really a better way. Quick Sort is definitely fastest way to sort, though it's _unstable_ which I noticed as stated by many.

## Question:

So, can I say that _O(n^2)_(brute-force way) time-complexity is bad, when compared with _O(n.logn)/O(n^2)_(sorting) + _O(n)_(better way)?

Or in general way, `O(n.logn) + O(n)` is better than `O(n^2)` in practice too ?


```
This report may have overlooked some other things. If there's anything significant which I've missed, please tell
```
