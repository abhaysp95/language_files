from math import sqrt
from timeit import default_timer as timer
import concurrent.futures

def is_prime(x):
    if x < 2:
        return False
    if x == 2:
        return True
    if x % 2 == 0:
        return False
    limit = int(sqrt(x)) + 1
    for num in range(3, limit, 1):
        if x % num == 0:
            return False
    return True

input = [i for i in range(10 ** 13, 10 ** 13 + 500)]

start = timer()
result = []

# sequential (took 19.54 seconds)
# for i in input:
    # if is_prime(i):
        # result.append(i)

# concurrent
with concurrent.futures.ProcessPoolExecutor(max_workers=20) as executor:
    futures = [executor.submit(is_prime, i) for i in input]

    for i, futures in enumerate(concurrent.futures.as_completed(futures)):
        if futures.result():
            result.append(input[i])

print("result 1 is:", result)
print("took %.2f seconds" % (timer() - start))

