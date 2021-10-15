# Terminology

Amdahl's law provides a mathematical formula that calculates the potential improvement in speed of a concurrent program by increasing its resources(specifically, the number of available processors). Before we can get into the theory behind the Amdahl's law, first we must clarify some terminology, as follows:

* Amdahl's law solely discusses the potential speedup in latency resulting from executing a task in **parallel**. While concurrency is not directly discussed here, the results from Amdahl's law concerning parallelism will nonetheless give us an estimation regarding concurrent programs.
* The **speed** of a program denotes the time it takes for the program to execute in full. This can be measured in any increment of time
* **Speedup** is time that measures the benefit of executing a computation in parallel. It is defined as the time it takes a program to execute in serial(with one processor), divided by the time it takes to execute in parallel(with multiple processors). The formula for speedups is as follows:

```
                      T(1)
				 s = ------
					  T(j)
```

In the preceding formula, _T(j)_ is the time it takes to execute the program when using _j_ processors.

# Formula and Interpretation

Before we get into the formula for Amdahl's law and its implications, let's explore the concept of speedup, through some brief analysis. Let's assume that there a re N workers working on a given job that is fully parallelizable - that is, the job can be perfectly divided into N equal sections. This means that N workers working together to complete the job will only take _1/N_ of the time it takes one worker to complete the same job.

However, most computer programs are not 100% parallelizable: some parts of a program might be inherently sequential, while others are broken up into parallel tasks.

# The formula for Amdahl's law

Now, let B denote the fraction of the program that is strictly serial, and consider the following:
* _B * T(1)_ is the time it takes to execute the parts of the program that is inherently sequential.
* _T(1) - B * T(1) = (1 - B) * T(1)_ is the time it takes to execute the parts of the program that are parallelizable, with one processor:
	- Then, _((1 - B) * T(1)) / N_ is the time it takes to execute these parts with _N_ processors
* So, _B * T(1) + ((1 - B) * T(1)) / N_ is the total time it takes to execute the whole program with N processors.

Coming back to the formula for the speedup quantity, we have the following:

```
             T(1)               T(1)                     1
	     s = ------ = ------------------------- =  --------------
	    	 T(j)     B * T(1) + (1 - B) * T(1)      B + (1 - B)
			                     --------------          -------
			  				           j                    j
```

This formula is actually a form of Amdahl's law, used to estimate the speedup in a parallel program

# Implications

A quote from Gene Amdahl in 1967 indicated that whatever concurrent and parallel techniques are implemented in a program, the sequential nature of the overhead portion required in the program always sets an upper boundary on how much speedup the program will gain. This is one of the implications that Amdahl's law further suggests. Consider the following example:

```
   1 - B   1 - B         1             1
   ----- > ----- ==> ---------- < ----------- ==> S(j) < S(j + 1)
     j     j + 1      B + 1 - B    B + 1 - B
                          -----        -----
						    j          j + 1
```
S(n) denotes the speedup gained from 'n' processors.

However, this doesn't mean that we should always implement concurrency and parallelism with as many system processors as possible, to achieve the highest performance. In fact, from the formula, we can also gather that the speedup achieved from incrementing the number of processors decreases. In other words, as we add more processors for our concurrent program, we will obtain less and less improvement in execution time.

Furthermore, as mentioned previously, another implication of Amdahl's law suggests concerns the upper limit of the execution time improvement:
```
             /--
			 |
			 |  S <= 1 / B
			 |
			 ---
			 |
			 |  lim(j->inf) S = 1 / B
			 |
			 \--
```

_1 / B_ is the cap of how much improvement concurrency and parallelism can offer your program. This is to say that, no matter how many available resources your system has, it is impossible to obtain a speedup larger than _1 / B_ through concurrency, and this limit is dictated by the sequential overhead portion of the program(B is the fraction of the program that is strictly serial).


# Amdahl's law's relationship to the law of diminishing returns

Amdahl's law is often conflated with the law of diminishing returns, which is rather popular concept in economics. However, the law of diminishing returns is only a special case of applying Amdahl's law, depending on the order of improvement. If the order of separate tasks in the program is chosen to be improved in an **optimal** way, a monotonically decreasing improvement in execution time will be observed, demonstrating diminishing returns. An optimal method indicates first applying those improvements that will result in returns. An optimal method indicates first applying those improvements that will result in the greatest speedups, and leaving those improvements yielding smaller speedups for later.

Now, if we were to reverse this sequence for choosing resources, in which we improve less optimal components of our program before optimal components, the speedup achieved through the improvement would increase throughout the process. Furthermore, it is actually more beneficial for us to implement system improvements in the reverse-optimal order in reality, as the more optimal components are usually more complex, and take more time to improve.

Another similarity between Amdahl's law and the law f diminishing returns concerns the improvement in speedup obtained through adding more processors to a system. Specifically, as a new processor is added to the system to process a fixed-size task, it will offer less usable computation power than the previous processor. As we discussed in the last section, the improvement in this situation strictly decreases as the number of processors increases, and the total throughout approaches the upper boundary of _1 / B_.

It is important to note that this analysis does not take into account other potential bottlenecks, such as memory bandwidth and I/O bandwidth. In fact, these resources do not scale with number of processors, then simply adding processors results in even lower returns.

# Simulation in Python

```python
from math import sqrt
from timeit import default_timer as timer
import concurrent.futures
import multiprocessing

def is_prime(x):
    if x < 2:
        return False
    if x == 2:
        return True
    if x % 2 == 0:
        return False
    limit = int(sqrt(x)) + 1
    for i in range(3, limit, 1):
        if x % i == 0:
            return False
    return True

def concurrent_solve(n_workers):
    print("Number of workers: %i" % n_workers)

    start = timer()
    result = []

    with concurrent.futures.ProcessPoolExecutor(max_workers=n_workers) as executor:
        futures = [executor.submit(is_prime, i) for i in input]
        completed_futures = concurrent.futures.as_completed(futures)

        sub_start = timer()

        for _, future in enumerate(completed_futures):
            if future.result():
                result.append(future.result())
        sub_duration = timer() - sub_start

    duration = timer() - start
    print("Sub took: %.4f seconds" % sub_duration)
    print("Took: %.4f seconds" % duration)

input = [i for i in range(10 ** 13, 10 ** 13 + 1000)]

for n_workers in range(1, multiprocessing.cpu_count() + 1):
    concurrent_solve(n_workers)
    print('_' * 20)
```

<hr></hr>
**OUTPUT:**

```
$ python3 example1.py
Number of workers: 1
Sub took: 38.3627 seconds
Took: 38.4594 seconds
____________________
Number of workers: 2
Sub took: 19.7153 seconds
Took: 19.9212 seconds
____________________
Number of workers: 3
Sub took: 13.5572 seconds
Took: 13.6383 seconds
____________________
Number of workers: 4
Sub took: 13.0046 seconds
Took: 13.0960 seconds
____________________
```

We can see that while considerable improvements were gained after increasing the number of processors from 1 to 2, hardly any speedup was achieved during the third iteration(and so for fourth). This is consistent with our earlier discussions regarding the similarity between Amdahl's law and the law of diminishing returns, when considering the number of processors.

# Practical application of Amdahl's law

As discussed, by analyzing the sequential and parallelizable portion of a given program or system with Amdahl's law, we can determine, or at least estimate, the upper limit of any potential improvements in speed resulting from parallel computing. Upon obtaining this estimation, we can then make an informed decision on whether an improved execution time is worth an increase in processing power.

From the examples, we can see that Amdahl's law is applied when you have a concurrent program that is mixture of both sequentially and executed-in-parallels instructions. By performing analysis using Amdahl's law, we can determine the speedup through each incrementation of the number of cores available to perform the execution, as well as how close that incrementation is to helping the program achieve the best possible speedup from parallelization.

Now, let's suppose that you are in charge of developing a concurrent program that currently has 40% of its instructions parallelizable. This means that multiple processors can be simultaneously for 40% program execution. Now you have been tasked with increasing the speed of this program by implementing either of the following two choices:

	* Having four processors implemented to execute the program instructions
	* Having two processors implemented, in addition to increasing the parallelizable portion of the program to 80%

How can we analytically compare these two choices, in order to determine the one that will produce the best speed for our program ?

```
1.
            1              10
  S = --------------- ==> ---- =~ 1.43
	  0.6 + (0.4 / 4)      7


2.
            1              10
  S = --------------- ==> ---- =~ 1.67
	  0.2 + (0.8 / 2)      6

```

As you can see, the second option is actually the better choice to speed up our specific program.

As final note, it is important to know that, while Amdahl's law offers an estimation of potential speedup in an unambiguous way, the law itself makes a number of underlying assumptions and does not take into account some potentially important factors, such as the overhead of parallelism or the speed of memory. For this reason, the formula of Amdahl's law simplifies various considerations that might be common in practice.
